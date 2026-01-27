//
//  ITPSPrayAbility.h
//
//
//  Created by Topstep on 2024/3/18.
//

#ifndef ITPSPrayAbility_h
#define ITPSPrayAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSPrayTimes.h>
#import <TopStepComKit/TPSPrayConfigs.h>

/**
 * @brief Prayer type enumeration
 * @chinese 祈祷类型枚举
 */
typedef NS_ENUM(NSInteger, TPSPraySwitchType) {
    TPSPrayTypeMain = 0,     // 祈祷总开关 | Main prayer switch
    TPSPrayTypeFajr = 1,     // 晨礼(黎明祈祷) | Fajr (dawn) prayer
    TPSPrayTypeDhuhr = 2,    // 晌礼(正午祈祷) | Dhuhr (noon) prayer
    TPSPrayTypeAsr = 3,      // 晡礼(下午祈祷) | Asr (afternoon) prayer
    TPSPrayTypeMaghrib = 4,  // 昏礼(日落祈祷) | Maghrib (sunset) prayer
    TPSPrayTypeIsha = 5      // 宵礼(夜间祈祷) | Isha (night) prayer
};

@protocol ITPSPrayAbility <NSObject,ITPSWearBaseAbility>

typedef void(^PrayDidChangedBlock)(TPSPrayConfigs * _Nullable configs);


/**
 * @brief Get the shared instance of prayer ability
 * @chinese 获取祈祷功能的共享实例
 * 
 * @return 
 * EN: Shared instance of prayer ability
 * CN: 祈祷功能的共享实例
 */
+(instancetype _Nullable )share;

/**
 * @brief Set prayer reminder state for a specific prayer type
 * @chinese 设置特定祈祷类型的提醒状态
 *
 * @param prayType
 * EN: Prayer type to set
 * CN: 要设置的祈祷类型
 * 
 * @param enabled 
 * EN: Whether to enable the specified prayer type
 * CN: 是否启用指定的祈祷类型
 * 
 * @param completion 
 * EN: Callback indicating whether the operation was successful
 * CN: 回调函数，指示操作是否成功
 */
- (void)setSinglePrayStateWithType:(TPSPraySwitchType)prayType enabled:(BOOL)enabled completion:(_Nonnull TPSCompletionBlock)completion;

/**
 * @brief Set all prayer configurations at once
 * @chinese 一次性设置所有祈祷配置
 * 
 * @param configs 
 * EN: Prayer configuration object containing settings for all prayer reminders
 * CN: 包含所有祈祷提醒设置的祈祷配置对象
 * 
 * @param completion 
 * EN: Callback indicating whether the operation was successful
 * CN: 回调函数，指示操作是否成功
 */
- (void)setAllPrayConfigs:(TPSPrayConfigs *_Nonnull)configs completion:(_Nonnull TPSCompletionBlock)completion;

/**
 * @brief Get current prayer configuration
 * @chinese 获取当前祈祷配置
 * 
 * @param completion 
 * EN: Callback with the current prayer configuration object and operation status
 * CN: 回调函数，返回当前的祈祷配置对象和操作状态
 */
- (void)getPrayConfigsWithCompletion:(nonnull void(^)(TPSPrayConfigs * _Nullable configs, NSError * _Nullable error))completion;

/**
 * @brief Synchronize prayer times to device
 * @chinese 同步祈祷时间到设备
 * 
 * @param prayTimes 
 * EN: Array of TPSPrayTimes objects containing prayer times to be synchronized
 * CN: 包含要同步的祈祷时间的TPSPrayTimes对象数组
 * 
 * @param completion 
 * EN: Callback indicating whether the operation was successful
 * CN: 回调函数，指示操作是否成功
 */
- (void)syncPrayTimes:(NSArray<TPSPrayTimes *> * _Nonnull)prayTimes completion:(TPSCompletionBlock _Nonnull )completion;

/**
 * @brief Register for prayer state change notifications
 * @chinese 注册祈祷状态变化通知
 * 
 * @param stateChangeHandler
 * EN: Callback that will be invoked when prayer state changes, with the updated prayer configuration
 * CN: 当祈祷状态发生变化时将被调用的回调函数，包含更新后的祈祷配置
 */
- (void)registerPrayStateChangeHandler:(nonnull PrayDidChangedBlock)stateChangeHandler;


@end


#endif /* IFwWorldClockAbility_h */
