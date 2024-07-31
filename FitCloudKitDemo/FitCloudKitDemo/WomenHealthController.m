//
//  WomenHealthController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 7/6/23.
//  Copyright © 2023 HetangSmart. All rights reserved.
//

#import "WomenHealthController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]
@interface WomenHealthController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation WomenHealthController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0){
        TPSUserInfoModel* userinfoModel = [[TPSUserInfoModel alloc] init];
        userinfoModel.userGender = eTPSUserGenderTypeFemale;
        userinfoModel.userWeight = 60;
        userinfoModel.userAge = 18;
        userinfoModel.userHeight = 175;
        [TPSSdk.share.userInfoAbility setUserInfo:userinfoModel success:^(BOOL isSendOK, NSDictionary * _Nullable errorInfo) {
            NSLog(@"setUserInfo SUCCESS");
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(self.view, YES);
            });
        }];
    }else if(indexPath.row == 1){
        [FitCloudKit getWomenHealthSettingWithBlock:^(BOOL succeed, FitCloudWomenHealthSetting *whSetting, NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"getWomenHealthSettingWithBlock %d, %d, %d, %d, %d, %@, %d, %d"
                      , whSetting.mode
                      , whSetting.advanceDaysToRemind  //提前几天提醒，单位：天 --How many days in advance reminder, unit: days
                      , whSetting.offsetMinutesInDayOfRemind  //提醒时间，相对零点的分钟偏移数 --Reminder time, minute offset relative to zero,for example, at 8:30 in the morning, is 8 * 60+30=510
                      , whSetting.mensesDuration //经期长度，单位：天 --Menstrual period length, unit: days
                      , whSetting.menstrualCycle  //月经周期长度，单位：天  --Menstrual cycle length, unit: days
                      , whSetting.recentMenstruationBegin //最近一次经期，格式：yyyy-MM-dd  --Last menstrual period, format: yyyy MM dd
                      , whSetting.daysOfFinishSinceMensesBegin //不为0时表示月经结束日期距离月经开始日期的天数 --Indicates the number of days between the end date of menstruation and the start date of menstruation
                      , whSetting.pregancyRemindType  //孕期提醒方式  --Pregnancy reminder methods
                      );
                OpResultToastTip(self.view, YES);
            });
        }];
    }
    else if(indexPath.row == 2){
        FitCloudWomenHealthSetting *whSetting = [FitCloudWomenHealthSetting settingwithMode:(WOMENHEALTHMODE_MENSES) advanceDaysToRemind:3 offsetMinutesInDayOfRemind:8*60 mensesDuration:5 menstrualCycle:28 recentMenstruationBegin:@"2024-07-12" daysOfFinishSinceMensesBegin:28 pregancyRemindType:PREGNANCYREMINDTYPE_PREGNANTDAYS];
        [FitCloudKit setWomenHealthConfig:whSetting block:^(BOOL succeed, NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if(succeed){
                    NSLog(@"setWomenHealthConfig success");
                }else{
                    NSLog(@"setWomenHealthConfig fail");
                }
                OpResultToastTip(self.view, YES);
            });
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
