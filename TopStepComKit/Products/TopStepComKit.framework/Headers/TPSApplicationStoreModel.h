//
//  TPSApplicationStoreModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/3/6.
//

#import <Foundation/Foundation.h>

@class FwApplicationStoreModel;

NS_ASSUME_NONNULL_BEGIN

@interface TPSApplicationStoreModel : NSObject

@property (nonatomic, strong) NSString *appName;

@property (nonatomic, assign) BOOL isInstalled;

+ (NSArray<TPSApplicationStoreModel *> *)appStoreModelsFormFwModels:(NSArray<FwApplicationStoreModel *> *)fwModels;

+ (instancetype)appStoreModelWithFwModel:(FwApplicationStoreModel *)fwModel;

+ (BOOL)isContainPrayInModels:(NSArray<TPSApplicationStoreModel *> *)tpsModels;

- (BOOL)isPrayApp;

@end

NS_ASSUME_NONNULL_END
