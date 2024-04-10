//
//  IWearMusicSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef IWearMusicSync_h
#define IWearMusicSync_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwMusicUpdateModel.h>
#import <flywearsdk/IFwFileAbility.h>
#import <flywearsdk/FwMusicModel.h>

@protocol IFwMusicAbility <NSObject, IFwWearBaseAbility>

typedef void(^FwMusicListCallback)(NSArray<FwMusicModel*> * musicList);

+(instancetype)share;

-(void)getMusicListWithblock:(FwMusicListCallback)block;

-(void)pushMusicToDevWithPhoneFilePath:(NSString*)phoneFilePath remoteFileName:(NSString*)remoteFileName block:(onProgressResult)block;
-(void)delMusicWithFileName:(NSString*)fileName block:(FwSendMsgResult)block;
///@param fileName -文件名，不是全路径
-(void)cancelPushMusicWithFileName:(NSString*)fileName;

@end


#endif /* IWearAlbumSync_h */
