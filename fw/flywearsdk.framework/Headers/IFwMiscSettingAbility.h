//
//  IWearMiscSettingSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//

#ifndef IWearMiscSettingSync_h
#define IWearMiscSettingSync_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwMiscSettingModel.h>

@protocol IFwMiscSettingAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwMiscSettingCallback)(FwMiscSettingModel* miscSettingModel);

+(instancetype)share;

-(void)getAllMiscSetting:(FwMiscSettingCallback)block;

-(void)sendTarget_drink_warn:(FwMiscSettingModel_State)target_drink_warn;

-(void)sendTarget_sit_warn:(FwMiscSettingModel_State)target_sit_warn;

-(void)sendHt_health_enhanced:(FwMiscSettingModel_State)ht_health_enhanced;

-(void)sendHt_sleep_allDay:(FwMiscSettingModel_State)ht_sleep_allDay;

-(void)sendSystem_timing_method:(FwMiscSettingModel_Time_Format)system_timing_method;

-(void)sendWeather_temp_unit:(FwMiscSettingModel_Temperature_Unit)weather_temp_unit;

-(void)sendSport_sportUnit:(FwMiscSettingModel_System_Unit)sport_sportUnit;

-(void)sendHabit_wear_hand:(FwMiscSettingModel_Wear_Hand)habit_wear_hand;

-(void)sendScreen_raise_to_wake:(FwMiscSettingModel_State)screen_raise_to_wake;

-(void)sendWeather_sync_mode:(FwMiscSettingModel_State)weather_sync_mode;

-(void)sendBloodoxygen_auto_mode:(FwMiscSettingModel_State)bloodoxygen_auto_mode;

-(void)sendHeartrate_auto_mode:(FwMiscSettingModel_State)heartrate_auto_mode;

-(void)sendUserNickName:(NSString*)nickName;

-(void)sendHt_sos:(FwMiscSettingModel_State)ht_sos;

- (void)sendHeartRateValue:(NSDictionary *)value complete:(void(^)(BOOL isSendOK))complete;

-(void)sendDataToDevice:(NSDictionary*)dic complete:(void(^)(BOOL isSendOK))complete;

@end


#endif /* IWearDevInfoSync_h */
