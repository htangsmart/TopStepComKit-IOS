//
//  HistoryDataController.m
//  FitCloudKitDemo
//
//  Created by Zhuanz on 2024/6/6.
//  Copyright © 2024 HetangSmart. All rights reserved.
//  获取历史数据 --- Get History Data

#import "HistoryDataController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface HistoryDataController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation HistoryDataController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    __weak typeof(self) weakSelf = self;
    if (indexPath.row == 0) {
        // 历史心率 --- History Heart Rate
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.heartRateDataAbility getHistoryHeartRate:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryHeartRateModel *> * _Nullable historyHeartRateModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyHeartRateModelList enumerateObjectsUsingBlock:^(TPSHistoryHeartRateModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"Heart Rate --- timestamp: %ld  heartRate: %d", obj.timestamp, obj.heartRate);
                }];
            }];
        }];
    } else if (indexPath.row == 1) {
        // 历史静息心率 --- History Rest Quiet Heart Rate
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.heartRateDataAbility getHistoryRestQuietHeartRate:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryHeartRateModel *> * _Nullable historyHeartRateModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyHeartRateModelList enumerateObjectsUsingBlock:^(TPSHistoryHeartRateModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"Rest Quiet Heart Rate --- timestamp: %ld  heartRate: %d", obj.timestamp, obj.heartRate);
                }];
            }];
        }];
    } else if (indexPath.row == 2) {
        // 历史实时心率 --- History Realtime Heart Rate
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.heartRateDataAbility getHistoryRealTimeHeartRate:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryHeartRateModel *> * _Nullable historyHeartRateModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyHeartRateModelList enumerateObjectsUsingBlock:^(TPSHistoryHeartRateModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"Realtime Heart Rate --- timestamp: %ld  heartRate: %d", obj.timestamp, obj.heartRate);
                }];
            }];
        }];
    } else if (indexPath.row == 3) {
        // 历史血氧 --- History SPO2
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.spo2Ability getHistorySPO2:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistorySPO2Model *> * _Nullable historySPO2ModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historySPO2ModelList enumerateObjectsUsingBlock:^(TPSHistorySPO2Model * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"SPO2 --- record_time: %ld  blood_oxy: %d", obj.record_time, obj.blood_oxy);
                }];
            }];
        }];
    } else if (indexPath.row == 4) {
        // 历史实时血氧 --- History Realtime SPO2
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.spo2Ability getHistoryRealTimeSPO2:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistorySPO2Model *> * _Nullable historySPO2ModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historySPO2ModelList enumerateObjectsUsingBlock:^(TPSHistorySPO2Model * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"Realtime SPO2 --- record_time: %ld  blood_oxy: %d", obj.record_time, obj.blood_oxy);
                }];
            }];
        }];
    } else if (indexPath.row == 5) {
        // 历史压力 --- History Stress
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.stressDataAbility getHistoryStress:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryStressModel *> * _Nullable historyStressModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyStressModelList enumerateObjectsUsingBlock:^(TPSHistoryStressModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"Stress --- record_time: %ld  stress: %d", obj.record_time, obj.stress);
                }];
            }];
        }];
    } else if (indexPath.row == 6) {
        // 历史活动 --- History Activity
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.activityDataAbility getHistoryActivity:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryActivityModel *> * _Nullable historyActivityModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyActivityModelList enumerateObjectsUsingBlock:^(TPSHistoryActivityModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"Activity --- start_time: %ld  stand: %d  sport: %f", obj.start_time, obj.stand, obj.sport);
                }];
            }];
        }];
    } else if (indexPath.row == 7) {
        // 历史运动 --- History Sport
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.sportDataAbility getHistorySport:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistorySportModel *> * _Nullable historySportModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historySportModelList enumerateObjectsUsingBlock:^(TPSHistorySportModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"Sport --- sport_id: %ld  type: %hhu  device_type: %d", obj.sport_id, obj.type, obj.device_type);
                }];
            }];
        }];
    } else if (indexPath.row == 8) {
        // 历史睡眠 --- History Sleep
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.sleepDataAbility getHistorySleep:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistorySleepModel *> * _Nullable historySleepModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historySleepModelList enumerateObjectsUsingBlock:^(TPSHistorySleepModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"Sleep --- belongDay: %ld  type: %hhu  duration: %d", obj.belongDay, obj.type, obj.duration);
                }];
                
                [TPSSdk.share.sleepDataAbility getDaySleepEntityList:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSDaySleepEntity *> * _Nullable daySleepEntityList) {
                    NSLog(@"sleep analyse data");
                }];
            }];
        }];
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
