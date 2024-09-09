//
//  TPSRemindDistrubModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/25.
//

#import <Foundation/Foundation.h>


@class FitCloudDNDSetting;
@class WMNoDisturb;
NS_ASSUME_NONNULL_BEGIN

@interface TPSRemindDistrubModel : NSObject

@property (nonatomic,assign) BOOL isEnabled;
/**
 从当日0点算起的总分钟值，比如早上8:30，该值就为8*60+30=510
 The total minute value calculated from 0:00 on the same day, for example, at 8:30 in the morning, is 8 * 60+30=510
 */
@property (nonatomic,assign) int start;

/**
 从当日0点算起的总分钟值，比如早上8:30，该值就为8*60+30=510
 The total minute value calculated from 0:00 on the same day, for example, at 8:30 in the morning, is 8 * 60+30=510
 */
@property (nonatomic,assign) int end;

// 配置免打扰数据 FitCloudDNDSetting
+ (TPSRemindDistrubModel *)configModelWithDNDSetting:(FitCloudDNDSetting *)dndSet;

//// 851 个性化提醒
//+ (TPSRemindDistrubModel *)configModelWithFitCloudRemind:(FitCloudPersonalizedReminderObject *)remindObject;

- (NSDictionary *)toDictonary;


+ (TPSRemindDistrubModel *)distrubModelWithWMDistrub:(WMNoDisturb *)distrubModel;

@end

NS_ASSUME_NONNULL_END
