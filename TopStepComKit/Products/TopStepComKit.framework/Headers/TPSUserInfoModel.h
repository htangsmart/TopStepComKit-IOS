//
//  TPSUserInfoModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/6/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class  FitCloudUserProfileObject;

typedef NS_ENUM(NSInteger, UserGenderType) {
    UserGenderTypeUnknow = -1,   // 未知
    UserGenderTypeFemale = 0,   // 女
    eUserGenderTypeMale = 1,    // 男
};

@interface TPSUserInfoModel : NSObject

@property (nonatomic,assign) NSInteger userAge;

// 身高，单位cm
@property (nonatomic,assign) CGFloat userHeight;

@property (nonatomic,assign) UserGenderType userGender;
// 体重，单位kg
@property (nonatomic,assign) CGFloat userWeight;

- (FitCloudUserProfileObject *)toTPSModel;

@end

NS_ASSUME_NONNULL_END
