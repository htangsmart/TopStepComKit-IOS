//
//  FwDevLimitModel.h
//  flywearsdk
//
//  Created by 磐石 on 2024/5/29.
//

#import <Foundation/Foundation.h>

@interface FwDevLimitModel : NSObject

@property (nonatomic,assign) NSInteger innerDial;//内置表盘个数5个

@property (nonatomic,assign) NSInteger cloudDial;//云表盘限制个数，20个

@property (nonatomic,assign) NSInteger alarm;//闹钟最大个数 10

@property (nonatomic,assign) NSInteger contacts;//联系人最大个数 100

@property (nonatomic,assign) NSInteger remind;//个性化提醒中自定义提醒的最大个数

+ (FwDevLimitModel *)limitModelWithInfo:(NSDictionary *)info;

@end


