//
//  IWearDevInfoSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//

#ifndef ITPSDevInfoAbility_h
#define ITPSDevInfoAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSDevInfoModel.h>
//#import <ReactiveObjC.h>

@class RACSubject<ValueType>;
@protocol ITPSDevInfoAbility <NSObject,ITPSWearBaseAbility>

+(instancetype)share;

-(RACSubject<TPSDevInfoModel*>*)getDevInfo;

-(RACSubject<NSNumber*>*)observeBattery;

-(void)resetToFactoryState:(TPSSendMsgResult _Nullable)block;

-(TPSDevInfoModel*)getExistDevInfo;

-(void)sendPhoneSystemTime;

- (RACSubject*)restartPeripheral;

- (RACSubject*)shutdownPeripheral;

- (void)updateBattery:(CGFloat)batteryValue;

- (void)getCurrentBatteryInfo:(void (^)(NSNumber * _Nonnull))success;


@end


#endif /* IWearDevInfoSync_h */
