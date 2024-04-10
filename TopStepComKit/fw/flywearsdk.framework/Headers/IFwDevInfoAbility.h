//
//  IWearDevInfoSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//

#ifndef IWearDevInfoSync_h
#define IWearDevInfoSync_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwDevInfoModel.h>
//#import <ReactiveObjC.h>

@class RACSubject<ValueType>;
@protocol IFwDevInfoAbility <NSObject,IFwWearBaseAbility>

+(instancetype)share;

-(RACSubject<FwDevInfoModel*>*)getDevInfo;

/**
 监听电池电量，返回的值为整数1--100
 */
-(RACSubject<NSNumber*>*)observeBattery;
-(void)resetToFactoryState:(FwSendMsgResult _Nullable)block;


-(FwDevInfoModel*)getExistDevInfo;
-(void)sendPhoneSystemTime;



- (RACSubject*)restartPeripheral;

- (RACSubject*)shutdownPeripheral;



@end


#endif /* IWearDevInfoSync_h */
