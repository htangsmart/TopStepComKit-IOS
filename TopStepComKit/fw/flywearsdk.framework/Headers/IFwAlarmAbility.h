//
//  IWearAlarmSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef IWearAlarmSync_h
#define IWearAlarmSync_h

#import <flywearsdk/FwAlarmModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>

@class RACSubject<ValueType>;
@protocol IFwAlarmAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwAlarmListCallback)(NSArray<FwAlarmModel*>* _Nullable alarmList);

+(instancetype)share;

-(void)getAlarmList:(FwAlarmListCallback)block;

-(void)sendAlarmList:(NSArray<FwAlarmModel*>*)alarmList success:(void(^)(NSArray*alarmList))success;

-(RACSubject*)observeAlarmChange;

- (NSString *)newClockId;

@end


#endif /* IWearCurDayActivitySync_h */
