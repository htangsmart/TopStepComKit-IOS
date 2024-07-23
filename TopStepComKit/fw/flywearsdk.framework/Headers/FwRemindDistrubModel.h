//
//  FwRemindDistrubModel.h
//  flywearsdk
//
//  Created by 磐石 on 2024/3/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FwRemindDistrubModel : NSObject

@property (nonatomic,assign) BOOL isEnabled;

@property (nonatomic,assign) double start;

@property (nonatomic,assign) double end;

+(FwRemindDistrubModel *)distrubModelWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
