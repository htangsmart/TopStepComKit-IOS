//
//  SearchingPeripheral.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/15.
//

#ifndef SearchingPeripheral_h
#define SearchingPeripheral_h

#import <CoreBluetooth/CoreBluetooth.h>

@interface FwScanResult : NSObject

+(instancetype) new NS_UNAVAILABLE;
-(instancetype) init NS_UNAVAILABLE;

-(instancetype) initWithPeripheral:(CBPeripheral*)peripheral mac:(NSString*)mac name:(NSString*)name RSSI:(NSNumber*)RSSI advertisementData:(NSDictionary<NSString *,id>*)advertisementData central:(CBCentralManager*)central;

@property(nonatomic, strong) CBPeripheral* peripheral;
//确实有一种拿不到mac的情况，如果用户连接成功后，又卸载app，此时系统的ble还连接，然后用户再次安装app，扫描的时候不会扫描到（因为属于还在系统连接中的），这时候就怎么也拿不到mac。（要考虑绑定成功后通过js返回mac）
@property(nonatomic, strong) NSString* mac;
@property(nonatomic, strong) NSString* name;
@property(nonatomic, strong) NSNumber* RSSI;
@property(nonatomic, strong) NSDictionary<NSString *,id>* advertisementData;
@property(nonatomic, strong) CBCentralManager* central;

@end


#endif /* SearchingPeripheral_h */
