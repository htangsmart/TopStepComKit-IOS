//
//  ITPSHealthMeasureAbility.h
//  TopStepComKit
//
//  Created by Zhuanz on 2024/8/16.
//

#ifndef ITPSHealthMeasureAbility_h
#define ITPSHealthMeasureAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSMeasureConfig.h>
#import <TopStepComKit/TPSMeasureValue.h>

@protocol ITPSHealthMeasureAbility <NSObject, ITPSWearBaseAbility>

+ (instancetype _Nonnull )share;

/**
 * @brief Start health measurement
 * @chinese 开始健康测量
 *
 * @param config
 * EN: Measurement configuration
 * CN: 测量配置
 *
 * @param completion
 * EN: Result callback
 * CN: 结果回调
 */
- (void)startMeasureWithConfig:(TPSMeasureConfig *_Nonnull)config completion:(TPSResultCompletion _Nullable)completion;

/**
 * @brief Stop health measurement
 * @chinese 结束健康测量
 *
 * @param completion
 * EN: Result callback
 * CN: 结果回调
 */
- (void)stopMeasureWithCompletion:(TPSResultCompletion _Nullable)completion;

/**
 * @brief Observe measurement values
 * @chinese 监听测量数值
 *
 * @return
 * EN: RACSubject for observing measurement values
 * CN: 用于监听测量数值的 RACSubject
 */
-(RACSubject<TPSMeasureValue*>*_Nonnull)observeMeasureValue;

/**
 * @brief Observe close measurement event on watch
 * @chinese 监听手表端关闭测量事件
 *
 * @return
 * EN: RACSubject for observing close event
 * CN: 用于监听关闭事件的 RACSubject
 */
-(RACSubject*_Nonnull)observeCloseMeasureOnWatch;



@end

#endif /* ITPSHealthMeasureAbility_h */
