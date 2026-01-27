//
//  TPSPrayConfigs.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/4/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TPSPrayConfigs : NSObject

/**
 * @brief Enable/disable prayer function
 * @chinese 启用/禁用祈祷功能
 *
 * @discussion
 * [EN]: Master switch for the prayer function. When set to NO, all prayer reminders will be disabled regardless of their individual settings.
 * [CN]: 祈祷功能的总开关。当设置为NO时，所有祈祷提醒将被禁用，无论它们各自的设置如何。
 */
@property (nonatomic,assign) BOOL prayEnable;

/**
 * @brief Enable/disable Fajr prayer reminder
 * @chinese 启用/禁用晨礼(Fajr)提醒
 *
 * @discussion
 * [EN]: Controls whether to receive reminders for Fajr prayer (dawn prayer).
 * [CN]: 控制是否接收晨礼(黎明祈祷)的提醒。
 *
 * @note
 * [EN]: This setting is only effective when prayEnable is set to YES.
 * [CN]: 此设置仅在prayEnable设置为YES时有效。
 */
@property (nonatomic,assign) BOOL fajrReminderEnable;

/**
 * @brief Enable/disable Dhuhr prayer reminder
 * @chinese 启用/禁用晌礼(Dhuhr)提醒
 *
 * @discussion
 * [EN]: Controls whether to receive reminders for Dhuhr prayer (noon prayer).
 * [CN]: 控制是否接收晌礼(正午祈祷)的提醒。
 *
 * @note
 * [EN]: This setting is only effective when prayEnable is set to YES.
 * [CN]: 此设置仅在prayEnable设置为YES时有效。
 */
@property (nonatomic,assign) BOOL dhuhrReminderEnable;

/**
 * @brief Enable/disable Asr prayer reminder
 * @chinese 启用/禁用晡礼(Asr)提醒
 *
 * @discussion
 * [EN]: Controls whether to receive reminders for Asr prayer (afternoon prayer).
 * [CN]: 控制是否接收晡礼(下午祈祷)的提醒。
 *
 * @note
 * [EN]: This setting is only effective when prayEnable is set to YES.
 * [CN]: 此设置仅在prayEnable设置为YES时有效。
 */
@property (nonatomic,assign) BOOL asrReminderEnable;

/**
 * @brief Enable/disable Maghrib prayer reminder
 * @chinese 启用/禁用昏礼(Maghrib)提醒
 *
 * @discussion
 * [EN]: Controls whether to receive reminders for Maghrib prayer (sunset prayer).
 * [CN]: 控制是否接收昏礼(日落祈祷)的提醒。
 *
 * @note
 * [EN]: This setting is only effective when prayEnable is set to YES.
 * [CN]: 此设置仅在prayEnable设置为YES时有效。
 */
@property (nonatomic,assign) BOOL maghribReminderEnable;

/**
 * @brief Enable/disable Isha prayer reminder
 * @chinese 启用/禁用宵礼(Isha)提醒
 *
 * @discussion
 * [EN]: Controls whether to receive reminders for Isha prayer (night prayer).
 * [CN]: 控制是否接收宵礼(夜间祈祷)的提醒。
 *
 * @note
 * [EN]: This setting is only effective when prayEnable is set to YES.
 * [CN]: 此设置仅在prayEnable设置为YES时有效。
 */
@property (nonatomic,assign) BOOL ishabReminderEnable;


@end

NS_ASSUME_NONNULL_END
