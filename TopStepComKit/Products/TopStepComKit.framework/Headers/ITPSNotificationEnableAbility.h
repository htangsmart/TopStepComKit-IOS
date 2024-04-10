//
//  IWearNotificationEnableSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/11.
//

#ifndef ITPSNotificationEnableAbility_h
#define ITPSNotificationEnableAbility_h

#import <TopStepComKit/TPSNotificationEnableModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

@protocol ITPSNotificationEnableAbility <NSObject, ITPSWearBaseAbility>

typedef void(^TPSNotificationEnableListCallback)(NSArray<TPSNotificationEnableModel*>* list);

+(instancetype)share;

-(void)getNotificationEnableList:(TPSNotificationEnableListCallback)block;
-(void)sendNotificationEnableList:(NSArray<TPSNotificationEnableModel*>*)list block:(TPSSendMsgResult)block;
-(TPSNotification_Type)getTypeByName:(NSString*)name;


@end


#endif /* IWearNotificationEnableSync_h */
