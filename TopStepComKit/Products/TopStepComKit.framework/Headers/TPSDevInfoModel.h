//
//  DevInfoModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//
#import <TopStepComKit/TPSDevLimitModel.h>

#ifndef TPSDevInfoModel_h
#define TPSDevInfoModel_h

@class FwDevInfoModel;

@interface TPSDevInfoModel : NSObject

/// 手表屏幕宽度
@property(nonatomic, assign) float screenWidth;
/// 手表屏幕高度
@property(nonatomic, assign) float screenHeight;

@property(nonatomic, assign) double app_installation_space;
/// 表盘预览图圆角大小
@property(nonatomic, assign) float screen_border_radius;
@property(nonatomic, strong) NSString* uiVersion;
@property(nonatomic, assign) int uiVersionCode;
@property(nonatomic, strong) NSString* firmVersion;
@property(nonatomic, assign) int firmVersionCode;
@property(nonatomic, strong) NSString* virtualVersion;
@property(nonatomic, assign) int virtualVersionCode;
@property(nonatomic, strong) NSString* mobo;
@property(nonatomic, strong) NSString* projectId;
/// mac地址 不带冒号
@property(nonatomic, strong) NSString* mac;

@property(nonatomic, strong) NSString* deviceModel;

@property(nonatomic, strong) NSString* deviceSn;

@property(nonatomic, strong) NSString* device_model;

@property(nonatomic, strong) NSString* device_sn;

@property(nonatomic, strong) NSString* os_version;

@property(nonatomic, strong) NSString* device_manufacturer;

@property(nonatomic, strong) NSString* screen_shape;

@property(nonatomic, strong) NSString* screen_size;

@property(nonatomic, strong) TPSDevLimitModel* limit;


@property (nonatomic,assign) CGFloat dialPreviewSize_width;

@property (nonatomic,assign) CGFloat dialPreviewSize_Height;

@property (nonatomic,assign) CGFloat dialPreviewCorner;


-(instancetype)initWithFwModel:(FwDevInfoModel*)fwDevInfoModel;



@end


#endif /* DevInfoModel_h */
