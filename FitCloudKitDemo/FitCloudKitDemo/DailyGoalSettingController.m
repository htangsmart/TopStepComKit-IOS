//
//  DailyGoalSettingController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/2.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DailyGoalSettingController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface DailyGoalSettingController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation DailyGoalSettingController

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
        TPSSportTargetModel *model = [TPSSportTargetModel new];
        model.steps = 10000;
        model.stand_time = 60;
        model.sport_time = 30;
        model.sport_num = 3;
        model.calorie = 30;
        model.distance = 5000;
        __weak typeof(self) weakSelf = self;
        [TPSSdk.share.sportTargetAbility sendSportTargets:model block:^(BOOL isSendOK) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (isSendOK) {
                    OpResultToastTip(weakSelf.view, YES);
                } else {
                    OpResultToastTip(weakSelf.view, NO);
                }
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
