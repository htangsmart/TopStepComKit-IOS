//
//  IWearDialSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef ITPSDialAbility_h
#define ITPSDialAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSDialModel.h>
#import <TopStepComKit/TPSDialProgressModel.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

@protocol ITPSDialAbility <NSObject, ITPSWearBaseAbility>

typedef void(^TPSDialProgressCallback)(TPSDialProgressModel* model);
typedef void(^TPSGetAllDialCallback)(NSArray<TPSDialModel*>* modelList);
typedef void(^TPSDialGetCurDialCallback)(TPSDialModel* model);

+(instancetype)share;


-(void)pushDialWithLocalPath:(NSString*)localPath dialId:(NSString*)dialId block:(TPSDialProgressCallback)block;
-(void)getAllDialInfo:(TPSGetAllDialCallback)block;
-(void)changeDialWithDialId:(NSString*)dialId block:(TPSSendMsgResult)block;
-(void)getCurrentDial:(TPSDialGetCurDialCallback)block;

-(RACSubject *)deleteRemoteWatchDialWithName:(NSString *)dialName block:(TPSSendMsgResult)block;


@end


#endif /* IWearAlbumSync_h */
