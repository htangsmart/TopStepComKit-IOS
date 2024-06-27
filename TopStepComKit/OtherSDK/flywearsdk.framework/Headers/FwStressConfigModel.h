//
//  FwStressConfigModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/21.
//

#ifndef FwStressConfigModel_h
#define FwStressConfigModel_h

@interface FwStressConfigModel : NSObject

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
@property (nonatomic, assign) int minAlarmStress;
@property (nonatomic, assign) int maxAlarmStress;

@property (nonatomic, assign) BOOL restAlarmEnable;
@property (nonatomic, assign) int minRestAlarmStress;
@property (nonatomic, assign) int maxRestAlarmStress;




@end


#endif /* FwHrConfigModel_h */
