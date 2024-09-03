//
//  flywearsdk.h
//  flywearsdk
//
//  Created by Topstep on 2024/2/23.
//

#import <Foundation/Foundation.h>


//! Project version number for flywearsdk.
FOUNDATION_EXPORT double flywearsdkVersionNumber;

//! Project version string for flywearsdk.
FOUNDATION_EXPORT const unsigned char flywearsdkVersionString[];

//#import "FwBleManager2.h"
//#impport <FwBleManager.h>
//#import <persimwearSDK/persimwearSDK.h>

// In this header, you should import all the public headers of your framework using statements like #import <flywearsdk/PublicHeader.h>
#import <flywearsdk/Fw_Tools.h>
#import <flywearsdk/FwSdk.h>
#import <flywearsdk/FwExPeripheral.h>
#import <flywearsdk/IFwConnectorAbility.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwConnectResult.h>
#import <flywearsdk/FwExtraConnectParam.h>
#import <flywearsdk/FwScanResult.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/IFwFileAbility.h>
#import <flywearsdk/FwProgressModel.h>
#import <flywearsdk/FwFileUpdateModel.h>
#import <flywearsdk/IFwContactAbility.h>
#import <flywearsdk/FwContactModel.h>
#import <flywearsdk/IFwNotificationEnableAbility.h>
#import <flywearsdk/FwNotificationEnableModel.h>
#import <flywearsdk/FwDevFileDesModel.h>


#import <flywearsdk/FwWalletModel.h>
#import <flywearsdk/FwNameCardModel.h>
#import <flywearsdk/IFwCardPocketAbility.h>

#import <flywearsdk/IFwEleBookAbility.h>
#import <flywearsdk/FwEBookModel.h>
#import <flywearsdk/FwEBookUpdateModel.h>

#import <flywearsdk/IFwAlbumAbility.h>
#import <flywearsdk/FwAlbumUpdateModel.h>
#import <flywearsdk/IFwMusicAbility.h>
#import <flywearsdk/FwMusicUpdateModel.h>
#import <flywearsdk/FwMusicModel.h>
#import <flywearsdk/IFwDialAbility.h>
#import <flywearsdk/FwDialModel.h>
#import <flywearsdk/FwDialProgressModel.h>

#import <flywearsdk/IFwFinderAbility.h>
#import <flywearsdk/IFwDevInfoAbility.h>
#import <flywearsdk/FwDevInfoModel.h>
#import <flywearsdk/IFwMiscSettingAbility.h>
#import <flywearsdk/FwMiscSettingModel.h>
#import <flywearsdk/IFwOTAAbility.h>
#import <flywearsdk/IFwSportTargetAbility.h>
#import <flywearsdk/FwSportTargetModel.h>
#import <flywearsdk/IFwAlarmAbility.h>
#import <flywearsdk/FwAlarmModel.h>

#import <flywearsdk/IFwNavAbility.h>
#import <flywearsdk/IFwWeatherAbility.h>
#import <flywearsdk/FwWeatherModel.h>
#import <flywearsdk/FwWeatherDescribeType.h>
#import <flywearsdk/FwFutureDayWeatherModel.h>
#import <flywearsdk/FwFutureHourWeatherModel.h>
#import <flywearsdk/FwTodayWeatherModel.h>


#import <flywearsdk/IFwCurDayActivityAbility.h>
#import <flywearsdk/FwCurDayActivityModel.h>

#import <flywearsdk/IFwActivityDataAbility.h>
#import <flywearsdk/FwHistoryActivityModel.h>
#import <flywearsdk/IFwHeartRateDataAbility.h>
#import <flywearsdk/FwHistoryHeartRateModel.h>

#import <flywearsdk/IFwSPO2Ability.h>
#import <flywearsdk/FwHistorySPO2Model.h>

#import <flywearsdk/IFwStressDataAbility.h>
#import <flywearsdk/FwHistoryStressModel.h>

#import <flywearsdk/FwRemindSettingModel.h>
#import <flywearsdk/FwRemindDistrubModel.h>
#import <flywearsdk/IFwRemindSettingAbility.h>

#import <flywearsdk/IFwH5GameAbility.h>
#import <flywearsdk/FwH5GameModel.h>

#import <flywearsdk/IFwLanguageAbility.h>
#import <flywearsdk/FwLanguageModel.h>
#import <flywearsdk/FwLanguageAbility.h>

#import <flywearsdk/IFwSleepDataAbility.h>
#import <flywearsdk/FwHistorySleepModel.h>
#import <flywearsdk/IFwSportDataAbility.h>
#import <flywearsdk/FwHistorySportModel.h>
#import <flywearsdk/IFwBloodPressureDataAbility.h>
#import <flywearsdk/FwHistoryBloodPressureModel.h>
#import <flywearsdk/FwBloodPressureConfigModel.h>

#import <flywearsdk/FwWearFactory.h>

#import <flywearsdk/FwWorldClockModel.h>
#import <flywearsdk/IFwWorldClockAbility.h>

#import <flywearsdk/FwFemalHeltheModel.h>
#import <flywearsdk/IFwFemalHeltheAbility.h>
#import <flywearsdk/FwPrayModel.h>
#import <flywearsdk/FwDayPrayModel.h>
#import <flywearsdk/IFwPrayAbility.h>

#import <flywearsdk/IFwRemotePhotographyAbility.h>


#import <flywearsdk/FwHrConfigModel.h>
#import <flywearsdk/FwStressConfigModel.h>
#import <flywearsdk/FwSpo2ConfigModel.h>
#import <flywearsdk/FwSportItemModel.h>

#import <flywearsdk/FwWebRequestModel.h>
#import <flywearsdk/FwWebResponseModel.h>
#import <flywearsdk/IFwHttpAbility.h>

#import <flywearsdk/FwUserInfoModel.h>
#import <flywearsdk/IFwUserInfoAbility.h>

#import <flywearsdk/IFwHealthMonitorAbility.h>

#import <flywearsdk/FwSportPreciseModel.h>
#import <flywearsdk/FwSportPreciseHeartRateItem.h>
#import <flywearsdk/FwSportPreciseCaloriesItem.h>
#import <flywearsdk/FwSportPreciseDistanceItem.h>
#import <flywearsdk/FwSportPreciseStepItem.h>


