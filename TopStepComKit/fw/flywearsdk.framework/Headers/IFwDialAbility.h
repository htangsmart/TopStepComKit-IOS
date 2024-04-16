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


/*
 * @brief 获取当前表盘信息
 */
-(void)getCurrentDial:(FwDialGetCurDialCallback)block;

/*
 * @brief 获取手表所有表盘
 */
-(void)getAllDialInfo:(FwGetAllDialCallback)block;

/*
 * @brief 改变当前盘
 */
-(void)changeDialWithDialId:(NSString*)dialId block:(FwSendMsgResult)block;

/*
 * @brief 推送本地表盘到手表
 */
-(void)pushDialWithLocalPath:(NSString*)localPath dialId:(NSString*)dialId block:(FwDialProgressCallback)block;

/*
 * @brief  删除手表表盘
 *
 * @param  dialName 表盘名称
 */
-(RACSubject *)deleteRemoteWatchDialWithName:(NSString *)dialName block:(FwSendMsgResult)block;

/*
 * @brief 获取手表支持的挂件信息
 */
-(void)requestSupportWidgetListFormWatchSuccess:(void(^)(NSDictionary *result))success faile:(void(^)(NSDictionary *error))faile;

/*
 * @brief 修改自定义表盘位置信息
 */
-(void)setDialFrameInfo:(NSDictionary *)frameInfo block:(FwSendMsgResult)block;

@end


#endif /* IWearAlbumSync_h */
