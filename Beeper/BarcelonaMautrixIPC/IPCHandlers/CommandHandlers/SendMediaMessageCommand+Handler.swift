//
//  SendMediaMessageCommand+Handler.swift
//  BarcelonaFoundation
//
//  Created by Eric Rabil on 8/23/21.
//  Copyright © 2021 Eric Rabil. All rights reserved.
//

import Barcelona
import Foundation
import IMCore
import IMFoundation
import Logging
import Sentry

protocol Runnable {
    func run(payload: IPCPayload, ipcChannel: MautrixIPCChannel, chatRegistry _: CBChatRegistry) async
}

protocol AuthenticatedAsserting {}

extension SendMediaMessageCommand: Runnable, AuthenticatedAsserting {
    var log: Logging.Logger {
        Logger(label: "SendMediaMessageCommand")
    }

    func uploadAndRetry(filename: String, path: String) async throws -> String {
        let uploader = MediaUploader()
        for attempt in 1..<3 {
            do {
                return try await uploader.uploadFile(filename: file_name, path: URL(fileURLWithPath: path_on_disk))
            } catch {
                log.debug("Upload attempt \(attempt) failed: \(error.localizedDescription). Retrying in \(attempt)s")
                try await Task.sleep(nanoseconds: UInt64(attempt) * 1_000_000_000)
                continue
            }
        }
        return try await uploader.uploadFile(filename: file_name, path: URL(fileURLWithPath: path_on_disk))
    }

    func run(payload: IPCPayload, ipcChannel: MautrixIPCChannel, chatRegistry _: CBChatRegistry) async {
        SentrySDK.configureScope { scope in
            scope.setContext(
                value: [
                    "id": String(describing: payload.id),
                    "command": payload.command.name.rawValue,
                ],
                key: "payload"
            )
        }
        let span = SentrySDK.startTransaction(name: "SendMediaMessageCommand", operation: "run", bindToScope: true)
        let breadcrumb = Breadcrumb(level: .debug, category: "command")
        breadcrumb.message = "SendMediaMessageCommand/\(payload.id ?? 0)"
        breadcrumb.type = "user"
        SentrySDK.addBreadcrumb(breadcrumb)
        guard let chat = await cbChat, let imChat = chat.imChat else {
            payload.fail(strategy: .chat_not_found, ipcChannel: ipcChannel)
            span.finish(status: .notFound)
            return
        }
        SentrySDK.configureScope { scope in
            scope.setContext(
                value: [
                    "id": chat.id,
                    "service": String(describing: chat.service),
                ],
                key: "chat"
            )
        }

        let canSend = imChat.canSendTransfer(imChat)
        log.debug("Can send transfer to chat \(String(describing: imChat.guid)): \(canSend)")

        do {
            log.debug("Starting attachment upload")
            let guid = try await uploadAndRetry(filename: file_name, path: path_on_disk)
            log.debug("Attachment upload finished with GUID: \(guid)")

            var messageCreation = CreateMessage(parts: [
                .init(type: .attachment, details: guid)
            ])
            messageCreation.metadata = metadata

            let message = try await chat.sendReturningRaw(message: messageCreation)

            let service: String = {
                if let item = message._imMessageItem {
                    return item.service
                }
                if message.wasDowngraded {
                    return "SMS"
                }
                if imChat.isDowngraded() {
                    return "SMS"
                }
                return imChat.account.serviceName
            }()

            payload.reply(
                withResponse: .message_receipt(
                    BLPartialMessage(
                        guid: message.id,
                        service: service,
                        timestamp: Date().timeIntervalSinceNow
                    )
                ),
                ipcChannel: ipcChannel
            )
        } catch let error as LocalizedError & CustomNSError {
            SentrySDK.capture(error: error)
            log.error("failed to send media message: \(error as NSError)", source: "BLMautrix")
            payload.fail(
                code: error.errorUserInfo[NSDebugDescriptionErrorKey] as? String ?? "unknown",
                message: error.localizedDescription,
                ipcChannel: ipcChannel
            )
            span.finish(status: .internalError)
        } catch {
            SentrySDK.capture(error: error)
            log.error("failed to send media message: \(error as NSError)", source: "BLMautrix")
            payload.fail(
                code: "internal_error",
                message: "Sorry, we're having trouble processing your attachment upload.",
                ipcChannel: ipcChannel
            )
            span.finish(status: .internalError)
        }
    }
}
