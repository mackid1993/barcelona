#import <DataDetectorsCore/DDAbstractType.h>
#import <DataDetectorsCore/DDAtomicRegexp.h>
#import <DataDetectorsCore/DDBasicRegexp.h>
#import <DataDetectorsCore/DDBindableRegexp.h>
#import <DataDetectorsCore/DDBinderInfo.h>
#import <DataDetectorsCore/DDCompilationNote.h>
#import <DataDetectorsCore/DDCompilerState.h>
#import <DataDetectorsCore/DDConcatenationRegexp.h>
#import <DataDetectorsCore/DDDictionaryError.h>
#import <DataDetectorsCore/DDDisjunctionRegexp.h>
#import <DataDetectorsCore/DDEmptyPatternError.h>
#import <DataDetectorsCore/DDErrorRegexp.h>
#import <DataDetectorsCore/DDGrammar.h>
#import <DataDetectorsCore/DDInvalidRangeError.h>
#import <DataDetectorsCore/DDLRItem.h>
#import <DataDetectorsCore/DDLocation.h>
#import <DataDetectorsCore/DDLookupRegexp.h>
#import <DataDetectorsCore/DDMessageCache.h>
#import <DataDetectorsCore/DDMessageCacheElement.h>
#import <DataDetectorsCore/DDNonTerminal.h>
#import <DataDetectorsCore/DDOneOrMoreExp.h>
#import <DataDetectorsCore/DDOperatorRegexp.h>
#import <DataDetectorsCore/DDOptionalExp.h>
#import <DataDetectorsCore/DDParserState.h>
#import <DataDetectorsCore/DDProduction.h>
#import <DataDetectorsCore/DDRegexpManager.h>
#import <DataDetectorsCore/DDRepeatCount.h>
#import <DataDetectorsCore/DDRepeatMax.h>
#import <DataDetectorsCore/DDRepeatMinMax.h>
#import <DataDetectorsCore/DDScanServer.h>
#import <DataDetectorsCore/DDScanServerDispatcher.h>
#import <DataDetectorsCore/DDScanStepBlockContainer.h>
#import <DataDetectorsCore/DDScannerList.h>
#import <DataDetectorsCore/DDScannerObject.h>
#import <DataDetectorsCore/DDScannerResult.h>
#import <DataDetectorsCore/DDScannerService.h>
#import <DataDetectorsCore/DDScannerServiceConfiguration.h>
#import <DataDetectorsCore/DDStarExp.h>
#import <DataDetectorsCore/DDStatsBuilder.h>
#import <DataDetectorsCore/DDSymbol.h>
#import <DataDetectorsCore/DDTokenRegexp.h>
#import <DataDetectorsCore/DDTypeChecker.h>
#import <DataDetectorsCore/DDTypeCheckerDelegate.h>
#import <DataDetectorsCore/DDTypeInhabitant.h>
#import <DataDetectorsCore/DDURLMatch.h>
#import <DataDetectorsCore/DDURLifier.h>
#import <DataDetectorsCore/DDUnaryOperator.h>
#import <DataDetectorsCore/DDVariable.h>
#import <DataDetectorsCore/DDVariableNotFoundError.h>
#import <DataDetectorsCore/DataDetectorsSourceAccess.h>
#import <DataDetectorsCore/DataDetectorsSourceAccessProtocol.h>

typedef void* DDResultRef;
typedef void* DDScanQueryRef;

DDResultRef DDResultCreateEmpty(void);
typedef struct __DDQueryOffset {
    CFIndex         p0:32;
    CFIndex         p1:32;
} DDQueryOffset;
typedef struct __DDQueryRange {
    DDQueryOffset     p0;
    DDQueryOffset     p1;
} DDQueryRange;
DDResultRef DDResultCreate(CFStringRef arg0, DDQueryRange arg1);
void DDResultSetContent(DDResultRef result, DDScanQueryRef query);
DDScanQueryRef DDScanQueryCreateFromString(CFAllocatorRef allocator, CFStringRef string, CFRange range);
