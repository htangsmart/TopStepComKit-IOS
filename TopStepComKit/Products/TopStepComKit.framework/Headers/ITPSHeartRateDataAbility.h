//
//  IWearHistoryHeartRateSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSHeartRateDataAbility_h
#define ITPSHeartRateDataAbility_h

#import <TopStepComKit/TPSHistoryHeartRateModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSHrConfigModel.h>

@protocol ITPSHeartRateDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistoryHeartRateCallback)(NSArray<TPSHistoryHeartRateModel*>* _Nullable historyHeartRateModelList);
typedef void(^TPSHeartRateConfigCallback)(TPSHrConfigModel* _Nullable configModel);

+(instancetype _Nonnull )share;
/// 获取历史静息心率
-(void)getHistoryRestQuietHeartRate:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryHeartRateCallback _Nullable)block;

/// 获取历史心率
-(void)getHistoryHeartRate:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryHeartRateCallback _Nullable)block;

/// 获取历史实时心率
-(void)getHistoryRealTimeHeartRate:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryHeartRateCallback _Nullable)block;

/// 获取心率配置
-(void)getHrConfig:(TPSHeartRateConfigCallback _Nonnull )block;

/// 设置心率配置
-(void)setHrConfig:(TPSHrConfigModel*)model block:(TPSSendMsgResult)block;

@end


#endif /* IWearCurDayActivitySync_h */
