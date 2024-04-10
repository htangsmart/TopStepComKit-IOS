//
//  DialModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/23.
//

#ifndef TPSDialModel_h
#define TPSDialModel_h

@class FwDialModel;
@interface TPSDialModel : NSObject

/// 表盘ID
@property(nonatomic, strong) NSString* dialId;
/// 背景图
@property(nonatomic, strong) NSString* alias;

@property(nonatomic, strong) NSString* group;
@property(nonatomic, strong) NSString* icon;
@property(nonatomic, strong) NSString* version;

@property(nonatomic, assign) BOOL isEditable;
@property(nonatomic, assign) BOOL isHide;


-(instancetype)initWithFwModel:(FwDialModel*)fwDialModel;

+(NSArray<TPSDialModel*>*)toTPSArrWithFwArr:(NSArray<FwDialModel*>*)fwArr;

@end


#endif /* DialModel_h */
