//
//  ITFwUserInfoAbility.h
//  flywearsdk
//
//  Created by 磐石 on 2024/7/3.
//

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwUserInfoModel.h>
NS_ASSUME_NONNULL_BEGIN

@protocol IFwUserInfoAbility <NSObject,IFwWearBaseAbility>

/*
 * @brief   获取用户年龄
 */
- (void)queryUserAgeSuccess:(void(^)(NSInteger age))success;
/*
 * @brief   设置用户年龄
 *
 * @param   age 年龄
 */
- (void)setUserAge:(NSInteger)age success:(FwResultBlock)success;

/*
 * @brief   获取用户身高
 */
- (void)queryUserHeightSuccess:(void(^)(CGFloat height))success;
/*
 * @brief   设置用户身高
 *
 * @param   height 身高
 */
- (void)setUserHeight:(CGFloat)height success:(FwResultBlock)success;

/*
 * @brief   获取用户体重
 */
- (void)queryUserWeightSuccess:(void(^)(NSInteger age))success;
/*
 * @brief   设置用户体重
 *
 * @param   weight 体重
 */
- (void)setUserWeight:(CGFloat)weight success:(FwResultBlock)success;

/*
 * @brief   获取用户性别  0 女性 1 男性
 */
- (void)queryUserGenderSuccess:(void(^)(NSInteger age))success;
/*
 * @brief   设置用户性别
 *
 * @param   agender 性别  0 女性 1 男性
 */
- (void)setUserGender:(NSInteger)agender success:(FwResultBlock)success;


/*
 * @brief   获取用户信息
 */
- (void)queryUserInfoSuccess:(void(^)(FwUserInfoModel *userinfoModel))success;
/*
 * @brief   设置用户信息
 *
 * @param   userInfo 用户信息模型
 */
- (void)setUserInfo:(FwUserInfoModel *)userInfo success:(FwResultBlock)success;


@end

NS_ASSUME_NONNULL_END
