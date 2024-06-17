//
//  DialController.m
//  FitCloudKitDemo
//  Created by Zhuanz on 2024/6/15.
//  Copyright © 2024 HetangSmart. All rights reserved.
//  表盘 --- Dial

#import "DialController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface DialController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation DialController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    __weak typeof(self) weakSelf =self;
    if (indexPath.row == 0) {
        [TPSSdk.share.dialAbility getCurrentDial:^(TPSDialModel *model) {
            XLOG_INFO(@"Dial --- dialId: %@", model.dialId);
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(weakSelf.view);
            });
        }];
    } else if (indexPath.row == 1) {
        [TPSSdk.share.dialAbility getAllDialInfo:^(NSArray<TPSDialModel *> *modelList) {
            [modelList enumerateObjectsUsingBlock:^(TPSDialModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                XLOG_INFO(@"Dial --- dialId: %@", obj.dialId);
            }];
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(weakSelf.view);
            });
        }];
    } else if (indexPath.row == 2) {
        [TPSSdk.share.dialAbility changeDialWithDialId:@"3" block:^(BOOL isSendOK) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (isSendOK) {
                    OpResultToastTip(weakSelf.view, YES);
                } else {
                    OpResultToastTip(weakSelf.view, NO);
                }
            });
        }];
    } else if (indexPath.row == 3) {
        [[TPSSdk.share.dialAbility deleteRemoteWatchDialWithName:@"3" block:^(BOOL isSendOK) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (isSendOK) {
                    OpResultToastTip(weakSelf.view, YES);
                } else {
                    OpResultToastTip(weakSelf.view, NO);
                }
            });
        }] subscribeNext:^(id  _Nullable x) {
            XLOG_INFO(@"Dial --- %@", x);
        }];
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
