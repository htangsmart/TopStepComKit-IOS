//
//  DialModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/23.
//


#ifndef TPSDialModel_h
#define TPSDialModel_h

typedef NS_ENUM(NSUInteger, TSDialTimePosition) {
    eDialTimePositionLeft = 0,        //左方
    eDialTimePositionTop = 1,         //上方
    eDialTimePositionRight = 2,       //右方
    eDialTimePositionBottom = 3,      //下方
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
