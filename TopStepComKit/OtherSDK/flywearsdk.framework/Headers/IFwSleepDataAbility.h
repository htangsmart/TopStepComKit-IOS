//
//  IWearHistorySleepSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef IWearHistorySleepSync_h
#define IWearHistorySleepSync_h

#import <flywearsdk/FwHistorySleepModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>

@protocol IFwSleepDataAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwHistorySleepCallback)(NSArray<FwHistorySleepModel*>* _Nullable historySleepModelList);

+(instancetype _Nonnull )share;

-(void)getHistorySleep:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistorySleepCallback _Nullable)block;

@end


#endif /* IWearCurDayActivitySync_h */
