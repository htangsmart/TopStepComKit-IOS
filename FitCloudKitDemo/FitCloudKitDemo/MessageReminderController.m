//
//  MessageReminderController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/22.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "MessageReminderController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface MessageReminderController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation MessageReminderController

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
        // 查询开启的消息提醒
        // Query enabled message reminders
        XLOG_INFO(@"\n查询消息提醒设置...\nQuery message reminder settings...");
        [TPSSdk.share.notificationEnableAbility getNotificationEnableList:^(NSArray<TPSNotificationEnableModel *> *list) {
            
            [list enumerateObjectsUsingBlock:^(TPSNotificationEnableModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                             
                NSLog(@"NotificationType:%@, name:%@, enable:%d", @(obj.type), obj.name, obj.enable);
            }];
            XLOG_INFO(@"\n消息提醒设置查询完毕。\nThe message reminder settings query is complete.");
        }];
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 1)
    {
        
        // 设置消息提醒。调用sendNotificationEnableList:block:方法时传入的list是全部的消息，SDK会将此list覆盖之前的list。
        // Set message reminders. When calling the sendNotificationEnableList:block: method, the list passed in is all the messages, and the SDK will overwrite the previous list with this list.
        
        NSMutableArray<TPSNotificationEnableModel *> *notificationModels = NSMutableArray.new;
        
        // 添加电话提醒设置
        // Add phone reminder settings
        [notificationModels addObject:[self generateModelsQuicklyWithType:(TPSNotification_Type_telephony)
                                                                     name:@"telephony"
                                                                   enable:true]];
        
        // 添加tiktok提醒设置
        // Add tiktok reminder settings
        [notificationModels addObject:[self generateModelsQuicklyWithType:(TPSNotification_Type_tiktok)
                                                                     name:@"tiktok"
                                                                   enable:true]];
        
        // ...
        
        XLOG_INFO(@"\n修改消息提醒设置...\nModify message reminder settings...");
        [TPSSdk.share.notificationEnableAbility sendNotificationEnableList:[notificationModels copy] block:^(BOOL isSendOK) {
            
            NSString *names = [[notificationModels valueForKeyPath:@"name"] componentsJoinedByString:@", "];
            if (isSendOK) {
                
                XLOG_INFO(@"\n%@\n消息提醒设置成功\nMessage reminder setting successful", names);
            } else {
                
                XLOG_INFO(@"\n%@\n消息提醒设置失败\nMessage reminder setting failed", names);
            }
        }];
        ConsoleResultToastTip(self.view);
    }
}

- (TPSNotificationEnableModel *)generateModelsQuicklyWithType:(TPSNotification_Type)type name:(NSString *)name enable:(BOOL)enable {
    
    TPSNotificationEnableModel *model = [[TPSNotificationEnableModel alloc] init];
    model.type = type;
    model.name = name;
    model.enable = enable;
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
