//
//  DevInfoModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//
#import <flywearsdk/FwDevLimitModel.h>
#ifndef DevInfoModel_h
#define DevInfoModel_h



@interface FwDevInfoModel : NSObject

@property(nonatomic, assign) float screenWidth;
@property(nonatomic, assign) float screenHeight;

@property(nonatomic, assign) double app_installation_space;
@property(nonatomic, assign) float screen_border_radius;

@property(nonatomic, strong) NSString* uiVersion;
@property(nonatomic, assign) int uiVersionCode;
@property(nonatomic, strong) NSString* firmVersion;
@property(nonatomic, assign) int firmVersionCode;
@property(nonatomic, strong) NSString* virtualVersion;
@property(nonatomic, assign) int virtualVersionCode;
@property(nonatomic, strong) NSString* mobo;
@property(nonatomic, strong) NSString* projectId;
@property(nonatomic, strong) NSString* mac;

@property(nonatomic, strong) NSString* device_model;
@property(nonatomic, strong) NSString* device_sn;
@property(nonatomic, strong) NSString* os_version;
@property(nonatomic, strong) NSString* device_manufacturer;
@property(nonatomic, strong) NSString* screen_shape;
@property(nonatomic, strong) NSString* screen_size;

@property(nonatomic, strong) NSString* dialPreview;

@property(nonatomic, strong) FwDevLimitModel* limit;




@property (nonatomic,assign) CGFloat dialPreviewSize_width;

@property (nonatomic,assign) CGFloat dialPreviewSize_Height;

@property (nonatomic,assign) CGFloat dialPreviewCorner;







@end


#endif /* DevInfoModel_h */
