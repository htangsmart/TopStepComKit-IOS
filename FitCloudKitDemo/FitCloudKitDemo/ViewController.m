//
//  ViewController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "ViewController.h"

@interface ViewController (){
    RACDisposable* batteryRacDispose;
    RACDisposable* connectRacDispose;
}

@property (weak, nonatomic) IBOutlet UIImageView *imageSmartWatch;
@property (weak, nonatomic) IBOutlet UILabel *deviceName;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *indicator;
@property (weak, nonatomic) IBOutlet UILabel *connectStatus;
@property (weak, nonatomic) IBOutlet UIButton *btnConnectDevice;
@property (weak, nonatomic) IBOutlet UIButton *btnRemoveDevice;
@property (weak, nonatomic) IBOutlet UIButton *btnMoreDemo;
@property (weak, nonatomic) IBOutlet UILabel *progressTip;

@property (weak, nonatomic) IBOutlet UILabel *soc;

@property (weak, nonatomic) IBOutlet UIButton *btnSearch;

- (IBAction)OnConnectDevice:(id)sender;
- (IBAction)OnRemoveDevice:(id)sender;
- (IBAction)OnMoreDemo:(id)sender;
@end

@implementation ViewController

-(void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Do any additional setup after loading the view.
    
    {
        [self.btnConnectDevice setTitle:NSLocalizedString(@"Connect Device", nil) forState:UIControlStateNormal];
        self.btnConnectDevice.layer.borderColor = UIColor.blackColor.CGColor;
        [self.btnConnectDevice setContentEdgeInsets:UIEdgeInsetsMake(0, 30, 0, 30)];
    }
    
    {
        [self.btnSearch setTitle:NSLocalizedString(@"Search Device", nil) forState:UIControlStateNormal];
        self.btnSearch.layer.borderColor = UIColor.blackColor.CGColor;
        [self.btnSearch setContentEdgeInsets:UIEdgeInsetsMake(0, 30, 0, 30)];
    }
    
    {
        [self.btnRemoveDevice setTitle:NSLocalizedString(@"Remove Device", nil) forState:UIControlStateNormal];
    }
    
    {
        [self.btnMoreDemo setTitle:NSLocalizedString(@"More Demo >", nil) forState:UIControlStateNormal];
    }
    
    {
        [self updateControlVisible];
    }
    
    [self registerNotificationObsever];
    NSString* lastMac = [TPS_Tools getUserByKey:@"lastMac"];
    if(lastMac){
        TPSExtraConnectParam* extraParam = [[TPSExtraConnectParam alloc] initWithUserId:@"123456789" gender:0 age:18 height:180 weight:65];
        [[TPSSdk share].connectorAbility reconnectWithMac:lastMac extraParam:extraParam];
    }
}

-(void) registerNotificationObsever{
    if(connectRacDispose){
        [connectRacDispose dispose];
    }
    connectRacDispose = [[[TPSSdk share].connectorAbility observeConnectResult] subscribeNext:^(TPSConnectResult * _Nullable x) {
        if(x.state == TPSConnnectResult_State_Connected){
            dispatch_async(dispatch_get_main_queue(), ^{
                if(self.indicator.isAnimating)[self.indicator stopAnimating];
                self.connectStatus.text = NSLocalizedString(@"Connected", nil);
                self.connectStatus.textColor = RGB(0x00, 0xB2, 0x00);
                self.btnConnectDevice.hidden = TRUE;
                self.imageSmartWatch.hidden = self.deviceName.hidden = FALSE;
                self.btnSearch.hidden = TRUE;
                self.btnRemoveDevice.hidden = self.btnMoreDemo.hidden = FALSE;
                [self getBatteryInfo];
            });
        }else if(x.state == TPSConnnectResult_State_Connecting){
            dispatch_async(dispatch_get_main_queue(), ^{
                self.indicator.hidden = self.connectStatus.hidden = FALSE;
                if(!self.indicator.isAnimating)[self.indicator startAnimating];
                self.btnConnectDevice.hidden = TRUE;
                self.btnRemoveDevice.hidden = TRUE;
                self.btnMoreDemo.hidden = TRUE;
                self.connectStatus.text = NSLocalizedString(@"Connecting...", nil);
                self.connectStatus.textColor = RGB(0x9A, 0x9A, 0x9A);
            });
        }else if(x.state == TPSConnnectResult_State_Disconnected){
            dispatch_async(dispatch_get_main_queue(), ^{
                if(self.indicator.isAnimating)[self.indicator stopAnimating];
                self.connectStatus.text = NSLocalizedString(@"Disconnected", nil);
                self.connectStatus.textColor = RGB(0x9A, 0x9A, 0x9A);
                if([FitCloudKit lastConnectPeripheral])self.btnConnectDevice.hidden = FALSE;
                self.btnRemoveDevice.hidden = NO;
                self.btnMoreDemo.hidden = YES;
                self.soc.text = @"";
            });
        }
    }];
}

-(void)getBatteryInfo{
    if(batteryRacDispose){
        [batteryRacDispose dispose];
    }
    batteryRacDispose = [[[TPSSdk share].devInfoAbility observeBattery] subscribeNext:^(NSNumber * _Nullable x) {
        dispatch_async(dispatch_get_main_queue(), ^{
             self.soc.text = [NSString stringWithFormat:NSLocalizedString(@"SOC: %d%%", nil), [x intValue]];
        });
    }];
}

-(void) updateControlVisible
{
    self.imageSmartWatch.hidden = self.deviceName.hidden = self.indicator.hidden = self.connectStatus.hidden = self.btnConnectDevice.hidden = self.btnRemoveDevice.hidden = self.btnMoreDemo.hidden = TRUE;
    self.btnSearch.hidden = FALSE;
}

-(BOOL)shouldPerformSegueWithIdentifier:(NSString *)identifier sender:(id)sender
{
#if TARGET_IPHONE_SIMULATOR//模拟器
    return FALSE;
#else
    return TRUE;
#endif
}

- (IBAction)OnConnectDevice:(id)sender {
    self.indicator.hidden = self.connectStatus.hidden = FALSE;
    [self.indicator startAnimating];
    self.btnConnectDevice.hidden = TRUE;
    NSString* lastMac = [TPS_Tools getUserByKey:@"lastMac"];
    if(lastMac){
        TPSExtraConnectParam* extraParam = [[TPSExtraConnectParam alloc] initWithUserId:@"123456789" gender:0 age:18 height:180 weight:65];
        [[TPSSdk share].connectorAbility connectWithMac:lastMac extraParam:extraParam];
    }
}

- (IBAction)OnRemoveDevice:(id)sender {
    __weak typeof(self) weakSelf = self;
    [[TPSSdk share].connectorAbility unbindDevWithUserId:@"123456789" block:^(BOOL isSendOK) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [weakSelf updateControlVisible];
        });
    }];
}

- (IBAction)OnMoreDemo:(id)sender {
}
@end
