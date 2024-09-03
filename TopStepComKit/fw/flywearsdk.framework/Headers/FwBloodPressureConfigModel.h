//
//  FwBloodPressureConfigModel.h
//  flywearsdk
//
//  Created by luigi on 2024/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FwBloodPressureConfigModel : NSObject
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
@property (nonatomic, assign) int sbpMin;//0表示不生效
@property (nonatomic, assign) int sbpMax;//0表示不生效
@property (nonatomic, assign) int dbpMin;//0表示不生效
@property (nonatomic, assign) int dbpMax;//0表示不生效
@end

NS_ASSUME_NONNULL_END
