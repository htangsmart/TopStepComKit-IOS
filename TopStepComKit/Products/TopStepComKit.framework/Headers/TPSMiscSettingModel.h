//
//  MiscSettingModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/26.
//

#ifndef TPSMiscSettingModel_h
#define TPSMiscSettingModel_h


@interface TPSMiscSettingModel : NSObject

typedef NS_ENUM(UInt8, TPSMiscSettingModel_State){
    TPSMiscSettingModel_State_Close = 0,
    TPSMiscSettingModel_State_Open,
};

typedef NS_ENUM(UInt8, TPSMiscSettingModel_Time_Format){
    TPSMiscSettingModel_Time_Format_12 = 12,
    TPSMiscSettingModel_Time_Format_24 = 24,
};

typedef NS_ENUM(UInt8, TPSMiscSettingModel_Temperature_Unit){
    TPSMiscSettingModel_Temperature_Unit_C = 0,
    TPSMiscSettingModel_Temperature_Unit_F = 1,
};

typedef NS_ENUM(UInt8, TPSMiscSettingModel_System_Unit){
    MiscSettingModel_TSTPS_Sport_Unit_British_System = 0,
    MiscSettingModel_TSTPS_Sport_Unit_Metric_System = 1,
};

typedef NS_ENUM(UInt8, TPSMiscSettingModel_Wear_Hand){
    TPSMiscSettingModel_Wear_Hand_Left = 0,
    TPSMiscSettingModel_Wear_Hand_Right = 1,
};

@property(nonatomic,assign) TPSMiscSettingModel_State target_drink_warn;
@property(nonatomic,assign) TPSMiscSettingModel_State target_sit_warn;
@property(nonatomic,assign) TPSMiscSettingModel_State ht_health_enhanced;
@property(nonatomic,assign) TPSMiscSettingModel_State ht_sleep_allDay;
@property(nonatomic,assign) TPSMiscSettingModel_Time_Format system_timing_method;
@property(nonatomic,assign) TPSMiscSettingModel_Temperature_Unit weather_temp_unit;
@property(nonatomic,assign) TPSMiscSettingModel_System_Unit sport_sportUnit;
@property(nonatomic,assign) TPSMiscSettingModel_Wear_Hand habit_wear_hand;
@property(nonatomic,assign) TPSMiscSettingModel_State screen_raise_to_wake;
@property(nonatomic,assign) TPSMiscSettingModel_State weather_sync_mode;
@property(nonatomic,assign) TPSMiscSettingModel_State bloodoxygen_auto_mode;
@property(nonatomic,assign) TPSMiscSettingModel_State heartrate_auto_mode;
@property(nonatomic,assign) NSDictionary * heartrate_config;



@end





#endif /* MiscSettingModel_h */


//NSArray* keys = @[
//    @"target.drink_warn",
//    @"target.sit_warn",
//    @"ht.health.enhanced",
//    @"ht.sleep.allDay",
//    @"system.timing_method",
//    @"weather.temp_unit",
//    @"sport.sportUnit",
//    @"habit.wear_hand",
//    @"screen.raise_to_wake",
//    @"weather.sync_mode",
//    @"bloodoxygen.auto_mode",
//    @"heartrate.auto_mode"
//];
