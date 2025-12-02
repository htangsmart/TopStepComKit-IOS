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
@property (weak, nonatomic) IBOutlet UILabel *reslutLabel;
- (IBAction)OnGoBack:(id)sender;
@end

@implementation RealtimeMeasureController

- (void)viewDidLoad {
    
    [[TPSSdk.share.healthMeasureAbility observeMeasureValue] subscribeNext:^(TPSMeasureValue * _Nullable x) {
       
        NSLog(@"observeMeasureValue : %@",x.debugDescription);
        self.reslutLabel.text = x.debugDescription;
    }];
    
    [super viewDidLoad];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    __weak typeof(self) weakSelf = self;

    if (indexPath.row == 0) {
        
        TPSMeasureConfig *config = [[TPSMeasureConfig alloc]init];
        config.type = TPSHealthMeasureHeartRate;
        config.duration = 1;
        config.interval = 10;
        [TPSSdk.share.healthMeasureAbility startMeasureWithConfig:config completion:^(BOOL isSendOK, NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, isSendOK);
            });
        }];
        
        
    } else if (indexPath.row == 1) {
        
        TPSMeasureConfig *config = [[TPSMeasureConfig alloc]init];
        config.type = TPSHealthMeasureTemperature;
        config.duration = 1;
        config.interval = 10;
        [TPSSdk.share.healthMeasureAbility startMeasureWithConfig:config completion:^(BOOL isSendOK, NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, isSendOK);
            });
        }];
        
    } else if (indexPath.row == 2) {
        
        TPSMeasureConfig *config = [[TPSMeasureConfig alloc]init];
        config.type = TPSHealthMeasureAll;
        config.duration = 1;
        config.interval = 10;

        [TPSSdk.share.healthMeasureAbility startMeasureWithConfig:config completion:^(BOOL isSendOK, NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, isSendOK);
            });
        }];
        
        
    } else if (indexPath.row == 3) {
        
        [TPSSdk.share.healthMeasureAbility stopMeasureWithCompletion:^(BOOL isSendOK, NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, isSendOK);
            });
        }];
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
