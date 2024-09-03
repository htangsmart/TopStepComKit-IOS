//
//  FwSdk.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/21.
//

#ifndef FwSdk_h
#define FwSdk_h

#import <flywearsdk/IFwConnectorAbility.h>
#import <flywearsdk/IFwFileAbility.h>
#import <flywearsdk/IFwContactAbility.h>
#import <flywearsdk/IFwNotificationEnableAbility.h>
#import <flywearsdk/IFwCardPocketAbility.h>
#import <flywearsdk/IFwEleBookAbility.h>
#import <flywearsdk/IFwAlbumAbility.h>
#import <flywearsdk/IFwMusicAbility.h>
#import <flywearsdk/IFwDialAbility.h>
#import <flywearsdk/IFwFinderAbility.h>
#import <flywearsdk/IFwDevInfoAbility.h>
#import <flywearsdk/IFwMiscSettingAbility.h>
#import <flywearsdk/IFwOTAAbility.h>
#import <flywearsdk/IFwSportTargetAbility.h>
#import <flywearsdk/IFwAlarmAbility.h>
#import <flywearsdk/IFwNavAbility.h>
#import <flywearsdk/IFwWeatherAbility.h>
#import <flywearsdk/IFwCurDayActivityAbility.h>
#import <flywearsdk/IFwActivityDataAbility.h>
#import <flywearsdk/IFwHeartRateDataAbility.h>
#import <flywearsdk/IFwSPO2Ability.h>
#import <flywearsdk/IFwStressDataAbility.h>
#import <flywearsdk/IFwSleepDataAbility.h>
#import <flywearsdk/IFwSportDataAbility.h>
#import <flywearsdk/IFwBloodPressureDataAbility.h>

#import <flywearsdk/IFwRemindSettingAbility.h>
#import <flywearsdk/IFwH5GameAbility.h>
#import <flywearsdk/IFwWorldClockAbility.h>
#import <flywearsdk/IFwPrayAbility.h>

#import <flywearsdk/FwWearFactory.h>
#import <flywearsdk/FwExPeripheral.h>
#import <flywearsdk/FwDevFileDesModel.h>
#import <flywearsdk/FwHistorySleepModel.h>

#import <flywearsdk/IFwFemalHeltheAbility.h>
#import <flywearsdk/IFwLanguageAbility.h>
#import <flywearsdk/IFwHttpAbility.h>
#import <flywearsdk/IFwRemotePhotographyAbility.h>

#import <flywearsdk/IFwUserInfoAbility.h>
#import <flywearsdk/IFwHealthMonitorAbility.h>

@interface FwSdk : NSObject

+(instancetype)share;

-(void)initSdk;

/**
 设备连接相关
 */
@property(nonatomic, strong) id<IFwConnectorAbility> connectorAbility;

/**
 文件传输相关，获取手表指定文件夹的文件列表及向对应文件夹传输文件
 */
@property(nonatomic, strong) id<IFwFileAbility> fileAbility;

/**
 联系人列表相关，增删改查手表的联系人列表
 */
@property(nonatomic, strong) id<IFwContactAbility> contactAbility;

/**
 消息通知相关，指定要不要将类似微信、qq等的消息发送到手表上
 */
@property(nonatomic, strong) id<IFwNotificationEnableAbility> notificationEnableAbility;

/**
 卡包及名片二维码相关。将收款二维码或名片二维码上传到手表及相关管理。
 */
@property(nonatomic, strong) id<IFwCardPocketAbility> cardPocketAbility;

/**
 电子书相关。增删改查手表的电子书列表，及传送电子书（txt格式）到手表
 */
@property(nonatomic, strong) id<IFwEleBookAbility> eleBookAbility;

/**
 相册相关。增删改查手表的相册列表，及传送图片到手表
 */
@property(nonatomic, strong) id<IFwAlbumAbility> albumAbility;

/**
 音乐相关。增删改查手表的音乐列表，及传送音乐到手表
 */
@property(nonatomic, strong) id<IFwMusicAbility> musicAbility;

/**
 表盘相关。增删改查手表的表盘列表，及传送表盘文件到手表
 */
@property(nonatomic, strong) id<IFwDialAbility> dialAbility;

/**
 查找手机手表相关。发送命令后，手表或手机会震动，提醒用户手表或手机在哪里
 */
@property(nonatomic, strong) id<IFwFinderAbility> finderAbility;

/**
 设备基本信息相关。获取设备的版本号、屏幕尺寸等信息
 */
@property(nonatomic, strong) id<IFwDevInfoAbility> devInfoAbility;

/**
 杂设置项相关。常见的一些设置收集，如单位制、是否开启全天心率检测等。
 */
@property(nonatomic, strong) id<IFwMiscSettingAbility> miscSettingAbility;

/**
 OTA相关。
 */
@property(nonatomic, strong) id<IFwOTAAbility> otaAbility;

/**
 运动目标设置。
 */
@property(nonatomic, strong) id<IFwSportTargetAbility> sportTargetAbility;

/**
 闹钟设置。
 */
@property(nonatomic, strong) id<IFwAlarmAbility> alarmAbility;

/**
 导航功能相关。
 */
@property(nonatomic, strong) id<IFwNavAbility> navAbility;

/**
 天气功能相关。
 */
@property(nonatomic, strong) id<IFwWeatherAbility> weatherAbility;

/**
 当日活动数据概览相关。
 */
@property(nonatomic, strong) id<IFwCurDayActivityAbility> curDayActivityAbility;

/**
 活动数据详情概览相关。
 */
@property(nonatomic, strong) id<IFwActivityDataAbility> activityDataAbility;

/**
 心率数据详情概览相关。
 */
@property(nonatomic, strong) id<IFwHeartRateDataAbility> heartRateDataAbility;

/**
 血氧数据详情概览相关。
 */
@property(nonatomic, strong) id<IFwSPO2Ability> spo2Ability;

/**
 压力数据详情概览相关。
 */
@property(nonatomic, strong) id<IFwStressDataAbility> stressDataAbility;

/**
 睡眠数据详情概览相关。
 */
@property(nonatomic, strong) id<IFwSleepDataAbility> sleepDataAbility;

/**
 运动数据详情概览相关。
 */
@property(nonatomic, strong) id<IFwSportDataAbility> sportDataAbility;

/**
 血压数据详情概览相关。
 */
@property(nonatomic, strong) id<IFwBloodPressureDataAbility> bloodPressureDataAbility;

/**
 提醒设置
 */
@property (nonatomic,strong) id<IFwRemindSettingAbility> remindSettingDataAbility;


/**
 体感游戏
 */
@property (nonatomic,strong) id<IFwH5GameAbility> gameAbility;

/**
 女性健康
 */
@property (nonatomic,strong) id<IFwFemalHeltheAbility> femalHeltheAbility;

/**
 世界时钟
 */
@property (nonatomic,strong) id<IFwWorldClockAbility> worldClockAbility;

/**
 祈祷功能
 */
@property (nonatomic,strong) id<IFwPrayAbility> prayAbility;

/**
 语言设置
 */
@property (nonatomic,strong) id<IFwLanguageAbility> languageSettingAbility;

/**
 遥控拍照
 */
@property (nonatomic,strong) id<IFwRemotePhotographyAbility>  remotePhotoAbility;

/**
 http协议中转透传
 */
@property (nonatomic,strong) id<IFwHttpAbility> httpAbility;

@property (nonatomic,strong) id<IFwUserInfoAbility> userInfoAbility;

@property (nonatomic,strong) id<IFwHealthMonitorAbility> healthMonitorAbility;

@end


#endif /* FwSdk_h */
