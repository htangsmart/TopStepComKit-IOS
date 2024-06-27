//
//  FwSpo2ConfigModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/21.
//

#ifndef FwSpo2ConfigModel_h
#define FwSpo2ConfigModel_h

@interface FwSpo2ConfigModel : NSObject

-(instancetype)initWithDic:(NSDictionary*)dic;
-(NSDictionary*)toDic;

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
