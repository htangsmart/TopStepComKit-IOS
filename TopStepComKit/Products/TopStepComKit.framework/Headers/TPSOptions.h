//
//  TPSOptions.h
//  TopStepComKit
//
//  Created by Topstep on 2024/5/11.
//

#ifndef TPSOptions_h
#define TPSOptions_h

#import <Foundation/Foundation.h>

/**
 * @brief TPSOptions选项(目前这些功能尚未完善，未真实接入)
 */
@interface TPSOptions : NSObject

/**
 * @brief 是否为调试模式, 调试模式会打印较为详细的日志, 默认为非调试模式
 */
@property(nonatomic, assign) BOOL  debugMode;

///**
// * @brief 扫描超时时间，默认10s
// */
//@property(nonatomic, assign) NSTimeInterval secsScanTimeOut;
//
///**
// * @brief 命令执行超时时间，默认10s
// */
//@property(nonatomic, assign) NSTimeInterval secsCommandTimeOut;
//
///**
// * @brief 蓝牙包传输间隔，默认0.015s=15ms
// */
//@property(nonatomic, assign) NSTimeInterval secsPacketUnitInterval;
//
///**
// * @brief 是否应该自动扫描连接， 默认否
// */
//@property(nonatomic, assign) BOOL    shouldAutoConnect;
//
///**
// * @brief 手表语言偏好，默认：FITCLOUDLANGUAGE_NOTSET
// */
//@property(nonatomic, assign) FITCLOUDLANGUAGE watchPreferLang;
//
///**
// * @brief 是否优先使用系统的本地化语言设置，这将影响同步给手表的语言设置， 默认否
// * @note: 当您手动修改了APP的语言设置时，由于系统限制，无法优先系统的本地化语言设置。
//*/
//@property(nonatomic, assign) BOOL    preferSystemLocale;
//
///**
// * @brief 是否自动同步系统时间，默认为YES
// */
//@property(nonatomic, assign) BOOL autoSyncSystemTime;
//
///// 是否自动同步系统语言，默认YES
//@property(nonatomic, assign) BOOL autoSyncSystemLang;
//
///// 是否优先使用WriteWithoutResponse，默认为NO
//@property(nonatomic, assign) BOOL preferWriteWithoutResponse;

/**
 * @brief 默认选项
 */
+ (instancetype)defaultOption;

@end


#endif /* TPSOptions_h */
