//
//  IWearConnectorSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef IWearConnectorSync_h
#define IWearConnectorSync_h

#import <flywearsdk/IFwConnectorAbility.h>
#import <flywearsdk/FwConnectResult.h>
#import <flywearsdk/FwExtraConnectParam.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <flywearsdk/FwScanResult.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwExPeripheral.h>

@class RACSubject<ValueType>;

@protocol IFwConnectorAbility <NSObject,IFwWearBaseAbility>


+(instancetype)share;

-(CBManagerState)getCBManagerState;
-(FwConnnectResult_State)getConnectState;
-(RACSubject<FwScanResult*>*)startScan;
-(void)stopScan;
/**
 @mac 设备的mac地址，每两个字符间要以冒号间隔，不区分大小写
 @extraParam 连接时需要的其他参数，包括userId，年龄，体重等
 */
-(RACSubject<FwConnectResult*>*)connectWithMac:(NSString*)mac extraParam:(FwExtraConnectParam*)extraParam;
-(RACSubject<FwConnectResult*>*)connectWithCBPeripheral:(CBPeripheral*)peripheral mac:(NSString*)mac extraParam:(FwExtraConnectParam*)extraParam;
-(RACSubject<FwConnectResult*>*)autoConnectLastPeripheralWithUserInfo:(FwExtraConnectParam*)extraParam;
-(void)cancelAutoConnectLastPeripheral;
-(RACSubject<FwConnectResult*>*)observeConnectResult;
-(void)disconnect;
-(void)unbindDevWithUserId:(NSString*)userId block:(FwSendMsgResult _Nullable)block;
-(FwExPeripheral*)getPeripheral;
-(RACSubject<NSNumber*>*_Nonnull)getIsBtConnected;

@end


#endif /* IWearEleBookSync_h */
