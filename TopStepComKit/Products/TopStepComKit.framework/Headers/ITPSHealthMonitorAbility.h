//
//  ITPSHealthMonitorAbility.h
//  TopStepComKit
//
//  Created by Zhuanz on 2024/8/16.
//

#ifndef ITPSHealthMonitorAbility_h
#define ITPSHealthMonitorAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

@protocol ITPSHealthMonitorAbility <NSObject, ITPSWearBaseAbility>

+ (instancetype)share;

- (void)startMeasureWithMeasureInfo:(NSDictionary *)measureInfo success:(void (^)(void))success failure:(void (^)(NSDictionary *error))failure;

- (void)getMeasureResultWithValues:(NSArray *)valuesKey poolName:(NSString *)poolName success:(void (^)(NSArray * values))success failure:(void (^)(NSDictionary *error))failure;

- (void)receiveMeasureData:(NSArray *)records;

- (void)stopMeasure:(TPSSendMsgResult)block;

-(RACSubject<NSNumber*>*_Nonnull)observeMeasureValue;

-(RACSubject*_Nonnull)observeCloseMeasureOnWatch;

@end

#endif /* ITPSHealthMonitorAbility_h */
