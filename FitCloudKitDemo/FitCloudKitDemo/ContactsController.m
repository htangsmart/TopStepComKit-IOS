//
//  UserProfileController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/3.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "ContactsController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface ContactsController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation ContactsController

- (void)viewDidLoad {
    [super viewDidLoad];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    __weak typeof(self) weakSelf = self;
    if (indexPath.row == 0) {
        // 获取所有普通联系人 --- Get Normal Contacts
        [[TPSSdk.share.contactAbility getAllContact] subscribeNext:^(NSArray<TPSContactModel *> * _Nullable x) {
            if ([x isKindOfClass:[NSArray class]]) {
                [x enumerateObjectsUsingBlock:^(TPSContactModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    XLOG_INFO(@"Contact --- name: %@ phone: %@", obj.name, obj.phone);
                }];
                dispatch_async(dispatch_get_main_queue(), ^{
                    ConsoleResultToastTip(weakSelf.view);
                });
            }
        }];
    } else if (indexPath.row == 1) {
        // 设置普通联系人 --- Set Normal Contacts
        TPSContactModel *model1 = [[TPSContactModel alloc] initWithName:@"Lily" phone:@"18910723096" initial:@""];
        TPSContactModel *model2 = [[TPSContactModel alloc] initWithName:@"Jack" phone:@"15603325273" initial:@""];
        NSArray *arr = [NSArray arrayWithObjects:model1, model2, nil];
        [TPSSdk.share.contactAbility sendCommonContact:arr];
        OpResultToastTip(self.view, YES);
    } else if (indexPath.row == 2) {
        // 获取紧急联系人 --- Get Emergency Contact
        [TPSSdk.share.contactAbility getEmergencyContact:^(NSArray<TPSContactModel *> *list) {
            [list enumerateObjectsUsingBlock:^(TPSContactModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                XLOG_INFO(@"Emergency Contact --- name: %@ phone: %@", obj.name, obj.phone);
            }];
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(weakSelf.view);
            });
        }];
//        [TPSSdk.share.contactAbility getEmergencyContact:^(NSMutableArray<TPSContactModel *> *list) {
//            [list enumerateObjectsUsingBlock:^(TPSContactModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//                XLOG_INFO(@"Emergency Contact --- name: %@ phone: %@", obj.name, obj.phone);
//            }];
//            dispatch_async(dispatch_get_main_queue(), ^{
//                ConsoleResultToastTip(weakSelf.view);
//            });
//        }];
    } else if (indexPath.row == 3) {
        // 设置紧急联系人 --- Set Emergency Contact
        TPSContactModel *model = [[TPSContactModel alloc] initWithName:@"Lucy" phone:@"18730325788" initial:@""];
        [TPSSdk.share.contactAbility sendEmergencyContact:model];
        OpResultToastTip(self.view, YES);
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
