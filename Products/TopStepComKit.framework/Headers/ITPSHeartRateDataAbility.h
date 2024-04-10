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
-(void)getHistoryRestQuietHeartRate:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryHeartRateCallback _Nullable)block;
-(void)getHistoryHeartRate:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryHeartRateCallback _Nullable)block;
-(void)getHistoryRealTimeHeartRate:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryHeartRateCallback _Nullable)block;
-(void)getHrConfig:(TPSHeartRateConfigCallback _Nonnull )block;
-(void)setHrConfig:(TPSHrConfigModel*)model block:(TPSSendMsgResult)block;

@end


#endif /* IWearCurDayActivitySync_h */
