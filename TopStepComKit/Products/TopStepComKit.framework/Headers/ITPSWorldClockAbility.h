//
//  ITPSWorldClockAbility.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef ITPSWorldClockAbility_h
#define ITPSWorldClockAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSWorldClockModel.h>

@protocol ITPSWorldClockAbility <NSObject,ITPSWearBaseAbility>

+(instancetype)share;

-(void)sendCurZoneClock:(TPSWorldClockModel*)worldClockModel block:(TPSSendMsgResult)block;
-(void)sendAllZoneClock:(NSArray<TPSWorldClockModel*>*)list block:(TPSSendMsgResult)block;

@end


#endif /* IFwWorldClockAbility_h */
