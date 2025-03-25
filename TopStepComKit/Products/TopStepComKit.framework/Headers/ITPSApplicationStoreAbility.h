
//
//  ITPSRecordingAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/3/6.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSApplicationStoreModel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 应用列表回调block
 * @chinese 获取已安装应用列表的回调
 *
 * @param apps 已安装的应用列表
 * @param error 错误信息，如果获取成功则为nil
 */
typedef void(^TPSApplicationResultBlock)(NSArray<TPSApplicationStoreModel*>*apps,NSError * _Nullable error);

/**
 * @brief 应用状态变化回调block
 * @chinese 监听应用状态变化的回调
 *
 * @param app 发生变化的应用信息
 * @param error 错误信息，如果监听成功则为nil
 */
typedef void(^TPSApplicationDidChangedBlock)(TPSApplicationStoreModel*app,NSError *_Nullable error);

/**
 * @brief 应用商店能力接口
 * @chinese 提供设备应用商店相关的功能接口
 */
@protocol ITPSApplicationStoreAbility <ITPSWearBaseAbility>

/**
 * @brief Get installed applications list
 * @chinese 获取设备已安装的应用列表
 *
 * @param completion
 * EN: Callback with installed applications list and error if any
 * CN: 获取结果的回调，返回已安装的应用列表，如果有错误则返回错误信息
 */
- (void)getInstalledApplicationCompletion:(TPSApplicationResultBlock)completion;

/**
 * @brief Register callback for application state changes
 * @chinese 注册应用状态变化的监听
 *
 * @param didChangedBlock
 * EN: Callback triggered when application state changes
 * CN: 当应用状态发生变化时的回调
 *
 * @discussion
 * [EN]: This method will notify when applications are installed, uninstalled or updated
 * [CN]: 此方法会在应用被安装、卸载或更新时通知
 */
- (void)registerAppStateDidChangedBlock:(TPSApplicationDidChangedBlock)didChangedBlock;

/**
 * @brief Check if prayer application is installed
 * @chinese 检查祈祷应用是否已安装
 *
 * @param completion
 * EN: Callback with installation status and error if any
 * CN: 检查结果的回调，返回是否已安装以及可能的错误信息
 *
 * @discussion
 * [EN]: Returns YES if prayer app is installed, NO otherwise
 * [CN]: 如果祈祷应用已安装则返回YES，否则返回NO
 */
- (void)checkIfInstalledPrayAppCompletion:(void(^)(BOOL isInstalled,NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
