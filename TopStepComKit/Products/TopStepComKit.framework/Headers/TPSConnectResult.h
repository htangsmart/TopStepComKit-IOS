//
//  ConnectResult.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/30.
//

#ifndef TPSConnectResult_h
#define TPSConnectResult_h

@class FwConnectResult;
@interface TPSConnectResult : NSObject

typedef NS_ENUM(UInt8, TPSConnnectResult_State){
    TPSConnnectResult_State_Disconnected = 0,
    TPSConnnectResult_State_Connecting,
    TPSConnnectResult_State_Connected,
};

typedef NS_ENUM(UInt8, TPSConnnectResult_Error_Code){
    TPSConnnectResult_Error_Code_Success = 0,
    TPSConnnectResult_Error_Code_Scanning,
    TPSConnnectResult_Error_Code_Ble_Failed,
    TPSConnnectResult_Error_Code_Binding,
    TPSConnnectResult_Error_Code_Lose_Signal,
    TPSConnnectResult_Error_Code_Disconnect_By_User_InApp,
    TPSConnnectResult_Error_Code_Under_IOS13,
    TPSConnnectResult_Error_Code_Low_Battery,
    TPSConnnectResult_Error_Code_Wait_Reboot,
    TPSConnnectResult_Error_Code_Other_Fail,
    TPSConnnectResult_Error_Code_Disconnect_By_User_InSystemSetting,
    TPSConnnectResult_Error_Code_Ota_DFU_Mode,
};

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

-(instancetype)initWithState:(TPSConnnectResult_State)state errorCode:(TPSConnnectResult_Error_Code)errorCode;
-(instancetype)initWithFwModel:(FwConnectResult*)fwConnectResult;

@property(nonatomic, assign) TPSConnnectResult_State state;
@property(nonatomic, assign) TPSConnnectResult_Error_Code errorCode;



@end


#endif /* ConnectResult_h */
