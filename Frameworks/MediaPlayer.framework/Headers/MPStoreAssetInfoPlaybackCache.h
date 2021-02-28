//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableArray, NSMutableDictionary;
@protocol OS_dispatch_queue;

@interface MPStoreAssetInfoPlaybackCache : NSObject
{
    NSObject *_accessQueue;
    NSMutableArray *_accessOrderedRequests;
    NSMutableDictionary *_requestToCachedResponse;
}

+ (id)sharedCache;

- (void)updateForPlaybackOfFileAsset:(id)arg1 fromResponse:(id)arg2;
- (id)cachedResponseForRequest:(id)arg1;
- (void)addCachedResponse:(id)arg1 forRequest:(id)arg2;
- (id)_init;

@end
