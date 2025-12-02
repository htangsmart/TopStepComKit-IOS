//
//  TPSMeasureConfig.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/12/1.
//

#ifndef TPSMeasureConfig_h
#define TPSMeasureConfig_h

#import <Foundation/Foundation.h>

/// 实时健康测量项定义 / Real-time health measurement items definition
typedef NS_ENUM(UInt16, TPSHealthMeasureType) {
    /// 无 / None
    TPSHealthMeasure_None = 0,
    
    /// 心率 / Heart rate
    TPSHealthMeasureHeartRate = 1,
    
    /// 血氧 / Blood oxygen
    TPSHealthMeasureBloodOxygen = 1 << 1,
    
    /// 血压 / Blood pressure
    TPSHealthMeasureBloodPressure = 1 << 2,
    
    /// 呼吸频率 / Respiratory rate
    TPSHealthMeasureRespiratoryRate = 1 << 3,
    
    /// 心电 / ECG
    TPSHealthMeasureECG = 1 << 4,
    
    /// 体温 / Body temperature
    TPSHealthMeasureTemperature = 1 << 5,
    
    /// 压力指数 / Stress index
    TPSHealthMeasureStressIndex = 1 << 6,
    
    /// 全部 / All
    TPSHealthMeasureAll =   TPSHealthMeasureHeartRate |
                            TPSHealthMeasureBloodOxygen |
                            TPSHealthMeasureBloodPressure |
                            TPSHealthMeasureRespiratoryRate |
                            TPSHealthMeasureECG |
                            TPSHealthMeasureTemperature |
                            TPSHealthMeasureStressIndex,
};


NS_ASSUME_NONNULL_BEGIN

@interface TPSMeasureConfig : NSObject

/**
 * @brief Measurement type.
 * @chinese 测量类型
 */
@property (nonatomic, assign) TPSHealthMeasureType type;

/**
 * @brief Maximum measurement duration.
 * @chinese 测量最大时长
 *
 * @discussion
 * [EN]: Unit: Minute.
 * [CN]: 单位：分钟。
 */
@property (nonatomic, assign) NSInteger duration;

/**
 * @brief Measurement interval.
 * @chinese 测量间隔
 *
 * @discussion
 * [EN]: Unit: Second.
 * [CN]: 单位：秒。
 */
@property (nonatomic, assign) NSInteger interval;

@end

NS_ASSUME_NONNULL_END

#endif /* TPSMeasureConfig_h */
