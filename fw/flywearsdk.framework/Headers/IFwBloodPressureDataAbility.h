//
//  IFwBloodPressureDataAbility.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/21.
//

#ifndef IFwBloodPressureDataAbility_h
#define IFwBloodPressureDataAbility_h

#import <flywearsdk/FwHistoryBloodPressureModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>

@protocol IFwBloodPressureDataAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwHistoryBloodPressureCallback)(NSArray<FwHistoryBloodPressureModel*>* _Nullable bloodPressureList);

+(instancetype _Nonnull )share;

-(void)getHistoryBloodPressure:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistoryBloodPressureCallback _Nullable)block;

@end


#endif /* IFwBloodPressureDataAbility_h */
