//
//  AlarmEntity.h
//  JieliJianKang
//
//  Created by Topstep on 2023/8/31.
//

#import <Foundation/Foundation.h>

@class FitCloudAlarmObject;
typedef NS_OPTIONS(uint8_t, TPSAlarmRepeat) {
    TPSAlarmRepeatNone      = 0,
    TPSAlarmRepeatMonday    = 1 << 0,
    TPSAlarmRepeatTuesday   = 1 << 1,
    TPSAlarmRepeatWednesday = 1 << 2,
    TPSAlarmRepeatThursday  = 1 << 3,
    TPSAlarmRepeatFriday    = 1 << 4,
    TPSAlarmRepeatSaturday  = 1 << 5,
    TPSAlarmRepeatSunday    = 1 << 6,
};

@class FitCloudAlarmObject;
@class FwAlarmModel;
@interface TPSAlarmModel : NSObject

@property(nonatomic,assign)int alarmId;
@property(nonatomic,strong)NSString *label;
@property(nonatomic,assign)int  hour;
@property(nonatomic,assign)int  min;
@property(nonatomic,assign)BOOL  enable;
@property(nonatomic,assign)BOOL isRemindLater;
@property (nonatomic, assign) TPSAlarmRepeat repeatOptions;

-(instancetype)initWithFwModel:(FwAlarmModel*)fwAlarmModel;
+(NSArray<TPSAlarmModel*>*)toTPSArrayWithFwModelArr:(NSArray<FwAlarmModel*>*)fwArr;
+(NSArray<FwAlarmModel*>*)toFwArrayWithTPSModelArr:(NSArray<TPSAlarmModel*>*)tpsArr;
-(FwAlarmModel*)toFwModel;


+(NSArray<TPSAlarmModel*>*)toTPSArrayWithFCPModelArr:(NSArray<FitCloudAlarmObject*>*)fcpArr;
+(NSArray<FitCloudAlarmObject*>*)toFCPArrayWithTPSModelArr:(NSArray<TPSAlarmModel*>*)tpsArr;


@end

