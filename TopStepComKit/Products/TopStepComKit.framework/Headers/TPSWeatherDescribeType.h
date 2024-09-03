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


//+(NSString*)getDesWithType:(TPSWeatherDescribeType_ENUM)type;

+(NSString*)getLargeCategoryDes:(TPSWeatherLargeCategory)type;
+(NSString*)getSubTypeDes:(TPSWeatherSubType)subType;
+(TPSWeatherLargeCategory)getLargeCategoryWithSubType:(TPSWeatherSubType)subType;



@end


#endif /* TPSWeatherDescribeType_h */
