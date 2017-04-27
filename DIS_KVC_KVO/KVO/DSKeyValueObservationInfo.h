//
//  DSKeyValueObservationInfo.h
//  DIS_KVC_KVO
//
//  Created by renjinkui on 2016/12/31.
//  Copyright © 2016年 JK. All rights reserved.
//


#import <Foundation/Foundation.h>

@class DSKeyValueObservance;
@class DSKeyValueProperty;
@class DSKeyValueContainerClass;

@interface DSKeyValueObservationInfo : NSObject
@property (nonatomic, strong) NSArray<DSKeyValueObservance *> *observances;
@property (nonatomic, assign) NSUInteger cachedHash;
@property (nonatomic, assign) BOOL cachedIsShareable;

- (id)_initWithObservances:(DSKeyValueObservance **)observances count:(NSUInteger)count hashValue:(NSUInteger)hashValue;
- (DSKeyValueObservationInfo *)_copyByAddingObservance:(DSKeyValueObservance *)observance;

@end

@interface DSKeyValueShareableObservationInfoKey : NSObject
@property (nonatomic, assign) BOOL addingNotRemoving;
@property (nonatomic, strong) DSKeyValueObservationInfo *baseObservationInfo;
@property (nonatomic, strong) NSObject *additionObserver;
@property (nonatomic, strong) DSKeyValueProperty *additionProperty;
@property (nonatomic, assign) NSUInteger additionOptions;
@property (nonatomic, assign) void* additionContext;
@property (nonatomic, strong) NSObject* additionOriginalObservable;
@property (nonatomic, strong) DSKeyValueObservance* removalObservance;
@property (nonatomic, assign) NSUInteger removalObservanceIndex;
@property (nonatomic, assign) NSUInteger cachedHash;
@end

DSKeyValueObservationInfo *_DSKeyValueObservationInfoCreateByAdding(DSKeyValueObservationInfo *baseObservationInfo, id observer, DSKeyValueProperty *property, int options, void *context, id originalObservable,  BOOL *flag, DSKeyValueObservance **pObservance);
DSKeyValueObservationInfo *_DSKeyValueObservationInfoCreateByRemoving(DSKeyValueObservationInfo *baseObservationInfo, id observer, DSKeyValueProperty *property, void *context, BOOL flag,  id originalObservable,  BOOL *fromCache, DSKeyValueObservance **pObservance);
void _DSKeyValueReplaceObservationInfoForObject(id object, DSKeyValueContainerClass * containerClass, DSKeyValueObservationInfo *oldObservationInfo, DSKeyValueObservationInfo *newObservationInfo);
NSUInteger _DSKeyValueObservationInfoGetObservanceCount(DSKeyValueObservationInfo *info) ;
void _DSKeyValueObservationInfoGetObservances(DSKeyValueObservationInfo *info, DSKeyValueObservance *observances[], NSUInteger count) ;
BOOL _DSKeyValueObservationInfoContainsObservance(DSKeyValueObservationInfo *info, DSKeyValueObservance *observance);



