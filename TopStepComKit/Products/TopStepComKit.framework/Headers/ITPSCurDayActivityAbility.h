//
//  IWearCurDayActivitySync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSCurDayActivityAbility_h
#define ITPSCurDayActivityAbility_h

#import <TopStepComKit/TPSCurDayActivityModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

@protocol ITPSCurDayActivityAbility <NSObject,ITPSWearBaseAbility>

typedef void(^ITPSCurDayActivityCallback)(TPSCurDayActivityModel* curDayActivityModel);

+(instancetype)share;

-(void)getCurDayAcitity:(ITPSCurDayActivityCallback)block;

@end


#endif /* IWearCurDayActivitySync_h */
