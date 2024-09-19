//
//  NotificationManageController.m
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/6/15.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NotificationManageController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface NotificationManageController (){
    NSArray* allNotificationArray;
    NSArray<TPSNotificationEnableModel *> *notificationEnableList;
}
- (IBAction)OnGoBack:(id)sender;
@end

@implementation NotificationManageController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    allNotificationArray =  @[
        @{@"msgType":@(TPSNotification_Type_telephony),@"msg_title":@"Phone",@"msgName":@"telephony",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_sms),@"msg_title":@"SMS",@"msgName":@"sms",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_mail),@"msg_title":@"Mail",@"msgName":@"mail",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_wechat),@"msg_title":@"Wechat",@"msgName":@"wechat",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_qq),@"msg_title":@"QQ",@"msgName":@"qq",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_facebook),@"msg_title":@"Facebook",@"msgName":@"facebook",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_twitter),@"msg_title":@"X",@"msgName":@"twitter",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_whatsapp),@"msg_title":@"WhatsApp",@"msgName":@"whatsapp",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_linkedin),@"msg_title":@"LinkedIn",@"msgName":@"linkedin",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_instagram),@"msg_title":@"Instagram",@"msgName":@"instagram",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_facebookmessenger),@"msg_title":@"Messenger",@"msgName":@"facebookmessenger",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_snapchat),@"msg_title":@"Snapchat",@"msgName":@"snapchat",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_line),@"msg_title":@"Line",@"msgName":@"line",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_kakaotalk),@"msg_title":@"Kaokao Talk",@"msgName":@"kakaotalk",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_viber),@"msg_title":@"Viber",@"msgName":@"viber",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_skype),@"msg_title":@"Skype",@"msgName":@"skype",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_telegram),@"msg_title":@"Telegram",@"msgName":@"telegram",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_pinterest),@"msg_title":@"Pinterest",@"msgName":@"pinterest",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_youtube),@"msg_title":@"Youtube",@"msgName":@"youtube",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_applemusic),@"msg_title":@"Applemusic",@"msgName":@"applemusic",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_zoom),@"msg_title":@"Zoom",@"msgName":@"zoom",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_tiktok),@"msg_title":@"Tiktok",@"msgName":@"tiktok",@"visible":@(1)},
        @{@"msgType":@(TPSNotification_Type_hike),@"msg_title":@"Hike",@"msgName":@"hike",@"visible":@(0)},
        @{@"msgType":@(TPSNotification_Type_default),@"msg_title":@"More other",@"msgName":@"default",@"visible":@(1)},
    ];
    self.mTableView.allowsSelection = YES;
    self.mTableView.hidden = YES;
    [TPSSdk.share.notificationEnableAbility getNotificationEnableList:^(NSArray<TPSNotificationEnableModel *> *list) {
        self->notificationEnableList = list;
        for(int i=0;i<list.count;i++){
            TPSNotification_Type tpsNoteType = list[i].type;
            NSLog(@"TPSNotification_Type tpsNoteType %d", tpsNoteType);
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.mTableView reloadData];
            self.mTableView.hidden = NO;
        });
    }];
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return allNotificationArray.count;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSLog(@"abccc");
    __weak typeof(self) weakSelf = self;
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    TPSNotification_Type msgType = [allNotificationArray[indexPath.row][@"msgType"] intValue];
    BOOL previousState = [self getIsEanbleWithType:msgType];
    [self setEnableWithType:msgType enable:!previousState];
    BOOL currentState = !previousState;
    [TPSSdk.share.notificationEnableAbility sendNotificationEnableList:notificationEnableList block:^(BOOL isSendOK) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if(currentState){
                cell.textLabel.text = [NSString stringWithFormat:@"%@-enable",self->allNotificationArray[indexPath.row][@"msg_title"]];
                cell.textLabel.textColor = UIColor.blackColor;
            }else{
                cell.textLabel.text = [NSString stringWithFormat:@"%@-disable",self->allNotificationArray[indexPath.row][@"msg_title"]];
                cell.textLabel.textColor = UIColor.redColor;
            }
        });
    }];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [[UITableViewCell alloc] init];
    cell.textLabel.text = allNotificationArray[indexPath.row][@"msg_title"];
    TPSNotification_Type msgType = [allNotificationArray[indexPath.row][@"msgType"] intValue];
    BOOL isOn = [self getIsEanbleWithType:msgType];
    if(isOn){
        cell.textLabel.text = [NSString stringWithFormat:@"%@-enable",allNotificationArray[indexPath.row][@"msg_title"]];
        cell.textLabel.textColor = UIColor.blackColor;
    }else{
        cell.textLabel.text = [NSString stringWithFormat:@"%@-disable",allNotificationArray[indexPath.row][@"msg_title"]];
        cell.textLabel.textColor = UIColor.redColor;
    }
    return cell;
}

-(BOOL)getIsEanbleWithType:(TPSNotification_Type)type{
    for(int i=0;i<notificationEnableList.count;i++){
        if(notificationEnableList[i].type == type){
            return notificationEnableList[i].enable;
        }
    }
    return NO;
}

-(void)setEnableWithType:(TPSNotification_Type)type enable:(BOOL)enable{
    for(int i=0;i<notificationEnableList.count;i++){
        if(notificationEnableList[i].type == type){
            notificationEnableList[i].enable = enable;
        }
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
