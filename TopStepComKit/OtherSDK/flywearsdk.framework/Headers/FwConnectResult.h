//
//  ConnectResult.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/30.
//

#ifndef ConnectResult_h
#define ConnectResult_h

@interface FwConnectResult : NSObject

typedef NS_ENUM(UInt8, FwConnnectResult_State){
    FwConnnectResult_State_Disconnected = 0,
    FwConnnectResult_State_Connecting,
    FwConnnectResult_State_Connected,
};

typedef NS_ENUM(UInt8, FwConnnectResult_Error_Code){
    FwConnnectResult_Error_Code_Success = 0,
    FwConnnectResult_Error_Code_Scanning,
    FwConnnectResult_Error_Code_Ble_Failed,
    FwConnnectResult_Error_Code_Binding,
    FwConnnectResult_Error_Code_Lose_Signal,
    FwConnnectResult_Error_Code_Disconnect_By_User_InApp,
    FwConnnectResult_Error_Code_Under_IOS13,
    FwConnnectResult_Error_Code_Low_Battery,
    FwConnnectResult_Error_Code_Wait_Reboot,
    FwConnnectResult_Error_Code_Other_Fail,
    FwConnnectResult_Error_Code_Disconnect_By_User_InSystemSetting,
};

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

-(instancetype)initWithState:(FwConnnectResult_State)state errorCode:(FwConnnectResult_Error_Code)errorCode;

@property(nonatomic, assign) FwConnnectResult_State state;
@property(nonatomic, assign) FwConnnectResult_Error_Code errorCode;



@end


#endif /* ConnectResult_h */
