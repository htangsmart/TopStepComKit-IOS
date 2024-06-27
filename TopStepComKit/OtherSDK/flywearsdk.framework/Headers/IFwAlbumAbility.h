//
//  IWearAlbumSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef IWearAlbumSync_h
#define IWearAlbumSync_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwAlbumUpdateModel.h>
#import <flywearsdk/FwProgressModel.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/IFwFileAbility.h>

@protocol IFwAlbumAbility <NSObject, IFwWearBaseAbility>

+(instancetype)share;

-(void)pushPictureWithLocalPath:(NSString*)localPath catalogName:(NSString*)catalogName fileName:(NSString*)fileName block:(onProgressResult)block;
-(void)delPictureWithCatalogName:(NSString*)catalogName fileName:(NSString*)fileName block:(FwSendMsgResult)block;
-(void)getMusicFileTreeWithBlock:(FwFileListCallback)block;
-(void)notifyDevAfterUpdate:(FwAlbumUpdateModel*)model;

@end


#endif /* IWearAlbumSync_h */
