//
//  IWearHistoryHeartRateSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef IWearHistoryHeartRateSync_h
#define IWearHistoryHeartRateSync_h

#import <flywearsdk/FwHistoryHeartRateModel.h>
#import <flywearsdk/FwHrConfigModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>

@protocol IFwHeartRateDataAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwHistoryHeartRateCallback)(NSArray<FwHistoryHeartRateModel*>* _Nullable historyHeartRateModelList);
typedef void(^FwHeartRateConfigCallback)(FwHrConfigModel* _Nullable configModel);

+(instancetype _Nonnull )share;
-(void)getHistoryRestQuietHeartRate:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistoryHeartRateCallback _Nullable)block;
-(void)getHistoryHeartRate:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistoryHeartRateCallback _Nullable)block;
-(void)getHistoryRealTimeHeartRate:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistoryHeartRateCallback _Nullable)block;
-(void)getHrConfig:(FwHeartRateConfigCallback _Nonnull )block;
-(void)setHrConfig:(FwHrConfigModel*)model block:(FwSendMsgResult)block;

@end


#endif /* IWearCurDayActivitySync_h */
