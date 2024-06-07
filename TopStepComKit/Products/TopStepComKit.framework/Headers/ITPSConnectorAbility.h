//
//  IWearConnectorSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef ITPSConnectorAbility_h
#define ITPSConnectorAbility_h

#import <TopStepComKit/ITPSConnectorAbility.h>
#import <TopStepComKit/TPSConnectResult.h>
#import <TopStepComKit/TPSExtraConnectParam.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <TopStepComKit/TPSScanResult.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSExPeripheral.h>

@class RACSubject<ValueType>;

@protocol ITPSConnectorAbility <NSObject,ITPSWearBaseAbility>


+(instancetype)share;

-(CBManagerState)getCBManagerState;
-(TPSConnnectResult_State)getConnectState;
-(RACSubject<TPSScanResult*>*)startScan;

//- (void)beginScanSuccess:(void(^)(TPSScanResult *result))success;

-(void)stopScan;
/**
 @mac 设备的mac地址，每两个字符间要以冒号间隔，不区分大小写
 @extraParam 连接时需要的其他参数，包括userId，年龄，体重等
 */
-(RACSubject<TPSConnectResult*>*)connectWithMac:(NSString*)mac extraParam:(TPSExtraConnectParam*)extraParam;
//-(void)connectWithMac:(NSString*)mac extraParam:(TPSExtraConnectParam*)extraParam success:(void(^)(TPSConnectResult *result))success;


-(RACSubject<TPSConnectResult*>*)connectWithCBPeripheral:(CBPeripheral*)peripheral mac:(NSString*)mac extraParam:(TPSExtraConnectParam*)extraParam;
//-(void)connectWithCBPeripheral:(CBPeripheral*)peripheral mac:(NSString*)mac extraParam:(TPSExtraConnectParam*)extraParam success:(void(^)(TPSConnectResult *result))success;


-(RACSubject<TPSConnectResult*>*)autoConnectLastPeripheralWithUserInfo:(TPSExtraConnectParam*)extraParam;
-(void)cancelAutoConnectLastPeripheral;
-(RACSubject<TPSConnectResult*>*)observeConnectResult;
-(void)disconnect;
-(void)unbindDevWithUserId:(NSString*)userId block:(TPSSendMsgResult _Nullable)block;
-(TPSExPeripheral*)getPeripheral;
-(RACSubject<NSNumber*>*_Nonnull)getIsBtConnected;

@end


#endif /* IWearEleBookSync_h */
