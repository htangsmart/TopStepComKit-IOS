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

/*
 * @brief 获取当前表盘信息
 */
-(void)getCurrentDial:(TPSDialGetCurDialCallback)block;

/*
 * @brief 获取手表所有表盘
 */
-(void)getAllDialInfo:(TPSGetAllDialCallback)block;

/*
 * @brief 改变当前盘
 */
-(void)changeDialWithDialId:(NSString*)dialId block:(TPSSendMsgResult)block;

/*
 * @brief 推送本地表盘到手表
 */
-(void)pushDialWithLocalPath:(NSString*)localPath dialId:(NSString*)dialId block:(TPSDialProgressCallback)block;

/*
 * @brief  删除手表表盘
 *
 * @param  dialName 表盘名称
 */
-(RACSubject *)deleteRemoteWatchDialWithName:(NSString *)dialName block:(TPSSendMsgResult)block;

/*
 * @brief 获取手表支持的挂件信息
 */
-(void)requestSupportWidgetListFormWatchSuccess:(void(^)(NSDictionary *result))success faile:(void(^)(NSDictionary *error))faile;

/*
 * @brief 修改自定义表盘位置信息
 */
-(void)setDialFrameInfo:(NSDictionary *)frameInfo block:(TPSSendMsgResult)block;

@end


#endif /* IWearAlbumSync_h */
