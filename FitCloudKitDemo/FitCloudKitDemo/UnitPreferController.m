//
//  UnitPreferController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/3.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "UnitPreferController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface UnitPreferController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation UnitPreferController

- (void)viewDidLoad {
    [super viewDidLoad];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0)
    {
        [TPSSdk.share.miscSettingAbility sendSport_sportUnit:MiscSettingModel_TSTPS_Sport_Unit_British_System];
        OpResultToastTip(self.view, YES);
    }
    else if(indexPath.row == 1)
    {
        [TPSSdk.share.miscSettingAbility sendSport_sportUnit:MiscSettingModel_TSTPS_Sport_Unit_Metric_System];
        OpResultToastTip(self.view, YES);
    }
    else if(indexPath.row == 2)
    {
        [TPSSdk.share.miscSettingAbility sendSystem_timing_method:TPSMiscSettingModel_Time_Format_12];
        OpResultToastTip(self.view, YES);
    }
    else if(indexPath.row == 3)
    {
        [TPSSdk.share.miscSettingAbility sendSystem_timing_method:TPSMiscSettingModel_Time_Format_24];
    }
    else if(indexPath.row == 4)
    {
        [TPSSdk.share.miscSettingAbility sendWeather_temp_unit:TPSMiscSettingModel_Temperature_Unit_C];

    }
    else if(indexPath.row == 5)
    {
        [TPSSdk.share.miscSettingAbility sendWeather_temp_unit:TPSMiscSettingModel_Temperature_Unit_F];

    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
