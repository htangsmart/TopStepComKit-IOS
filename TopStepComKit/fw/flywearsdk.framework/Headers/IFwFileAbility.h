//
//  IWearFileSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef IWearFileSync_h
#define IWearFileSync_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwProgressModel.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwFileUpdateModel.h>

@class FwDevFileDesModel;

typedef void(^FwFileListCallback)(NSArray<FwDevFileDesModel*> * fileList);
typedef void(^FwFileSizeCallback)(float sizeInByte);

@protocol IFwFileAbility <NSObject,IFwWearBaseAbility>

-(void)getDevFileListWithWatchFilePath:(NSString*)watchFilePath block:(FwFileListCallback)block;
-(void)pushFileToDevWithLocalPath:(NSString*)localPath remotePath:(NSString*)remotePath block:(onProgressResult)block;
-(void)delFileWithFolder:(NSString*)watchFolder fileName:(NSString*)fileName block:(FwSendMsgResult)block;
-(void)delFileWithWholePath:(NSString*)wholePath block:(FwSendMsgResult)block;
///@param fileName -文件名，不是全路径
-(void)cancelPushWithFileName:(NSString*)fileName;
-(void)getDevFileTreeWithWatchFilePath:(NSString*)watchFilePath block:(FwFileListCallback)block;
-(void)notifyDevAfterUpdate:(FwFileUpdateModel*)model remoteAppId:(NSString*)remoteAppId;
-(void)getDirSizeInfo:(NSString*)remoteFolder block:(FwFileSizeCallback)block;
-(void)pullFileWithRemotePath:(NSString*)remotePath localPath:(NSString*)localPath block:(onProgressResult)block;
/**
 取消拉取文件
 @param fileName -文件名，不是全路径
 */
-(void)cancelPullWithFileName:(NSString*)fileName;

@end


#endif /* IWearFileSync_h */
