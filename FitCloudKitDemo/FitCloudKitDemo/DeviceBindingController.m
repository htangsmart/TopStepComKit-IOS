//
//  DeviceBindingController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/17.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DeviceBindingController.h"
#import "MoView.h"

#define USER_ID @"10000"

@interface DeviceBindingController (){
    RACDisposable* connectRacDispose;
}

@property (weak, nonatomic) IBOutlet UIImageView *bindingImageView;
@property (weak, nonatomic) IBOutlet MoView *resultView;
@property (weak, nonatomic) IBOutlet LocalizedLabel *titleLabel;
@property (weak, nonatomic) IBOutlet LocalizedLabel *subTitleLabel;
@property (weak, nonatomic) IBOutlet UIButton *btnEnjoy;
@property (weak, nonatomic) IBOutlet UILabel *tipProgressLabel;
@property (weak, nonatomic) IBOutlet UIButton *btnTryLater;

@property (nonatomic, assign) BOOL   bBindSuccess;
@property (nonatomic, assign) BOOL   bShouldUnBindFirst;
- (IBAction)OnEnjoyNow:(id)sender;
- (IBAction)OnTryLater:(id)sender;
@end

@implementation DeviceBindingController

-(instancetype)init
{
    if(self = [super init])
    {
        _bBindSuccess = NO;
        _bShouldUnBindFirst = NO;
    }
    return self;
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self.navigationController setNavigationBarHidden:NO animated:animated];
    [self beginAnimation];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [self initControls];
    [self registerNotificationObserver];
}

-(void)dealloc
{
    if(connectRacDispose){
        [connectRacDispose dispose];
    }
}

-(void) initControls
{
    
    {
        self.bindingImageView.alpha = 0.0f;
        NSMutableArray *images = [NSMutableArray array];
        for(NSInteger i = 300; i < 319; i++)
        {
            [images addObject:[UIImage imageNamed:[NSString stringWithFormat:@"bind_%@",@(i)]]];
        }
        self.bindingImageView.animationImages = images;
        self.bindingImageView.animationDuration = [images count]*2/25.0f;//设置动画时间
        self.bindingImageView.animationRepeatCount = 0;//设置动画次数 0 表示无限
        [self.bindingImageView startAnimating];
    }
    
    {
        self.titleLabel.alpha = 0.0f;
    }
    
    {
        self.subTitleLabel.alpha = 0.0f;
    }
    
    {
        self.btnEnjoy.hidden = YES;
        self.btnEnjoy.alpha = 0.0f;
    }
    
    {
        self.btnTryLater.hidden = YES;
        [self.btnTryLater setContentEdgeInsets:UIEdgeInsetsMake(0, 20, 0, 20)];
        [self.btnTryLater setTitle:NSLocalizedString(@"Try Later", nil) forState:UIControlStateNormal];
        self.btnTryLater.alpha = 0.0f;
    }
}

-(void) registerNotificationObserver
{
    if(connectRacDispose){
        [connectRacDispose dispose];
    }
    connectRacDispose = [[[TPSSdk share].connectorAbility observeConnectResult] subscribeNext:^(TPSConnectResult * _Nullable x) {
        if(x.state == TPSConnnectResult_State_Connected){
            [self OnFitCloudInitializeResult:YES];
        }else if(x.state == TPSConnnectResult_State_Disconnected){
            [self OnFitCloudInitializeResult:NO];
        }
    }];
}

-(void)OnFitCloudInitializeResult:(BOOL)result
{
    dispatch_async(dispatch_get_main_queue(), ^{
            self.bBindSuccess = result;
            [self.btnEnjoy setTitle:result ? NSLocalizedString(@"Enjoy Now", nil) : (self.bShouldUnBindFirst ? NSLocalizedString(@"Unbind And Retry", nil) : NSLocalizedString(@"Retry", nil)) forState:UIControlStateNormal];
            [self.view layoutIfNeeded];
            __weak typeof (self) weakSelf = self;
            [UIView animateWithDuration:0.45 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
                
                __strong typeof(weakSelf) strongSelf = weakSelf;
                if (!strongSelf) return;
                if(result)
                {
                    strongSelf.titleLabel.text = NSLocalizedString(@"Smart Watch Bind Success", nil);
                    strongSelf.subTitleLabel.text = NSLocalizedString(@"Your Smart Watch Complete Bind...", nil);
                }
                else
                {
                    strongSelf.titleLabel.text = NSLocalizedString(@"Smart Watch Bind Failure", nil);
                    strongSelf.subTitleLabel.text = NSLocalizedString(@"Your Smart Watch Complete Failed to Bind...", nil);
                }
                strongSelf.bindingImageView.hidden = YES;
                strongSelf.resultView.alpha = 0.8f;
                [strongSelf.resultView startLoading];
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.5f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                    if(result)
                    {
                        [strongSelf.resultView success:^{
                            strongSelf.btnEnjoy.hidden = NO;
                            strongSelf.btnEnjoy.alpha = 1.0f;
                            self.tipProgressLabel.text = @"";
                            strongSelf.btnTryLater.hidden = YES;
                            strongSelf.btnTryLater.alpha = 0.0f;
                            [strongSelf.view layoutIfNeeded];
                        }];
                    }
                    else
                    {
                        [strongSelf.resultView error:^{
                            strongSelf.btnEnjoy.hidden = NO;
                            strongSelf.btnEnjoy.alpha = 1.0f;
                            self.tipProgressLabel.text = @"";
                            strongSelf.btnTryLater.hidden = NO;
                            strongSelf.btnTryLater.alpha = 1.0f;
                            [strongSelf.view layoutIfNeeded];
                        }];
                    }
                });
                
                [strongSelf.view layoutIfNeeded];
                
            }completion:^(BOOL finished) {
                
            }];
    });
    
}

-(void) beginAnimation
{
    [self.view layoutIfNeeded];
    [self initControls];
    __weak typeof (self) weakSelf = self;
    [UIView animateWithDuration:0.8 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
        __strong typeof(weakSelf) strongSelf = weakSelf;
        if (!strongSelf) return;
        [strongSelf.view layoutIfNeeded];
    }completion:^(BOOL finished) {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.5f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            //0520被leiwei屏蔽
//            [FitCloudKit bindUserObject:USER_ID abortIfExist:YES block:^(BOOL succeed, NSError *error) {
//            }];
        });
        [UIView animateWithDuration:1.45 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
            __strong typeof(weakSelf) strongSelf = weakSelf;
            if (!strongSelf) return;
            strongSelf.titleLabel.alpha = 1.0f;
            strongSelf.subTitleLabel.alpha = 1.0f;
            strongSelf.bindingImageView.alpha = 1.0f;
            [strongSelf.view layoutIfNeeded];
        }completion:^(BOOL finished) {
            
        }];
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)OnEnjoyNow:(id)sender {
    self.btnEnjoy.hidden = YES;
    self.btnTryLater.hidden = YES;
    self.btnEnjoy.alpha = 0.0f;
    if(!self.bBindSuccess)
    {
        self.titleLabel.text = NSLocalizedString(@"Binding Smart Watch", nil);
        self.subTitleLabel.text = NSLocalizedString(@"Please keep the smart watch nearby your iPhone.", nil);
        self.bindingImageView.hidden = NO;
        self.resultView.alpha = 0.0f;
        NSString* lastMac = [TPS_Tools getUserByKey:@"lastMac"];
        if(lastMac){
            TPSExtraConnectParam* extraParam = [[TPSExtraConnectParam alloc] initWithUserId:@"123456789" gender:0 age:18 height:180 weight:65];
            [[TPSSdk share].connectorAbility connectWithMac:lastMac extraParam:extraParam];
        }
    }
    else
    {
        [self dismissViewControllerAnimated:NO completion:^{
            //[[NSNotificationCenter defaultCenter] postNotificationName:SKIPTOMETABNOTIFICATION object:nil];
        }];
    }
}

- (IBAction)OnTryLater:(id)sender {
    [self dismissViewControllerAnimated:NO completion:^{
    }];
}

@end
