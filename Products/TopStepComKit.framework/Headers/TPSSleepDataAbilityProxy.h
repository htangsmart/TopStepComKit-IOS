//
//  TPSSleepDataAbilityProxy.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef TPSSleepDataAbilityProxy_h
#define TPSSleepDataAbilityProxy_h

#import <TopStepComKit/ITPSSleepDataAbility.h>
#import <TopStepComKit/TPSDaySleepEntity.h>

@interface TPSSleepDataAbilityProxy : NSObject<ITPSSleepDataAbility>

typedef void(^TPSDaySleepEntityCallback)(NSArray<TPSDaySleepEntity*>* _Nullable daySleepEntityList);

@property(nonatomic, strong) id<ITPSSleepDataAbility> _Nonnull realTarget;

+(instancetype _Nonnull )share;

-(void)getHistorySleep:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistorySleepCallback _Nullable)block;

-(void)getDaySleepEntityList:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSDaySleepEntityCallback _Nullable)block;

@end


#endif /* TSWearCurDayActivitySync_h */
