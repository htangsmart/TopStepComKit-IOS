//
//  AlarmEntity.h
//  JieliJianKang
//
//  Created by Topstep on 2023/8/31.
//

#import <Foundation/Foundation.h>

@interface FwAlarmModel : NSObject
/// 闹钟id，全局唯一，格式，"alarmItem" + Date.now().toString(36)，后来在7003上改成"alarmItem" + 20亿以内的随机数
@property(nonatomic,strong)NSString*  clockId;
/// 闹钟名
@property(nonatomic,strong)NSString *label;
@property(nonatomic,assign)int  hour;
@property(nonatomic,assign)int  min;
@property(nonatomic,assign)BOOL  enable;
@property(nonatomic,assign)BOOL isRemindLater;
@property(nonatomic,strong)NSArray  *repeatDays;



+(FwAlarmModel *)alarmJsonToObject:(NSDictionary*)dic;
-(NSDictionary*)toAlarmJson;

-(NSString*)stringRepeatDaysStr;

-(NSArray*)stringRepeatDaysArr;

-(int)getClockNumId;
-(NSString*)genFwIdWithNumId:(int)numId;


@end

