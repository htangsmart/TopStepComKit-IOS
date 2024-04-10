//
//  IWearDialSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef IWearDialSync_h
#define IWearDialSync_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwDialModel.h>
#import <flywearsdk/FwDialProgressModel.h>
#import <flywearsdk/WearBlockTypeDef.h>

@class RACSubject;

@protocol IFwDialAbility <NSObject, IFwWearBaseAbility>

typedef void(^FwDialProgressCallback)(FwDialProgressModel* model);
typedef void(^FwGetAllDialCallback)(NSArray<FwDialModel*>* modelList);
typedef void(^FwDialGetCurDialCallback)(FwDialModel* model);

+(instancetype)share;


-(void)pushDialWithLocalPath:(NSString*)localPath dialId:(NSString*)dialId block:(FwDialProgressCallback)block;
-(void)getAllDialInfo:(FwGetAllDialCallback)block;
-(void)changeDialWithDialId:(NSString*)dialId block:(FwSendMsgResult)block;
-(void)getCurrentDial:(FwDialGetCurDialCallback)block;

-(RACSubject *)deleteRemoteWatchDialWithName:(NSString *)dialName block:(FwSendMsgResult)block;

@end


#endif /* IWearAlbumSync_h */
