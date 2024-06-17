//
//  SettingsController.m
//  FitCloudKitDemo
//
//  Created by Zhuanz on 2024/6/13.
//  Copyright © 2024 HetangSmart. All rights reserved.
//  设置 --- Settings

#import "SettingsController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface SettingsController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation SettingsController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    __weak typeof(self) weakSelf = self;
    if (indexPath.row == 0) {
        // 语言 --- Language
        TPSLanguageModel *model = [[TPSLanguageModel alloc] initWithName:@"en"];
        [[TPSSdk.share.languageSettingAbility setCurrentLangue:model] subscribeNext:^(id  _Nullable x) {
            OpResultToastTip(weakSelf.view, YES);
        } error:^(NSError * _Nullable error) {
            OpResultToastTip(weakSelf.view, NO);
        }];
    } else if (indexPath.row == 1) {
        // 穿戴手(左手) --- Wear Hand (left)
//        [TPSSdk.share.miscSettingAbility sendHabit_wear_hand:TPSMiscSettingModel_Wear_Hand_Left];
//        OpResultToastTip(self.view, YES);
    } else if (indexPath.row == 2) {
        // 穿戴手(右手) --- Wear Hand (right)
//        [TPSSdk.share.miscSettingAbility sendHabit_wear_hand:TPSMiscSettingModel_Wear_Hand_Right];
//        OpResultToastTip(self.view, YES);
    } else if (indexPath.row == 3) {
        // 增强监测(开) --- Health Enhanced monitoring (open)
        [TPSSdk.share.miscSettingAbility sendHt_health_enhanced:TPSMiscSettingModel_State_Open];
        OpResultToastTip(self.view, YES);
    } else if (indexPath.row == 4) {
        // 增强监测(关) --- Health Enhanced monitoring (close)
        [TPSSdk.share.miscSettingAbility sendHt_health_enhanced:TPSMiscSettingModel_State_Close];
        OpResultToastTip(self.view, YES);
    }
    
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
