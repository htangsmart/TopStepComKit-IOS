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
-(void)pushLocalDialWithLocalPath:(NSString*)localPath dialId:(NSString*)dialId block:(FwDialProgressCallback)block;

/*
 * @brief 推送自定义表盘到手表
 */
-(void)pushCustomerDialWithLocalPath:(NSString*)localPath dialId:(NSString*)dialId block:(FwDialProgressCallback)block;

/*
 * @brief  删除云端表盘
 *
 * @param  dialId 表盘名称
 */
-(void)deleteRemoteWatchWithDiaId:(NSString *)dialId block:(FwResultBlock)block;

/*
 * @brief  删除自定义表盘
 *
 * @param  dialName 表盘名称
 */
-(void)deleteCustomerWatchWithDiaName:(NSString *)dialName block:(FwResultBlock)block;


/*
 * @brief 获取手表支持的挂件信息
 */
-(void)requestSupportWidgetListFormWatchSuccess:(void(^)(NSDictionary *result))success faile:(void(^)(NSDictionary *error))faile;

/*
 * @brief 修改自定义表盘位置信息
 */
-(void)setDialFrameInfo:(NSDictionary *)frameInfo block:(FwSendMsgResult)block;

/*
 * @brief 注册表盘被删除事件
 */
- (void)registerWatchDialBeenDeleted:(void(^)(NSString *beDeletedDialId))deletedBlock;

/*
 * @brief 注册表盘被修改事件
 */
- (void)registerWatchDialBeenChanged:(void(^)(NSString *selectedDialId))changedBlock;

/*
 * @brief 取消传输
 */
- (void)cancelPushDialWithName:(NSString *)dialName;

                             
@end


#endif /* IWearAlbumSync_h */
