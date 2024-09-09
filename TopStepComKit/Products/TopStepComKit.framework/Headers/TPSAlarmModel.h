//
//  AlarmEntity.h
//  JieliJianKang
//
//  Created by Topstep on 2023/8/31.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/TSJConnectorAbility.h>

@class FitCloudAlarmObject;
@class WMAlarmModel;

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

@interface TPSAlarmModel : NSObject

@property(nonatomic,assign)int alarmId;
@property (nonatomic,strong) NSString * alarmIdentifier;
@property(nonatomic,strong)NSString *label;
@property(nonatomic,assign)int  hour;
@property(nonatomic,assign)int  min;
@property(nonatomic,assign)BOOL  enable;
@property(nonatomic,assign)BOOL isRemindLater;
@property (nonatomic, copy) NSString * remark;
@property (nonatomic, assign) TPSAlarmRepeat repeatOptions;




-(instancetype)initWithFCPModel:(FitCloudAlarmObject*)fcpAlarmModel;
-(FitCloudAlarmObject*)toFCPModel;



+(NSArray<TPSAlarmModel*>*)toTPSArrayWithFCPModelArr:(NSArray<FitCloudAlarmObject*>*)fcpArr;


+(NSArray<FitCloudAlarmObject*>*)toFCPArrayWithTPSModelArr:(NSArray<TPSAlarmModel*>*)tpsArr;

-(instancetype)initWithWMModel:(WMAlarmModel*)wmAlarmModel;
-(WMAlarmModel*)toWModel;
+ (NSArray<WMAlarmModel *> *)toWMAlarmModelWithArray:(NSArray *)alarms;
+ (NSArray<TPSAlarmModel *> *)toTPSAlarmModelWithWMArray:(NSArray *)alarms;

@end

