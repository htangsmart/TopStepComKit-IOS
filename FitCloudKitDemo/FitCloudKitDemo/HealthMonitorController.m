//
//  HealthMonitorController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/31.
//  Copyright © 2019 HetangSmart. All rights reserved.
//  健康监控设置 --- Health Monitor Settings

#import "HealthMonitorController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface HealthMonitorController ()
@property (weak, nonatomic) IBOutlet UILabel *configLabel;
- (IBAction)OnGoBack:(id)sender;
@end

@implementation HealthMonitorController

- (void)viewDidLoad {
    
    
    
    [super viewDidLoad];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    __weak typeof(self) weakSelf = self;
    if (indexPath.row == 0) {
        // 获取心率监测配置 --- Fetch Heart Rate Monitor Settings
        [TPSSdk.share.heartRateDataAbility getHrConfig:^(TPSHrConfigModel * _Nullable configModel, NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                weakSelf.configLabel.text = configModel.debugDescription;
                ConsoleResultToastTip(weakSelf.view);
            });
            XLOG_INFO(@"Heart Rate --- autoMonitorEnable:%d autoMonitorInterval:%d autoMonitorStartTime:%d, autoMonitorEndTime:%d sportAlarmEnable:%d maxSportAlarmHr:%d restAlarmEnable:%d maxRestAlarmHr:%d", configModel.autoMonitorEnable, configModel.autoMonitorInterval, configModel.autoMonitorStartTime, configModel.autoMonitorEndTime, configModel.sportAlarmEnable, configModel.maxSportAlarmHr, configModel.restAlarmEnable, configModel.maxRestAlarmHr);
        }];
    } else if (indexPath.row == 1) {
        // 设置心率监测配置 --- Do Heart Rate Monitor Settings
        TPSHrConfigModel *model = [TPSHrConfigModel new];
        
        model.autoMonitorEnable = YES;
        model.autoMonitorStartTime = 360;
        model.autoMonitorEndTime = 1200;
        model.autoMonitorInterval = 30;

        model.sportAlarmEnable = YES;
        model.maxSportAlarmHr = 180;
        model.minSportAlarmHr = 90;

        model.restAlarmEnable = YES;
        model.maxRestAlarmHr = 120;
        model.minRestAlarmHr = 50;

        [TPSSdk.share.heartRateDataAbility setHrConfig:model block:^(BOOL isSendOK) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (isSendOK) {
                    OpResultToastTip(weakSelf.view, YES);
                } else {
                    OpResultToastTip(weakSelf.view, NO);
                }
            });
        }];
    } else if (indexPath.row == 2) {
        // 获取血氧监测配置 --- Fetch Spo2 Monitor Settings
        
        [TPSSdk.share.spo2Ability getSpo2Config:^(TPSSpo2ConfigModel * _Nullable configModel, NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                weakSelf.configLabel.text = configModel.debugDescription;
                ConsoleResultToastTip(weakSelf.view);
            });
            XLOG_INFO(@"Spo2 --- autoMonitorEnable: %d autoMonitorStartTime: %d autoMonitorEndTime：%d autoMonitorInterval: %d",
                      configModel.autoMonitorEnable,
                      configModel.autoMonitorStartTime,
                      configModel.autoMonitorEndTime,
                      configModel.autoMonitorInterval);
        }];
    } else if (indexPath.row == 3) {
        // 设置血氧监测配置 --- Do Spo2 Monitor Settings
        TPSSpo2ConfigModel *model = [TPSSpo2ConfigModel new];
        model.autoMonitorEnable = YES;
        model.autoMonitorStartTime = 600;
        model.autoMonitorEndTime = 1200;
        model.autoMonitorInterval = 1;
//        model.alarmEnable = YES;
//        model.maxAlarmSpo2 = 99;
//        model.minAlarmSpo2 = 90;
//        model.restAlarmEnable = YES;
//        model.maxRestAlarmSpo2 = 99;
//        model.minRestAlarmSpo2 = 90;
        [TPSSdk.share.spo2Ability setSpo2Config:model block:^(BOOL isSendOK) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (isSendOK) {
                    OpResultToastTip(weakSelf.view, YES);
                } else {
                    OpResultToastTip(weakSelf.view, NO);
                }
            });
        }];
    } else if (indexPath.row == 4) {
        // 获取压力监测配置 --- Fetch Stress Monitor Settings
        [TPSSdk.share.stressDataAbility getHrConfig:^(TPSStressConfigModel * _Nullable configModel, NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                weakSelf.configLabel.text = configModel.debugDescription;

                ConsoleResultToastTip(weakSelf.view);
            });
            XLOG_INFO(@"Stress --- autoMonitorEnable: %d autoMonitorStartTime: %d autoMonitorEndTime：%d autoMonitorInterval: %d", configModel.autoMonitorEnable, configModel.autoMonitorStartTime, configModel.autoMonitorEndTime, configModel.autoMonitorInterval);
        }];
    } else if (indexPath.row == 5) {
        // 设置压力监测配置 --- Do Stress Monitor Settings
        TPSStressConfigModel *model = [TPSStressConfigModel new];
        model.autoMonitorEnable = YES;
        model.autoMonitorStartTime = 600;
        model.autoMonitorEndTime = 1200;
        model.autoMonitorInterval = 1;
//        model.alarmEnable = YES;
//        model.maxAlarmStress = 100;
//        model.minAlarmStress = 60;
//        model.restAlarmEnable = YES;
//        model.maxRestAlarmStress = 80;
//        model.minRestAlarmStress = 40;
        [TPSSdk.share.stressDataAbility setHrConfig:model block:^(BOOL isSendOK) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (isSendOK) {
                    OpResultToastTip(weakSelf.view, YES);
                } else {
                    OpResultToastTip(weakSelf.view, NO);
                }
            });
        }];
    } else if (indexPath.row == 6) {
        [TPSSdk.share.temperatureAbility getTempConfigWithBlock:^(TPSTempConfigModel * _Nullable configModel, NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                weakSelf.configLabel.text = configModel.debugDescription;
                ConsoleResultToastTip(weakSelf.view);
            });
            XLOG_INFO(@"Temperature --- autoMonitorEnable: %d autoMonitorStartTime: %ld autoMonitorEndTime：%ld autoMonitorInterval: %ld", configModel.isEnable, (long)configModel.startTime, (long)configModel.endTime, (long)configModel.interval);

        }];
    } else if (indexPath.row == 7) {
        
        TPSTempConfigModel *model = [TPSTempConfigModel new];
        model.enable = YES;
        model.startTime = 600;
        model.endTime = 1200;
        model.interval = 5;
        [TPSSdk.share.temperatureAbility setTempConfig:model block:^(BOOL isSendOK, NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (isSendOK) {
                    OpResultToastTip(weakSelf.view, YES);
                } else {
                    OpResultToastTip(weakSelf.view, NO);
                }
            });
        }];
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
