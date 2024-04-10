//
//  FwHrConfigModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/21.
//

#ifndef FwHrConfigModel_h
#define FwHrConfigModel_h

@interface FwHrConfigModel : NSObject

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

/**
 该值用来计算运动的状态如（极限、燃脂、温和等等）
 */
@property (nonatomic, assign) int maxThresHold;

@property (nonatomic, assign) int autoMonitorInterval;

@property (nonatomic, assign) BOOL sportAlarmEnable;
@property (nonatomic, assign) int minSportAlarmHr;
@property (nonatomic, assign) int maxSportAlarmHr;

@property (nonatomic, assign) BOOL restAlarmEnable;
@property (nonatomic, assign) int minRestAlarmHr;
@property (nonatomic, assign) int maxRestAlarmHr;




@end


#endif /* FwHrConfigModel_h */
