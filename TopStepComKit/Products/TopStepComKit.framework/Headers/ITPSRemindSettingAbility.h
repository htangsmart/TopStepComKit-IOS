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


@protocol ITPSRemindSettingAbility <ITPSWearBaseAbility>

+(instancetype _Nonnull )share;

- (void)resetRemindIndex:(NSArray *_Nullable)indexArray success:(TPSSendMsgResult _Nullable )success;

// 查询提醒
- (void)requestRemindSettingDataFormWatchSuccess:(TPSRemindSettingCallback _Nullable)success;

/// 设置提醒
- (void)setRemindValueWithValue:(NSDictionary *_Nonnull)valueDict index:(NSArray *_Nullable)indexArray success:(TPSSendMsgResult _Nullable)success;


@end

NS_ASSUME_NONNULL_END
