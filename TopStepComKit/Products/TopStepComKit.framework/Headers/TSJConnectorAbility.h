//
//  TSJConnectorAbility.h
//  TopStepComKit
//
//  Created by luigi on 2024/5/28.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/ITPSConnectorAbility.h>


NS_ASSUME_NONNULL_BEGIN

@class RACSubject<ValueType>;
@class WMPeripheral;


@interface TSJConnectorAbility : NSObject<ITPSConnectorAbility>

+(instancetype)share;

/// 当前连接的设备
@property (nonatomic, strong, nullable) WMPeripheral * peripheral;

@end

NS_ASSUME_NONNULL_END
