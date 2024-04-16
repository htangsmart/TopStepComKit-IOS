//
//  IWearMusicSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef ITPSMusicAbility_h
#define ITPSMusicAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSMusicUpdateModel.h>
#import <TopStepComKit/ITPSFileAbility.h>
#import <TopStepComKit/TPSMusicModel.h>

@protocol ITPSMusicAbility <NSObject, ITPSWearBaseAbility>

typedef void(^TPSMusicListCallback)(NSArray<TPSMusicModel*> * musicList);

+(instancetype)share;

-(void)getMusicListWithblock:(TPSMusicListCallback)block;
-(void)pushMusicToDevWithPhoneFilePath:(NSString*)phoneFilePath remoteFileName:(NSString*)remoteFileName block:(onTPSProgressResult)block;
-(void)delMusicWithFileName:(NSString*)fileName block:(TPSSendMsgResult)block;
///@param fileName -文件名，不是全路径
-(void)cancelPushMusicWithFileName:(NSString*)fileName;

-(void)musicOnLogMessage:(NSString*)message level:(int)level;

@end


#endif /* IWearAlbumSync_h */
