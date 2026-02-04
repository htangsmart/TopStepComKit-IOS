//
//  TPSTodayWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef TPSTodayWeatherModel_h
#define TPSTodayWeatherModel_h

#import <TopStepComKit/TPSWeatherDescribeType.h>
#import <TopStepComKit/TPSFutureHourWeatherModel.h>

@class FwTodayWeatherModel;

/**
 * @brief Today's weather information model
 * @chinese 今日天气信息模型
 *
 * @discussion
 * [EN]: This model contains comprehensive weather information for the current day,
 * including temperature, humidity, wind, visibility, UV index, air quality and more.
 * [CN]: 此模型包含当天的综合天气信息，包括温度、湿度、风力、能见度、紫外线指数、空气质量等。
 */
@interface TPSTodayWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

/**
 * @brief Weather description category
 * @chinese 天气描述类别
 *
 * @discussion
 * [EN]: Main weather category such as sunny, cloudy, rainy, etc.
 * [CN]: 主要天气类别，如晴天、多云、雨天等。
 */
@property (nonatomic, assign) TPSWeatherLargeCategory describe;

/**
 * @brief Weather sub-type
 * @chinese 天气子类型
 *
 * @discussion
 * [EN]: Detailed weather sub-type for more specific weather description.
 * [CN]: 详细的天气子类型，用于更具体的天气描述。
 */
@property (nonatomic, assign) TPSWeatherSubType subType;

/**
 * @brief Current temperature
 * @chinese 当前温度
 *
 * @discussion
 * [EN]: Current temperature in Celsius.
 * [CN]: 当前温度，单位为摄氏度。
 */
@property (nonatomic, assign) int curTemperature;

/**
 * @brief Minimum temperature
 * @chinese 最低温度
 *
 * @discussion
 * [EN]: Minimum temperature for the day in Celsius.
 * [CN]: 当天最低温度，单位为摄氏度。
 */
@property (nonatomic, assign) int minTemperature;

/**
 * @brief Maximum temperature
 * @chinese 最高温度
 *
 * @discussion
 * [EN]: Maximum temperature for the day in Celsius.
 * [CN]: 当天最高温度，单位为摄氏度。
 */
@property (nonatomic, assign) int maxTemperature;

/**
 * @brief Air pressure
 * @chinese 气压
 *
 * @discussion
 * [EN]: Atmospheric pressure in hectopascals (hPa).
 * [CN]: 大气压力，单位为百帕(hPa)。
 */
@property (nonatomic, assign) int airpressure;

/**
 * @brief Wind direction
 * @chinese 风向
 *
 * @discussion
 * [EN]: Wind direction in degrees (0-360).
 * [CN]: 风向，单位为度(0-360)。
 */
@property (nonatomic, assign) int wind;

/**
 * @brief Wind angle
 * @chinese 风向角度
 *
 * @discussion
 * [EN]: Wind angle in degrees for more precise wind direction.
 * [CN]: 风向角度，单位为度，用于更精确的风向描述。
 */
@property (nonatomic, assign) int windAngle;

/**
 * @brief Wind speed
 * @chinese 风速
 *
 * @discussion
 * [EN]: Wind speed in meters per second (m/s).
 * [CN]: 风速，单位为米/秒(m/s)。
 */
@property (nonatomic, assign) int windSpeed;

/**
 * @brief Humidity
 * @chinese 湿度
 *
 * @discussion
 * [EN]: Relative humidity percentage (0-100).
 * [CN]: 相对湿度百分比(0-100)。
 */
@property (nonatomic, assign) int humidity;

/**
 * @brief UV index level
 * @chinese 紫外线指数等级
 *
 * @discussion
 * [EN]: UV index indicates the strength of ultraviolet radiation from the sun.
 * [CN]: 紫外线指数表示太阳紫外线辐射强度。
 *
 * @note
 * [EN]: Valid range is 0-11+, where 0-2 is low, 3-5 is moderate, 6-7 is high.
 * [CN]: 有效范围为0-11+，其中0-2为低，3-5为中等，6-7为高。
 */
@property(nonatomic, assign) NSInteger uvIndex;

/**
 * @brief Air quality index
 * @chinese 空气质量指数
 *
 * @discussion
 * [EN]: Air quality index (AQI) indicates the level of air pollution.
 * [CN]: 空气质量指数(AQI)表示空气污染程度。
 *
 * @note
 * [EN]: Valid range is 0-500, where 0-50 is excellent, 51-100 is good.
 * [CN]: 有效范围为0-400，其中0-50为优，51-100为良。
 */
@property(nonatomic, assign) NSInteger airQuality;

/**
 * @brief Visibility distance
 * @chinese 能见度距离
 *
 * @discussion
 * [EN]: Visibility distance in meters, maximum 30000 meters.
 * [CN]: 能见度距离，单位为米，最大30000米。
 *
 * @note
 * [EN]: Maximum value is 30000 meters.
 * [CN]: 最大值为30000米。
 */
@property (nonatomic, assign) CGFloat visibility;

/**
 * @brief Future hour weather forecast
 * @chinese 未来小时天气预报
 *
 * @discussion
 * [EN]: Array of weather forecasts for upcoming hours.
 * [CN]: 未来几小时的天气预报数组。
 */
@property (nonatomic, strong) NSArray<TPSFutureHourWeatherModel*>* futureHourWeather;

/**
 * @brief Initialize with weather parameters
 * @chinese 使用天气参数初始化
 *
 * @param curTemperature Current temperature in Celsius
 * @chinese 当前温度，单位为摄氏度
 * @param minTemperature Minimum temperature in Celsius
 * @chinese 最低温度，单位为摄氏度
 * @param maxTemperature Maximum temperature in Celsius
 * @chinese 最高温度，单位为摄氏度
 * @param airpressure Air pressure in hPa
 * @chinese 气压，单位为百帕
 * @param wind Wind direction in degrees
 * @chinese 风向，单位为度
 * @param windAngle Wind angle in degrees
 * @chinese 风向角度，单位为度
 * @param windSpeed Wind speed in m/s
 * @chinese 风速，单位为米/秒
 * @param humidity Humidity percentage
 * @chinese 湿度百分比
 * @param uvIndex UV index value
 * @chinese 紫外线指数值
 * @param airQuality Air quality index value
 * @chinese 空气质量指数值
 * @param visibility Visibility distance in meters
 * @chinese 能见度距离，单位为米
 * @param futureHourWeather Array of future hour weather models
 * @chinese 未来小时天气模型数组
 *
 * @return Initialized TPSTodayWeatherModel instance
 * @chinese 初始化后的TPSTodayWeatherModel实例
 */
-(instancetype)initWithCurTemperature:(int)curTemperature 
                       minTemperature:(int)minTemperature
                       maxTemperature:(int)maxTemperature 
                          airpressure:(int)airpressure
                                 wind:(int)wind
                            windAngle:(int)windAngle
                            windSpeed:(int)windSpeed
                             humidity:(int)humidity
                              uvIndex:(NSInteger)uvIndex
                           airQuality:(NSInteger)airQuality
                           visibility:(CGFloat)visibility
                       futureHourList:(NSArray<TPSFutureHourWeatherModel*>*)futureHourWeather;


@end

#endif /* TPSTodayWeatherModel_h */
