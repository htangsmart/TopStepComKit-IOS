//
//  DialModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/23.
//

#ifndef TPSDialModel_h
#define TPSDialModel_h

typedef NS_ENUM(NSUInteger, TSDialTimePosition) {
    eDialTimePositionTop = 0,         //上方
    eDialTimePositionBottom = 1,      //下方
    eDialTimePositionLeft = 2,        //左方
    eDialTimePositionRight = 3,       //右方
};

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

@property (nonatomic,strong) NSString * filePath;

@property (nonatomic,strong) UIImage * backgroundImage;

@property (nonatomic,strong) UIImage * previewImage;

@property (nonatomic,assign) TSDialTimePosition dialTimePosition;

-(instancetype)initWithFwModel:(FwDialModel*)fwDialModel;

+(NSArray<TPSDialModel*>*)toTPSArrWithFwArr:(NSArray<FwDialModel*>*)fwArr;

@end


#endif /* DialModel_h */
