//
//  SedentaryRemindController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/31.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "SedentaryRemindController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface SedentaryRemindController ()

- (IBAction)OnGoBack:(id)sender;

@end

@implementation SedentaryRemindController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0)
    {
        XLOG_INFO(@"\n获取久坐提醒设置...\nGet sedentary reminder settings...");
        // 1.先获取提醒设置 2.获取提醒设置后找出久坐设置
        // 1. Get the reminder settings first
        // 2. After getting the reminder settings, find the sedentary settings
        [TPSSdk.share.remindSettingAbility requestRemindSettingDataFormWatchSuccess:^(NSArray<TPSRemindSettingModel *> * _Nullable remindSettingList) {
            
            if ([remindSettingList isKindOfClass:NSArray.class]) {
                
                __block TPSRemindSettingModel *remindSettingModel;
                [remindSettingList enumerateObjectsUsingBlock:^(TPSRemindSettingModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                   
                    // 0为久坐，1喝水，2吃药
                    // 0 means sitting for a long time,
                    // 1 means drinking water
                    // 2 means taking medicine
                    if (obj.remindId == 0) {
                        
                        remindSettingModel = obj;
                        XLOG_INFO(@"Sedentary Remind Settings:\nisOn:%@\nbegin:%@\nend:%@", @(obj.isEnabled), @(obj.start), @(obj.end));
                    }
                }];
                if (!remindSettingList) {
                    
                    XLOG_INFO(@"\n未找到久坐提醒\nNo sedentary reminder found");
                }
            } else {
                
                XLOG_INFO(@"\n未找到久坐提醒\nNo sedentary reminder found");
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(self.view);
            });
        }];
    }
    else if(indexPath.row == 1)
    {
        
        TPSRemindSettingModel *remindSettingModel = [[TPSRemindSettingModel alloc] init];
        
//        FitCloudLSRObject *settings = [FitCloudLSRObject new];
//        settings.on = true;
//        settings.offWhenLunchBreak = true;
//        settings.begin = 60*9;
//        settings.end = 60*20;
//        [FitCloudKit setSedentaryRemind:settings block:^(BOOL succeed, NSError *error) {
//            
//        }];
        
//        [TPSSdk.share.remindSettingAbility setRemindValueWithValue:<#(NSDictionary * _Nonnull)#> index:<#(NSArray * _Nullable)#> success:<#^(BOOL isSendOK)success#>]
//        
//        dispatch_async(dispatch_get_main_queue(), ^{
//            OpResultToastTip(self.view, succeed);
//        });
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
