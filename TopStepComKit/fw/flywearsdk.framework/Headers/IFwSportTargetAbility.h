//
//  IWearSportTargetSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef IWearSportTargetSync_h
#define IWearSportTargetSync_h

#import <flywearsdk/FwSportTargetModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>

@protocol IFwSportTargetAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwSportTargetCallback)(FwSportTargetModel* sportTargetModel);

+(instancetype)share;

-(void)getSportTargets:(FwSportTargetCallback)block;
-(void)sendSportTargets:(FwSportTargetModel*)sportTargetModel block:(FwSendMsgResult)block;

@end


#endif /* IWearCurDayActivitySync_h */
