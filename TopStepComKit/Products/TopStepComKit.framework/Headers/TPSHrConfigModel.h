//
//  TPSHrConfigModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/21.
//

#import <TopStepComKit/TSJConnectorAbility.h>

#ifndef TPSHrConfigModel_h
#define TPSHrConfigModel_h

@class FitCloudHRAlarmObject;
@class WMHeartRateConfigModel;
@class  FitCloudHTMSingleObject;
@interface TPSHrConfigModel : NSObject


/// 自动心率监测是否开启
@property (nonatomic, assign) BOOL autoMonitorEnable;
/**
 自动监测开启时间
 相对于一天0时0点的分钟数。如凌晨1点30分，就是90
 */
@property (nonatomic, assign) int autoMonitorStartTime;
/**
 自动监测关闭时间
 相对于一天0时0点的分钟数。如凌晨1点30分，就是90
 */
@property (nonatomic, assign) int autoMonitorEndTime;
/// 测量时间间隔
@property (nonatomic, assign) int autoMonitorInterval;

/**
 该值用来计算运动的状态如（极限、燃脂、温和等等）
 */
@property (nonatomic, assign) int maxThresHold;

/// 运动心率报警是否开启
@property (nonatomic, assign) BOOL sportAlarmEnable;
/// 运动时最低报警心率
@property (nonatomic, assign) int minSportAlarmHr;
/// 运动时最高报警心率
@property (nonatomic, assign) int maxSportAlarmHr;

/// 静息心率报警是否开启
@property (nonatomic, assign) BOOL restAlarmEnable;
/// 静息最低心率
@property (nonatomic, assign) int minRestAlarmHr;
/// 静息最高心率
@property (nonatomic, assign) int maxRestAlarmHr;



-(instancetype)initWithFCPModel:(FitCloudHRAlarmObject*)fcpModel;
- (FitCloudHRAlarmObject *)toFitHRAlarmModel;

- (FitCloudHTMSingleObject *)toFitSingleModel;


-(instancetype)initWithFCPModel:(FitCloudHRAlarmObject*)fcpModel htmSingleModel:(FitCloudHTMSingleObject *)htmModel;



- (instancetype)initWithWMModel:(WMHeartRateConfigModel *)wmModel;

-(WMHeartRateConfigModel*)toWMModel;


@end


#endif /* FwHrConfigModel_h */
