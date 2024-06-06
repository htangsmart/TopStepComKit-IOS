//
//  MiscSettingModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/26.
//

#ifndef MiscSettingModel_h
#define MiscSettingModel_h

@interface FwMiscSettingModel : NSObject

typedef NS_ENUM(UInt8, FwMiscSettingModel_State){
    FwMiscSettingModel_State_Close = 0,
    FwMiscSettingModel_State_Open,
};

typedef NS_ENUM(UInt8, FwMiscSettingModel_Time_Format){
    FwMiscSettingModel_Time_Format_12 = 12,
    FwMiscSettingModel_Time_Format_24 = 24,
};

typedef NS_ENUM(UInt8, FwMiscSettingModel_Temperature_Unit){
    FwMiscSettingModel_Temperature_Unit_C = 0,
    FwMiscSettingModel_Temperature_Unit_F = 1,
};

typedef NS_ENUM(UInt8, FwMiscSettingModel_System_Unit){
    MiscSettingModel_TSFW_Sport_Unit_British_System = 0,
    MiscSettingModel_TSFW_Sport_Unit_Metric_System = 1,
};

typedef NS_ENUM(UInt8, FwMiscSettingModel_Wear_Hand){
    FwMiscSettingModel_Wear_Hand_Left = 0,
    FwMiscSettingModel_Wear_Hand_Right = 1,
};

@property(nonatomic,assign) FwMiscSettingModel_State target_drink_warn;
@property(nonatomic,assign) FwMiscSettingModel_State target_sit_warn;
@property(nonatomic,assign) FwMiscSettingModel_State ht_health_enhanced;
@property(nonatomic,assign) FwMiscSettingModel_State ht_sleep_allDay;
@property(nonatomic,assign) FwMiscSettingModel_Time_Format system_timing_method;
@property(nonatomic,assign) FwMiscSettingModel_Temperature_Unit weather_temp_unit;
@property(nonatomic,assign) FwMiscSettingModel_System_Unit sport_sportUnit;
@property(nonatomic,assign) FwMiscSettingModel_Wear_Hand habit_wear_hand;
@property(nonatomic,assign) FwMiscSettingModel_State screen_raise_to_wake;
@property(nonatomic,assign) FwMiscSettingModel_State weather_sync_mode;
@property(nonatomic,assign) FwMiscSettingModel_State bloodoxygen_auto_mode;
@property(nonatomic,assign) FwMiscSettingModel_State heartrate_auto_mode;

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
