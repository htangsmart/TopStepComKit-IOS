//
//  IWearHistorySPO2Sync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSSPO2Ability_h
#define ITPSSPO2Ability_h

#import <TopStepComKit/TPSHistorySPO2Model.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSSpo2ConfigModel.h>

@class FwSpo2ConfigModel;
@protocol ITPSSPO2Ability <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistorySPO2Callback)(NSArray<TPSHistorySPO2Model*>* _Nullable historySPO2ModelList);
typedef void(^TPSSpo2ConfigCallback)(TPSSpo2ConfigModel* _Nullable configModel);

+(instancetype _Nonnull )share;

/// 获取历史血氧
/// Obtain historical blood oxygen
-(void)getHistorySPO2:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistorySPO2Callback _Nullable)block;

/// 获取实时血氧
/// Obtain real-time blood oxygen
-(void)getHistoryRealTimeSPO2:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistorySPO2Callback _Nullable)block;

/// 获取血氧配置
/// Obtain blood oxygen configuration
-(void)getSpo2Config:(TPSSpo2ConfigCallback _Nonnull )block;

/// 设置血氧配置
/// Set blood oxygen configuration
-(void)setSpo2Config:(TPSSpo2ConfigModel*)model block:(TPSSendMsgResult)block;

@end


#endif /* IWearCurDayActivitySync_h */
