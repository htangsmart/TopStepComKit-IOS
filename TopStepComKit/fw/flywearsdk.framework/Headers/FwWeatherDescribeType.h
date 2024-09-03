//
//  FwWeatherDescribeType.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/3.
//

#ifndef FwWeatherDescribeType_h
#define FwWeatherDescribeType_h

@interface FwWeatherDescribeType : NSObject

/*以下是20240819之前的定义，后来不用这个定义了，做了修改
 // 天气图片格式
 // 晴天：weather_CLEAR_DAY_32bit.png
 // 部分阴天：weather_PARTLY_CLOUDY_DAY_32bit.png
 // 阴天（多云）：weather_CLOUDY_32bit.png
 // 灰尘：weather_DUST_32bit.png
 // 沙暴：weather_SAND_STORM_32bit.png
 // 雾：weather_FOG_32bit.png
 // 雾霾：weather_HAZE_32bit.png
 // 小雨：weather_LIGHT_RAIN_32bit.png
 // 中雨：weather_MODERATE_RAIN_32bit.png
 // 大雨：weather_HEAVY_RAIN_32bit.png
 // 小雪：weather_LIGHT_SNOW_32bit.png
 // 中雪：weather_MODERATE_SNOW_32bit.png
 // 大雪：weather_HEAVY_SNOW_32bit.png
 // 阵雨：weather_RAIN_SHOWER_32bit.png
 // 雨夹雪：weather_SLEET_32bit.png
 // 雷阵雨：weather_THUNDER_SHOWER_32bit.png
 // 未知天气：weather_unknown_32bit.png
 
 */

//typedef NS_ENUM(UInt8,FwWeatherDescribeType_ENUM){
//
//    FwWeatherDescribeType_ENUM_UNKNOWN = 0,  //
//    FwWeatherDescribeType_ENUM_CLEAR_DAY,
//    FwWeatherDescribeType_ENUM_PARTLY_CLOUDY_DAY,
//    FwWeatherDescribeType_ENUM_CLOUDY,
//
//    FwWeatherDescribeType_ENUM_RAIN_SHOWER,
//    FwWeatherDescribeType_ENUM_THUNDER_SHOWER,
//    FwWeatherDescribeType_ENUM_LIGHT_RAIN,
//    FwWeatherDescribeType_ENUM_HEAVY_RAIN,
//
//    FwWeatherDescribeType_ENUM_SLEET,
//
//    FwWeatherDescribeType_ENUM_LIGHT_SNOW,
//    FwWeatherDescribeType_ENUM_HEAVY_SNOW,
//    FwWeatherDescribeType_ENUM_DUST,
//    FwWeatherDescribeType_ENUM_FOG,
//    FwWeatherDescribeType_ENUM_WIND,
//};


//以下的定义是20240819之后修改的
//这里将天气的的类型分为大类和小类，此处是大类的定义
typedef NS_ENUM(UInt8,FwWeatherLargeCategory){
    FwWeatherLargeCategory_UNKNOWN,//未知
    FwWeatherLargeCategory_CLEAR,//晴
    FwWeatherLargeCategory_CLOUDY,//多云
    FwWeatherLargeCategory_OVERCAST,//阴
    FwWeatherLargeCategory_RAIN,//雨
    FwWeatherLargeCategory_HEAVY_RAIN,//大雨
    FwWeatherLargeCategory_RAIN_SHOWER,//阵雨
    FwWeatherLargeCategory_SNOW,//雪
    FwWeatherLargeCategory_HEAVY_SNOW,//大雪
    FwWeatherLargeCategory_SNOW_SHOWER,//阵雪
    FwWeatherLargeCategory_HAZE,//雾霾
    FwWeatherLargeCategory_SAND_DUST,//沙尘，浮尘
    FwWeatherLargeCategory_SMOKE_FOG,//烟，雾
    FwWeatherLargeCategory_WIND,//风
    FwWeatherLargeCategory_HAIL_SLEET,//冰雹，冰晶，霰
    FwWeatherLargeCategory_FREEZING_RAIN,//冻雨,雨夹雪,雨夹冰雹
    FwWeatherLargeCategory_THUNDER_SHOWER,//雷阵雨
};

typedef NS_ENUM(UInt8,FwWeatherSubType){
    FwWeatherSubType_UNKNOWN,
    FwWeatherSubType_TORNADO,
    FwWeatherSubType_TROPICAL_STORM,
    FwWeatherSubType_HURRICANE,
    FwWeatherSubType_STORM_WIND,
    FwWeatherSubType_THUNDER_SHOWER,
    FwWeatherSubType_RAIN_AND_SNOW,
    FwWeatherSubType_RAIN_AND_HAIL,
    FwWeatherSubType_RAIN_MIXED_SNOW,
    FwWeatherSubType_FREEZING_DRIZZLE,
    FwWeatherSubType_DRIZZLE,
    FwWeatherSubType_FREEZING_RAIN,
    FwWeatherSubType_RAIN_SHOWER,
    FwWeatherSubType_RAIN,
    FwWeatherSubType_LIGHT_SNOW,
    FwWeatherSubType_SNOW_SHOWER,
    FwWeatherSubType_DRIFTING_SNOW,
    FwWeatherSubType_SNOW,
    FwWeatherSubType_HAIL,
    FwWeatherSubType_SLEET,
    FwWeatherSubType_SAND_STORM,
    FwWeatherSubType_FOG,
    FwWeatherSubType_HAZE,
    FwWeatherSubType_SMOKE,
    FwWeatherSubType_BREEZY,
    FwWeatherSubType_WIND,
    FwWeatherSubType_ICE_CRYSTALS,
    FwWeatherSubType_OVERCAST_DAY,
    FwWeatherSubType_CLOUDY_NIGHT,
    FwWeatherSubType_CLOUDY_DAY,
    FwWeatherSubType_PARTLY_CLOUDY_NIGHT,
    FwWeatherSubType_PARTLY_CLOUDY_DAY,
    FwWeatherSubType_CLEAR_NIGHT,
    FwWeatherSubType_CLEAR_DAY,
    FwWeatherSubType_FEW_CLOUDY_NIGHT,
    FwWeatherSubType_FEW_CLOUDY_DAY,
    FwWeatherSubType_RAIN_MIXED_HAIL,
    FwWeatherSubType_HOT,
    FwWeatherSubType_PARTLY_THUNDER_SHOWER,
    FwWeatherSubType_PARTLY_THUNDER_SHOWER_DAY,
    FwWeatherSubType_PARTLY_RAIN_SHOWER_DAY,
    FwWeatherSubType_HEAVY_RAIN,
    FwWeatherSubType_PARTLY_SNOW_SHOWER_DAY,
    FwWeatherSubType_HEAVY_SNOW,
    FwWeatherSubType_STORM_SNOW,
    FwWeatherSubType_PARTLY_RAIN_SHOWER_NIGHT,
    FwWeatherSubType_PARTLY_SNOW_SHOWER_NIGHT,
    FwWeatherSubType_PARTLY_THUNDER_SHOWER_NIGHT,
    FwWeatherSubType_OVERCAST_NIGHT,
    FwWeatherSubType_COLD,
    FwWeatherSubType_LIGHT_RAIN,
    FwWeatherSubType_MODERATE_RAIN,
    FwWeatherSubType_STORM_RAIN,
    FwWeatherSubType_MODERATE_SNOW,
    FwWeatherSubType_LIGHT_HAZE,
    FwWeatherSubType_MODERATE_HAZE,
    FwWeatherSubType_HEAVY_HAZE,
    FwWeatherSubType_SAND,
    FwWeatherSubType_DUST,
};
    
//+(NSString*)getDesWithType:(FwWeatherDescribeType_ENUM)type;
+(NSString*)getLargeCategoryDes:(FwWeatherLargeCategory)type;
+(NSString*)getSubTypeDes:(FwWeatherSubType)subType;
+(FwWeatherLargeCategory)getLargeCategoryWithSubType:(FwWeatherSubType)subType;

@end


#endif /* FwWeatherDescribeType_h */
