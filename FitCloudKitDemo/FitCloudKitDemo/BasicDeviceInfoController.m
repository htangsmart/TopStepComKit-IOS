//
//  BasicDeviceInfoController.m
//  FitCloudKitDemo
//
//  Created by Zhuanz on 2024/6/13.
//  Copyright © 2024 HetangSmart. All rights reserved.
//  设备基本信息 --- Basic Device Info

#import "BasicDeviceInfoController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface BasicDeviceInfoController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation BasicDeviceInfoController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 0) {
        // 获取设备基本信息 --- Get Basic Device Info
        __weak typeof(self) weakSelf = self;
        [[TPSSdk.share.devInfoAbility getDevInfo] subscribeNext:^(TPSDevInfoModel * _Nullable x) {
            if ([x isKindOfClass:[TPSDevInfoModel class]]) {
                ConsoleResultToastTip(weakSelf.view);
                XLOG_INFO(@"screenWidth: %f screenHeight: %f jsVersion: %@ firmVersion: %@", x.screenWidth, x.screenHeight, x.jsVersion, x.firmVersion);
            } else {
                OpResultToastTip(weakSelf.view, NO);
            }
        } error:^(NSError * _Nullable error) {
            OpResultToastTip(weakSelf.view, NO);
        }];
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end