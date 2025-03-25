//
//  FwApplicationStoreModel.h
//  flywearsdk
//
//  Created by 磐石 on 2025/3/6.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface FwApplicationStoreModel : NSObject


@property (nonatomic, strong) NSString *appName;

@property (nonatomic, assign) BOOL isInstalled;

+ (NSArray<FwApplicationStoreModel *> *)appStoreModelsFormFwNames:(NSArray<NSString *> *)fwAppNames;

- (instancetype)initWithName:(NSString *)appName installed:(BOOL)installed;

@end

NS_ASSUME_NONNULL_END
