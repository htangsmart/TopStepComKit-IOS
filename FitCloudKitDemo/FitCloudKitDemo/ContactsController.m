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
/**
 * @brief Target image size for contact background
 * @chinese 联系人背景图的目标尺寸
 */
@property (nonatomic, assign) CGSize targetImageSize;
@end

@implementation ContactsController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 初始化结果图片视图
    [self setupResultImageView];
    
    [self registerSOSRequest];
}

- (void)registerSOSRequest{
    [[[TPSSdk share] contactAbility] registerDeviceSOSRequest:^(NSError *error) {
        NSLog(@"receive sos request");
    }];
}

/**
 * 设置结果图片视图
 */
- (void)setupResultImageView {
    self.resultImageView = [[UIImageView alloc] init];
    self.resultImageView.contentMode = UIViewContentModeScaleAspectFit;
    self.resultImageView.backgroundColor = [UIColor colorWithWhite:0.95 alpha:1.0];
    self.resultImageView.layer.cornerRadius = 8.0;
    self.resultImageView.layer.borderWidth = 1.0;
    self.resultImageView.layer.borderColor = [UIColor colorWithWhite:0.8 alpha:1.0].CGColor;
    self.resultImageView.clipsToBounds = YES;
    self.resultImageView.hidden = YES; // 初始隐藏
    
    [self.view addSubview:self.resultImageView];
    
    // 添加保存路径标签
    UILabel *pathLabel = [[UILabel alloc] init];
    pathLabel.text = [NSString stringWithFormat:@"保存路径: %@", [self ts_getDocumentsDirectoryPath]];
    pathLabel.font = [UIFont systemFontOfSize:12.0];
    pathLabel.textColor = [UIColor colorWithWhite:0.4 alpha:1.0];
    pathLabel.textAlignment = NSTextAlignmentCenter;
    pathLabel.numberOfLines = 0;
    pathLabel.backgroundColor = [UIColor colorWithWhite:0.98 alpha:1.0];
    pathLabel.layer.cornerRadius = 4.0;
    pathLabel.layer.borderWidth = 0.5;
    pathLabel.layer.borderColor = [UIColor colorWithWhite:0.8 alpha:1.0].CGColor;
    
    [self.view addSubview:pathLabel];
    
    // 设置约束 - 结果图片视图放在页面底部
    self.resultImageView.translatesAutoresizingMaskIntoConstraints = NO;
    pathLabel.translatesAutoresizingMaskIntoConstraints = NO;
    
    [NSLayoutConstraint activateConstraints:@[
        // 结果图片视图约束
        [self.resultImageView.leadingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.leadingAnchor constant:20],
        [self.resultImageView.trailingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.trailingAnchor constant:-20],
        [self.resultImageView.bottomAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.bottomAnchor constant:-50], // 留出空间给路径标签
        [self.resultImageView.heightAnchor constraintEqualToConstant:200], // 固定高度200
        
        // 路径标签约束
        [pathLabel.leadingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.leadingAnchor constant:20],
        [pathLabel.trailingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.trailingAnchor constant:-20],
        [pathLabel.bottomAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.bottomAnchor constant:-20],
        [pathLabel.heightAnchor constraintGreaterThanOrEqualToConstant:30]
    ]];
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
        TPSContactModel *model3 = [[TPSContactModel alloc] initWithName:@"jeseka" phone:@"15201063278" initial:@""];

        NSArray *arr = [NSArray arrayWithObjects:model1, model2,model3, nil];
//        [TPSSdk.share.contactAbility sendCommonContact:arr];
        [TPSSdk.share.contactAbility sendCommonContact:arr complete:^(BOOL success, NSError *error) {
                    
        }];
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
        [TPSSdk.share.contactAbility sendEmergencyContact:model isSOSOn:YES complete:^(BOOL success, NSError *error) {
            
        }];
//        [TPSSdk.share.contactAbility sendEmergencyContact:model];
        OpResultToastTip(self.view, YES);
    }else if (indexPath.row == 4){
        
        [[[TPSSdk share] contactAbility] queryContactBackgroundImageDimensions:^(CGSize imageSize, NSError *error) {
            if (error) {
                NSLog(@"[ContactBG] query dimensions error: %@", error);
            } else {
                XLOG_INFO(@"[ContactBG] image dimensions: %@ (w=%.0f, h=%.0f)", NSStringFromCGSize(imageSize), imageSize.width, imageSize.height);
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(weakSelf.view);
            });
        }];
        
    }else if (indexPath.row == 5){
        
        [[[TPSSdk share] contactAbility] queryContactBackgroundImageSlotsSuccess:^(NSArray<TPSContactImageSlot *> *slots) {
            [slots enumerateObjectsUsingBlock:^(TPSContactImageSlot * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                XLOG_INFO(@"[ContactBG] slotIndex=%ld, phone=%@, hasImage=%@", (long)obj.slotIndex, obj.contactPhone ?: @"", obj.hasBackgroundImage ? @"YES" : @"NO");
            }];
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(weakSelf.view);
            });
        } failure:^(NSError *error) {
            NSLog(@"[ContactBG] query slots error: %@", error);
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, NO);
            });
        }];
        
    }else if (indexPath.row == 6){
        
        [[[TPSSdk share] contactAbility] queryContactBackgroundImageDimensions:^(CGSize imageSize, NSError *error) {
            if (error) {
                NSLog(@"[ContactBG] query dimensions error: %@", error);
                return;
            }
            CGSize targetSize = CGSizeEqualToSize(imageSize, CGSizeZero) ? CGSizeMake(240, 320) : imageSize;
            XLOG_INFO(@"[ContactBG] device requires image size: %@ (w=%.0f, h=%.0f)", NSStringFromCGSize(targetSize), targetSize.width, targetSize.height);
            
            // 保存目标尺寸到实例变量，供相册选择后使用
            weakSelf.targetImageSize = targetSize;
            
            // 清除之前的结果图片
            dispatch_async(dispatch_get_main_queue(), ^{
                weakSelf.resultImageView.image = nil;
                weakSelf.resultImageView.hidden = YES;
            });
            
            // 在主线程中打开相册选择照片
            dispatch_async(dispatch_get_main_queue(), ^{
                UIImagePickerController *imagePicker = [[UIImagePickerController alloc] init];
                imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
                imagePicker.delegate = weakSelf;
                imagePicker.allowsEditing = NO; // 不编辑，我们自己裁切
                [weakSelf presentViewController:imagePicker animated:YES completion:nil];
            });
        }];
    }else if (indexPath.row == 7){
        
        [[[TPSSdk share] contactAbility] deleteContactBackgroundImageAtSlot:1 completion:^(BOOL success, NSError *error) {
            if (success) {
                XLOG_INFO(@"[ContactBG] delete succeeded for slot 0");
            } else {
                NSLog(@"[ContactBG] delete failed: %@", error);
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, success);
            });
        }];
    }
}

/**
 * 创建指定颜色的纯色图片
 */
- (UIImage *)ts_imageWithColor:(UIColor *)color size:(CGSize)size {
    UIGraphicsBeginImageContextWithOptions(size, YES, 1.0);
    [color setFill];
    UIRectFill(CGRectMake(0, 0, size.width, size.height));
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

/**
 * 生成不超过指定字节数的JPEG纯色图片（默认目标40KB以内）
 */
- (UIImage *)ts_solidJPEGImageWithColor:(UIColor *)color size:(CGSize)size maxBytes:(NSUInteger)maxBytes outBytes:(NSUInteger *)outBytes {
    if (maxBytes == 0) { maxBytes = 40 * 1024; }
    CGSize currentSize = size;
    if (currentSize.width <= 0 || currentSize.height <= 0) {
        currentSize = CGSizeMake(240, 320);
    }
    // 先生成无透明度的纯色UIImage（保持与设备要求相同的像素尺寸）
    UIGraphicsBeginImageContextWithOptions(currentSize, YES, 1.0);
    [color setFill];
    UIRectFill(CGRectMake(0, 0, currentSize.width, currentSize.height));
    UIImage *baseImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    // 仅通过质量压缩，尽力压到 maxBytes 以下，不改变像素尺寸
    CGFloat quality = 0.9;
    NSData *jpegData = UIImageJPEGRepresentation(baseImage, quality);
    while (jpegData.length > maxBytes && quality > 0.05) {
        quality -= 0.05;
        jpegData = UIImageJPEGRepresentation(baseImage, quality);
    }

    if (outBytes) { *outBytes = jpegData.length; }
    if (jpegData.length > maxBytes) {
        NSLog(@"[ContactBG][WARN] JPEG still exceeds %lu bytes after quality compression: %lu", (unsigned long)maxBytes, (unsigned long)jpegData.length);
    }

    UIImage *finalImage = [UIImage imageWithData:jpegData scale:1.0];
    return finalImage ?: baseImage;
}

#pragma mark - UIImagePickerControllerDelegate

/**
 * 用户选择照片后的回调
 */
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<UIImagePickerControllerInfoKey,id> *)info {
    [picker dismissViewControllerAnimated:YES completion:nil];
    
    UIImage *selectedImage = info[UIImagePickerControllerOriginalImage];
    if (!selectedImage) {
        NSLog(@"[ContactBG] Failed to get selected image");
        OpResultToastTip(self.view, NO);
        return;
    }
    
    XLOG_INFO(@"[ContactBG] selected image: dimensions=%@ (w=%.0f,h=%.0f)px", 
              NSStringFromCGSize(selectedImage.size), 
              selectedImage.size.width, 
              selectedImage.size.height);
    
    // 1. 裁切到目标尺寸（从中间裁切）
    UIImage *croppedImage = [self ts_cropImage:selectedImage toSize:self.targetImageSize];
    XLOG_INFO(@"[ContactBG] cropped image: dimensions=%@ (w=%.0f,h=%.0f)px", 
              NSStringFromCGSize(croppedImage.size), 
              croppedImage.size.width, 
              croppedImage.size.height);
    
    // 2. 压缩到40KB以内
    NSUInteger finalBytes = 0;
    UIImage *compressedImage = [self ts_compressJPEGImage:croppedImage maxBytes:(30 * 1024) outBytes:&finalBytes];
    XLOG_INFO(@"[ContactBG] compressed image: format=JPEG, bytes=%lu (<40960), dimensions=%@ (w=%.0f,h=%.0f)px",
              (unsigned long)finalBytes,
              NSStringFromCGSize(compressedImage.size),
              compressedImage.size.width,
              compressedImage.size.height);
    
    // 3. 保存图片到本地Documents目录
    NSString *savedImagePath = [self ts_saveImageToDocuments:compressedImage withFileName:@"contact_background_image"];
    if (savedImagePath) {
        XLOG_INFO(@"[ContactBG] Image saved to local path: %@", savedImagePath);
    } else {
        NSLog(@"[ContactBG] Failed to save image to local");
    }
    
    
    
//    TPSContactModel *model1 = [[TPSContactModel alloc] initWithName:@"Lily" phone:@"18910723096" initial:@""];
//    TPSContactModel *model2 = [[TPSContactModel alloc] initWithName:@"Jack" phone:@"15603325273" initial:@""];
//    TPSContactModel *model3 = [[TPSContactModel alloc] initWithName:@"jeseka" phone:@"15201063278" initial:@""];

    // 4. 开始上传
    NSInteger slotIndex = 2;
    NSString *phone = @"15201063278";

    
    // 在上传开始前显示结果图片
    dispatch_async(dispatch_get_main_queue(), ^{
        self.resultImageView.image = compressedImage;
        self.resultImageView.hidden = NO;
        XLOG_INFO(@"[ContactBG] Displaying result image before upload");
    });
    

    [[[TPSSdk share] contactAbility] updateContactBackgroundImageAtSlot:slotIndex contactPhone:phone backgroundImage:compressedImage progress:^(CGFloat progress) {
        XLOG_INFO(@"[ContactBG] update progress: %.0f%%", progress * 100.0);
    } completion:^(BOOL success, NSError *error) {
        if (success) {
            XLOG_INFO(@"[ContactBG] update completed successfully for slot %ld, phone=%@",(long)slotIndex ,phone);
        } else {
            NSLog(@"[ContactBG] update failed: %@", error);
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            OpResultToastTip(self.view, success);
        });
    }];
}

/**
 * 用户取消选择照片
 */
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
    [picker dismissViewControllerAnimated:YES completion:nil];
    XLOG_INFO(@"[ContactBG] User cancelled photo selection");
}

#pragma mark - Image Processing Methods

/**
 * 将图片裁切到指定尺寸（从中间裁切）
 */
- (UIImage *)ts_cropImage:(UIImage *)image toSize:(CGSize)targetSize {
    if (CGSizeEqualToSize(image.size, targetSize)) {
        return image; // 尺寸相同，无需裁切
    }
    
    // 计算裁切区域（从中间裁切）
    CGSize imageSize = image.size;
    CGFloat scaleX = targetSize.width / imageSize.width;
    CGFloat scaleY = targetSize.height / imageSize.height;
    CGFloat scale = MAX(scaleX, scaleY); // 取较大值，确保覆盖目标尺寸
    
    CGSize scaledSize = CGSizeMake(imageSize.width * scale, imageSize.height * scale);
    CGRect cropRect = CGRectMake((scaledSize.width - targetSize.width) / 2,
                                (scaledSize.height - targetSize.height) / 2,
                                targetSize.width,
                                targetSize.height);
    
    // 创建图形上下文并裁切
    UIGraphicsBeginImageContextWithOptions(targetSize, YES, 1.0);
    [image drawInRect:CGRectMake(-cropRect.origin.x / scale,
                                -cropRect.origin.y / scale,
                                scaledSize.width / scale,
                                scaledSize.height / scale)];
    UIImage *croppedImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return croppedImage;
}

/**
 * 压缩JPEG图片到指定字节数以内
 */
- (UIImage *)ts_compressJPEGImage:(UIImage *)image maxBytes:(NSUInteger)maxBytes outBytes:(NSUInteger *)outBytes {
    if (maxBytes == 0) { maxBytes = 40 * 1024; }
    
    // 通过质量压缩，尽力压到 maxBytes 以下
    CGFloat quality = 0.9;
    NSData *jpegData = UIImageJPEGRepresentation(image, quality);
    
    while (jpegData.length > maxBytes && quality > 0.05) {
        quality -= 0.05;
        jpegData = UIImageJPEGRepresentation(image, quality);
    }
    
    if (outBytes) { *outBytes = jpegData.length; }
    if (jpegData.length > maxBytes) {
        NSLog(@"[ContactBG][WARN] JPEG still exceeds %lu bytes after quality compression: %lu", (unsigned long)maxBytes, (unsigned long)jpegData.length);
    }
    
    UIImage *finalImage = [UIImage imageWithData:jpegData scale:1.0];
    return finalImage ?: image;
}

/**
 * 将图片保存到Documents目录
 */
- (NSString *)ts_saveImageToDocuments:(UIImage *)image withFileName:(NSString *)fileName {
    NSData *imageData = UIImageJPEGRepresentation(image, 0.9); // 使用JPEG格式保存
    if (!imageData) {
        return nil;
    }
    
    NSString *documentsPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
    NSString *filePath = [documentsPath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.jpg", fileName]];
    
    NSError *error = nil;
    BOOL success = [imageData writeToFile:filePath options:NSDataWritingAtomic error:&error];
    
    if (success) {
        return filePath;
    } else {
        NSLog(@"[ContactBG] Failed to save image to Documents: %@", error);
        return nil;
    }
}

/**
 * 获取Documents目录路径
 */
- (NSString *)ts_getDocumentsDirectoryPath {
    return [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end

