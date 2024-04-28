//
//  TFwRemotePhotographyAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/22.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ITPSRemotePhotographyAbility <NSObject,ITPSWearBaseAbility>

+ (instancetype)share;

/// app通知手环进入拍照
- (void)enterRemotePhotography:(void(^)(void))shoutterBlock;
/// app退出拍照
- (void)exitRemotePhotography;

/// 手环控制手机拍照
- (void)remotePhotographyOnTakePhotoCtrl ;


/// 手环通知App退出拍照
- (void)remotePhotographyOnExitCamera ;
/// 手环通知App进入拍照
- (void)remotePhotographyOnOpenCamera ;

/// 监听手表进入拍照
- (void)observerWatchOpenCamera:(void(^)(void))openCameraBlock;

/// 监听手表退出拍照
- (void)observerWatchExitCamera:(void(^)(void))exitCameraBlock;


@end

NS_ASSUME_NONNULL_END
