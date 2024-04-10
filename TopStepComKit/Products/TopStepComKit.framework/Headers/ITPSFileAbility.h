//
//  IWearFileSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef ITPSFileAbility_h
#define ITPSFileAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSProgressModel.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSFileUpdateModel.h>

@class TPSDevFileDesModel;

typedef void(^TPSFileListCallback)(NSArray<TPSDevFileDesModel*> * fileList);
typedef void(^TPSFileSizeCallback)(float sizeInByte);

@protocol ITPSFileAbility <NSObject,ITPSWearBaseAbility>

-(void)getDevFileListWithWatchFilePath:(NSString*)watchFilePath block:(TPSFileListCallback)block;
-(void)pushFileToDevWithLocalPath:(NSString*)localPath remotePath:(NSString*)remotePath block:(onTPSProgressResult)block;
-(void)delFileWithFolder:(NSString*)watchFolder fileName:(NSString*)fileName block:(TPSSendMsgResult)block;
-(void)delFileWithWholePath:(NSString*)wholePath block:(TPSSendMsgResult)block;
///@param fileName -文件名，不是全路径
-(void)cancelPushWithFileName:(NSString*)fileName;
-(void)getDevFileTreeWithWatchFilePath:(NSString*)watchFilePath block:(TPSFileListCallback)block;
-(void)notifyDevAfterUpdate:(TPSFileUpdateModel*)model remoteAppId:(NSString*)remoteAppId;
-(void)getDirSizeInfo:(NSString*)remoteFolder block:(TPSFileSizeCallback)block;

@end


#endif /* IWearFileSync_h */
