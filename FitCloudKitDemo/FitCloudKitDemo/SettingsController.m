//
//  SettingsController.m
//  FitCloudKitDemo
//
//  Created by Zhuanz on 2024/6/13.
//  Copyright © 2024 HetangSmart. All rights reserved.
//  设置 --- Settings

#import <TopStepComKit/TPSLanguageModel.h>

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
        [[TPSSdk.share.languageSettingAbility queryCurrentLanguage] subscribeNext:^(TPSLanguageModel * _Nullable x) {
            NSLog(@"Language is %@",x.name);
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, YES);
            });
        }];
    } else if (indexPath.row == 1) {
        TPSLanguageModel *model = [[TPSLanguageModel alloc] initWithName:@"en"];
        [[TPSSdk.share.languageSettingAbility setCurrentLangue:model] subscribeNext:^(id  _Nullable x) {
            OpResultToastTip(weakSelf.view, YES);
        } error:^(NSError * _Nullable error) {
            OpResultToastTip(weakSelf.view, NO);
        }];
    } else if (indexPath.row == 2) {
        // 穿戴手(左手) --- Wear Hand (left)
        [TPSSdk.share.miscSettingAbility sendHabit_wear_hand:TPSMiscSettingModel_Wear_Hand_Left];
        OpResultToastTip(self.view, YES);
    } else if (indexPath.row == 3) {
        // 穿戴手(右手) --- Wear Hand (right)
        [TPSSdk.share.miscSettingAbility sendHabit_wear_hand:TPSMiscSettingModel_Wear_Hand_Right];
        OpResultToastTip(self.view, YES);
    } else if (indexPath.row == 4) {
        // 增强监测(开) --- Health Enhanced monitoring (open)
        [TPSSdk.share.miscSettingAbility sendHt_health_enhanced:TPSMiscSettingModel_State_Open];
        OpResultToastTip(self.view, YES);
    } else if (indexPath.row == 5) {
        // 增强监测(关) --- Health Enhanced monitoring (close)
        [TPSSdk.share.miscSettingAbility sendHt_health_enhanced:TPSMiscSettingModel_State_Close];
        OpResultToastTip(self.view, YES);
    } else if (indexPath.row == 6) {
        [TPSSdk.share.miscSettingAbility sendHt_sos:TPSMiscSettingModel_State_Open];
        OpResultToastTip(self.view, YES);
    } else if(indexPath.row == 7){
        //勿扰设置。 --Do not distrub setting
        TPSRemindDistrubModel* notDisturbModel = [[TPSRemindDistrubModel alloc] init];
        notDisturbModel.isEnabled = YES;
        notDisturbModel.start = 8*60+30;//8:30 in morning
        notDisturbModel.end = 18*60+30;//18:30 at afternoon
        [TPSSdk.share.remindSettingAbility setNotDistrubConfig:notDisturbModel success:^(BOOL isSendOK) {
            OpResultToastTip(self.view, YES);
        }];
    }else if(indexPath.row == 8){
        //获取勿扰设置。 --get "Do not distrub" setting
        [TPSSdk.share.remindSettingAbility getNotDistrubConfig:^(TPSRemindDistrubModel * _Nullable remindSetting) {
            NSLog(@"getNotDistrubConfig: %d, %d, %d", remindSetting.isEnabled, remindSetting.start, remindSetting.end);
            OpResultToastTip(weakSelf.view, YES);
        }];
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
