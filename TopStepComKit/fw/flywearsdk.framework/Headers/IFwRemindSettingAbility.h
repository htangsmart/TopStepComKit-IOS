//
//  IFwRemindSettingAbility.h
//  flywearsdk
//
//  Created by 磐石 on 2024/3/7.
//

#import <Foundation/Foundation.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwRemindSettingModel.h>
#import <flywearsdk/WearBlockTypeDef.h>

@protocol IFwRemindSettingAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwRemindSettingCallback)(NSArray<FwRemindSettingModel*>* _Nullable remindSettingList);

+(instancetype _Nonnull )share;

- (void)resetRemindIndex:(NSArray * _Nonnull)indexArray success:(FwSendMsgResult _Nullable)success;

- (void)requestRemindSettingDataFormWatchSuccess:(FwRemindSettingCallback _Nullable )success;

- (void)setRemindValueWithValue:(NSDictionary *_Nonnull)valueDict index:(NSArray *_Nullable)indexArray success:(FwSendMsgResult _Nullable)block;


@end
