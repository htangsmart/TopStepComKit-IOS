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
-(void)pushLocalDialWithDial:(TPSDialModel *)dialModel block:(TPSDialProgressCallback)block;

/*
 * @brief 推送自定义表盘到手表
 */
-(void)pushCustomerDialWithDial:(TPSDialModel *)dialModel block:(TPSDialProgressCallback)block;

/*
 * @brief  删除云端表盘
 *
 * @param  dialId 表盘名称
 */
-(void)deleteRemoteWatchWithDiaId:(NSString *)dialId block:(TPSResultBlock)block;

/*
 * @brief  删除自定义表盘
 *
 * @param  dialName 表盘名称
 */
-(void)deleteCustomerWatchWithDiaName:(NSString *)dialName block:(TPSResultBlock)block;

/*
 * @brief 获取手表支持的挂件信息
 */
-(void)requestSupportWidgetListFormWatchSuccess:(void(^)(NSDictionary *result))success faile:(void(^)(NSDictionary *error))faile;

/*
 * @brief 修改自定义表盘位置信息
 */
-(void)setDialFrameInfo:(NSDictionary *)frameInfo block:(TPSSendMsgResult)block;


/*
 * @brief 注册表盘被删除事件
 */
- (void)registerWatchDialBeenDeleted:(void(^)(NSString *beDeletedDialId))deletedBlock;

/*
 * @brief 注册表盘被修改事件
 */
- (void)registerWatchDialBeenChanged:(void(^)(NSString *selectedDialId))changedBlock;

/*
 * @brief 生成预览图
 */
- (void)previewImageViewWithBackgroundImage:(UIImage *)backgroundImage textImage:(UIImage *)textImage imageSize:(CGSize)imageSize cornerRadius:(CGFloat)cornerRadius complete:(void (^)(BOOL, UIImage *))complete;


@end


#endif /* IWearAlbumSync_h */
