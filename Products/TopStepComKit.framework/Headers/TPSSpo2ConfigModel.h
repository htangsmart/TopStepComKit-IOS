//
//  TPSSpo2ConfigModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/21.
//

#ifndef TPSSpo2ConfigModel_h
#define TPSSpo2ConfigModel_h

@class FwSpo2ConfigModel;
@interface TPSSpo2ConfigModel : NSObject

-(instancetype)initWithFwModel:(FwSpo2ConfigModel*)fwModel;
-(FwSpo2ConfigModel*)toFwModel;

@property (nonatomic, assign) BOOL autoMonitorEnable;
/**
 相对于一天0时0点的分钟数。如凌晨1点30分，就是90
 */
@property (nonatomic, assign) int autoMonitorStartTime;
/**
 相对于一天0时0点的分钟数。如凌晨1点30分，就是90
 */
@property (nonatomic, assign) int autoMonitorEndTime;

@property (nonatomic, assign) int autoMonitorInterval;

@property (nonatomic, assign) BOOL alarmEnable;
@property (nonatomic, assign) int minAlarmSpo2;
@property (nonatomic, assign) int maxAlarmSpo2;

@property (nonatomic, assign) BOOL restAlarmEnable;
@property (nonatomic, assign) int minRestAlarmSpo2;
@property (nonatomic, assign) int maxRestAlarmSpo2;




@end


#endif /* FwHrConfigModel_h */
