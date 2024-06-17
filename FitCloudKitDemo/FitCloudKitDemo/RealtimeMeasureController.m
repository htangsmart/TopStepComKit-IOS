//
//  RealtimeMeasureController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/2.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "RealtimeMeasureController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

/**
 *@brief 健康实时测量事件类型定义
 */

@interface RealtimeMeasureController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation RealtimeMeasureController

- (void)viewDidLoad {
    [super viewDidLoad];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row == 0) {
        
    } else if (indexPath.row == 1) {
        
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
