//
//  IMChat+Representable.swift
//  imcore-rest
//
//  Created by Eric Rabil on 8/9/20.
//  Copyright © 2020 Eric Rabil. All rights reserved.
//

import Foundation
import IMCore

@available(iOS 14, macOS 10.16, watchOS 7, *)
private var guidKey: String {
    if #available(iOS 15, macOS 12.0, watchOS 8, *) {
        return IMChatPropertyGroupPhotoGUID
    } else {
        return IMGroupPhotoGuidKey
    }
}

extension IMChat: ChatConfigurationRepresentable {
    public var readReceipts: Bool {
        get {
            value(forChatProperty: "EnableReadReceiptForChat") as? Bool ?? false
        }
        set {
            setValue(newValue == true ? 1 : 0, forChatProperty: "EnableReadReceiptForChat")
        }
    }
    
    public var ignoreAlerts: Bool {
        get {
            value(forChatProperty: "ignoreAlertsFlag") as? Bool ?? false
        }
        set {
            setValue(newValue == true ? 1 : 0, forChatProperty: "ignoreAlertsFlag")
        }
    }
    
    public var groupPhotoID: String? {
        get {
            if #available(iOS 14, macOS 10.16, watchOS 7, *) {
                return value(forChatProperty: guidKey) as? String
            } else {
                return nil
            }
        }
        set {
            if #available(iOS 14, macOS 10.16, watchOS 7, *) {
                setValue(newValue, forChatProperty: IMGroupPhotoGuidKey)
                sendGroupPhotoUpdate(newValue)
            }
        }
    }
}