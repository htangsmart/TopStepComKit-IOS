//
//  TPSMeasureValue.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/12/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FitCloudRealTimeHealthMeasuringResultObject;

@interface TPSMeasureValue : NSObject

/**
 * @brief Sampling moment.
 * @chinese 采样时刻
 */
@property(nonatomic, strong) NSDate *moment;

/**
 * @brief Heart rate.
 * @chinese 心率
 */
@property(nonatomic, assign) NSInteger heartRate;

/**
 * @brief Blood oxygen.
 * @chinese 血氧
 */
@property(nonatomic, assign) NSInteger bloodOxygen;

/**
 * @brief Diastolic pressure.
 * @chinese 舒张压
 */
@property(nonatomic, assign) NSInteger diastolic;

/**
 * @brief Systolic pressure.
 * @chinese 收缩压
 */
@property(nonatomic, assign) NSInteger systolic;

/**
 * @brief Respiratory rate.
 * @chinese 呼吸频率
 */
@property(nonatomic, assign) NSInteger respiratoryRate;

/**
 * @brief Body temperature measurement status.
 * @chinese 体温测量状态
 *
 * @discussion
 * [EN]:
 * 0: Normal status, data is being returned normally;
 * 1: Measurement end, normal end time reached;
 * 2: Measurement end, watch not worn;
 * 3: Measurement end, body temperature too high;
 * 4: Measurement end, body temperature too low.
 *
 * [CN]:
 * 0: 正常状态，数据正常返回中；
 * 1: 测量结束，正常结束时间到达；
 * 2: 测量结束，未佩戴手表；
 * 3: 测量结束，体温过高；
 * 4: 测量结束，体温过低。
 */
@property(nonatomic, assign) NSInteger temperatureFlag;

/**
 * @brief Wrist temperature.
 * @chinese 腕温
 *
 * @discussion
 * [EN]: Unit: Celsius degrees.
 * [CN]: 单位：摄氏度。
 */
@property(nonatomic, assign) CGFloat wrist;

/**
 * @brief Body temperature.
 * @chinese 体温
 *
 * @discussion
 * [EN]: Unit: Celsius degrees.
 * [CN]: 单位：摄氏度。
 */
@property(nonatomic, assign) CGFloat body;

/**
 * @brief Stress index.
 * @chinese 压力指数
 *
 * @discussion
 * [EN]: Valid when watch supports stress index measurement.
 * [CN]: 当手表支持压力指数测量时有效。
 */
@property(nonatomic, assign) NSInteger stressIndex;

/**
 * @brief Initialize with FitCloudRealTimeHealthMeasuringResultObject.
 * @chinese 使用 FitCloudRealTimeHealthMeasuringResultObject 初始化
 *
 * @param model FitCloudRealTimeHealthMeasuringResultObject
 * @return TPSMeasureValue instance
 */
- (instancetype)initWithFitCloudModel:(FitCloudRealTimeHealthMeasuringResultObject *)model;

@end

NS_ASSUME_NONNULL_END
