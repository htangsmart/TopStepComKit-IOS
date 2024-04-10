//
//  TPSWeatherDescribeType.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/3.
//

#ifndef TPSWeatherDescribeType_h
#define TPSWeatherDescribeType_h

@interface TPSWeatherDescribeType : NSObject

typedef NS_ENUM(UInt8,TPSWeatherDescribeType_ENUM){
    
    TPSWeatherDescribeType_ENUM_UNKNOWN = 0,  //
    TPSWeatherDescribeType_ENUM_CLEAR_DAY,
    TPSWeatherDescribeType_ENUM_PARTLY_CLOUDY_DAY,
    TPSWeatherDescribeType_ENUM_CLOUDY,
    
    TPSWeatherDescribeType_ENUM_RAIN_SHOWER,
    TPSWeatherDescribeType_ENUM_THUNDER_SHOWER,
    TPSWeatherDescribeType_ENUM_LIGHT_RAIN,
    TPSWeatherDescribeType_ENUM_HEAVY_RAIN,

    TPSWeatherDescribeType_ENUM_SLEET,

    TPSWeatherDescribeType_ENUM_LIGHT_SNOW,
    TPSWeatherDescribeType_ENUM_HEAVY_SNOW,
    TPSWeatherDescribeType_ENUM_DUST,
    TPSWeatherDescribeType_ENUM_FOG,
    TPSWeatherDescribeType_ENUM_WIND,
};

+(NSString*)getDesWithType:(TPSWeatherDescribeType_ENUM)type;




@end


#endif /* TPSWeatherDescribeType_h */
