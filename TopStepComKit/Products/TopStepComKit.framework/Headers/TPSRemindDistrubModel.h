//
//  TPSRemindDistrubModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/25.
//

#import <Foundation/Foundation.h>


@class FwRemindDistrubModel;

NS_ASSUME_NONNULL_BEGIN

@interface TPSRemindDistrubModel : NSObject

@property (nonatomic,assign) BOOL isEnabled;

@property (nonatomic,assign) double start;

@property (nonatomic,assign) double end;

+ (TPSRemindDistrubModel *)distrubModelWithFWDistrub:(FwRemindDistrubModel *)distrubModel;

- (NSDictionary *)toDictonary;

@end

NS_ASSUME_NONNULL_END
