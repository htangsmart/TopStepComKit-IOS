//
//  TPSDevice.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, TPSSDKType) {
    eTPSSDKFlyWear,
    eTPSSDKFitCloudPro,
    eTPSSDKFWM,//绅聚
};

@interface TPSDevice : NSObject

+ (instancetype)share;


/*
 * @brief 初始化设备类型，每次绑定设备成功之后候需要初始化一次
 *
 * @param deviceType 设备类型
 */
- (void)initDeviceType:(NSString *)deviceType;

/*
 * @brief 获取合适的sdk
 *
 */
- (TPSSDKType)fitSDK;

/*
 * @brief 获取合适的类名前缀
 *
 */
- (NSString *)fitSDKPrefixes;
@end

NS_ASSUME_NONNULL_END
