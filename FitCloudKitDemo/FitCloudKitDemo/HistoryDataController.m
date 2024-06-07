//
//  HistoryDataController.m
//  FitCloudKitDemo
//
//  Created by Zhuanz密码0000 on 2024/6/6.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

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
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.heartRateDataAbility getHistoryHeartRate:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistoryHeartRateModel *> * _Nullable historyHeartRateModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historyHeartRateModelList enumerateObjectsUsingBlock:^(TPSHistoryHeartRateModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"timestamp: %ld  heartRate: %d", obj.timestamp, obj.heartRate);
                }];
            }];
        }];
    } else if (indexPath.row == 1) {
        [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
            [TPSSdk.share.spo2Ability getHistorySPO2:0 endTime:[[NSDate date] timeIntervalSince1970] block:^(NSArray<TPSHistorySPO2Model *> * _Nullable historySPO2ModelList) {
                ConsoleResultToastTip(weakSelf.view);
                [historySPO2ModelList enumerateObjectsUsingBlock:^(TPSHistorySPO2Model * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"record_time: %ld  blood_oxy: %d", obj.record_time, obj.blood_oxy);
                }];
            }];
        }];
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
