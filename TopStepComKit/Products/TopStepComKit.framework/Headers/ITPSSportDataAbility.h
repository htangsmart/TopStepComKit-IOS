//
//  IWearHistorySportSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSSportDataAbility_h
#define ITPSSportDataAbility_h

#import <TopStepComKit/TPSHistorySportModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

@protocol ITPSSportDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistorySportCallback)(NSArray<TPSHistorySportModel*>* _Nullable historySportModelList);

+(instancetype _Nonnull )share;

/// 根据时间范围获取历史运动数据 部分设备不支持查询截止时间（绅聚）
/// Get historical sports data based on time range
-(void)getHistorySport:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistorySportCallback _Nullable)block;

@end


#endif /* IWearCurDayActivitySync_h */
