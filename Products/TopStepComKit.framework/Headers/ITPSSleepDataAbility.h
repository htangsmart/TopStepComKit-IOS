//
//  IWearHistorySleepSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSSleepDataAbility_h
#define ITPSSleepDataAbility_h

#import <TopStepComKit/TPSHistorySleepModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

@protocol ITPSSleepDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistorySleepCallback)(NSArray<TPSHistorySleepModel*>* _Nullable historySleepModelList);

+(instancetype _Nonnull )share;

-(void)getHistorySleep:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistorySleepCallback _Nullable)block;

@end


#endif /* IWearCurDayActivitySync_h */
