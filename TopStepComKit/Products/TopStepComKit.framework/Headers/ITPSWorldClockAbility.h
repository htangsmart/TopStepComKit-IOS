//
//  ITPSWorldClockAbility.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef ITPSWorldClockAbility_h
#define ITPSWorldClockAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSWorldClockModel.h>

@protocol ITPSWorldClockAbility <NSObject,ITPSWearBaseAbility>

/**
 * @brief Get the shared instance of ITPSWorldClockAbility
 * @chinese 获取ITPSWorldClockAbility的共享实例
 *
 * @return 
 * [EN]: The shared instance of ITPSWorldClockAbility
 * [CN]: ITPSWorldClockAbility的共享实例
 */
+(instancetype _Nonnull )share;

/**
 * @brief Get the maximum number of world clocks supported by the device
 * @chinese 获取设备支持的最大世界时钟数量
 *
 * @return 
 * [EN]: The maximum number of world clocks that can be set
 * [CN]: 可以设置的最大世界时钟数量
 */
-(NSInteger)getSupportMaxWorldClockCount;

/**
 * @brief Get all world clocks from the device
 * @chinese 从设备获取所有世界时钟
 *
 * @param completion
 * [EN]: Callback completion that returns an array of TPSWorldClockModel objects
 * [CN]: 返回TPSWorldClockModel对象数组的回调块
 */
-(void)getAllWorldClocksCompletion:(void(^_Nonnull)(NSArray<TPSWorldClockModel*>* _Nullable worldClocks,NSError * _Nullable error ))completion;

/**
 * @brief Set all world clocks to the device
 * @chinese 设置所有世界时钟到设备
 *
 * @param worldClocks 
 * [EN]: Array of TPSWorldClockModel objects to be set
 * [CN]: 要设置的TPSWorldClockModel对象数组
 *
 * @param completion
 * [EN]: Callback block that indicates whether the operation was successful
 * [CN]: 指示操作是否成功的回调块
 */
-(void)setAllWorldClocks:(NSArray<TPSWorldClockModel*>*_Nonnull)worldClocks completion:(TPSCompletionBlock _Nonnull )completion;

@end

#endif /* IFwWorldClockAbility_h */
