//
//  IFwHealthMonitorAbility.h
//  flywearsdk
//
//  Created by Zhuanz on 2024/8/16.
//

#ifndef IFwHealthMonitorAbility_h
#define IFwHealthMonitorAbility_h

#import <flywearsdk/IFwWearBaseAbility.h>

@protocol IFwHealthMonitorAbility <NSObject, IFwWearBaseAbility>

+ (instancetype)share;

- (void)startMeasureWithMeasureInfo:(NSDictionary *)measureInfo success:(void (^)(void))success failure:(void (^)(NSDictionary *error))failure;

- (void)getMeasureResultWithValues:(NSArray *)valuesKey poolName:(NSString *)poolName success:(void (^)(NSArray * values))success failure:(void (^)(NSDictionary *error))failure;

@end



#endif /* IFwHealthMonitorAbility_h */
