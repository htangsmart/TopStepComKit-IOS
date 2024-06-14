//
//  IWearAlarmSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSAlarmAbility_h
#define ITPSAlarmAbility_h

#import <TopStepComKit/TPSAlarmModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

@class RACSubject<ValueType>;
@protocol ITPSAlarmAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSAlarmListCallback)(NSArray<TPSAlarmModel*>* _Nullable alarmList);

+(instancetype)share;

-(void)getAlarmList:(TPSAlarmListCallback)block;
-(void)sendAlarmList:(NSArray<TPSAlarmModel*>*)alarmList block:(void(^)(NSArray *alarmList))block;
-(RACSubject*)observeAlarmChange;

- (NSString *)newClockId;

@end


#endif /* IWearCurDayActivitySync_h */
