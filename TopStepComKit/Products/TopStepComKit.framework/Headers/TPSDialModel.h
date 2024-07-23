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
    
    eDialTimePositionTopLeft = 4,
    eDialTimePositionBottomLeft = 5,
    eDialTimePositionTopRight = 6,
    eDialTimePositionBottomRight = 7,      

    
};

typedef NS_ENUM(NSUInteger, TSDialType) {
    
    eDialTypeLocal = 0,
    eDialTypeCustomer = 1,
    eDialTypeCloud = 2,
};

@class FwDialModel;
@class FitCloudWatchfaceSlot;

@interface TPSDialModel : NSObject

/// 表盘ID
@property(nonatomic, strong) NSString* dialId;
/// 背景图
@property(nonatomic, strong) NSString* alias;

@property(nonatomic, strong) NSString* dialName;

@property(nonatomic, strong) NSString* group;
@property(nonatomic, strong) NSString* icon;
@property(nonatomic, strong) NSString* version;

@property (nonatomic,strong) UIColor * textColor;
@property (nonatomic,strong) UIImage * textImage;

@property(nonatomic, assign) BOOL isEditable;
@property(nonatomic, assign) BOOL isHide;

@property (nonatomic,strong) NSString * filePath;

@property (nonatomic,strong) UIImage * backgroundImage;

@property (nonatomic,strong) UIImage * previewImage;

@property (nonatomic,assign) TSDialTimePosition dialTimePosition;

@property (nonatomic,assign) TSDialType dialType;



-(instancetype)initWithFwModel:(FwDialModel*)fwDialModel;

+(NSArray<TPSDialModel*>*)toTPSArrWithFwArr:(NSArray<FwDialModel*>*)fwArr;

- (instancetype)initWithFitModel:(FitCloudWatchfaceSlot *)fitDialModel;

@end


#endif /* DialModel_h */
