//
//  TPSWeatherDescribeType.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/3.
//

#ifndef TPSWeatherDescribeType_h
#define TPSWeatherDescribeType_h

@interface TPSWeatherDescribeType : NSObject

typedef NS_ENUM(UInt8,TPSWeatherLargeCategory){
    TPSWeatherLargeCategory_UNKNOWN = 0,//未知
    TPSWeatherLargeCategory_CLEAR = 1,//晴
    TPSWeatherLargeCategory_CLOUDY = 2,//多云
    TPSWeatherLargeCategory_OVERCAST= 3,//阴
    TPSWeatherLargeCategory_RAIN_SHOWER= 4,//阵雨
    TPSWeatherLargeCategory_THUNDER_SHOWER= 5,//雷阵雨
    TPSWeatherLargeCategory_RAIN= 6,//小雨
    TPSWeatherLargeCategory_HEAVY_RAIN= 7,//中雨、大雨
    TPSWeatherLargeCategory_HAIL_SLEET= 8,// 雨夹雪 冰雹，冰晶，霰
    TPSWeatherLargeCategory_SNOW= 9,//小雪
    TPSWeatherLargeCategory_HEAVY_SNOW= 10,//中雪、大雪、暴雪
    TPSWeatherLargeCategory_SANDSTORM= 11,//沙尘暴
    TPSWeatherLargeCategory_HAZE= 12,//雾霾
    TPSWeatherLargeCategory_WIND= 13,//风

};

/**
 * @brief Weather sub-type enumeration based on weather API codes
 * @chinese 基于气象API代码的天气子类型枚举
 * 
 * @discussion
 * [EN]: This enumeration includes both daytime (starting from 1000) and nighttime (starting from 113) weather types
 * [CN]: 此枚举包含白天（从1000开始）和夜间（从113开始）的天气类型
 */
typedef NS_ENUM(NSInteger, TPSWeatherSubType) {
    // ========== 白天部分 (1000开始) ==========
    
    // 晴天类 (1000-1009)
    TPSWeatherSubType_SUNNY = 1000,                    // 晴天/晴朗
    TPSWeatherSubType_PARTLY_CLOUDY = 1003,            // 局部多云
    TPSWeatherSubType_CLOUDY = 1006,                   // 多云
    TPSWeatherSubType_OVERCAST = 1009,                 // 阴天
    
    // 阵雨类 (1240-1249)
    TPSWeatherSubType_LIGHT_RAIN_SHOWER = 1240,        // 小阵雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_RAIN_SHOWER = 1243, // 中到大阵雨
    TPSWeatherSubType_TORRENTIAL_RAIN_SHOWER = 1246,   // 暴雨阵雨
    TPSWeatherSubType_LIGHT_SLEET_SHOWERS = 1249,      // 小雨夹雪阵雨
    
    // 雷暴类 (1087, 1273-1282)
    TPSWeatherSubType_THUNDERY_OUTBREAKS_POSSIBLE = 1087, // 可能有雷暴
    TPSWeatherSubType_PATCHY_LIGHT_RAIN_WITH_THUNDER = 1273, // 局部小雷阵雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_RAIN_WITH_THUNDER = 1276, // 中到大雷阵雨
    TPSWeatherSubType_PATCHY_LIGHT_SNOW_WITH_THUNDER = 1279, // 局部小雷阵雪
    TPSWeatherSubType_MODERATE_OR_HEAVY_SNOW_WITH_THUNDER = 1282, // 中到大雷阵雪
    
    // 雨类 (1063, 1150-1198)
    TPSWeatherSubType_PATCHY_RAIN_POSSIBLE = 1063,     // 局部可能有雨
    TPSWeatherSubType_PATCHY_LIGHT_DRIZZLE = 1150,     // 局部轻毛毛雨
    TPSWeatherSubType_LIGHT_DRIZZLE = 1153,            // 轻毛毛雨
    TPSWeatherSubType_PATCHY_LIGHT_RAIN = 1180,        // 局部小雨
    TPSWeatherSubType_LIGHT_RAIN = 1183,               // 小雨
    TPSWeatherSubType_MODERATE_RAIN_AT_TIMES = 1186,   // 间歇性中雨
    TPSWeatherSubType_MODERATE_RAIN = 1189,            // 中雨
    TPSWeatherSubType_HEAVY_RAIN_AT_TIMES = 1192,      // 间歇性大雨
    TPSWeatherSubType_HEAVY_RAIN = 1195,               // 大雨
    
    // 雨夹雪和冻雨类 (1069, 1198-1207, 1237)
    TPSWeatherSubType_PATCHY_SLEET_POSSIBLE = 1069,    // 局部可能有雨夹雪
    TPSWeatherSubType_LIGHT_FREEZING_RAIN = 1198,      // 小冻雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_FREEZING_RAIN = 1201, // 中到大冻雨
    TPSWeatherSubType_LIGHT_SLEET = 1204,              // 小雨夹雪
    TPSWeatherSubType_MODERATE_OR_HEAVY_SLEET = 1207,  // 中到大雨夹雪
    TPSWeatherSubType_ICE_PELLETS = 1237,              // 冰粒
    
    // 冻毛毛雨类 (1072, 1168-1171, 1252, 1261-1264)
    TPSWeatherSubType_PATCHY_FREEZING_DRIZZLE_POSSIBLE = 1072, // 局部可能有冻毛毛雨
    TPSWeatherSubType_FREEZING_DRIZZLE = 1168,         // 冻毛毛雨
    TPSWeatherSubType_HEAVY_FREEZING_DRIZZLE = 1171,   // 强冻毛毛雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_SLEET_SHOWERS = 1252, // 中到大雨夹雪阵雨
    TPSWeatherSubType_LIGHT_SHOWERS_OF_ICE_PELLETS = 1261, // 小冰粒阵雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_SHOWERS_OF_ICE_PELLETS = 1264, // 中到大冰粒阵雨
    
    // 雪类 (1066, 1210-1225, 1255, 1258, 1114, 1117)
    TPSWeatherSubType_PATCHY_SNOW_POSSIBLE = 1066,     // 局部可能下雪
    TPSWeatherSubType_PATCHY_LIGHT_SNOW = 1210,        // 局部小雪
    TPSWeatherSubType_LIGHT_SNOW = 1213,               // 小雪
    TPSWeatherSubType_PATCHY_MODERATE_SNOW = 1216,     // 局部中雪
    TPSWeatherSubType_MODERATE_SNOW = 1219,            // 中雪
    TPSWeatherSubType_LIGHT_SNOW_SHOWERS = 1255,       // 小雪阵雨
    TPSWeatherSubType_BLOWING_SNOW = 1114,             // 飘雪
    TPSWeatherSubType_BLIZZARD = 1117,                 // 暴风雪
    TPSWeatherSubType_PATCHY_HEAVY_SNOW = 1222,        // 局部大雪
    TPSWeatherSubType_HEAVY_SNOW = 1225,               // 大雪
    TPSWeatherSubType_MODERATE_OR_HEAVY_SNOW_SHOWERS = 1258, // 中到大雪阵雨
    
    // 雾类 (1135, 1030, 1147)
    TPSWeatherSubType_FOG = 1135,                      // 雾
    TPSWeatherSubType_MIST = 1030,                     // 薄雾
    TPSWeatherSubType_FREEZING_FOG = 1147,             // 冻雾
    
    // ========== 夜间部分 (113开始) ==========
    
    // 夜间晴天类 (113-122)
    TPSWeatherSubType_CLEAR_NIGHT = 113,               // 夜间晴天/晴朗
    TPSWeatherSubType_PARTLY_CLOUDY_NIGHT = 116,       // 夜间局部多云
    TPSWeatherSubType_CLOUDY_NIGHT = 119,              // 夜间多云
    TPSWeatherSubType_OVERCAST_NIGHT = 122,            // 夜间阴天
    
    // 夜间阵雨类 (353-359)
    TPSWeatherSubType_LIGHT_RAIN_SHOWER_NIGHT = 353,   // 夜间小阵雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_RAIN_SHOWER_NIGHT = 356, // 夜间中到大阵雨
    TPSWeatherSubType_TORRENTIAL_RAIN_SHOWER_NIGHT = 359, // 夜间暴雨阵雨
    
    // 夜间雷暴类 (200, 386-395)
    TPSWeatherSubType_THUNDERY_OUTBREAKS_POSSIBLE_NIGHT = 200, // 夜间可能有雷暴
    TPSWeatherSubType_PATCHY_LIGHT_RAIN_WITH_THUNDER_NIGHT = 386, // 夜间局部小雷阵雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_RAIN_WITH_THUNDER_NIGHT = 389, // 夜间中到大雷阵雨
    TPSWeatherSubType_PATCHY_LIGHT_SNOW_WITH_THUNDER_NIGHT = 392, // 夜间局部小雷阵雪
    TPSWeatherSubType_MODERATE_OR_HEAVY_SNOW_WITH_THUNDER_NIGHT = 395, // 夜间中到大雷阵雪
    
    // 夜间雨类 (176, 263-308)
    TPSWeatherSubType_PATCHY_RAIN_POSSIBLE_NIGHT = 176, // 夜间局部可能有雨
    TPSWeatherSubType_PATCHY_LIGHT_DRIZZLE_NIGHT = 263, // 夜间局部轻毛毛雨
    TPSWeatherSubType_LIGHT_DRIZZLE_NIGHT = 266,       // 夜间轻毛毛雨
    TPSWeatherSubType_PATCHY_LIGHT_RAIN_NIGHT = 293,   // 夜间局部小雨
    TPSWeatherSubType_LIGHT_RAIN_NIGHT = 296,          // 夜间小雨
    TPSWeatherSubType_MODERATE_RAIN_AT_TIMES_NIGHT = 299, // 夜间间歇性中雨
    TPSWeatherSubType_MODERATE_RAIN_NIGHT = 302,       // 夜间中雨
    TPSWeatherSubType_HEAVY_RAIN_AT_TIMES_NIGHT = 305, // 夜间间歇性大雨
    TPSWeatherSubType_HEAVY_RAIN_NIGHT = 308,          // 夜间大雨
    
    // 夜间雨夹雪和冻雨类 (182, 311-350)
    TPSWeatherSubType_PATCHY_SLEET_POSSIBLE_NIGHT = 182, // 夜间局部可能有雨夹雪
    TPSWeatherSubType_LIGHT_FREEZING_RAIN_NIGHT = 311, // 夜间小冻雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_FREEZING_RAIN_NIGHT = 314, // 夜间中到大冻雨
    TPSWeatherSubType_LIGHT_SLEET_NIGHT = 317,         // 夜间小雨夹雪
    TPSWeatherSubType_MODERATE_OR_HEAVY_SLEET_NIGHT = 320, // 夜间中到大雨夹雪
    TPSWeatherSubType_ICE_PELLETS_NIGHT = 350,         // 夜间冰粒
    
    // 夜间冻毛毛雨类 (185, 281-377)
    TPSWeatherSubType_PATCHY_FREEZING_DRIZZLE_POSSIBLE_NIGHT = 185, // 夜间局部可能有冻毛毛雨
    TPSWeatherSubType_FREEZING_DRIZZLE_NIGHT = 281,   // 夜间冻毛毛雨
    TPSWeatherSubType_HEAVY_FREEZING_DRIZZLE_NIGHT = 284, // 夜间强冻毛毛雨
    TPSWeatherSubType_LIGHT_SLEET_SHOWERS_NIGHT = 362, // 夜间小雨夹雪阵雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_SLEET_SHOWERS_NIGHT = 365, // 夜间中到大雨夹雪阵雨
    TPSWeatherSubType_LIGHT_SHOWERS_OF_ICE_PELLETS_NIGHT = 374, // 夜间小冰粒阵雨
    TPSWeatherSubType_MODERATE_OR_HEAVY_SHOWERS_OF_ICE_PELLETS_NIGHT = 377, // 夜间中到大冰粒阵雨
    
    // 夜间雪类 (179, 323-371)
    TPSWeatherSubType_PATCHY_SNOW_POSSIBLE_NIGHT = 179, // 夜间局部可能下雪
    TPSWeatherSubType_PATCHY_LIGHT_SNOW_NIGHT = 323,   // 夜间局部小雪
    TPSWeatherSubType_LIGHT_SNOW_NIGHT = 326,          // 夜间小雪
    TPSWeatherSubType_PATCHY_MODERATE_SNOW_NIGHT = 329, // 夜间局部中雪
    TPSWeatherSubType_MODERATE_SNOW_NIGHT = 332,       // 夜间中雪
    TPSWeatherSubType_LIGHT_SNOW_SHOWERS_NIGHT = 368,  // 夜间小雪阵雨
    TPSWeatherSubType_BLOWING_SNOW_NIGHT = 227,        // 夜间飘雪
    TPSWeatherSubType_BLIZZARD_NIGHT = 230,            // 夜间暴风雪
    TPSWeatherSubType_PATCHY_HEAVY_SNOW_NIGHT = 335,   // 夜间局部大雪
    TPSWeatherSubType_HEAVY_SNOW_NIGHT = 338,          // 夜间大雪
    TPSWeatherSubType_MODERATE_OR_HEAVY_SNOW_SHOWERS_NIGHT = 371, // 夜间中到大雪阵雨
    
    // 夜间雾类 (248, 143, 260)
    TPSWeatherSubType_FOG_NIGHT = 248,                 // 夜间雾
    TPSWeatherSubType_MIST_NIGHT = 143,                // 夜间薄雾
    TPSWeatherSubType_FREEZING_FOG_NIGHT = 260,        // 夜间冻雾
    
    // 未知类型
    TPSWeatherSubType_UNKNOWN = 0                     // 未知天气类型
};

/**
 * @brief Get large weather category from weather sub-type
 * @chinese 根据天气子类型获取大类别天气
 * 
 * @param subType 
 * EN: Weather sub-type to be converted
 * CN: 需要转换的天气子类型
 * 
 * @return 
 * EN: Converted large weather category
 * CN: 转换后的大类别天气
 */
+ (TPSWeatherLargeCategory)getLargeCategoryWithSubType:(TPSWeatherSubType)subType;

/**
 * @brief Convert weather sub-type to byte value for device communication
 * @chinese 将天气子类型转换为设备通信用的字节值
 * 
 * @param subType 
 * EN: Weather sub-type to be converted
 * CN: 需要转换的天气子类型
 * 
 * @return 
 * EN: Byte value for device communication
 * CN: 用于设备通信的字节值
 */
+ (Byte)weatherTypeWithSubType:(TPSWeatherSubType)subType;

@end

#endif /* TPSWeatherDescribeType_h */
