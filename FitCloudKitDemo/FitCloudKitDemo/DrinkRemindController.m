//
//  DrinkRemindController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/31.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DrinkRemindController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface DrinkRemindController ()

- (IBAction)OnGoBack:(id)sender;

@end

@implementation DrinkRemindController

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
        XLOG_INFO(@"\n获取喝水提醒设置...\nGet drinking reminder settings...");
        // 1.先获取提醒设置 2.获取提醒设置后找出久坐设置
        // 1. Get the reminder settings first
        // 2. After getting the reminder settings, find the sedentary settings
        [TPSSdk.share.remindSettingAbility requestRemindSettingDataFormWatchSuccess:^(NSArray<TPSRemindSettingModel *> * _Nullable remindSettingList) {
            if (!remindSettingList) {
                XLOG_INFO(@"\n未找到喝水提醒\nNo drinking reminder found");
                return;
            }
            if ([remindSettingList isKindOfClass:NSArray.class]) {
                __block TPSRemindSettingModel *remindSettingModel;
                [remindSettingList enumerateObjectsUsingBlock:^(TPSRemindSettingModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                   
                    // 0为久坐，1喝水，2吃药
                    // 0 means sitting for a long time,
                    // 1 means drinking water
                    // 2 means taking medicine
                    if (obj.remindId == 1) {
                        
                        remindSettingModel = obj;
                        XLOG_INFO(@"Drinking Remind Settings:\nisOn:%@\nbegin:%@\nend:%@", @(obj.isEnabled), @(obj.start), @(obj.end));
                    }
                }];
            } else {
                XLOG_INFO(@"\n未找到喝水提醒\nNo drinking reminder found");
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(self.view);
            });
        }];
    }
    else if(indexPath.row == 1)
    {
        [TPSSdk.share.remindSettingAbility requestRemindSettingDataFormWatchSuccess:^(NSArray<TPSRemindSettingModel *> * _Nullable remindSettingList) {
            if (!remindSettingList) {
                XLOG_INFO(@"\n未找到喝水提醒\nNo drinking reminder found");
                return;
            }
            
            NSMutableArray<TPSRemindSettingModel *> *remindSettingMutList = [remindSettingList mutableCopy];
            __block BOOL isFound = NO;
            __block TPSRemindSettingModel *remindSettingModel;
            [remindSettingMutList enumerateObjectsUsingBlock:^(TPSRemindSettingModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
               
                // 0为久坐，1喝水，2吃药
                // 0 means sitting for a long time,
                // 1 means drinking water
                // 2 means taking medicine
                if (obj.remindId == 1) {
                    isFound = YES;
                    remindSettingModel = obj;
                    XLOG_INFO(@"Drinking Remind Settings:\nisOn:%@\nbegin:%@\nend:%@", @(obj.isEnabled), @(obj.start), @(obj.end));
                }
            }];
            
            if (isFound) {
                remindSettingModel.isEnabled = YES;
                remindSettingModel.type = 1;
                remindSettingModel.start = 0;
                remindSettingModel.end = 1440;
                remindSettingModel.interval = 1;
                remindSettingModel.repeat = @[@1, @2, @3, @4, @5];
            } else {
                TPSRemindSettingModel *remindSettingModel = [[TPSRemindSettingModel alloc] init];
                remindSettingModel.remindId = 1;
                remindSettingModel.isEnabled = YES;
                remindSettingModel.type = 1;
                remindSettingModel.start = 0;
                remindSettingModel.end = 1440;
                remindSettingModel.interval = 1;
                remindSettingModel.repeat = @[@1, @2, @3, @4, @5];
                [remindSettingMutList addObject:remindSettingModel];
            }
            NSArray *indexArray = [TPSRemindSettingModel transferIndexRemindSettingModelToDict:remindSettingMutList];
            NSDictionary *valueDict = [TPSRemindSettingModel remindSettingValueWithArray:remindSettingMutList];
            XLOG_INFO(@"indexArray --- %@", indexArray);
            XLOG_INFO(@"valueDict --- %@",valueDict);
            
            [TPSSdk.share.remindSettingAbility setRemindValueWithValue:valueDict index:indexArray success:^(BOOL isSendOK) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    if (isSendOK) {
                        OpResultToastTip(self.view, YES);
                    } else {
                        OpResultToastTip(self.view, NO);
                    }
                });
            }];
        }];
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
