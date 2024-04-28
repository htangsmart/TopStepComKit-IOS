//
//  TPSSleepBigItemEntity.h
//  TopStepComKit
//
//  Created by Topstep on 2024/3/28.
//

#ifndef TPSSleepBigItemEntity_h
#define TPSSleepBigItemEntity_h

#import <TopStepComKit/TPSHistorySleepModel.h>

//一段连续睡眠(大段睡眠，由许多原始睡眠数据组成)，一天中有可能有多段连续的睡眠，以中间超过30分钟的清醒为两个睡眠的间隔，由许多原始睡眠数据组成一段连续的睡眠（大段睡眠）
@interface TPSSleepBigItemEntity : NSObject

typedef NS_ENUM(UInt8, TPSSleepAnalyEntity_Sleep_Type){
    TPSSleepAnalyEntity_Sleep_Type_LightOrDeepOrWake = 2,
    TPSSleepAnalyEntity_Sleep_Type_Nap = 3,
};

@property(nonatomic,assign) long start_time;
@property(nonatomic,assign) long end_time;
@property(nonatomic,assign) double deepMinute;
@property(nonatomic,assign) int deepSeconds;
@property(nonatomic,assign) double lightMinute;
@property(nonatomic,assign) int lightSeconds;
@property(nonatomic,assign) double rapidEyeMoveMinute;
@property(nonatomic,assign) int rapidEyeMoveSeconds;
@property(nonatomic,assign) double napMinute;
@property(nonatomic,assign) int napSeconds;
@property(nonatomic,assign) double napMinuteWithoutWake;
@property(nonatomic,assign) int napSecondsWithoutWake;
@property(nonatomic,assign) double wakeMinute;
@property(nonatomic,assign) int wakeSeconds;
@property(nonatomic,assign) int deepCount;
@property(nonatomic,assign) int lightCount;
@property(nonatomic,assign) int rapidEyeMoveCount;
@property(nonatomic,assign) int napCount;
@property(nonatomic,assign) int wakeCount;
@property(nonatomic,assign) double deepProportion;
@property(nonatomic,assign) double lightProportion;
@property(nonatomic,assign) double rapidEyeMoveProportion;
@property(nonatomic,assign) double napProportion;
@property(nonatomic,assign) double wakeProportion;
@property(nonatomic,assign) double totalSleepMinute;
@property(nonatomic,assign) int totalSleepSeconds;
@property(nonatomic,assign) TPSSleepAnalyEntity_Sleep_Type type;
@property(nonatomic,strong) NSMutableArray<TPSHistorySleepModel*>* smallItemList;

@end


#endif /* TPSSleepBigItemEntity_h */
