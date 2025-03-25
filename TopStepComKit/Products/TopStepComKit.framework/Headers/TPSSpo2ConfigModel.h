//
//  TPSSpo2ConfigModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/21.
//

#ifndef TPSSpo2ConfigModel_h
#define TPSSpo2ConfigModel_h

@class FwSpo2ConfigModel;
@class FitCloudHTMSingleObject;

@interface TPSSpo2ConfigModel : NSObject

// 是否开启
@property (nonatomic, assign) BOOL autoMonitorEnable;
// 自动测量开始时间 -- 从0点0分开始的偏移分钟数，凌晨1点就是60，以此类推
@property (nonatomic, assign) int autoMonitorStartTime;
// 自动测量结束时间 -- 从0点0分开始的偏移分钟数，凌晨1点就是60，以此类推
@property (nonatomic, assign) int autoMonitorEndTime;
// 自动测量时间间隔
@property (nonatomic, assign) int autoMonitorInterval;

@property (nonatomic, assign) BOOL alarmEnable;
@property (nonatomic, assign) int minAlarmSpo2;
@property (nonatomic, assign) int maxAlarmSpo2;

@property (nonatomic, assign) BOOL restAlarmEnable;
@property (nonatomic, assign) int minRestAlarmSpo2;
@property (nonatomic, assign) int maxRestAlarmSpo2;


-(instancetype)initWithFwModel:(FwSpo2ConfigModel*)fwModel;
-(FwSpo2ConfigModel*)toFwModel;

-(instancetype)initWithFitModel:(FitCloudHTMSingleObject*)fitModel;
-(FitCloudHTMSingleObject*)toFitModel;


@end


#endif /* FwHrConfigModel_h */
