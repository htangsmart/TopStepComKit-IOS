//
//  RemotePhotographyController.m
//  FitCloudKitDemo
//
//  Created by Zhuanz on 2024/6/13.
//  Copyright © 2024 HetangSmart. All rights reserved.
//  遥控拍照 --- Remote Photography

#import <AVFoundation/AVFoundation.h>
#import "RemotePhotographyController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface RemotePhotographyController () <AVCapturePhotoCaptureDelegate>
- (IBAction)OnGoBack:(id)sender;

@property (nonatomic, strong) AVCaptureDevice *device;
@property (nonatomic, strong) AVCaptureDeviceInput *input;
//@property (nonatomic, strong) AVCaptureMetadataOutput *output;
@property (nonatomic, strong) AVCapturePhotoOutput *output;
@property (nonatomic, strong) AVCaptureSession *session;
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;

@end

@implementation RemotePhotographyController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setCamera];
    __weak typeof(self) weakSelf = self;
    [TPSSdk.share.remotePhotoAbility observerWatchOpenCamera:^{
        __strong typeof(self) strongSelf = weakSelf;
        [strongSelf openCamera];
    }];
    [TPSSdk.share.remotePhotoAbility observerWatchExitCamera:^{
        __strong typeof(self) strongSelf = weakSelf;
        [strongSelf closeCamera];
    }];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 0) {
        [self openCamera];
    }
}

- (void)setCamera {
    if ([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo] != AVAuthorizationStatusAuthorized) {
        [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {
            if (granted) {
                // 相机访问成功
                [self customCamera];
            } else {
                // 相机访问被拒绝
                OpResultToastTip(self.view, NO);
            }
        }];
    } else {
        // 已有相机权限
        [self customCamera];
    }
}

- (void)customCamera {
    self.device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    self.input = [AVCaptureDeviceInput deviceInputWithDevice:self.device error:nil];
    self.output = [AVCapturePhotoOutput new];
    self.session = [AVCaptureSession new];
    self.session.sessionPreset = AVCaptureSessionPresetPhoto;
    if (self.input && [self.session canAddInput:self.input]) {
        [self.session addInput:self.input];
    }
    if (self.output && [self.session canAddOutput:self.output]) {
        [self.session addOutput:self.output];
    }
    self.previewLayer = [[AVCaptureVideoPreviewLayer alloc] initWithSession:self.session];
    self.previewLayer.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height);
//    self.previewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
    [self.view.layer addSublayer:self.previewLayer];
}

- (void)openCamera {
    if (!self.session) {
        return;
    }
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
        [self.session startRunning];
        NSLog(@"----- running success -----");
        dispatch_async(dispatch_get_main_queue(), ^{
            __weak typeof(self) weakSelf = self;
            [TPSSdk.share.remotePhotoAbility enterRemotePhotography:^{
                dispatch_async(dispatch_get_main_queue(), ^{
                    AVCapturePhotoSettings *settings = [AVCapturePhotoSettings photoSettings];
                    [weakSelf.output capturePhotoWithSettings:settings delegate:weakSelf ];
                });
            }];
        });
    });
}

- (void)captureOutput:(AVCapturePhotoOutput *)output didFinishProcessingPhoto:(AVCapturePhoto *)photo error:(NSError *)error {
    if (!error) {
        NSData *imageData = photo.fileDataRepresentation;
        UIImage *image = [UIImage imageWithData:imageData];
        UIImageWriteToSavedPhotosAlbum(image, self, @selector(image:didFinishSavingWithError:contextInfo:), NULL);
    } else {
        NSLog(@"----- error -----");
    }
}

- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo {
    NSString *msg = nil;
    if (!error) {
        msg = @"save photo success";
    } else {
        msg = @"save photo failure";
    }
    NSLog(@"result ----- %@",msg);
}

- (void)closeCamera {
    if (self.session) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
            [self.session stopRunning];
            NSLog(@"----- stop success -----");
        });
    }
    dispatch_async(dispatch_get_main_queue(), ^{
        [TPSSdk.share.remotePhotoAbility exitRemotePhotography];
        [self.navigationController popViewControllerAnimated:YES];
        NSLog(@"----- exit -----");
    });
}

- (IBAction)OnGoBack:(id)sender {
    [self closeCamera];
}


@end
