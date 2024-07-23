//
//  IWearNotificationEnableSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/11.
//

#ifndef IWearNotificationEnableSync_h
#define IWearNotificationEnableSync_h

#import <flywearsdk/FwNotificationEnableModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>

@protocol IFwNotificationEnableAbility <NSObject, IFwWearBaseAbility>

typedef void(^FwNotificationEnableListCallback)(NSMutableArray<FwNotificationEnableModel*>* list);

+(instancetype)share;

-(void)getNotificationEnableList:(FwNotificationEnableListCallback)block;
-(void)sendNotificationEnableList:(NSMutableArray<FwNotificationEnableModel*>*)list block:(FwSendMsgResult)block;
-(FwNotification_Type)getTypeByName:(NSString*)name;


@end


#endif /* IWearNotificationEnableSync_h */
