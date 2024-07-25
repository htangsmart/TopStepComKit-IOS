//
//  DialController.m
//  FitCloudKitDemo
//  Created by Zhuanz on 2024/6/15.
//  Copyright © 2024 HetangSmart. All rights reserved.
//  表盘 --- Dial

#import "DialController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface DialController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation DialController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    __weak typeof(self) weakSelf =self;
    if (indexPath.row == 0) {
        // Retrieve Current Watch Face Information
        [TPSSdk.share.dialAbility getCurrentDial:^(TPSDialModel *model) {
            XLOG_INFO(@"Dial --- dialId: %@", model.dialId);
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(weakSelf.view);
            });
        }];
    } else if (indexPath.row == 1) {
        // Retrieve All Watch Face Information from the Watch
        [TPSSdk.share.dialAbility getAllDialInfo:^(NSArray<TPSDialModel *> *modelList) {
            [modelList enumerateObjectsUsingBlock:^(TPSDialModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                XLOG_INFO(@"Dial --- dialId: %@", obj.dialId);
            }];
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(weakSelf.view);
            });
        }];
    } else if (indexPath.row == 2) {
        
        // Change the current watch face according to the watch face ID
        [TPSSdk.share.dialAbility getAllDialInfo:^(NSArray<TPSDialModel *> *modelList) {
            [modelList enumerateObjectsUsingBlock:^(TPSDialModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                XLOG_INFO(@"Dial --- dialId: %@", obj.dialId);
            }];
           
            if (![modelList isKindOfClass:NSArray.class] || modelList.count == 0) { return; }
            [TPSSdk.share.dialAbility changeDialWithDialId:modelList.firstObject.dialId block:^(BOOL isSendOK) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    if (isSendOK) {
                        OpResultToastTip(weakSelf.view, YES);
                    } else {
                        OpResultToastTip(weakSelf.view, NO);
                    }
                });
            }];
        }];
    } else if (indexPath.row == 3) {
        // Delete cloud watch face
        [TPSSdk.share.dialAbility deleteRemoteWatchWithDiaId:@"57417" block:^(BOOL isSendOK, NSDictionary * _Nullable errorInfo) {
            
            if (errorInfo) {
                NSLog(@"-----error = %@", errorInfo);
            }
            if (isSendOK) {
                OpResultToastTip(weakSelf.view, YES);
            } else {
                OpResultToastTip(weakSelf.view, NO);
            }
        }];
    } else if (indexPath.row == 4) {//for custom watch face
        
        TPSDialModel *model = [[TPSDialModel alloc] init];
        TPSSDKType sdkType = [TPSDevice.share fitSDK];
        if (sdkType == eTPSSDKFlyWear) {
            
            // 表盘ID
            // Watch Face ID
            model.dialId = @"com.realthread.superDial";
            // 准备发送给手表的表盘文件路径
            // Prepare the watch face file path for sending to the watch
            model.filePath = [[NSBundle mainBundle] pathForResource:@"flywearsdkDial" ofType:@"zip"];
            // 设置表盘预览图
            // Set up the watch face preview image
            model.previewImage = [UIImage imageNamed:@"preview.png"];
            // 设置表盘背景图
            // Set the Watch Face Preview Image
            model.backgroundImage = [UIImage imageNamed:@"bg1.png"];
        } else if (sdkType == eTPSSDKFitCloudPro) {
            
            // 表盘ID
            // Watch Face ID, no use for eTPSSDKFitCloudPro type
//            model.dialId = @"5";
            // 准备发送给手表的表盘文件路径
            // Prepare the watch face file path for sending to the watch
            model.filePath = [[NSBundle mainBundle] pathForResource:@"template9845" ofType:@"bin"];
            // 设置表盘预览图
            // Set up the watch face preview image
            model.previewImage = [UIImage imageNamed:@"500198_TB_preview.png"];
            // 设置表盘背景图
            // Set the Watch Face Preview Image
            model.backgroundImage = [UIImage imageNamed:@"500198_TB.png"];
        }
        // 设置表盘类型
        // Set the Watch Face Type
        model.dialType = eDialTypeCustomer;
        // 设置时间显示位置
        // Set the Time Display Position
        model.dialTimePosition = eDialTimePositionRight;
        // 设置表盘时间文字颜色 805芯片的手表支持五种颜色
        // Set the Color of the Time Text on the Watch Face. The watch with the 805 chip supports five colors.
        model.textColor = [DialController allColors][4];
        // 向手表推送自定义表盘
        // Push Custom Watch Face to the Watch
        [TPSSdk.share.dialAbility pushCustomerDialWithDial:model block:^(TPSDialProgressModel *model) {
            
            if (model.eventType == TPSDialProgressModel_Event_Type_OnCompleted) {
                NSLog(@"push watch face ok");
                OpResultToastTip(weakSelf.view, YES);
            } else if (model.eventType == TPSDialProgressModel_Event_Type_OnProcess){
                NSLog(@"progress number:%.1f", model.percent);
            }else if (model.eventType == TPSDialProgressModel_Event_Type_OnFailed) {
                NSLog(@"push watch face fail");
                OpResultToastTip(weakSelf.view, NO);
            }
        }];
    }else if (indexPath.row == 5){// for cloud watch face
        TPSDialModel *model = [[TPSDialModel alloc] init];
        TPSSDKType sdkType = [TPSDevice.share fitSDK];
        if (sdkType == eTPSSDKFlyWear) {
        }else if (sdkType == eTPSSDKFitCloudPro) {
            model.filePath = [[NSBundle mainBundle] pathForResource:@"gui_dial_binfile_watch_500155_1_20240708_MP-515c1edf17afcd2c075e0e11315a7b78" ofType:@"bin"];
            [TPSSdk.share.dialAbility pushLocalDialWithDial:model block:^(TPSDialProgressModel *model) {
                if (model.eventType == TPSDialProgressModel_Event_Type_OnCompleted) {
                    NSLog(@"push cloud face ok");
                    OpResultToastTip(weakSelf.view, YES);
                } else if (model.eventType == TPSDialProgressModel_Event_Type_OnProcess){
                    NSLog(@"progress number:%.1f", model.percent);
                }else if (model.eventType == TPSDialProgressModel_Event_Type_OnFailed) {
                    NSLog(@"push cloud face fail");
                    OpResultToastTip(weakSelf.view, NO);
                }
            }];
        }
    }
}


+ (NSArray *)allColors{
    return @[
        [self colorwithHexString:@"#FFFFFF" alpha:1.0f],
        [self colorwithHexString:@"#333333" alpha:1.0f],
        [self colorwithHexString:@"#F7B500" alpha:1.0f],
        [self colorwithHexString:@"#44D7B6" alpha:1.0f],
        [self colorwithHexString:@"#32C5FF" alpha:1.0f]];
}

+ (UIColor *)colorwithHexString:(NSString *)hexStr alpha:(CGFloat)alpha

{
    //-----------------------------------------
    // Convert hex string to an integer
    //-----------------------------------------
    
    unsigned int hexint = 0;
    
    //convert the hex value into an unsigned integer
    //1. Create scanner
    NSScanner *scanner = [NSScanner scannerWithString:hexStr];
    
    //2. Tell scanner to skip the # character
    [scanner setCharactersToBeSkipped:[NSCharacterSet
                                       characterSetWithCharactersInString:@"#"]];
    [scanner scanHexInt:&hexint];
    
    
    //-----------------------------------------
    // Create color object, specifying alpha
    //-----------------------------------------
    //create a UIColor object by doing a bitwise ‘&’ operation to isolate the various color attributes and divide each by 255 to get the float value for the same.
    
    UIColor *color =
    [UIColor colorWithRed:((CGFloat) ((hexint & 0xFF0000) >> 16))/255
                    green:((CGFloat) ((hexint & 0xFF00) >> 8))/255
                     blue:((CGFloat) (hexint & 0xFF))/255
                    alpha:alpha];
    
    return color;
}


- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
