//
//  HistorySleepModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/19.
//

#ifndef TPSHistorySleepModel_h
#define TPSHistorySleepModel_h

@class FwHistorySleepModel;
//该类只表达从手表获取的原始数据，未做任何计算处理
@interface TPSHistorySleepModel : NSObject

typedef NS_ENUM(UInt8, TPSHistorySleep_Type){
    TPSHistorySleep_Type_Quickly_Eyes_Move = 1,
    TPSHistorySleep_Type_Light = 2,
    TPSHistorySleep_Type_Deep = 3,
    TPSHistorySleep_Type_Nap = 4,
    TPSHistorySleep_Type_Wake = 5,
};

//该段睡眠归属于哪一天,该天的零时时间戳秒。之所以有这个字段，是因为有的跨天睡眠归属日期会根据不同的项目有不同。该值不等同于睡眠所在的日期(譬如跨凌晨零点睡眠的情况下不等同于睡眠所在的日期，还有有的项目21:30后的睡眠都归类为属于次日的睡眠)。
//在BES项目上，这个值已经由手表计算给出。在Fitcloud上，这个值由sdk根据产品规则计算
@property(nonatomic, assign) long belongDay;
//TSDB记录该数据的时间戳，不一定等同于睡眠其实时间,秒
@property(nonatomic, assign) long record_time;
//该睡眠时段的起始时间戳,秒
@property (nonatomic, assign) long start_time;
@property (nonatomic, assign) TPSHistorySleep_Type type;
//该睡眠时段的时长，秒
@property (nonatomic, assign) int duration;

-(instancetype)initWithFwModel:(FwHistorySleepModel*)fwHistorySleepModel;
-(NSData*)toJsonNSData;

@end


#endif /* HistorySleepModel_h */
