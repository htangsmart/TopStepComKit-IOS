//
//  FwFemalHeltheModel.h
//  flywearsdk
//
//  Created by luigi on 2024/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, FwFemalHeltheMode) {
    /// 关闭
    FwFemalHeltheMode_close = 0,
    /// 月经模式
    FwFemalHeltheMode_menstrual = 1,
    /// 备孕模式
    FwFemalHeltheMode_preparingForPregnancy = 2,
    /// 怀孕模式
    FwFemalHeltheMode_pregnant = 3,
};


@interface FwFemalHeltheModel : NSObject
/// 模式
@property (nonatomic, assign) FwFemalHeltheMode mode;
/// 月经周期天数 17-60天
@property (nonatomic, assign) NSInteger cycle;
///  每个周期中月经持续天数，3-15天
@property (nonatomic, assign) NSInteger duration;
/// 最近一次月经的日期 ISO-Date "2023-12-10"
@property (nonatomic, copy) NSString * latest;
/// 最近一次月经的日期
@property (nonatomic, copy, readonly, nullable) NSDate * lastMenstrualDate;
/// 提前几天开始提醒，仅在mode=1或2时有效。比如提示，月经还有3天开始
@property (nonatomic, assign) NSInteger remindAdvance;
/// 每天提醒时间，比如690=11*60+30，即11:30。
@property (nonatomic, assign) NSInteger remindTime;
/// 提醒类型，仅在mode=3时有效，0，提示已怀孕30天，1提示离预产期还有200天
@property (nonatomic, assign) NSInteger remindType;
/// 月经结束天数,当经期不规律时，指latest所在周期第几天结束月经。
@property (nonatomic, assign) NSInteger menstruationEnd;

+ (FwFemalHeltheModel *)femalHeltheJsonToObject:(NSDictionary *)json;
- (NSDictionary *)toFemalHeltheJson;
+ (FwFemalHeltheModel *)getDefaultModel;
@end

NS_ASSUME_NONNULL_END
