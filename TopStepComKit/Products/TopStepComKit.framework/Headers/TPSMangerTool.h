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

-(UIImage *)createRoundPreviewWithBackgroudImage:(UIImage *)backgroundImage imageSize:(CGSize)imageSize;

- (void)previewImageViewWithBackgroundImage:(UIImage *)backgroundImage textImage:(UIImage *)textImage imageSize:(CGSize)imageSize cornerRadius:(CGFloat)cornerRadius complete:(void (^)(UIImage *resultImage))complete;

-(UIImage *)previewImageViewWithBackgroundImage:(UIImage *)backgroundImage textImage:(UIImage *)textImage imageSize:(CGSize)imageSize;

@end

NS_ASSUME_NONNULL_END
