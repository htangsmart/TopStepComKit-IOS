//
//  TPSHistoryTempModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/12/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Historical wrist temperature data model
 * @chinese 历史腕温数据模型
 */
@interface TPSHistoryTempModel : NSObject

/**
 * @brief Measurement timestamp
 * @chinese 测量时间戳
 */
@property (nonatomic, assign) long timestamp;

/**
 * @brief Wrist temperature in Celsius
 * @chinese 腕温，单位：摄氏度
 */
@property (nonatomic, assign) double wrist;

/**
 * @brief Body temperature in Celsius
 * @chinese 体温，单位：摄氏度
 */
@property (nonatomic, assign) double body;

/**
 * @brief Whether this record is a manual measurement
 * @chinese 是否为手动测量
 *
 * @discussion
 * [EN]: YES indicates manual measurement, NO indicates automatic monitoring.
 * [CN]: YES 表示手动测量，NO 表示自动监测。
 */
@property (nonatomic, assign) BOOL isManual;

/**
 * @brief Initialize with a database row dictionary
 * @chinese 使用数据库行字典初始化
 *
 * @param dict
 * EN: Dictionary from SQLite query result
 * CN: SQLite 查询结果字典
 *
 * @return TPSHistoryTempModel instance
 */
- (instancetype)initWithDatabaseDict:(NSDictionary *)dict;

/**
 * @brief Convert a database result array to model array
 * @chinese 将数据库结果数组转换为模型数组
 *
 * @param array
 * EN: Array of SQLite row dictionaries
 * CN: SQLite 行字典数组
 *
 * @return Model array
 */
+ (NSArray<TPSHistoryTempModel *> *)modelFromArray:(NSArray<NSDictionary *> *)array;

@end

NS_ASSUME_NONNULL_END
