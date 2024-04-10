//
//  ContactModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/31.
//

#ifndef ContactModel_h
#define ContactModel_h

#import <Foundation/Foundation.h>

@interface FwContactModel : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

-(instancetype)initWithName:(NSString*)name phone:(NSString*)phone initial:(NSString*)initial;

@property(nonatomic, strong) NSString* name;
@property(nonatomic, strong) NSString* phone;
/**
 名字的首字母，列表可以按这个排序。传#表示没有需要排序
 */
@property(nonatomic, strong) NSString* initial;

@end


#endif /* ContactModel_h */
