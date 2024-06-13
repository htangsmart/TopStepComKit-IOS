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
        // 历史心率
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.heartRateDataAbility getHistoryHeartRate:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryHeartRateModel *> * _Nullable historyHeartRateModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyHeartRateModelList enumerateObjectsUsingBlock:^(TPSHistoryHeartRateModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"timestamp: %ld  heartRate: %d", obj.timestamp, obj.heartRate);
                }];
            }];
        }];
    } else if (indexPath.row == 1) {
        // 历史静息心率
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.heartRateDataAbility getHistoryRestQuietHeartRate:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryHeartRateModel *> * _Nullable historyHeartRateModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyHeartRateModelList enumerateObjectsUsingBlock:^(TPSHistoryHeartRateModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"timestamp: %ld  heartRate: %d", obj.timestamp, obj.heartRate);
                }];
            }];
        }];
    } else if (indexPath.row == 2) {
        // 历史实时心率
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.heartRateDataAbility getHistoryRealTimeHeartRate:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryHeartRateModel *> * _Nullable historyHeartRateModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyHeartRateModelList enumerateObjectsUsingBlock:^(TPSHistoryHeartRateModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"timestamp: %ld  heartRate: %d", obj.timestamp, obj.heartRate);
                }];
            }];
        }];
    } else if (indexPath.row == 3) {
        // 历史血氧
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.spo2Ability getHistorySPO2:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistorySPO2Model *> * _Nullable historySPO2ModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historySPO2ModelList enumerateObjectsUsingBlock:^(TPSHistorySPO2Model * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"record_time: %ld  blood_oxy: %d", obj.record_time, obj.blood_oxy);
                }];
            }];
        }];
    } else if (indexPath.row == 4) {
        // 历史实时血氧
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.spo2Ability getHistoryRealTimeSPO2:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistorySPO2Model *> * _Nullable historySPO2ModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historySPO2ModelList enumerateObjectsUsingBlock:^(TPSHistorySPO2Model * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"record_time: %ld  blood_oxy: %d", obj.record_time, obj.blood_oxy);
                }];
            }];
        }];
    } else if (indexPath.row == 5) {
        // 历史压力
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.stressDataAbility getHistoryStress:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryStressModel *> * _Nullable historyStressModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyStressModelList enumerateObjectsUsingBlock:^(TPSHistoryStressModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"record_time: %ld  stress: %d", obj.record_time, obj.stress);
                }];
            }];
        }];
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
