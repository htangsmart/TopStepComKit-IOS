//
//  ITPSUserInfoAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/6/24.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSUserInfoModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TPSUserInfoModel;

@protocol ITPSUserInfoAbility <NSObject,ITPSWearBaseAbility>

+ (instancetype)share;

- (TPSUserInfoModel *)userInfoModel;


/*
 * @brief   获取用户年龄
 */
- (void)queryUserAgeSuccess:(void(^)(NSInteger age))success;
/*
 * @brief   设置用户年龄
 *
 * @param   age 年龄
 */
- (void)setUserAge:(NSInteger)age success:(TPSResultBlock)success;

/*
 * @brief   获取用户身高
 */
- (void)queryUserHeightSuccess:(void(^)(CGFloat height))success;
/*
 * @brief   设置用户身高
 *
 * @param   height 身高
 */
- (void)setUserHeight:(CGFloat)height success:(TPSResultBlock)success;

/*
 * @brief   获取用户体重
 */
- (void)queryUserWeightSuccess:(void(^)(NSInteger age))success;
/*
 * @brief   设置用户体重
 *
 * @param   weight 体重
 */
- (void)setUserWeight:(CGFloat)weight success:(TPSResultBlock)success;

/*
 * @brief   获取用户性别  0 女性 1 男性
 */
- (void)queryUserGenderSuccess:(void(^)(NSInteger age))success;
/*
 * @brief   设置用户性别
 *
 * @param   agender 性别  0 女性 1 男性
 */
- (void)setUserGender:(NSInteger)agender success:(TPSResultBlock)success;


/*
 * @brief   获取用户信息
 */
- (void)queryUserInfoSuccess:(void(^)(TPSUserInfoModel *userinfoModel))success;
/*
 * @brief   设置用户信息
 *
 * @param   userInfo 用户信息模型
 */
- (void)setUserInfo:(TPSUserInfoModel *)userInfo success:(TPSResultBlock)success;

@end

NS_ASSUME_NONNULL_END
