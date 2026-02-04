//
//  TPSFutureDayWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef TPSFutureDayWeatherModel_h
#define TPSFutureDayWeatherModel_h

#import <TopStepComKit/TPSWeatherDescribeType.h>

@class FwFutureDayWeatherModel;

/**
 * @brief Future day weather forecast model
 * @chinese 未来某天天气预报模型
 *
 * @discussion
 * [EN]: This model contains weather information for a specific day in the future,
 * including timestamp, weather description, and temperature range (min/max).
 * [CN]: 此模型包含未来特定某天的天气信息，包括时间戳、天气描述和温度范围（最低/最高）。
 */
@interface TPSFutureDayWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

/**
 * @brief Timestamp for the weather forecast
 * @chinese 天气预报的时间戳
 *
 * @discussion
 * [EN]: Unix timestamp indicating which specific day this weather forecast is for.
 * [CN]: Unix时间戳，表示此天气预报对应的具体日期。
 *
 * @note
 * [EN]: Used to identify the exact date for the weather forecast.
 * [CN]: 用于标识天气预报的确切日期。
 */
@property (nonatomic, assign) long timestamp;

/**
 * @brief Weather description category
 * @chinese 天气描述类别
 *
 * @discussion
 * [EN]: Main weather category such as sunny, cloudy, rainy, etc.
 * [CN]: 主要天气类别，如晴天、多云、雨天等。
 *
 * @note
 * [EN]: Provides a general overview of the weather conditions for the day.
 * [CN]: 提供当天天气状况的总体概述。
 */
@property (nonatomic, assign) TPSWeatherLargeCategory describe;

/**
 * @brief Weather sub-type
 * @chinese 天气子类型
 *
 * @discussion
 * [EN]: Detailed weather sub-type for more specific weather description.
 * [CN]: 详细的天气子类型，用于更具体的天气描述。
 *
 * @note
 * [EN]: Offers more granular weather information beyond the main category.
 * [CN]: 提供比主要类别更细粒度的天气信息。
 */
@property (nonatomic, assign) TPSWeatherSubType subType;

/**
 * @brief Minimum temperature for the day
 * @chinese 当天最低温度
 *
 * @discussion
 * [EN]: Lowest expected temperature for the specific day in Celsius.
 * [CN]: 特定一天的最低预期温度，单位为摄氏度。
 *
 * @note
 * [EN]: Usually occurs during early morning or night hours.
 * [CN]: 通常出现在清晨或夜间时段。
 */
@property (nonatomic, assign) int minTemperature;

/**
 * @brief Maximum temperature for the day
 * @chinese 当天最高温度
 *
 * @discussion
 * [EN]: Highest expected temperature for the specific day in Celsius.
 * [CN]: 特定一天的最高预期温度，单位为摄氏度。
 *
 * @note
 * [EN]: Usually occurs during afternoon hours.
 * [CN]: 通常出现在下午时段。
 */
@property (nonatomic, assign) int maxTemperature;

/**
 * @brief Initialize with weather parameters
 * @chinese 使用天气参数初始化
 *
 * @param timestamp Timestamp for the weather forecast
 * @chinese 天气预报的时间戳
 * @param describe Weather description category
 * @chinese 天气描述类别
 * @param minTemperature Minimum temperature in Celsius
 * @chinese 最低温度，单位为摄氏度
 * @param maxTemperature Maximum temperature in Celsius
 * @chinese 最高温度，单位为摄氏度
 *
 * @return Initialized TPSFutureDayWeatherModel instance
 * @chinese 初始化后的TPSFutureDayWeatherModel实例
 */
-(instancetype)initWithTimestamp:(long)timestamp 
                         describe:(TPSWeatherLargeCategory)describe 
                    minTemperature:(int)minTemperature 
                    maxTemperature:(int)maxTemperature;


@end

#endif /* TPSFutureDayWeatherModel_h */
