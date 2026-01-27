//
//  TPSRemindSettingModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/25.
//


#import <Foundation/Foundation.h>
#import <TopStepComKit/TPSRemindDistrubModel.h>

@class FitCloudLSRObject;
@class FitCloudDRObject;

@class WMReminderModel;

NS_ASSUME_NONNULL_BEGIN
@class FitCloudLSRObject;
@class FitCloudDRObject;
@class FitCloudPersonalizedReminderObject;

@interface TPSRemindSettingModel : NSObject

/**
 * @brief Reminder identifier.
 * @chinese 提醒标识符
 *
 * @discussion
 * [EN]: 0 for sedentary reminder, 1 for drinking water reminder, 2 for medication reminder.
 * [CN]: 0表示久坐提醒，1表示喝水提醒，2表示吃药提醒。
 */
@property (nonatomic,assign) NSInteger remindId;

/**
 * @brief Name of the reminder.
 * @chinese 提醒名称
 *
 * @discussion
 * [EN]: Only valid for custom reminder types.
 * [CN]: 只有自定义类型的提醒才有效。
 */
@property (nonatomic,strong) NSString * name;

/**
 * @brief Enable status of the reminder.
 * @chinese 提醒启用状态
 *
 * @discussion
 * [EN]: true for enabled, false for disabled.
 * [CN]: true表示开启，false表示关闭。
 */
@property (nonatomic,assign) BOOL isEnabled;

/**
 * @brief Type of the reminder.
 * @chinese 提醒类型
 *
 * @discussion
 * [EN]: 0 for fixed time, 1 for fixed interval.
 * [CN]: 0表示固定时间，1表示固定间隔。
 */
@property (nonatomic,assign) NSInteger type;

/**
 * @brief Array of reminder times.
 * @chinese 提醒时间数组
 *
 * @discussion
 * [EN]: Contains specific times for reminders when type is 0 (fixed time).
 * [CN]: 当提醒类型为0（固定时间）时，包含具体的提醒时间点。
 */
@property (nonatomic,strong) NSArray *times;

/**
 * @brief Start time for interval reminders.
 * @chinese 间隔提醒的开始时间
 *
 * @discussion
 * [EN]: Used when reminder type is 1 (fixed interval). Value is in minutes from midnight, e.g., 690 = 11*60+30, meaning 11:30.
 * [CN]: 当提醒类型为1（固定间隔）时使用。值为从午夜开始的分钟数，例如690=11*60+30，即11:30。
 */
@property (nonatomic,assign) double start;

/**
 * @brief End time for interval reminders.
 * @chinese 间隔提醒的结束时间
 *
 * @discussion
 * [EN]: Used when reminder type is 1 (fixed interval). Value is in minutes from midnight, ending at 23:59.
 * [CN]: 当提醒类型为1（固定间隔）时使用。值为从午夜开始的分钟数，结束于23:59。
 */
@property (nonatomic,assign) double end;

/**
 * @brief Interval in minutes between reminders.
 * @chinese 提醒之间的间隔分钟数
 *
 * @discussion
 * [EN]: Used when reminder type is 1 (fixed interval). Specifies the minutes between consecutive reminders.
 * [CN]: 当提醒类型为1（固定间隔）时使用。指定连续提醒之间的分钟数。
 */
@property (nonatomic,assign) NSInteger interval;

/**
 * @brief Days of the week to repeat the reminder.
 * @chinese 重复提醒的星期几
 *
 * @discussion
 * [EN]: Array of days when reminder should repeat. 0 represents Sunday, 1 represents Monday, etc. Array length must be at least 1.
 * [CN]: 提醒应重复的日期数组。0代表周日，1代表周一，以此类推。数组长度至少为1。
 */
@property (nonatomic,strong) NSArray * repeat;

/**
 * @brief Additional note for the reminder.
 * @chinese 提醒的附加说明
 *
 * @discussion
 * [EN]: Optional text note associated with the reminder.
 * [CN]: 与提醒相关的可选文本说明。
 */
@property (nonatomic,strong) NSString * note;

/**
 * @brief Do not disturb settings for the reminder.
 * @chinese 提醒的勿扰设置
 *
 * @discussion
 * [EN]: Contains settings for when the reminder should not disturb the user.
 * [CN]: 包含提醒不应打扰用户的时间段设置。
 */
@property (nonatomic,strong) TPSRemindDistrubModel *noDisturbe;

/**
 * @brief Convert an array of reminder objects to TPSRemindSettingModel array.
 * @chinese 将提醒对象数组转换为TPSRemindSettingModel数组
 * 
 * @param remindArray 
 * EN: Array of reminder objects to be converted
 * CN: 需要转换的提醒对象数组
 * 
 * @return 
 * EN: Array of TPSRemindSettingModel objects
 * CN: TPSRemindSettingModel对象数组
 */
+ (NSArray *)remindModelArrayWithArray:(NSArray *)remindArray;

/**
 * @brief Convert an array of reminder settings to a dictionary.
 * @chinese 将提醒设置数组转换为字典
 * 
 * @param remindSettingArray 
 * EN: Array of reminder setting objects to be converted
 * CN: 需要转换的提醒设置对象数组
 * 
 * @return 
 * EN: Dictionary containing reminder settings values and changes
 * CN: 包含提醒设置值和变更的字典
 */
+ (NSDictionary *)remindSettingValueWithArray:(NSArray *)remindSettingArray;

/**
 * @brief Convert an array of reminder settings to an array of indices.
 * @chinese 将提醒设置数组转换为索引数组
 * 
 * @param remindSettingArray 
 * EN: Array of reminder setting objects to be converted
 * CN: 需要转换的提醒设置对象数组
 * 
 * @return 
 * EN: Array of reminder indices
 * CN: 提醒索引数组
 */
+ (NSArray *)transferIndexRemindSettingModelToDict:(NSArray *)remindSettingArray;

/**
 * @brief Convert the reminder setting model to a dictionary.
 * @chinese 将提醒设置模型转换为字典
 * 
 * @return 
 * EN: Dictionary representation of the reminder setting model
 * CN: 提醒设置模型的字典表示
 */
- (NSDictionary *)toDictonary;

/**
 * @brief Convert FitCloudLSRObject to TPSRemindSettingModel.
 * @chinese 将FitCloudLSRObject转换为TPSRemindSettingModel
 * 
 * @param srObject 
 * EN: FitCloudLSRObject to be converted
 * CN: 需要转换的FitCloudLSRObject对象
 * 
 * @return 
 * EN: Converted TPSRemindSettingModel object
 * CN: 转换后的TPSRemindSettingModel对象
 */
+ (TPSRemindSettingModel *)toTPSModelWithFCPLSRModel:(FitCloudLSRObject *)srObject;

/**
 * @brief Convert FitCloudDRObject to TPSRemindSettingModel.
 * @chinese 将FitCloudDRObject转换为TPSRemindSettingModel
 * 
 * @param drObject 
 * EN: FitCloudDRObject to be converted
 * CN: 需要转换的FitCloudDRObject对象
 * 
 * @return 
 * EN: Converted TPSRemindSettingModel object
 * CN: 转换后的TPSRemindSettingModel对象
 */
+ (TPSRemindSettingModel *)toTPSModelWithFCPDRModel:(FitCloudDRObject *)drObject;

/**
 * @brief Convert FitCloudPersonalizedReminderObject to TPSRemindSettingModel.
 * @chinese 将FitCloudPersonalizedReminderObject转换为TPSRemindSettingModel
 * 
 * @param remindObject 
 * EN: FitCloudPersonalizedReminderObject to be converted
 * CN: 需要转换的FitCloudPersonalizedReminderObject对象
 * 
 * @return 
 * EN: Converted TPSRemindSettingModel object
 * CN: 转换后的TPSRemindSettingModel对象
 */
+ (TPSRemindSettingModel *)configModelWithFitCloudRemindModel:(FitCloudPersonalizedReminderObject *)remindObject;

/**
 * @brief Configure reminder with Do Not Disturb settings.
 * @chinese 将勿扰数据配置到提醒中
 * 
 * @param remindModel 
 * EN: Reminder model to be configured
 * CN: 需要配置的提醒模型
 * 
 * @param disturbModel 
 * EN: Do Not Disturb model to be applied
 * CN: 需要应用的勿扰模型
 * 
 * @return 
 * EN: Configured TPSRemindSettingModel object
 * CN: 配置后的TPSRemindSettingModel对象
 */
+ (TPSRemindSettingModel *)confRemindWithDNDSet:(TPSRemindSettingModel *)remindModel
                                   andDNDConfig:(TPSRemindDistrubModel *)disturbModel;

/**
 * @brief Convert WMReminderModel (drink reminder) to TPSRemindSettingModel.
 * @chinese 将WMReminderModel（喝水提醒）转换为TPSRemindSettingModel
 * 
 * @param wmRemind 
 * EN: WMReminderModel to be converted
 * CN: 需要转换的WMReminderModel对象
 * 
 * @return 
 * EN: Converted TPSRemindSettingModel object
 * CN: 转换后的TPSRemindSettingModel对象
 */
+ (TPSRemindSettingModel *)remindSettingModelWithWMDrinkModel:(WMReminderModel *)wmRemind;

/**
 * @brief Convert WMReminderModel (sedentary reminder) to TPSRemindSettingModel.
 * @chinese 将WMReminderModel（久坐提醒）转换为TPSRemindSettingModel
 * 
 * @param wmRemind 
 * EN: WMReminderModel to be converted
 * CN: 需要转换的WMReminderModel对象
 * 
 * @return 
 * EN: Converted TPSRemindSettingModel object
 * CN: 转换后的TPSRemindSettingModel对象
 */
+ (TPSRemindSettingModel *)remindSettingModelWithWMSedentarinessModel:(WMReminderModel *)wmRemind;

@end

NS_ASSUME_NONNULL_END
