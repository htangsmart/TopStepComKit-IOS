//
//  TPSDaySleepEntity.h
//  TopStepComKit
//
//  Created by Topstep on 2024/3/28.
//

#ifndef TPSDaySleepEntity_h
#define TPSDaySleepEntity_h

#import <TopStepComKit/TPSHistorySleepModel.h>
#import <TopStepComKit/TPSSleepBigItemEntity.h>

//日睡眠分析
@interface TPSDaySleepEntity : NSObject


@property(nonatomic,assign) double deepTotalMinute;
@property(nonatomic,assign) int deepTotalSeconds;
@property(nonatomic,assign) double lightTotalMinute;
@property(nonatomic,assign) int lightTotalSeconds;
/*
 零星小睡有两种睡眠时长统计方式，这种算法会将零星小睡内部的短暂清醒时间也归为睡眠时间
 */
@property(nonatomic,assign) double napTotalMinute;
@property(nonatomic,assign) int napTotalSeconds;
/*
 零星小睡有两种睡眠时长统计方式，这种算法不会将零星小睡内部的短暂清醒时间也归为睡眠时间
 */
@property(nonatomic,assign) double napTotalMinuteWithoutWake;
@property(nonatomic,assign) int napTotalSecondsWithoutWake;
@property(nonatomic,assign) double wakeTotalMinute;
@property(nonatomic,assign) int wakeTotalSeconds;
@property(nonatomic,assign) double rapidEyeMoveTotalMinute;
@property(nonatomic,assign) int rapidEyeMoveTotalSeconds;
@property(nonatomic,assign) int deepCount;
@property(nonatomic,assign) int lightCount;
@property(nonatomic,assign) int rapidEyeMoveCount;
@property(nonatomic,assign) int napCount;
@property(nonatomic,assign) int wakeCount;
@property(nonatomic,assign) double deepProportion;
@property(nonatomic,assign) double lightProportion;
@property(nonatomic,assign) double napProportion;
@property(nonatomic,assign) double wakeProportion;
@property(nonatomic,assign) double rapidEyeMoveProportion;
//当前所有的睡眠时长总和，含零星小睡，但是将零星小睡视为一整段（这种算法会将零星小睡内部的短暂清醒时间也归为睡眠时间）
@property(nonatomic,assign) double totalSleepMinuteWithNap;
@property(nonatomic,assign) int totalSleepSecondsWithNap;
//当前所有的睡眠时长总和，不含零星小睡及其所代表的深睡浅睡等部分
@property(nonatomic,assign) double totalSleepMinuteWithoutNap;
@property(nonatomic,assign) int totalSleepSecondsWithoutNap;
//当天所有的睡眠总和时长，不将零星小睡视为一整段（这种算法不会将零星小睡内部的短暂清醒时间也归为睡眠时间）
@property(nonatomic,assign) double totalSleepMinuteWithNapButRemoveWakeInNap;
@property(nonatomic,assign) int totalSleepSecondsWithNapButRemoveWakeInNap;
@property(nonatomic,assign) long belongDay;
//原始的所有所有的睡眠小片段，不包含清醒时间段
@property(nonatomic,strong) NSArray<TPSHistorySleepModel*>* allRawSmallItemList;
//各个大段睡眠(不是原始数据的那种小段)的列表，将其中最长的一段放在数组的首位。注意这个数组的长度可能为0。
@property(nonatomic,strong) NSMutableArray<TPSSleepBigItemEntity*>* bigItemList;

-(instancetype)initWithRawSmallItem:(NSArray<TPSHistorySleepModel *> *)allRawSmallItemList;

-(TPSSleepBigItemEntity*)getMaxBigItem;
-(NSArray<TPSSleepBigItemEntity*>*) getNapBigItemList;
-(NSArray<TPSSleepBigItemEntity*>*) getLongSleepBigItemList;
-(BOOL) getIsAllNap;

@end


#endif /* TSDaySleepEntity_h */
