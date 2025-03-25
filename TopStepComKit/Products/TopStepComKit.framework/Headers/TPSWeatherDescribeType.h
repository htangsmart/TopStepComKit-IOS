//
//  TPSWeatherDescribeType.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/3.
//

#ifndef TPSWeatherDescribeType_h
#define TPSWeatherDescribeType_h

@interface TPSWeatherDescribeType : NSObject

//20240818后不再采用这个定义
//typedef NS_ENUM(UInt8,TPSWeatherDescribeType_ENUM){
//    
//    TPSWeatherDescribeType_ENUM_UNKNOWN = 0,  //
//    TPSWeatherDescribeType_ENUM_CLEAR_DAY,
//    TPSWeatherDescribeType_ENUM_PARTLY_CLOUDY_DAY,
//    TPSWeatherDescribeType_ENUM_CLOUDY,
//    
//    TPSWeatherDescribeType_ENUM_RAIN_SHOWER,
//    TPSWeatherDescribeType_ENUM_THUNDER_SHOWER,
//    TPSWeatherDescribeType_ENUM_LIGHT_RAIN,
//    TPSWeatherDescribeType_ENUM_HEAVY_RAIN,
//
//    TPSWeatherDescribeType_ENUM_SLEET,
//
//    TPSWeatherDescribeType_ENUM_LIGHT_SNOW,
//    TPSWeatherDescribeType_ENUM_HEAVY_SNOW,
//    TPSWeatherDescribeType_ENUM_DUST,
//    TPSWeatherDescribeType_ENUM_FOG,
//    TPSWeatherDescribeType_ENUM_WIND,
//};

//以下的定义是20240819之后修改的
//这里将天气的的类型分为大类和小类，此处是大类的定义
typedef NS_ENUM(UInt8,TPSWeatherLargeCategory){
    TPSWeatherLargeCategory_UNKNOWN,//未知
    TPSWeatherLargeCategory_CLEAR,//晴
    TPSWeatherLargeCategory_CLOUDY,//多云
    TPSWeatherLargeCategory_OVERCAST,//阴
    TPSWeatherLargeCategory_RAIN,//雨
    TPSWeatherLargeCategory_HEAVY_RAIN,//大雨
    TPSWeatherLargeCategory_RAIN_SHOWER,//阵雨
    TPSWeatherLargeCategory_SNOW,//雪
    TPSWeatherLargeCategory_HEAVY_SNOW,//大雪
    TPSWeatherLargeCategory_SNOW_SHOWER,//阵雪
    TPSWeatherLargeCategory_HAZE,//雾霾
    TPSWeatherLargeCategory_SAND_DUST,//沙尘，浮尘
    TPSWeatherLargeCategory_SMOKE_FOG,//烟，雾
    TPSWeatherLargeCategory_WIND,//风
    TPSWeatherLargeCategory_HAIL_SLEET,//冰雹，冰晶，霰
    TPSWeatherLargeCategory_FREEZING_RAIN,//冻雨,雨夹雪,雨夹冰雹
    TPSWeatherLargeCategory_THUNDER_SHOWER,//雷阵雨
};

typedef NS_ENUM(UInt8,TPSWeatherSubType){
    TPSWeatherSubType_UNKNOWN,
    TPSWeatherSubType_TORNADO,
    TPSWeatherSubType_TROPICAL_STORM,
    TPSWeatherSubType_HURRICANE,
    TPSWeatherSubType_STORM_WIND,
    TPSWeatherSubType_THUNDER_SHOWER,
    TPSWeatherSubType_RAIN_AND_SNOW,
    TPSWeatherSubType_RAIN_AND_HAIL,
    TPSWeatherSubType_RAIN_MIXED_SNOW,
    TPSWeatherSubType_FREEZING_DRIZZLE,
    TPSWeatherSubType_DRIZZLE,
    TPSWeatherSubType_FREEZING_RAIN,
    TPSWeatherSubType_RAIN_SHOWER,
    TPSWeatherSubType_RAIN,
    TPSWeatherSubType_LIGHT_SNOW,
    TPSWeatherSubType_SNOW_SHOWER,
    TPSWeatherSubType_DRIFTING_SNOW,
    TPSWeatherSubType_SNOW,
    TPSWeatherSubType_HAIL,
    TPSWeatherSubType_SLEET,
    TPSWeatherSubType_SAND_STORM,
    TPSWeatherSubType_FOG,
    TPSWeatherSubType_HAZE,
    TPSWeatherSubType_SMOKE,
    TPSWeatherSubType_BREEZY,
    TPSWeatherSubType_WIND,
    TPSWeatherSubType_ICE_CRYSTALS,
    TPSWeatherSubType_OVERCAST_DAY,
    TPSWeatherSubType_CLOUDY_NIGHT,
    TPSWeatherSubType_CLOUDY_DAY,
    TPSWeatherSubType_PARTLY_CLOUDY_NIGHT,
    TPSWeatherSubType_PARTLY_CLOUDY_DAY,
    TPSWeatherSubType_CLEAR_NIGHT,
    TPSWeatherSubType_CLEAR_DAY,
    TPSWeatherSubType_FEW_CLOUDY_NIGHT,
    TPSWeatherSubType_FEW_CLOUDY_DAY,
    TPSWeatherSubType_RAIN_MIXED_HAIL,
    TPSWeatherSubType_HOT,
    TPSWeatherSubType_PARTLY_THUNDER_SHOWER,
    TPSWeatherSubType_PARTLY_THUNDER_SHOWER_DAY,
    TPSWeatherSubType_PARTLY_RAIN_SHOWER_DAY,
    TPSWeatherSubType_HEAVY_RAIN,
    TPSWeatherSubType_PARTLY_SNOW_SHOWER_DAY,
    TPSWeatherSubType_HEAVY_SNOW,
    TPSWeatherSubType_STORM_SNOW,
    TPSWeatherSubType_PARTLY_RAIN_SHOWER_NIGHT,
    TPSWeatherSubType_PARTLY_SNOW_SHOWER_NIGHT,
    TPSWeatherSubType_PARTLY_THUNDER_SHOWER_NIGHT,
    TPSWeatherSubType_OVERCAST_NIGHT,
    TPSWeatherSubType_COLD,
    TPSWeatherSubType_LIGHT_RAIN,
    TPSWeatherSubType_MODERATE_RAIN,
    TPSWeatherSubType_STORM_RAIN,
    TPSWeatherSubType_MODERATE_SNOW,
    TPSWeatherSubType_LIGHT_HAZE,
    TPSWeatherSubType_MODERATE_HAZE,
    TPSWeatherSubType_HEAVY_HAZE,
    TPSWeatherSubType_SAND,
    TPSWeatherSubType_DUST,
};

//typedef NS_ENUM(UInt8,TPSWeatherSubType){
//    // 未知天气
//    TPSWeatherSubType_UNKNOWN = 0,                     // 未知
//
//    // 极端天气
//    TPSWeatherSubType_TORNADO = 1,                     // 龙卷风
//    TPSWeatherSubType_TROPICAL_STORM = 2,              // 热带风暴
//    TPSWeatherSubType_HURRICANE = 3,                   // 飓风
//    TPSWeatherSubType_STORM_WIND = 4,                  // 风暴风
//
//    // 降水
//    TPSWeatherSubType_THUNDER_SHOWER = 5,              // 雷阵雨
//    TPSWeatherSubType_RAIN_AND_SNOW = 6,               // 雨雪
//    TPSWeatherSubType_RAIN_AND_HAIL = 7,               // 雨夹冰雹
//    TPSWeatherSubType_RAIN_MIXED_SNOW = 8,             // 雨夹雪
//    TPSWeatherSubType_FREEZING_DRIZZLE = 9,            // 冻毛毛雨
//    TPSWeatherSubType_DRIZZLE = 10,                     // 毛毛雨
//    TPSWeatherSubType_FREEZING_RAIN = 11,               // 冻雨
//    TPSWeatherSubType_RAIN_SHOWER = 12,                 // 阵雨
//    TPSWeatherSubType_RAIN = 13,                        // 雨
//    TPSWeatherSubType_LIGHT_RAIN = 50,                  // 小雨
//    TPSWeatherSubType_MODERATE_RAIN = 51,               // 中雨
//    TPSWeatherSubType_STORM_RAIN = 52,                  // 暴雨
//    TPSWeatherSubType_HEAVY_RAIN = 41,                  // 大雨
//
//    // 雪
//    TPSWeatherSubType_LIGHT_SNOW = 14,                  // 小雪
//    TPSWeatherSubType_SNOW_SHOWER = 15,                 // 阵雪
//    TPSWeatherSubType_DRIFTING_SNOW = 16,               // 风吹雪
//    TPSWeatherSubType_SNOW = 17,                        // 雪
//    TPSWeatherSubType_HAIL = 18,                        // 冰雹
//    TPSWeatherSubType_SLEET = 19,                       // 雨夹雪
//    TPSWeatherSubType_HEAVY_SNOW = 43,                  // 大雪
//    TPSWeatherSubType_STORM_SNOW = 44,                  // 暴风雪
//
//    // 云层状况
//    TPSWeatherSubType_OVERCAST_DAY = 27,                // 阴天
//    TPSWeatherSubType_CLOUDY_NIGHT = 28,               // 多云夜
//    TPSWeatherSubType_CLOUDY_DAY = 29,                  // 多云天
//    TPSWeatherSubType_PARTLY_CLOUDY_NIGHT = 30,        // 夜间局部多云
//    TPSWeatherSubType_PARTLY_CLOUDY_DAY = 31,          // 白天局部多云
//    TPSWeatherSubType_FEW_CLOUDY_NIGHT = 34,           // 夜间少云
//    TPSWeatherSubType_FEW_CLOUDY_DAY = 35,             // 白天少云
//    TPSWeatherSubType_PARTLY_THUNDER_SHOWER = 38,      // 局部雷阵雨
//    TPSWeatherSubType_PARTLY_THUNDER_SHOWER_DAY = 39,  // 白天局部雷阵雨
//    TPSWeatherSubType_PARTLY_RAIN_SHOWER_DAY = 40,     // 白天局部阵雨
//    TPSWeatherSubType_PARTLY_SNOW_SHOWER_DAY = 42,     // 白天局部阵雪
//
//    // 能见度
//    TPSWeatherSubType_SAND_STORM = 20,                  // 沙尘暴
//    TPSWeatherSubType_FOG = 21,                         // 雾
//    TPSWeatherSubType_HAZE = 22,                        // 霾
//    TPSWeatherSubType_SMOKE = 23,                       // 烟雾
//
//    // 温度
//    TPSWeatherSubType_BREEZY = 24,                      // 微风
//    TPSWeatherSubType_WIND = 25,                        // 风
//    TPSWeatherSubType_COLD = 49,                        // 寒冷
//    TPSWeatherSubType_HOT = 37,                         // 热
//
//    // 其他
//    TPSWeatherSubType_ICE_CRYSTALS = 26,                // 冰晶
//    TPSWeatherSubType_CLEAR_NIGHT = 32,                 // 晴天夜
//    TPSWeatherSubType_CLEAR_DAY = 33,                   // 晴天
//    TPSWeatherSubType_RAIN_MIXED_HAIL = 36,             // 雨夹冰雹
//    TPSWeatherSubType_PARTLY_RAIN_SHOWER_NIGHT = 45,   // 夜间局部阵雨
//    TPSWeatherSubType_PARTLY_SNOW_SHOWER_NIGHT = 46,   // 夜间局部阵雪
//    TPSWeatherSubType_PARTLY_THUNDER_SHOWER_NIGHT = 47, // 夜间局部雷阵雨
//    TPSWeatherSubType_OVERCAST_NIGHT = 48,              // 夜间阴天
//    TPSWeatherSubType_LIGHT_HAZE = 54,                  // 轻度霾
//    TPSWeatherSubType_MODERATE_HAZE = 55,               // 中度霾
//    TPSWeatherSubType_HEAVY_HAZE = 56,                  // 重度霾
//    TPSWeatherSubType_SAND = 57,                        // 沙
//    TPSWeatherSubType_DUST = 58,                        // 尘土
//};



//+(NSString*)getDesWithType:(TPSWeatherDescribeType_ENUM)type;

+(NSString*)getLargeCategoryDes:(TPSWeatherLargeCategory)type;
+(NSString*)getSubTypeDes:(TPSWeatherSubType)subType;
+(TPSWeatherLargeCategory)getLargeCategoryWithSubType:(TPSWeatherSubType)subType;


+ (Byte)weatherTypeWithSubType:(TPSWeatherSubType)subType;


@end


#endif /* TPSWeatherDescribeType_h */
