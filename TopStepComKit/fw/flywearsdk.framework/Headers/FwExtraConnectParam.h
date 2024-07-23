//
//  FwExtraConnectParam.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/30.
//

#ifndef FwExtraConnectParam_h
#define FwExtraConnectParam_h

@interface FwExtraConnectParam : NSObject

typedef NS_ENUM(UInt8, FwExtraConnectParam_Gender){
    FwExtraConnectParam_Gender_Female = 0,
    FwExtraConnectParam_Gender_Male = 1,
};

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

-(instancetype)initWithUserId:(NSString *)userId gender:(FwExtraConnectParam_Gender)gender age:(int)age height:(float)height weight:(float)weight;
-(instancetype)initWithUserId:(NSString *)userId gender:(FwExtraConnectParam_Gender)gender age:(int)age height:(float)height weight:(float)weight authCode:(NSString*)authCode;

@property(nonatomic, strong) NSString* userId;
@property(nonatomic, assign) FwExtraConnectParam_Gender gender;
@property(nonatomic, assign) int age;
@property(nonatomic, assign) float height;
@property(nonatomic, assign) float weight;
/**
 验证码，非必填。如果验证码一致，则绑定时跳过弹框确认。
 只用于绑定时无需恢复出厂的设备(目前仅传音805H项目生效)
 */
@property(nonatomic, strong) NSString* authCode;

@end


#endif /* FwExtraConnectParam_h */
