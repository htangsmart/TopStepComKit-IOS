//
//  TPSExtraConnectParam.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/30.
//

#ifndef TPSExtraConnectParam_h
#define TPSExtraConnectParam_h

@interface TPSExtraConnectParam : NSObject

typedef NS_ENUM(UInt8, TPSExtraConnectParam_Gender){
    TPSExtraConnectParam_Gender_Female = 0,
    TPSExtraConnectParam_Gender_Male = 1,
};

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

-(instancetype)initWithUserId:(NSString *)userId gender:(TPSExtraConnectParam_Gender)gender age:(int)age height:(float)height weight:(float)weight;
-(instancetype)initWithUserId:(NSString *)userId gender:(TPSExtraConnectParam_Gender)gender age:(int)age height:(float)height weight:(float)weight authCode:(NSString*)authCode;

@property(nonatomic, strong) NSString* userId;
@property(nonatomic, assign) TPSExtraConnectParam_Gender gender;
@property(nonatomic, assign) int age;
@property(nonatomic, assign) float height;
@property(nonatomic, assign) float weight;
/**
 验证码，非必填。如果验证码一致，则绑定时跳过弹框确认。
 只用于绑定时无需恢复出厂的设备(目前仅传音805H项目生效)  851 随机码也适用
 */
@property(nonatomic, strong) NSString* authCode;



@end


#endif /* TPSExtraConnectParam_h */
