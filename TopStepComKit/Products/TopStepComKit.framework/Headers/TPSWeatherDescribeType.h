//
//  TPSWeatherDescribeType.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/3.
//

#ifndef TPSWeatherDescribeType_h
#define TPSWeatherDescribeType_h

@interface TPSWeatherDescribeType : NSObject

//以下的定义是20240819之后修改的
//这里将天气的的类型分为大类和小类，此处是大类的定义
typedef NS_ENUM(UInt8,TPSWeatherLargeCategory){
    TPSWeatherLargeCategory_UNKNOWN,//未知
    TPSWeatherLargeCategory_CLEAR = 1,//晴
    TPSWeatherLargeCategory_CLOUDY = 2,//多云
    TPSWeatherLargeCategory_OVERCAST= 3,//阴
    TPSWeatherLargeCategory_RAIN= 4,//小雨
    TPSWeatherLargeCategory_HEAVY_RAIN= 5,//中雨
    TPSWeatherLargeCategory_RAIN_SHOWER= 6,//阵雨
    TPSWeatherLargeCategory_SNOW= 7,//小雪
    TPSWeatherLargeCategory_HEAVY_SNOW= 8,//中雪
    TPSWeatherLargeCategory_SNOW_SHOWER= 9,//阵雪
    TPSWeatherLargeCategory_HAZE= 10,//雾霾
    TPSWeatherLargeCategory_SAND_DUST= 11,//沙尘，浮尘
    TPSWeatherLargeCategory_SMOKE_FOG= 12,//烟，雾
    TPSWeatherLargeCategory_WIND= 13,//风
    TPSWeatherLargeCategory_HAIL_SLEET= 14,// 雨夹雪 冰雹，冰晶，霰
    TPSWeatherLargeCategory_FREEZING_RAIN= 15,//冻雨
    TPSWeatherLargeCategory_THUNDER_SHOWER= 16,//雷阵雨
};

typedef NS_ENUM(UInt8,TPSWeatherSubType){
    TPSWeatherSubType_UNKNOWN,              // 未知
    TPSWeatherSubType_TORNADO,              // 龙卷风
    TPSWeatherSubType_TROPICAL_STORM,       // 热带风暴
    TPSWeatherSubType_HURRICANE,            // 飓风
    TPSWeatherSubType_STORM_WIND,           // 风暴风
    TPSWeatherSubType_THUNDER_SHOWER,       // 雷阵雨
    TPSWeatherSubType_RAIN_AND_SNOW,        // 雨雪
    TPSWeatherSubType_RAIN_AND_HAIL,        // 雨夹冰雹
    TPSWeatherSubType_RAIN_MIXED_SNOW,      // 雨夹雪
    TPSWeatherSubType_FREEZING_DRIZZLE,     // 冻毛毛雨
    TPSWeatherSubType_DRIZZLE,              // 毛毛雨
    TPSWeatherSubType_FREEZING_RAIN,        // 冻雨
    TPSWeatherSubType_RAIN_SHOWER,          // 阵雨
    TPSWeatherSubType_RAIN,                 // 雨
    TPSWeatherSubType_LIGHT_SNOW,           // 小雪
    TPSWeatherSubType_SNOW_SHOWER,          // 阵雪
    TPSWeatherSubType_DRIFTING_SNOW,        // 风吹雪
    TPSWeatherSubType_SNOW,                 // 雪
    TPSWeatherSubType_HAIL,                 // 冰雹
    TPSWeatherSubType_SLEET,                // 雨夹雪
    TPSWeatherSubType_SAND_STORM,           // 沙尘暴
    TPSWeatherSubType_FOG,                  // 雾
    TPSWeatherSubType_HAZE,                 // 霾
    TPSWeatherSubType_SMOKE,                // 烟雾
    TPSWeatherSubType_BREEZY,               // 微风
    TPSWeatherSubType_WIND,                 // 风
    TPSWeatherSubType_ICE_CRYSTALS,         // 冰晶
    TPSWeatherSubType_OVERCAST_DAY,         // 阴天
    TPSWeatherSubType_CLOUDY,               // 多云
    TPSWeatherSubType_MOST_CLOUDY_NIGHT,    // 夜间大部分多云
    TPSWeatherSubType_MOST_CLOUDY_DAY,      // 日间大部分多云
    TPSWeatherSubType_PARTLY_CLOUDY_NIGHT,  // 夜间局部多云
    TPSWeatherSubType_PARTLY_CLOUDY_DAY,    // 白天局部多云
    TPSWeatherSubType_FEW_CLOUDY_NIGHT,     // 夜间少云
    TPSWeatherSubType_FEW_CLOUDY_DAY,       // 白天少云
    TPSWeatherSubType_CLEAR_NIGHT,          // 晴天夜
    TPSWeatherSubType_CLEAR_DAY,            // 晴天
    TPSWeatherSubType_RAIN_MIXED_HAIL,      // 雨加冰雹
    TPSWeatherSubType_HOT,                  // 炎热
    TPSWeatherSubType_PARTLY_THUNDER_SHOWER,// 局部雷阵雨
    TPSWeatherSubType_PARTLY_THUNDER_SHOWER_DAY, // 白天局部雷阵雨
    TPSWeatherSubType_PARTLY_RAIN_SHOWER_DAY,    // 白天局部阵雨
    TPSWeatherSubType_HEAVY_RAIN,           // 大雨
    TPSWeatherSubType_PARTLY_SNOW_SHOWER_DAY,    // 白天局部阵雪
    TPSWeatherSubType_HEAVY_SNOW,           // 大雪
    TPSWeatherSubType_STORM_SNOW,           // 暴风雪
    TPSWeatherSubType_PARTLY_RAIN_SHOWER_NIGHT,  // 夜间局部阵雨
    TPSWeatherSubType_PARTLY_SNOW_SHOWER_NIGHT,  // 夜间局部阵雪
    TPSWeatherSubType_PARTLY_THUNDER_SHOWER_NIGHT, // 夜间局部雷阵雨
    TPSWeatherSubType_OVERCAST_NIGHT,       // 夜间阴天
    TPSWeatherSubType_COLD,                 // 寒冷
    TPSWeatherSubType_LIGHT_RAIN,           // 小雨
    TPSWeatherSubType_MODERATE_RAIN,        // 中雨
    TPSWeatherSubType_STORM_RAIN,           // 暴雨
    TPSWeatherSubType_MODERATE_SNOW,        // 中雪
    TPSWeatherSubType_LIGHT_HAZE,           // 轻度霾
    TPSWeatherSubType_MODERATE_HAZE,        // 中度霾
    TPSWeatherSubType_HEAVY_HAZE,           // 重度霾
    TPSWeatherSubType_SAND,                 // 沙
    TPSWeatherSubType_DUST,                 // 尘土
};


+(NSString*)getLargeCategoryDes:(TPSWeatherLargeCategory)type;
+(NSString*)getSubTypeDes:(TPSWeatherSubType)subType;
+(TPSWeatherLargeCategory)getLargeCategoryWithSubType:(TPSWeatherSubType)subType;
+(TPSWeatherLargeCategory)getOraimoLargeCategoryWithSubType:(TPSWeatherSubType)subType;


+ (Byte)weatherTypeWithSubType:(TPSWeatherSubType)subType;


@end


#endif /* TPSWeatherDescribeType_h */
