//
//  IFwWorldClockAbility.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef IFwWorldClockAbility_h
#define IFwWorldClockAbility_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwWorldClockModel.h>

@protocol IFwWorldClockAbility <NSObject,IFwWearBaseAbility>

+(instancetype)share;

-(void)sendCurZoneClock:(FwWorldClockModel*)worldClockModel block:(FwSendMsgResult)block;
-(void)sendAllZoneClock:(NSArray<FwWorldClockModel*>*)list block:(FwSendMsgResult)block;

@end


#endif /* IFwWorldClockAbility_h */
