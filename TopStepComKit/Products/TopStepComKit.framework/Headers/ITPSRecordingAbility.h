//
//  ITPSRecordingAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/2/19.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSRecordingModel.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSProgressModel.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(UInt8, TPSRecordingAction) {
    TPSRecordingActionStop = 0,
    TPSRecordingActionStart,
    TPSRecordingActionPause,
    TPSRecordingActionResume
};

typedef void(^TPSRecordingListCallback)(NSArray<TPSRecordingModel *> *fileList);
typedef void(^TPSRecordingOpusDataCallback)(NSInteger channel, NSData *byte);


@protocol ITPSRecordingAbility <NSObject, ITPSWearBaseAbility>

+ (instancetype)share;
/** 控制手表录音 0-停止 1-开始 2-暂停 3-恢复
    返回手表当前录音状态 0-停止 1-进行中 2-暂停 */
- (void)controlWatchRecordingWithAction:(TPSRecordingAction)action success:(void(^)(NSDictionary *result))success failure:(void(^)(NSDictionary *result))failure;
/// 查询手表当前录音状态
- (void)queryWatchRecordingStateSuccess:(void (^)(NSDictionary *result))success failure:(void (^)(NSDictionary *result))failure;
/// 接收手表控制手机指令
- (void)receiveWatchRecordingSuccess:(void (^)(NSDictionary *result))success failure:(void (^)(NSDictionary *result))failure;
/// 获取手表所有录音文件
- (void)getAllRecordingFiles:(TPSRecordingListCallback)result;
/// 根据录音文件名称删除录音文件
- (void)deleteRecordingFileWithName:(NSString *)fileName result:(TPSSendMsgResult)result;
/// 批量删除手表内录音文件（未实现）
- (void)deleteRecordingFilesWithNameList:(NSArray<NSString *> *)list result:(TPSSendMsgResult)result;
/// 删除所有手表内录音文件（未实现）
- (void)deleteAllRecordingFiles:(TPSSendMsgResult)result;
/// 手表传输录音文件到App（一次只能传输一个文件）
- (void)pullRecordingFileWithRemoteFileName:(NSString *)fileName toLocalPath:(NSString *)localPath result:(onTPSProgressResult)result;
/// 取消文件传输
- (void)cancelPullRecordingFileWithName:(NSString *)fileName;
/// 手表实时传输opus数据到App
- (void)transmitRealTimeOpusDataToPhone:(TPSRecordingOpusDataCallback)result;
/// 停止接收手表实时传输opus数据
- (void)stopTransmitRealTimeOpusDataToPhone;


@end

NS_ASSUME_NONNULL_END
