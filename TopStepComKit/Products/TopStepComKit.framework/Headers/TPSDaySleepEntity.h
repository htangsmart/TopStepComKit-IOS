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

@property(nonatomic,assign) int deepTotalMinute;
@property(nonatomic,assign) int lightTotalMinute;
@property(nonatomic,assign) int napTotalMinute;
@property(nonatomic,assign) int wakeTotalMinute;
@property(nonatomic,assign) int rapidEyeMoveTotalMinute;
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
//当前所有的睡眠时长总和，含零星小睡
@property(nonatomic,assign) int totalSleepMinuteWithNap;
//当前所有的睡眠时长总和，不含零星小睡
@property(nonatomic,assign) int totalSleepMinuteWithoutNap;
@property(nonatomic,assign) long belongDay;
//原始的所有所有的睡眠小片段，不包含清醒时间段
@property(nonatomic,strong) NSArray<TPSHistorySleepModel*>* allRawSmallItemList;
//各个大段睡眠(不是原始数据的那种小段)的列表，将其中最长的一段放在数组的首位。
@property(nonatomic,strong) NSMutableArray<TPSSleepBigItemEntity*>* bigItemList;

-(instancetype)initWithRawSmallItem:(NSArray<TPSHistorySleepModel *> *)allRawSmallItemList;

-(TPSSleepBigItemEntity*)getMaxBigItem;
-(NSArray<TPSSleepBigItemEntity*>*) getNapBigItemList;
-(NSArray<TPSSleepBigItemEntity*>*) getLongSleepBigItemList;
-(BOOL) getIsAllNap;

@end


#endif /* TSDaySleepEntity_h */
