//
//  TPSBloodPressureConfigModel.h
//  TopStepComKit
//

#ifndef TPSBloodPressureConfigModel_h
#define TPSBloodPressureConfigModel_h

@class FitCloudHTMSingleObject;
@class FitCloudHTMObject;

/**
 * @brief Blood pressure automatic monitoring configuration model
 * @chinese 血压自动监测配置模型
 */
@interface TPSBloodPressureConfigModel : NSObject

/// 是否开启自动监测
@property (nonatomic, assign) BOOL autoMonitorEnable;
/// 自动监测开始时间（从0点0分起的分钟偏移）
@property (nonatomic, assign) int autoMonitorStartTime;
/// 自动监测结束时间（从0点0分起的分钟偏移）
@property (nonatomic, assign) int autoMonitorEndTime;
/// 自动监测时间间隔（分钟）
@property (nonatomic, assign) int autoMonitorInterval;

/**
 * @brief Init from FitCloudHTMSingleObject (allowSingleHTMSettings = YES path)
 * @chinese 从单项健康监测对象初始化（新固件路径）
 */
- (instancetype)initWithFitCloudSingleObject:(FitCloudHTMSingleObject *)model;

/**
 * @brief Convert to FitCloudHTMSingleObject for setSingleHealthTimingMonitoring
 * @chinese 转换为单项对象，用于 setSingleHealthTimingMonitoring
 */
- (FitCloudHTMSingleObject *)toFitCloudSingleObject;

/**
 * @brief Init from FitCloudHTMObject (allowSingleHTMSettings = NO path)
 * @chinese 从通用健康定时监测对象初始化（旧固件路径）
 */
- (instancetype)initWithFitCloudHTMObject:(FitCloudHTMObject *)model;

/**
 * @brief Convert to FitCloudHTMObject for setHealthTimingMonitor
 * @chinese 转换为通用对象，用于 setHealthTimingMonitor
 */
- (FitCloudHTMObject *)toFitCloudHTMObject;

@end

#endif /* TPSBloodPressureConfigModel_h */
