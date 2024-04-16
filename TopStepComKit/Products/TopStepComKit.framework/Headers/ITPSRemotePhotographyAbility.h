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

- (RACSubject *)enterRemotePhotography;

- (void)exitRemotePhotography;


/// 手环控制手机拍照
- (void)remotePhotographyOnTakePhotoCtrl ;

/// 手表通知App退出拍照
- (void)remotePhotographyOnExitCamera ;

@end

NS_ASSUME_NONNULL_END
