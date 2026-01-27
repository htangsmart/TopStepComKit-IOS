//
//  TPSPrayModel.h
//
//
//  Created by Topstep on 2024/3/18.
//

#ifndef TPSPrayModel_h
#define TPSPrayModel_h

@interface TPSPrayTimes : NSObject

/**
 * @brief Day timestamp for prayer times
 * @chinese 祈祷时间对应的日期时间戳
 *
 * @discussion
 * [EN]: Timestamp representing 00:00:00 of the day for which prayer times are set
 * [CN]: 表示当天0时0分0秒的时间戳，用于确定祈祷时间的日期
 */
@property (nonatomic,assign) NSTimeInterval dayTimestamp;

/**
 * @brief Fajr prayer time in minutes
 * @chinese 晨礼(Fajr)祈祷时间（分钟）
 *
 * @discussion
 * [EN]: Minutes offset from midnight (00:00) for the Fajr prayer (dawn prayer)
 * [CN]: 从当天零点(00:00)开始计算的晨礼(黎明祈祷)时间的分钟偏移量
 *
 * @note
 * [EN]: For example, 5:00 AM would be represented as 300 minutes
 * [CN]: 例如，早上5点表示为300分钟
 */
@property (nonatomic,assign) NSInteger fajrTime;

/**
 * @brief Dhuhr prayer time in minutes
 * @chinese 晌礼(Dhuhr)祈祷时间（分钟）
 *
 * @discussion
 * [EN]: Minutes offset from midnight (00:00) for the Dhuhr prayer (noon prayer)
 * [CN]: 从当天零点(00:00)开始计算的晌礼(正午祈祷)时间的分钟偏移量
 *
 * @note
 * [EN]: For example, 12:00 PM would be represented as 720 minutes
 * [CN]: 例如，中午12点表示为720分钟
 */
@property (nonatomic,assign) NSInteger dhuhrTime;

/**
 * @brief Asr prayer time in minutes
 * @chinese 晡礼(Asr)祈祷时间（分钟）
 *
 * @discussion
 * [EN]: Minutes offset from midnight (00:00) for the Asr prayer (afternoon prayer)
 * [CN]: 从当天零点(00:00)开始计算的晡礼(下午祈祷)时间的分钟偏移量
 *
 * @note
 * [EN]: For example, 3:30 PM would be represented as 930 minutes
 * [CN]: 例如，下午3点30分表示为930分钟
 */
@property (nonatomic,assign) NSInteger asrTime;

/**
 * @brief Maghrib prayer time in minutes
 * @chinese 昏礼(Maghrib)祈祷时间（分钟）
 *
 * @discussion
 * [EN]: Minutes offset from midnight (00:00) for the Maghrib prayer (sunset prayer)
 * [CN]: 从当天零点(00:00)开始计算的昏礼(日落祈祷)时间的分钟偏移量
 *
 * @note
 * [EN]: For example, 6:45 PM would be represented as 1005 minutes
 * [CN]: 例如，下午6点45分表示为1005分钟
 */
@property (nonatomic,assign) NSInteger maghribTime;

/**
 * @brief Isha prayer time in minutes
 * @chinese 宵礼(Isha)祈祷时间（分钟）
 *
 * @discussion
 * [EN]: Minutes offset from midnight (00:00) for the Isha prayer (night prayer)
 * [CN]: 从当天零点(00:00)开始计算的宵礼(夜间祈祷)时间的分钟偏移量
 *
 * @note
 * [EN]: For example, 8:15 PM would be represented as 1215 minutes
 * [CN]: 例如，晚上8点15分表示为1215分钟
 */
@property (nonatomic,assign) NSInteger ishabTime;

@end

#endif /* FwWorldClockModel_h */
