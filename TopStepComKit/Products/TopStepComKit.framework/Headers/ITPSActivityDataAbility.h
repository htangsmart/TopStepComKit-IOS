//
//  IWearHistoryActivitySync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSActivityDataAbility_h
#define ITPSActivityDataAbility_h

#import <TopStepComKit/TPSHistoryActivityModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

@protocol ITPSActivityDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistoryActivityCallback)(NSArray<TPSHistoryActivityModel*>* _Nullable historyActivityModelList);
typedef void(^TPSTodayAllActivityCallback)(TPSHistoryActivityModel* _Nullable historyActivityModel);

+(instancetype _Nonnull )share;

/// 根据时间范围获取历史活动数据 部分设备不支持查询截止时间（绅聚）
/// Get historical activity data based on time range
-(void)getHistoryActivity:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryActivityCallback _Nullable)block;

/// 获取当日活动数据
/// Get today's activity data
-(void)getTodayTotalActivity:(TPSTodayAllActivityCallback _Nullable)block;

@end


#endif /* IWearCurDayActivitySync_h */
