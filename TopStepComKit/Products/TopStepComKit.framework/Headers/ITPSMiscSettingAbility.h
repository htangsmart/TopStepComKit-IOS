//
//  IWearMiscSettingSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//

#ifndef ITPSMiscSettingAbility_h
#define ITPSMiscSettingAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSMiscSettingModel.h>

@protocol ITPSMiscSettingAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSMiscSettingCallback)(TPSMiscSettingModel* miscSettingModel);

+(instancetype)share;
/*
 * @brief 获取所有设置项数据
 */
-(void)getAllMiscSetting:(TPSMiscSettingCallback)block;
/*
 * @brief
 */
-(void)sendTarget_drink_warn:(TPSMiscSettingModel_State)target_drink_warn;
/*
 * @brief 运动单位
 */
-(void)sendTarget_sit_warn:(TPSMiscSettingModel_State)target_sit_warn;
/*
 * @brief 加强检测（对不同皮肤进行调整）
 */
-(void)sendHt_health_enhanced:(TPSMiscSettingModel_State)ht_health_enhanced;
/*
 * @brief(此功能手表端不受控，应该去掉，此功能由手表端根据项目决定，不留给手机进行设置，fitcloud也无)
 */
-(void)sendHt_sleep_allDay:(TPSMiscSettingModel_State)ht_sleep_allDay;
/*
 * @brief 时间格式
 */
-(void)sendSystem_timing_method:(TPSMiscSettingModel_Time_Format)system_timing_method;
/*
 * @brief 天气单位
 */
-(void)sendWeather_temp_unit:(TPSMiscSettingModel_Temperature_Unit)weather_temp_unit;

/*
 * @brief 运动单位
 */
-(void)sendSport_sportUnit:(TPSMiscSettingModel_System_Unit)sport_sportUnit;
/*
 * @brief 左右手
 */
-(void)sendHabit_wear_hand:(TPSMiscSettingModel_Wear_Hand)habit_wear_hand;
/*
 * @brief 抬腕亮屏
 */
-(void)sendScreen_raise_to_wake:(TPSMiscSettingModel_State)screen_raise_to_wake;
/*
 * @brief 天气开关
 */
-(void)sendWeather_sync_mode:(TPSMiscSettingModel_State)weather_sync_mode;
/*
 * @brief 运动单位
 */
-(void)sendBloodoxygen_auto_mode:(TPSMiscSettingModel_State)bloodoxygen_auto_mode;

-(void)sendHeartrate_auto_mode:(TPSMiscSettingModel_State)heartrate_auto_mode;

-(void)sendUserNickName:(NSString*)nickName;
/*
 * @brief 紧急联系
 */
-(void)sendHt_sos:(TPSMiscSettingModel_State)ht_sos;

- (void)sendHeartRateValue:(NSDictionary *)value complete:(void(^)(BOOL isSendOK))complete;

-(void)sendDataToDevice:(NSDictionary*)dic complete:(void(^)(BOOL isSendOK))complete;

@end


#endif /* IWearDevInfoSync_h */
