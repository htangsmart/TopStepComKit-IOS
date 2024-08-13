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

typedef NS_ENUM(NSUInteger, TPSDeviceType) {
    TPSDeviceType_OSW850H,
    TPSDeviceType_OSW851H,
    TPSDeviceType_OSW805,
    TPSDeviceType_OSW802N,
    TPSDeviceType_TS9845,
};

@class FitCloudOption;
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

/*
 * @brief 获取合适的fitcloud-sdk的配置，每个厂家可能要设置不同的值
 *
 */
- (FitCloudOption*)getFitcloudOption;

@end

NS_ASSUME_NONNULL_END
