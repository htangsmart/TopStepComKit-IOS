//
//  IWearSportTargetSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSSportTargetAbility_h
#define ITPSSportTargetAbility_h

#import <TopStepComKit/TPSSportTargetModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

@protocol ITPSSportTargetAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSSportTargetCallback)(TPSSportTargetModel* sportTargetModel);

+(instancetype)share;

-(void)getSportTargets:(TPSSportTargetCallback)block;
-(void)sendSportTargets:(TPSSportTargetModel*)sportTargetModel block:(TPSSendMsgResult)block;

@end


#endif /* IWearCurDayActivitySync_h */
