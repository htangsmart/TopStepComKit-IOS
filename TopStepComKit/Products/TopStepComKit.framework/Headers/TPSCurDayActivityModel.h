//
//  CurDayActivityModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef TPSCurDayActivityModel_h
#define TPSCurDayActivityModel_h

@interface TPSCurDayActivityModel : NSObject

//读取今日站立时长 小时
@property (nonatomic, assign) double stand_time;
//读取今日步数
@property (nonatomic, assign) int steps;
//读取今日高强度运动时长,单位分钟
@property (nonatomic, assign) int sport_time;
//读取今日活动次数
@property (nonatomic, assign) int sport_num;//表示这个时间段内的活动次数
//读取今日消耗的卡路里
@property (nonatomic, assign) double calorie;//表示这个时间段内活动消耗的卡路里，单位千卡
//读取今日的运动距离 米
@property (nonatomic, assign) double distance;//表示这个时间段内活动的距离，单位米
//读取连续久坐时间,单位分钟
@property (nonatomic, assign) double sit_time;

-(instancetype)initWithDcmDict:(NSDictionary *)dict;




@end


#endif /* CurDayActivityModel_h */
