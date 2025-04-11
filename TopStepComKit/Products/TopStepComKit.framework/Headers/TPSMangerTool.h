//
//  TPSMangerTool.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/9/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TPSMangerTool : NSObject

+ (instancetype)share ;

- (void)dealImage:(UIImage *)targetImage toMaxKBSize:(CGFloat)toMaxKBSize imageSize:(CGSize)imageSize cornerRadius:(CGFloat)cornerRadius completion:(void (^)(UIImage *))completion;

- (void)previewImageViewWithBackgroundImage:(UIImage *)backgroundImage textImage:(UIImage *)textImage imageSize:(CGSize)imageSize cornerRadius:(CGFloat)cornerRadius completion:(void (^)(UIImage *resultImage))completion;

- (CGSize)dialPreviewSize;

- (CGFloat)dialPreviewCorner;

- (CGFloat)dialBackgroundImageCorner;

/**
 * @brief Save image to Document/test/ directory with timestamp filename
 * @chinese 将图片保存到Document/test/目录下，使用时间戳命名
 *
 * @param image
 * EN: The image to be saved
 * CN: 需要保存的图片
 *
 * @return
 * EN: The full path of the saved image file, nil if saving fails
 * CN: 保存的图片文件的完整路径，如果保存失败则返回nil
 */
- (nullable NSString *)saveImageToDocumentWithTimestamp:(UIImage *)image folder:(NSString *)folder;

@end

NS_ASSUME_NONNULL_END
