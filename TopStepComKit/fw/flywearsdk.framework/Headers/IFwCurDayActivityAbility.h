//
//  IWearCurDayActivitySync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef IWearCurDayActivitySync_h
#define IWearCurDayActivitySync_h

#import <flywearsdk/FwCurDayActivityModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>

@protocol IFwCurDayActivityAbility <NSObject,IFwWearBaseAbility>

typedef void(^IFwCurDayActivityCallback)(FwCurDayActivityModel* curDayActivityModel);

+(instancetype)share;

-(void)getCurDayAcitity:(IFwCurDayActivityCallback)block;

@end


#endif /* IWearCurDayActivitySync_h */
