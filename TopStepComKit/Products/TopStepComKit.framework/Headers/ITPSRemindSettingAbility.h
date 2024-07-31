//
//  ITPSRemindSettingAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/25.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSRemindSettingModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^TPSRemindSettingCallback)(NSArray<TPSRemindSettingModel*>* _Nullable remindSettingList);
typedef void(^TPSNotDistrubModelCallback)(TPSRemindDistrubModel* _Nullable remindSetting);


@protocol ITPSRemindSettingAbility <ITPSWearBaseAbility>

+(instancetype _Nonnull )share;

- (void)resetRemindIndex:(NSArray *_Nullable)indexArray success:(TPSSendMsgResult _Nullable )success;

- (void)requestRemindSettingDataFormWatchSuccess:(TPSRemindSettingCallback _Nullable)success;

- (void)setRemindValueWithValue:(NSDictionary *_Nonnull)valueDict index:(NSArray *_Nullable)indexArray success:(TPSSendMsgResult _Nullable)success;

-(void)setNotDistrubConfig:(TPSRemindDistrubModel*)noDisturbeModel success:(TPSSendMsgResult _Nullable )success;

-(void)getNotDistrubConfig:(TPSNotDistrubModelCallback _Nullable)block;


@end

NS_ASSUME_NONNULL_END
