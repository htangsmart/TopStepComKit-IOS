//
//  UserProfileController.h
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/3.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ContactsController : UITableViewController <UIImagePickerControllerDelegate, UINavigationControllerDelegate>

/**
 * @brief Result image view to display the processed contact background image
 * @chinese 用于显示处理后的联系人背景图的结果图片视图
 */
@property (nonatomic, strong) UIImageView *resultImageView;

@end

NS_ASSUME_NONNULL_END
