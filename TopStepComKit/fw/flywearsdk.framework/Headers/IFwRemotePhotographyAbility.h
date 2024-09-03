//
//  IFwRemotePhotographyAbility.h
//  flywearsdk
//
//  Created by 磐石 on 2024/3/22.
//

#import <flywearsdk/IFwWearBaseAbility.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IFwRemotePhotographyAbility <NSObject,IFwWearBaseAbility>

+ (instancetype)share;

/// app进入拍照页面
- (void)enterRemotePhotography:(void(^)(void))takePhotoBlock;
/// app退出拍照页面
- (void)exitRemotePhotography;

/// 监听手表进入拍照页面
- (void)observerWatchEnterRemotePhotography:(void(^)(void(^takePhotoBlock)(void)))watchEnterRemotePhotographyBlock;
/// 监听手表退出拍照页面
- (void)observerWatchExitRemotePhotography:(void(^)(void))watchExitRemotePhotographyBlock;



@end

NS_ASSUME_NONNULL_END
