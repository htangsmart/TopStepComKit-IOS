//
//  ExPeripheral.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/20.
//

#ifndef ExPeripheral_h
#define ExPeripheral_h

#import <CoreBluetooth/CoreBluetooth.h>

@interface FwExPeripheral : NSObject

@property(nonatomic, strong) CBPeripheral *peripheral;
//确实有一种拿不到mac的情况，如果用户连接成功后，又卸载app，此时系统的ble还连接，然后用户再次安装app，扫描的时候不会扫描到（因为属于还在系统连接中的），这时候就怎么也拿不到mac。（要考虑绑定成功后通过js返回mac）
@property(nonatomic, strong) NSString* mac;
@property(nonatomic, strong) NSString* name;
@property(nonatomic, strong) NSNumber* RSSI;
@property(nonatomic, strong) NSDictionary<NSString *,id>* advertisementData;
@property(nonatomic, strong) CBCentralManager* central;

@end


#endif /* ExPeripheral_h */
