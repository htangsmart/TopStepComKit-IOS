//
//  ITPSTempDataAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/12/1.
//

#ifndef ITPSTempDataAbility_h
#define ITPSTempDataAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSHistoryTempModel.h>
#import <TopStepComKit/TPSTempConfigModel.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ITPSTempDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistoryTempCallback)(NSArray<TPSHistoryTempModel *> * _Nullable historyTempList);
typedef void(^TPSTempConfigCallback)(TPSTempConfigModel * _Nullable configModel);

+ (instancetype _Nonnull)share;

/**
 * @brief Query historical wrist temperature data
 * @chinese 根据开始时间、结束时间查询历史腕温数据
 *
 * @param startTime
 * EN: Start timestamp for query
 * CN: 查询的开始时间戳
 *
 * @param endTime
 * EN: End timestamp for query
 * CN: 查询的结束时间戳
 *
 * @param block
 * EN: Callback block to return the query results
 * CN: 返回查询结果的回调
 */
- (void)queryHistoryTempDataWithStartTime:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryTempCallback _Nullable)block;

/**
 * @brief Get body temperature automatic monitoring configuration information
 * @chinese 获取体温自动监测配置信息
 *
 * @param block
 * EN: Callback block to return the configuration
 * CN: 返回配置信息的回调
 */
- (void)getTempConfigWithBlock:(TPSTempConfigCallback _Nullable)block;

/**
 * @brief Set body temperature automatic monitoring configuration information
 * @chinese 设置体温自动监测配置信息
 *
 * @param model
 * EN: Configuration model to set
 * CN: 需要设置的配置模型
 *
 * @param block
 * EN: Result callback
 * CN: 结果回调
 */
- (void)setTempConfig:(TPSTempConfigModel *_Nonnull)model block:(TPSResultCompletion _Nullable)block;

@end

NS_ASSUME_NONNULL_END

#endif /* ITPSTempDataAbility_h */
