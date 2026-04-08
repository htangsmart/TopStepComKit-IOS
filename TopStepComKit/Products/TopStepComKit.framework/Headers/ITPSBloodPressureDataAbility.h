//
//  ITPSBloodPressureDataAbility.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/21.
//

#ifndef ITPSBloodPressureDataAbility_h
#define ITPSBloodPressureDataAbility_h

#import <TopStepComKit/TPSHistoryBloodPressureModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSBloodPressureConfigModel.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

@protocol ITPSBloodPressureDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistoryBloodPressureCallback)(NSArray<TPSHistoryBloodPressureModel*>* _Nullable bloodPressureList);
typedef void(^TPSBloodPressureConfigCallback)(TPSBloodPressureConfigModel * _Nullable configModel, NSError * _Nullable error);

+(instancetype _Nonnull )share;

-(void)getHistoryBloodPressure:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryBloodPressureCallback _Nullable)block;

/// 获取血压自动监测配置
/// Obtain blood pressure automatic monitoring configuration
-(void)getBloodPressureConfig:(TPSBloodPressureConfigCallback _Nonnull)block;

/// 设置血压自动监测配置
/// Set blood pressure automatic monitoring configuration
-(void)setBloodPressureConfig:(TPSBloodPressureConfigModel *)model block:(TPSSendMsgResult)block;

@end


#endif /* ITPSBloodPressureDataAbility_h */
