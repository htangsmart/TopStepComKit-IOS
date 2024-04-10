//
//  IWearAlbumSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef ITPSAlbumAbility_h
#define ITPSAlbumAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSAlbumUpdateModel.h>
#import <TopStepComKit/TPSProgressModel.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/ITPSFileAbility.h>

@protocol ITPSAlbumAbility <NSObject, ITPSWearBaseAbility>

+(instancetype)share;

-(void)pushPictureWithLocalPath:(NSString*)localPath catalogName:(NSString*)catalogName fileName:(NSString*)fileName block:(onTPSProgressResult)block;
-(void)delPictureWithCatalogName:(NSString*)catalogName fileName:(NSString*)fileName block:(TPSSendMsgResult)block;
-(void)getMusicFileTreeWithBlock:(TPSFileListCallback)block;
-(void)notifyDevAfterUpdate:(TPSAlbumUpdateModel*)model;

@end


#endif /* IWearAlbumSync_h */
