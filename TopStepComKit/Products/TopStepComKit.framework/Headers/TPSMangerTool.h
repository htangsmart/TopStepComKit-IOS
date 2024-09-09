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

- (void)previewImageViewWithBackgroundImage:(UIImage *)backgroundImage textImage:(UIImage *)textImage imageSize:(CGSize)imageSize cornerRadius:(CGFloat)cornerRadius complete:(void (^)(UIImage *resultImage))complete;

@end

NS_ASSUME_NONNULL_END
