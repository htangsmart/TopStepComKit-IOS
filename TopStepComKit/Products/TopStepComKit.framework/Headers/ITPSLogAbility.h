//
//  ITPSLogAbility.h
//  TopStepComKit
//

//  Created by 磐石 on 2024/8/21.
//

#import <Foundation/Foundation.h>



typedef NS_ENUM(NSUInteger, TPSWatchLogState) {
    eTPSWatchLogStatCcompression = 0,     ///< 日志压缩中
    eTPSWatchLogStatCcompressSuccess,     ///< 日志压缩成功
    eTPSWatchLogStatCcompressFailed,      ///< 日志压缩失败
    eTPSWatchLogStateExproting,           ///< 日志导出中
    eTPSWatchLogStateExprotSuccess,       ///< 日志导出成功
    eTPSWatchLogStateExprotFailed,        ///< 日志导出失败
};



@protocol ITPSLogAbility <NSObject>


/**
 * 请求手表日志（使用默认路径）
 * @param completion 回调block，返回日志状态和进度
 *        - state: 当前操作状态，详见 FWWatchLogState
 *        - progress: 当前进度(0-100)
 * @note 日志将保存在默认路径下
 */
- (void)requestWatchLogCompletion:(void(^)(TPSWatchLogState state, CGFloat progress))completion __attribute__((unavailable("该方法暂时不可用")));

/**
 * 请求手表日志并保存到指定路径
 * @param filePath 日志保存路径，需要包含完整的文件名和扩展名
 * @param completion 回调block，返回日志状态和进度
 *        - state: 当前操作状态，详见 FWWatchLogState
 *        - progress: 当前进度(0-100)
 * @note 确保指定路径有写入权限
 */
- (void)requestWatchLogAtPath:(NSString *)filePath completion:(void(^)(TPSWatchLogState state, CGFloat progress))completion __attribute__((unavailable("该方法暂时不可用")));

/**
 * 请求手表日志并可选择是否清理远程日志
 * @param filePath 日志保存路径，需要包含完整的文件名和扩展名
 * @param isCleanRemoteLog 是否清理设备端日志
 *        - YES: 导出完成后清理设备端日志
 *        - NO: 保留设备端日志
 * @param completion 回调block，返回日志状态和进度
 *        - state: 当前操作状态，详见 FWWatchLogState
 *        - progress: 当前进度(0-100)
 * @note 清理设备端日志将释放设备存储空间
 */
- (void)requestWatchLogAtPath:(NSString *)filePath cleanRemoteLog:(BOOL)isCleanRemoteLog completion:(void(^)(TPSWatchLogState state, CGFloat progress))completion;

/**
 * 请求不包含SDK日志的手表日志
 * @param filePath 日志保存路径，需要包含完整的文件名和扩展名
 * @param isCleanRemoteLog 是否清理设备端日志
 *        - YES: 导出完成后清理设备端日志
 *        - NO: 保留设备端日志
 * @param completion 回调block，返回日志状态和进度
 *        - state: 当前操作状态，详见 FWWatchLogState
 *        - progress: 当前进度(0-100)
 * @note 此方法只获取设备原始日志，不包含SDK的日志信息
 *       适用于需要分析设备底层问题的场景
 */
- (void)requestWatchWithoutSDKLogAtPth:(NSString *)filePath cleanRemoteLog:(BOOL)isCleanRemoteLog completion:(void(^)(TPSWatchLogState state, CGFloat progress))completion ;


@end

