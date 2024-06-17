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

@interface WristWakeUpController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation WristWakeUpController

- (void)viewDidLoad {
    [super viewDidLoad];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0)
    {
    
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
