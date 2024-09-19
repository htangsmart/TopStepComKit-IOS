//
//  WristWakeUpController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/26.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "WristWakeUpController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface WristWakeUpController (){
    BOOL isOn;
}
- (IBAction)OnGoBack:(id)sender;
@end

@implementation WristWakeUpController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    isOn = YES;
    //监听手表抬手腕亮屏设置是否有变化 Monitor whether there is a change in setting ,such as the wrist lifting and screen on setting of the watch
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onFitcloudConfigChange:) name:FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY object:nil];
}

-(void)onFitcloudConfigChange:(NSNotification*)notification{
    NSLog(@"onConfigChange in fitcloud");
    //重新获取抬手腕亮屏设置 Retrieve the wrist lifting screen brightness setting again
    [FitCloudKit getWristWakeUpSettingWithBlock:^(BOOL succeed, FitCloudWWUObject *wwuSetting, NSError *error) {
        //wwuSetting.on;
    }];
    [FitCloudKit getDNDSettingWithBlock:^(BOOL succeed, FitCloudDNDSetting *dndSetting, NSError *error) {
            //重新获取并设置app上的按钮 Retrieve and reset buttons on the app
        NSLog(@"FitCloudDNDSetting come back");
    }];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0)
    {
        FitCloudDNDSetting *dndSetting = [[FitCloudDNDSetting alloc]init];
        dndSetting.on = NO;
        dndSetting.dndPeriodOn = isOn;
        dndSetting.periodBegin = 0;
        dndSetting.periodEnd = 0;
        [FitCloudKit setDND:dndSetting block:^(BOOL succeed, NSError *error) {
            
        }];
        isOn = !isOn;
    }
    else if(indexPath.row == 1)
    {
        [TPSSdk.share.miscSettingAbility sendScreen_raise_to_wake:TPSMiscSettingModel_State_Open];
        OpResultToastTip(self.view, YES);
    }
}



- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
