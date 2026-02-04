//
//  TPSFutureHourWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef TPSFutureHourWeatherModel_h
#define TPSFutureHourWeatherModel_h

#import <TopStepComKit/TPSWeatherDescribeType.h>

@class FwFutureHourWeatherModel;
@class FitCloudHourWeatherObject;

/**
 * @brief Future hour weather forecast model
 * @chinese 未来小时天气预报模型
 *
 * @discussion
 * [EN]: This model contains weather information for a specific hour in the future,
 * including temperature, wind, UV index, visibility, air quality and more.
 * [CN]: 此模型包含未来特定小时的天气信息，包括温度、风力、紫外线指数、能见度、空气质量等。
 */
@interface TPSFutureHourWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

/**
 * @brief Timestamp for the weather forecast
 * @chinese 天气预报的时间戳
 *
 * @discussion
 * [EN]: Unix timestamp indicating when this weather forecast is valid.
 * [CN]: Unix时间戳，表示此天气预报的有效时间。
 */
@property (nonatomic, assign) long timestamp;

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
 * @brief Temperature for the hour
 * @chinese 该小时的温度
 *
 * @discussion
 * [EN]: Temperature in Celsius for the specific hour.
 * [CN]: 特定小时的温度，单位为摄氏度。
 */
@property (nonatomic, assign) int temperature;

/**
 * @brief Wind scale
 * @chinese 风力等级
 *
 * @discussion
 * [EN]: Wind scale according to Beaufort scale (0-12).
 * [CN]: 根据蒲福风级的风力等级(0-12)。
 *
 * @note
 * [EN]: 0 is calm, 12 is hurricane.
 * [CN]: 0为无风，12为飓风。
 */
@property (nonatomic, assign) int windScale;

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
@property (nonatomic, assign) int uvIndex;

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
 * [CN]: 有效范围为0-500，其中0-50为优，51-100为良。
 */
@property (nonatomic, assign) int airQuality;

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
@property (nonatomic, assign) int visibility;

/**
 * @brief Initialize with basic weather parameters
 * @chinese 使用基本天气参数初始化
 *
 * @param timestamp Timestamp for the weather forecast
 * @chinese 天气预报的时间戳
 * @param describe Weather description category
 * @chinese 天气描述类别
 * @param temperature Temperature in Celsius
 * @chinese 温度，单位为摄氏度
 *
 * @return Initialized TPSFutureHourWeatherModel instance
 * @chinese 初始化后的TPSFutureHourWeatherModel实例
 */
-(instancetype)initWithTimestamp:(long)timestamp describe:(TPSWeatherLargeCategory)describe temperature:(int)temperature;

/**
 * @brief Convert FwFutureHourWeatherModel array to TPSFutureHourWeatherModel array
 * @chinese 将FwFutureHourWeatherModel数组转换为TPSFutureHourWeatherModel数组
 *
 * @param fwArr Array of FwFutureHourWeatherModel objects
 * @chinese FwFutureHourWeatherModel对象数组
 *
 * @return Array of converted TPSFutureHourWeatherModel objects
 * @chinese 转换后的TPSFutureHourWeatherModel对象数组
 */
+(NSArray<TPSFutureHourWeatherModel*>*)toTPSArrWithFwArr:(NSArray<FwFutureHourWeatherModel*>*)fwArr;


/**
 * @brief Convert to FitCloudHourWeatherObject
 * @chinese 转换为FitCloudHourWeatherObject
 *
 * @return Converted FitCloudHourWeatherObject instance
 * @chinese 转换后的FitCloudHourWeatherObject实例
 */
-(FitCloudHourWeatherObject*)toFitModel;

@end

#endif /* TPSFutureHourWeatherModel_h */
