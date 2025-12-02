//
//  TPSHistoryTempModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/12/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TPSHistoryTempModel : NSObject

/**
 * @brief Timestamp of the measurement.
 * @chinese 测量的时间戳
 */
@property (nonatomic, assign) long timestamp;

/**
 * @brief Wrist temperature.
 * @chinese 腕温
 *
 * @discussion
 * [EN]: Unit: Celsius.
 * [CN]: 单位：摄氏度。
 */
@property (nonatomic, assign) double wrist;

/**
 * @brief Body temperature.
 * @chinese 体温
 *
 * @discussion
 * [EN]: Unit: Celsius.
 * [CN]: 单位：摄氏度。
 */
@property (nonatomic, assign) double body;

/**
 * @brief Whether it is a manual measurement.
 * @chinese 是否为手动测量
 *
 * @discussion
 * [EN]: YES indicates manual measurement, NO indicates automatic monitoring.
 * [CN]: YES 表示手动测量，NO 表示自动监测。
 */
@property (nonatomic, assign) BOOL isManual;

/**
 * @brief Initialize with database dictionary.
 * @chinese 使用数据库字典初始化
 *
 * @param dict Database dictionary
 * @return Instance
 */
- (instancetype)initWithTsDbDict:(NSDictionary *)dict;

/**
 * @brief Convert database array to model array.
 * @chinese 将数据库数组转换为模型数组
 *
 * @param array Database array
 * @return Model array
 */
+ (NSArray<TPSHistoryTempModel *> *)modelFormArray:(NSArray<NSDictionary *> *)array;

@end

NS_ASSUME_NONNULL_END
