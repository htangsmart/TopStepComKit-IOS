//
//  ITPSBloodPressureDataAbility.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/21.
//

#ifndef ITPSBloodPressureDataAbility_h
#define ITPSBloodPressureDataAbility_h

#import <TopStepComKit/TPSHistoryBloodPressureModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

@protocol ITPSBloodPressureDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistoryBloodPressureCallback)(NSArray<TPSHistoryBloodPressureModel*>* _Nullable bloodPressureList);

+(instancetype _Nonnull )share;

-(void)getHistoryBloodPressure:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryBloodPressureCallback _Nullable)block;

@end


#endif /* ITPSBloodPressureDataAbility_h */
