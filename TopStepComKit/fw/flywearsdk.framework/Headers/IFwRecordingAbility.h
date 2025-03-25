//
//  IFwRecordingAbility.h
//  flywearsdk
//
//  Created by Zhuanz on 2024/6/24.
//

#ifndef IFwRecordingAbility_h
#define IFwRecordingAbility_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwRecordingModel.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwProgressModel.h>

typedef NS_ENUM(UInt8, FwRecordingAction) {
    FwRecordingActionStop = 0,
    FwRecordingActionStart,
    FwRecordingActionPause,
    FwRecordingActionResume
};

typedef void(^FwRecordingListCallback)(NSArray<FwRecordingModel *> *fileList);
typedef void(^FwRecordingOpusDataCallback)(NSInteger channel, NSData *byte);

@protocol IFwRecordingAbility <NSObject, IFwWearBaseAbility>

+ (instancetype)share;
/** 控制手表录音 0-停止 1-开始 2-暂停 3-恢复
    返回手表当前录音状态 0-停止 1-进行中 2-暂停 */
- (void)controlWatchRecordingWithAction:(FwRecordingAction)action success:(void(^)(NSDictionary *result))success failure:(void(^)(NSDictionary *result))failure;
/// 查询手表当前录音状态
- (void)queryWatchRecordingStateSuccess:(void (^)(NSDictionary *result))success failure:(void (^)(NSDictionary *result))failure;
/// 接收手表控制手机指令
- (void)receiveWatchRecordingSuccess:(void (^)(NSDictionary *result))success failure:(void (^)(NSDictionary *result))failure;
/// 获取手表所有录音文件
- (void)getAllRecordingFiles:(FwRecordingListCallback)result;
/// 根据录音文件名称删除录音文件
- (void)deleteRecordingFileWithName:(NSString *)fileName result:(FwSendMsgResult)result;
/// 批量删除手表内录音文件（未实现）
- (void)deleteRecordingFilesWithNameList:(NSArray<NSString *> *)list result:(FwSendMsgResult)result;
/// 删除所有手表内录音文件（未实现）
- (void)deleteAllRecordingFiles:(FwSendMsgResult)result;
/// 手表传输录音文件到App（一次只能传输一个文件）
- (void)pullRecordingFileWithRemoteFileName:(NSString *)fileName toLocalPath:(NSString *)localPath result:(onProgressResult)result;
/// 取消文件传输
- (void)cancelPullRecordingFileWithName:(NSString *)fileName;
/// 手表实时传输opus数据到App
- (void)transmitRealTimeOpusDataToPhone:(FwRecordingOpusDataCallback)result;
/// 停止接收手表实时传输opus数据
- (void)stopTransmitRealTimeOpusDataToPhone;

@end

#endif /* IFwRecordingAbility_h */
