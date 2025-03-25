//
//  TPSDevice.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/30.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/TPSOptions.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, TPSSDKType) {
    eTPSSDKFlyWear,
    eTPSSDKFitCloudPro,
    eTPSSDKFWM,//绅聚
};

//设备型号
typedef NS_ENUM(NSUInteger, TPSDeviceType) {
    TPSDeviceType_OSW850H,//7003
    TPSDeviceType_OSW851H,//9804
    TPSDeviceType_OSW805,//8004
    TPSDeviceType_OSW802N,
    TPSDeviceType_TS9845,
    
    TPSDeviceType_OSW805f,//809A
    TPSDeviceType_OSW806N,//8065
    TPSDeviceType_OSW820,//8809
    TPSDeviceType_OSW830,//8800
    TPSDeviceType_OSW832N,//8801
    
};

@class FitCloudOption;
@interface TPSDevice : NSObject

+ (instancetype)share;

@property(nonatomic, strong) TPSOptions* tpsOption;


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
