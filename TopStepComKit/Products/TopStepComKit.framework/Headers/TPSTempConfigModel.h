//
//  TPSTempConfigModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/12/1.
//

#ifndef TPSTempConfigModel_h
#define TPSTempConfigModel_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FitCloudHTMSingleObject;
@class FitCloudHTMObject;

@interface TPSTempConfigModel : NSObject

/**
 * @brief Whether automatic temperature monitoring is enabled.
 * @chinese 是否开启体温自动监测
 *
 * @discussion
 * [EN]: Set to YES to enable automatic monitoring, NO to disable.
 * [CN]: 设置为 YES 开启自动监测，NO 关闭。
 */
@property (nonatomic, assign,getter = isEnable) BOOL enable;

/**
 * @brief Start time for automatic monitoring.
 * @chinese 自动监测开始时间
 *
 * @discussion
 * [EN]: Minutes from 00:00. e.g. 6:00 AM is 360 (6 * 60).
 * [CN]: 从0点开始的分钟偏移数。例如早上6点，就是360（6 * 60）。
 *
 * @note
 * [EN]: Value range should be within 0-1440.
 * [CN]: 值范围应在 0-1440 之间。
 */
@property (nonatomic, assign) NSInteger startTime;

/**
 * @brief End time for automatic monitoring.
 * @chinese 自动监测结束时间
 *
 * @discussion
 * [EN]: Minutes from 00:00. e.g. 8:00 PM is 1200 (20 * 60).
 * [CN]: 从0点开始的分钟偏移数。例如晚上8点，就是1200（20 * 60）。
 *
 * @note
 * [EN]: Value range should be within 0-1440.
 * [CN]: 值范围应在 0-1440 之间。
 */
@property (nonatomic, assign) NSInteger endTime;

/**
 * @brief Measurement interval.
 * @chinese 测量时间间隔
 *
 * @discussion
 * [EN]: The interval between automatic measurements in minutes.
 * [CN]: 自动测量的间隔时间，单位为分钟。
 */
@property (nonatomic, assign) NSInteger interval;

/**
 * @brief Initialize with FitCloudHTMSingleObject
 * @chinese 使用 FitCloudHTMSingleObject 初始化
 *
 * @param model FitCloudHTMSingleObject
 * @return TPSTempConfigModel instance
 */
- (instancetype)initWithFitCloudModel:(FitCloudHTMSingleObject *)model;

/**
 * @brief Convert to FitCloudHTMSingleObject
 * @chinese 转换为 FitCloudHTMSingleObject
 *
 * @return FitCloudHTMSingleObject instance
 */
- (FitCloudHTMSingleObject *)toFitCloudModel;

/**
 * @brief Initialize with FitCloudHTMObject
 * @chinese 使用 FitCloudHTMObject 初始化
 *
 * @param model FitCloudHTMObject
 * @return TPSTempConfigModel instance
 */
- (instancetype)initWithFitCloudHTMModel:(FitCloudHTMObject *)model;

/**
 * @brief Convert to FitCloudHTMObject
 * @chinese 转换为 FitCloudHTMObject
 *
 * @return FitCloudHTMObject instance
 */
- (FitCloudHTMObject *)toFitCloudHTMModel;

@end

NS_ASSUME_NONNULL_END

#endif /* TPSTempConfigModel_h */

