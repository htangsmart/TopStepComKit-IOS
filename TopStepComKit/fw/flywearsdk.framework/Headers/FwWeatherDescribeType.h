//
//  FwWeatherDescribeType.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/3.
//

#ifndef FwWeatherDescribeType_h
#define FwWeatherDescribeType_h

@interface FwWeatherDescribeType : NSObject

/*
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

typedef NS_ENUM(UInt8,FwWeatherDescribeType_ENUM){
    
    FwWeatherDescribeType_ENUM_UNKNOWN = 0,  //
    FwWeatherDescribeType_ENUM_CLEAR_DAY,
    FwWeatherDescribeType_ENUM_PARTLY_CLOUDY_DAY,
    FwWeatherDescribeType_ENUM_CLOUDY,
    
    FwWeatherDescribeType_ENUM_RAIN_SHOWER,
    FwWeatherDescribeType_ENUM_THUNDER_SHOWER,
    FwWeatherDescribeType_ENUM_LIGHT_RAIN,
    FwWeatherDescribeType_ENUM_HEAVY_RAIN,

    FwWeatherDescribeType_ENUM_SLEET,

    FwWeatherDescribeType_ENUM_LIGHT_SNOW,
    FwWeatherDescribeType_ENUM_HEAVY_SNOW,
    FwWeatherDescribeType_ENUM_DUST,
    FwWeatherDescribeType_ENUM_FOG,
    FwWeatherDescribeType_ENUM_WIND,    
};












+(NSString*)getDesWithType:(FwWeatherDescribeType_ENUM)type;






@end


#endif /* FwWeatherDescribeType_h */
