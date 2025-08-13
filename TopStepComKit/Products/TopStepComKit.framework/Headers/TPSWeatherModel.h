//
//  TPSWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef TPSWeatherModel_h
#define TPSWeatherModel_h

#import <TopStepComKit/TPSWeatherDescribeType.h>
#import <TopStepComKit/TPSMiscSettingModel.h>
#import <TopStepComKit/TPSFutureDayWeatherModel.h>
#import <TopStepComKit/TPSFutureHourWeatherModel.h>
#import <TopStepComKit/TPSTodayWeatherModel.h>

@class FwWeatherModel;

/**
 * @brief Comprehensive weather information model
 * @chinese 综合天气信息模型
 *
 * @discussion
 * [EN]: This model contains complete weather information for a specific city,
 * including city name, temperature unit, update time, today's weather,
 * and future weather forecasts for multiple days.
 * [CN]: 此模型包含特定城市的完整天气信息，包括城市名称、温度单位、
 * 更新时间、今日天气和未来多天的天气预报。
 */
@interface TPSWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

/**
 * @brief City name
 * @chinese 城市名称
 *
 * @discussion
 * [EN]: Name of the city for which weather information is provided.
 * [CN]: 提供天气信息的城市名称。
 *
 * @note
 * [EN]: Usually in the local language of the city.
 * [CN]: 通常使用城市的当地语言。
 */
@property (nonatomic, strong) NSString* city;

/**
 * @brief Temperature unit setting
 * @chinese 温度单位设置
 *
 * @discussion
 * [EN]: Temperature unit preference (Celsius or Fahrenheit).
 * [CN]: 温度单位偏好设置（摄氏度或华氏度）。
 *
 * @note
 * [EN]: Affects how temperature values are displayed and interpreted.
 * [CN]: 影响温度值的显示和解释方式。
 */
@property (nonatomic, assign) TPSMiscSettingModel_Temperature_Unit temperatureUnit;

/**
 * @brief Weather data update timestamp
 * @chinese 天气数据更新时间戳
 *
 * @discussion
 * [EN]: Unix timestamp indicating when the weather data was last updated.
 * [CN]: Unix时间戳，表示天气数据最后更新的时间。
 *
 * @note
 * [EN]: Used to determine if weather data is current and valid.
 * [CN]: 用于判断天气数据是否最新和有效。
 */
@property (nonatomic, assign) long updateTime;

/**
 * @brief Today's weather information
 * @chinese 今日天气信息
 *
 * @discussion
 * [EN]: Detailed weather information for the current day,
 * including temperature, humidity, wind, UV index, air quality and more.
 * [CN]: 当天的详细天气信息，包括温度、湿度、风力、
 * 紫外线指数、空气质量等。
 */
@property (nonatomic, strong) TPSTodayWeatherModel* todayWeather;

/**
 * @brief Future weather forecasts
 * @chinese 未来天气预报
 *
 * @discussion
 * [EN]: Array of weather forecasts for upcoming days,
 * typically covering the next 7 days.
 * [CN]: 未来几天的天气预报数组，通常覆盖未来7天。
 *
 * @note
 * [EN]: Each element contains weather information for a specific day.
 * [CN]: 每个元素包含特定一天的天气信息。
 */
@property (nonatomic, strong) NSArray<TPSFutureDayWeatherModel*>* futureDayWeather;

/**
 * @brief Initialize with weather parameters
 * @chinese 使用天气参数初始化
 *
 * @param city Name of the city
 * @chinese 城市名称
 * @param temperatureUnit Temperature unit preference
 * @chinese 温度单位偏好
 * @param updateTime Weather data update timestamp
 * @chinese 天气数据更新时间戳
 * @param todayWeather Today's weather information
 * @chinese 今日天气信息
 * @param futureDayWeather Future weather forecasts array
 * @chinese 未来天气预报数组
 *
 * @return Initialized TPSWeatherModel instance
 * @chinese 初始化后的TPSWeatherModel实例
 */
-(instancetype)initWithCity:(NSString*)city 
              temperatureUnit:(TPSMiscSettingModel_Temperature_Unit)temperatureUnit 
                   updateTime:(long)updateTime 
                 todayWeather:(TPSTodayWeatherModel*)todayWeather 
            futureDayWeather:(NSArray<TPSFutureDayWeatherModel*>*)futureDayWeather;




@end

#endif /* TPSWeatherModel_h */
