//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import <MediaPlayer/MPExclusiveAccessible-Protocol.h>
#import <MediaPlayer/NSSecureCoding-Protocol.h>
#import <MediaPlayer/_MPSectionedIdentifierListEncodableNextEntriesProviding-Protocol.h>

@class MPSectionedIdentifierListEntry, NSDictionary, NSMutableArray, NSMutableDictionary, NSString;
@protocol MPSectionedIdentifierListAnnotationDelegate, MPSectionedIdentifierListDelegate, OS_dispatch_queue;

@interface MPSectionedIdentifierList : NSObject
{
    long long _itemCount;
    NSObject *_accessQueue;
    NSMutableArray *_startEntries;
    MPSectionedIdentifierListEntry *_endEntry;
    NSMutableDictionary *_sectionHeadEntryMap;
    _Bool _automaticallyReversesNonDestructiveDataSourceEdits;
    NSString *_identifier;
    id _delegate;
    id _annotationDelegate;
}

+ (void)_performWithoutRequiringExclusivity:(id)arg1;
+ (_Bool)supportsSecureCoding;

@property(nonatomic) __weak id annotationDelegate; // @synthesize annotationDelegate=_annotationDelegate;
@property(nonatomic) _Bool automaticallyReversesNonDestructiveDataSourceEdits; // @synthesize automaticallyReversesNonDestructiveDataSourceEdits=_automaticallyReversesNonDestructiveDataSourceEdits;
@property(nonatomic) __weak id delegate; // @synthesize delegate=_delegate;
@property(readonly, nonatomic) NSString *identifier; // @synthesize identifier=_identifier;
- (void)_reverseEnumeratorWillStartAtEnd:(id)arg1 withExclusiveAccessToken:(id)arg2;
- (void)_enumerator:(id)arg1 didEncounterEntry:(id)arg2 withExclusiveAccessToken:(id)arg3;
- (id)_endEntryWithExclusiveAccessToken:(id)arg1;
- (id)_sectionHeadEntryMapWithExclusiveAccessToken:(id)arg1;
- (id)_tailEntryForSectionIdentifier:(id)arg1 withExclusiveAccessToken:(id)arg2;
- (id)_startEntriesWithExclusiveAccessToken:(id)arg1;
@property(readonly, nonatomic, getter=_sectionDataSources) NSDictionary *sectionDataSources;
- (void)_loadDataSource:(id)arg1 forSection:(id)arg2 completion:(id)arg3;
- (long long)_itemCountWithExclusiveAccessToken:(id)arg1;
- (id)_itemEntry:(id)arg1 sectionIdentifier:(id)arg2 withExclusiveAccessToken:(id)arg3;
- (void)_insertDataSource:(id)arg1 forSection:(id)arg2 afterEntry:(id)arg3 withExclusiveAccessToken:(id)arg4;
- (void)_insertDataSourceHead:(id)arg1 afterEntry:(id)arg2 withExclusiveAccessToken:(id)arg3;
- (id)_dataSourceMoveItem:(id)arg1 inSection:(id)arg2 afterEntry:(id)arg3 withExclusiveAccessToken:(id)arg4;
- (id)_dataSourceInsertItems:(id)arg1 fromSection:(id)arg2 afterEntry:(id)arg3 withExclusiveAccessToken:(id)arg4;
- (void)_addBranchToEntry:(id)arg1 entries:(id)arg2 withExclusiveAccessToken:(id)arg3;
- (void)dataSourceUpdateSection:(id)arg1;
- (void)dataSourceReloadItem:(id)arg1 inSection:(id)arg2;
- (void)dataSourceRemoveItem:(id)arg1 fromSection:(id)arg2;
- (void)dataSourceMoveItemToTail:(id)arg1 inSection:(id)arg2;
- (void)dataSourceMoveItem:(id)arg1 afterItem:(id)arg2 inSection:(id)arg3;
- (void)dataSourceMoveItemToHead:(id)arg1 inSection:(id)arg2;
- (void)dataSourceInsertItemsAtTail:(id)arg1 inSection:(id)arg2;
- (void)dataSourceInsertItems:(id)arg1 afterItem:(id)arg2 inSection:(id)arg3;
- (void)dataSourceInsertItemsAtHead:(id)arg1 inSection:(id)arg2;
- (void)removeItem:(id)arg1 fromSection:(id)arg2;
- (void)moveItem:(id)arg1 fromSection:(id)arg2 afterTailOfSection:(id)arg3;
- (void)moveItem:(id)arg1 fromSection:(id)arg2 afterItem:(id)arg3 inSection:(id)arg4;
- (void)moveItem:(id)arg1 fromSection:(id)arg2 afterHeadOfSection:(id)arg3;
- (void)moveItemToEnd:(id)arg1 fromSection:(id)arg2;
- (void)moveItemToStart:(id)arg1 fromSection:(id)arg2;
@property(readonly, nonatomic) long long itemCount;
- (_Bool)isDeletedItem:(id)arg1 inSection:(id)arg2;
- (_Bool)hasSection:(id)arg1;
- (_Bool)hasItem:(id)arg1 inSection:(id)arg2;
- (void)addDataSourceAtEnd:(id)arg1 section:(id)arg2 completion:(id)arg3;
- (void)addDataSource:(id)arg1 section:(id)arg2 afterTailOfSection:(id)arg3 completion:(id)arg4;
- (void)addDataSource:(id)arg1 section:(id)arg2 afterItem:(id)arg3 inSection:(id)arg4 completion:(id)arg5;
- (void)addDataSource:(id)arg1 section:(id)arg2 afterHeadOfSection:(id)arg3 completion:(id)arg4;
- (void)addDataSourceAtStart:(id)arg1 section:(id)arg2 completion:(id)arg3;
- (id)enumeratorWithOptions:(unsigned long long)arg1 startingAtTailOfSection:(id)arg2 withExclusiveAccessToken:(id)arg3;
- (id)enumeratorWithOptions:(unsigned long long)arg1 startingAtTailOfSection:(id)arg2;
- (id)enumeratorWithOptions:(unsigned long long)arg1 startingAtItem:(id)arg2 inSection:(id)arg3 withExclusiveAccessToken:(id)arg4;
- (id)enumeratorWithOptions:(unsigned long long)arg1 startingAtItem:(id)arg2 inSection:(id)arg3;
- (id)enumeratorWithOptions:(unsigned long long)arg1 withExclusiveAccessToken:(id)arg2;
- (id)enumeratorWithOptions:(unsigned long long)arg1;
- (long long)performWithExclusiveAccessAndReturnInteger:(id)arg1;
- (_Bool)performWithExclusiveAccessAndReturnBOOL:(id)arg1;
- (id)performWithExclusiveAccessAndReturnObject:(id)arg1;
- (void)performWithExclusiveAccess:(id)arg1;
- (void)replaceDataSource:(id)arg1 forSection:(id)arg2 completion:(id)arg3;
- (id)_encodeEntry:(id)arg1 withExclusiveAccessToken:(id)arg2;
- (void)encodeWithCoder:(id)arg1 withExclusiveAccessToken:(id)arg2;
- (void)encodeWithCoder:(id)arg1;
- (void)_stitchPreviousEntry:(id)arg1 toEntry:(id)arg2 cloneIndex:(id)arg3;
- (void)_stitchLastItemEntryToHeadEntry:(id)arg1 branchList:(id)arg2;
- (void)_stitchWithPreviousEntry:(id)arg1 list:(id)arg2 cloneIndex:(id)arg3;
- (void)_beforeInitWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)dealloc;
- (id)initWithIdentifier:(id)arg1;
- (id)init;
- (id)_debugDescriptionWithEnumerator:(id)arg1 lengths:(id)arg2;
- (id)debugDescriptionStartingAtItem:(id)arg1 inSection:(id)arg2;
@property(readonly, copy) NSString *debugDescription;
- (id)encodableNextEntriesWithExclusiveAccessToken:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end
