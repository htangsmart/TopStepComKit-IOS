//
//  DialModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/23.
//

#ifndef DialModel_h
#define DialModel_h

@interface FwDialModel : NSObject

@property(nonatomic, strong) NSString* dialId;

@property(nonatomic, strong) NSString* alias;
@property(nonatomic, strong) NSString* group;
@property(nonatomic, strong) NSString* icon;
@property(nonatomic, strong) NSString* version;

@property(nonatomic, assign) BOOL isEditable;
@property(nonatomic, assign) BOOL isHide;


@end


#endif /* DialModel_h */
