//
//  TPSRemindDistrubModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/25.
//

#import <Foundation/Foundation.h>


@class FwRemindDistrubModel;
@class FitCloudDNDSetting;

NS_ASSUME_NONNULL_BEGIN

@interface TPSRemindDistrubModel : NSObject

@property (nonatomic,assign) BOOL isEnabled;

@property (nonatomic,assign) double start;

@property (nonatomic,assign) double end;

+ (TPSRemindDistrubModel *)distrubModelWithFWDistrub:(FwRemindDistrubModel *)distrubModel;

// 配置免打扰数据 FitCloudDNDSetting
+ (TPSRemindDistrubModel *)configModelWithDNDSetting:(FitCloudDNDSetting *)dndSet;

//// 851 个性化提醒
//+ (TPSRemindDistrubModel *)configModelWithFitCloudRemind:(FitCloudPersonalizedReminderObject *)remindObject;

- (NSDictionary *)toDictonary;

@end

NS_ASSUME_NONNULL_END
