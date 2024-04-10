//
//  FwRemindSettingModel.h
//  flywearsdk
//
//  Created by 磐石 on 2024/3/7.
//

#import <Foundation/Foundation.h>
#import <flywearsdk/FwRemindDistrubModel.h>
NS_ASSUME_NONNULL_BEGIN

@interface FwRemindSettingModel : NSObject


@property (nonatomic,assign) NSInteger remindId;//0为久坐，1喝水，2吃药

@property (nonatomic,strong) NSString * name;//只要自定义类型才有效

@property (nonatomic,assign) BOOL isEnabled;// true为开启，false为关闭

@property (nonatomic,assign) NSInteger type; // 提醒类型：0为固定时间，1为固定间隔

@property (nonatomic,strong) NSArray *times;

@property (nonatomic,assign) double start;// 提醒类型为1的时候开始时间，比如690=11*60+30，即11:30。开始0:00开始

@property (nonatomic,assign) double end;// 提醒类型为1的时候结束时间，结束23:59结束

@property (nonatomic,assign) NSInteger interval;//提醒类型为1的时候，间隔分钟数

@property (nonatomic,strong) NSArray * repeat;//重复的日期0代表周日，1代表周一。数组长度至少为1

@property (nonatomic,strong) NSString * note;

@property (nonatomic,strong) FwRemindDistrubModel *noDisturbe;


+ (NSArray *)remindSettingArrayWithItems:(NSDictionary *)itemDict index:(NSDictionary *)indexDict;


@end

NS_ASSUME_NONNULL_END
