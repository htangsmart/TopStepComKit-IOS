//
//  TPSUserInfoModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/6/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class  FitCloudUserProfileObject;
@class  FwUserInfoModel;

typedef NS_ENUM(NSInteger, TPSUserGenderType) {
    eTPSUserGenderTypeUnknow = -1,   // 未知
    eTPSUserGenderTypeFemale = 0,   // 女
    eTPSUserGenderTypeMale = 1,    // 男
};

@interface TPSUserInfoModel : NSObject

@property (nonatomic,assign) NSInteger userAge;
// 身高，单位cm
@property (nonatomic,assign) CGFloat userHeight;

@property (nonatomic,assign) TPSUserGenderType userGender;
// 体重，单位kg
@property (nonatomic,assign) CGFloat userWeight;

- (FitCloudUserProfileObject *)toFitModel;

- (FwUserInfoModel *)toFwModel;

+ (instancetype)initWithFwModel:(FwUserInfoModel *)fwModel;

@end

NS_ASSUME_NONNULL_END
