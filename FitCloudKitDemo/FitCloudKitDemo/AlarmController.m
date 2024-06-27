//
//  AlarmController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/24.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AlarmController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface AlarmController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation AlarmController

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
        
        XLOG_INFO(@"\n查询闹钟列表...\nCheck the alarm list...");
        [TPSSdk.share.alarmAbility getAlarmList:^(NSArray<TPSAlarmModel *> * _Nullable alarmList) {
            
            if ([alarmList isKindOfClass:NSArray.class]) {
                
                [alarmList enumerateObjectsUsingBlock:^(TPSAlarmModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                   
                    NSLog(@"alarm info : ID: %d, time: %d:%d, enable: %d, repleat: %d", obj.alarmId, obj.hour, obj.min, obj.enable, obj.repeatOptions);
                }];
            }
            XLOG_INFO(@"\n闹钟列表查询成功 %lu\nAlarm list query successful %lu", (unsigned long)alarmList.count, (unsigned long)alarmList.count);
        }];
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 1)
    {
        
        XLOG_INFO(@"\n添加闹钟...\nAdd an alarm...");
        // 添加闹钟步骤：1.先获取全部的闹钟列表 2.在闹钟列表中添加一个闹钟生成一个新的闹钟列表 3.重新设置闹钟列表，覆盖旧的闹钟列表
        // Steps to add an alarm: 1. Get the list of all alarms first 2. Add an alarm to the alarm list to generate a new alarm list 3. Reset the alarm list to overwrite the old alarm list
        
        // 1.先获取全部的闹钟
        // 1. Get all alarms first
        [TPSSdk.share.alarmAbility getAlarmList:^(NSArray<TPSAlarmModel *> * _Nullable alarmList) {
           
            // 2.在闹钟列表中添加一个闹钟生成一个新的闹钟列表
            // 2. Add an alarm to the alarm list to generate a new alarm list
            
            NSMutableArray *newAlarmList = [[NSMutableArray alloc] initWithArray:[alarmList isKindOfClass:NSArray.class] ? alarmList : @[]];
            [newAlarmList addObject:[self generateModelsQuicklyWithID:(int)newAlarmList.count Hour:10 minute:49 enable:true repeat:(TPSAlarmRepeatFriday | TPSAlarmRepeatSaturday)]];
            
            // 3.重新设置闹钟列表，覆盖旧的闹钟列表
            // 3. Reset the alarm list and overwrite the old alarm list
            [TPSSdk.share.alarmAbility sendAlarmList:[newAlarmList copy] block:^(NSArray *alarmList) {
               
                if (alarmList) {
                    
                    XLOG_INFO(@"\n闹钟添加成功\nAlarm added successfully");
                } else {
                    
                    XLOG_INFO(@"\n闹钟添加失败\nFailed to add alarm");
                }
            }];
        }];
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 2)
    {
        
        XLOG_INFO(@"\n编辑闹钟，修改最后一个闹钟状态...\nEdit Alarm, Modify the last alarm status......");
        // 编辑闹钟步骤：1.先获取全部的闹钟 2.然后找出需要修改的闹钟进行编辑后生成一个新的闹钟列表 3.重新设置闹钟列表，覆盖旧的闹钟列表
        // Steps to edit alarms: 1. Get all alarms first 2. Find the alarm that needs to be modified and edit it to generate a new alarm list 3. Reset the alarm list and overwrite the old alarm list
        
        // 1.先获取全部的闹钟
        // 1.Get all alarms first
        [TPSSdk.share.alarmAbility getAlarmList:^(NSArray<TPSAlarmModel *> * _Nullable alarmList) {
           
            // 2.然后找出需要修改的闹钟进行编辑后生成一个新的闹钟列表，比如修改最后一个闹钟的开关状态
            // 2.Then find the alarm that needs to be modified and edit it to generate a new alarm list, such as changing the switch status of the last alarm.
            
            if ([alarmList isKindOfClass:NSArray.class] && alarmList.count > 0) {
                
                TPSAlarmModel *lastAlarm = alarmList.lastObject;
                lastAlarm.enable = !lastAlarm.enable;
                
                // 3.重新设置闹钟列表，覆盖旧的闹钟列表
                // 3. Reset the alarm list and overwrite the old alarm list
                [TPSSdk.share.alarmAbility sendAlarmList:alarmList block:^(NSArray *alarmList) {
                   
                    if (alarmList) {
                        
                        XLOG_INFO(@"\n闹钟编辑成功\nAlarm edited successfully");
                    } else {
                        
                        XLOG_INFO(@"\n闹钟编辑失败\nAlarm editing failed");
                    }
                }];
            } else {
                
                XLOG_INFO(@"\n修改失败，请先添加闹钟\nModification failed, please add an alarm first");
            }
            
            NSMutableArray *newAlarmList = [[NSMutableArray alloc] initWithArray:[alarmList isKindOfClass:NSArray.class] ? alarmList : @[]];
            if (newAlarmList.count > 0) {
                
            }
            [newAlarmList addObject:[self generateModelsQuicklyWithID:(int)newAlarmList.count Hour:10 minute:20 enable:true repeat:(TPSAlarmRepeatFriday | TPSAlarmRepeatSaturday)]];
            
            // 3.重新设置闹钟列表，覆盖旧的闹钟列表
            // 3. Reset the alarm list and overwrite the old alarm list
            [TPSSdk.share.alarmAbility sendAlarmList:alarmList block:^(NSArray *alarmList) {

                if (alarmList) {

                    XLOG_INFO(@"\n闹钟设置成功\nSet alarm successfully");
                } else {
                    
                    XLOG_INFO(@"\n闹钟设置失败\nFailed to set alarm");
                }
            }];
        }];
        ConsoleResultToastTip(self.view);
    }
}

- (TPSAlarmModel *)generateModelsQuicklyWithID:(int)ID Hour:(int)hour minute:(int)min enable:(BOOL)enable repeat:(TPSAlarmRepeat)repeat {
    
    TPSAlarmModel *model = [[TPSAlarmModel alloc] init];
    model.hour = hour;
    model.min = min;
    model.enable = enable;
    model.repeatOptions = repeat;
    model.alarmId = ID;
    return model;
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
