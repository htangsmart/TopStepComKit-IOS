//
//  TPSWorldClockModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef TPSWorldClockModel_h
#define TPSWorldClockModel_h


/**
 * @brief World Clock Model for TopStep Wearable Devices
 * @chinese 拓步穿戴设备世界时钟模型
 *
 * @discussion
 * [EN]: This model represents a world clock entry with city name, timezone and UTC offset information.
 * [CN]: 该模型表示一个世界时钟条目，包含城市名称、时区和UTC偏移量信息。
 */
@interface TPSWorldClockModel : NSObject

/**
 * @brief Unique identifier for the clock entry
 * @chinese 时钟条目的唯一标识符
 *
 * @discussion
 * [EN]: A unique ID assigned to each world clock entry, value range is 0-255
 * [CN]: 分配给每个世界时钟条目的唯一ID，取值范围为0-255
 *
 * @note
 * [EN]: The ID is a random number between 0 and 255
 * [CN]: ID是一个0到255之间的随机数
 */
@property (nonatomic, assign) UInt8 clockId;

/**
 * @brief Name of the city for the world clock
 * @chinese 世界时钟对应的城市名称
 *
 * @discussion
 * [EN]: The name of the city this world clock represents
 * [CN]: 该世界时钟所代表的城市名称
 */
@property (nonatomic, copy) NSString *cityName;

/**
 * @brief IANA time zone identifier for the world clock
 * @chinese 世界时钟的IANA时区标识符
 *
 * @discussion
 * [EN]: The IANA time zone identifier (e.g., "Asia/Shanghai", "America/New_York")
 * [CN]: IANA时区标识符（例如："Asia/Shanghai", "America/New_York"）
 */
@property (nonatomic, copy) NSString *timeZoneIdentifier;

/**
 * @brief UTC offset in minutes
 * @chinese UTC偏移量（分钟）
 *
 * @discussion
 * [EN]: The UTC offset in minutes for this time zone, range is -720 to +720
 * [CN]: 该时区的UTC偏移量（以分钟为单位），范围为-720到+720
 *
 * @note
 * [EN]: Positive values indicate time zones ahead of UTC (e.g., +480 for UTC+8),
 *       negative values indicate time zones behind UTC (e.g., -300 for UTC-5)
 * [CN]: 正值表示比UTC快（例如：+480表示UTC+8），
 *       负值表示比UTC慢（例如：-300表示UTC-5）
 */
@property (nonatomic, assign) NSInteger utcOffsetInMinutes;

/**
 * @brief Create a new world clock model instance
 * @chinese 创建一个新的世界时钟模型实例
 *
 * @param clockId The unique identifier for the clock entry (0-255)
 * @param cityName The name of the city
 * @param timeZoneIdentifier The IANA time zone identifier
 * @param utcOffsetInMinutes The UTC offset in minutes (-720 to +720)
 *
 * @return A new TPSWorldClockModel instance
 */
+ (instancetype)modelWithClockId:(UInt8)clockId
                       cityName:(NSString *)cityName
              timeZoneIdentifier:(NSString *)timeZoneIdentifier
                utcOffsetInMinutes:(NSInteger)utcOffsetInMinutes;

@end



#endif /* FwWorldClockModel_h */
