//
//  SportTargetModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/25.
//

#ifndef SportTargetModel_h
#define SportTargetModel_h

@interface FwSportTargetModel : NSObject

//今日活动时长 单位分钟
@property (nonatomic, assign) int stand_time;
//读取今日步数
@property (nonatomic, assign) int steps;
//读取今日高强度运动时长,单位分钟
@property (nonatomic, assign) int sport_time;
//读取今日活动次数
@property (nonatomic, assign) int sport_num;//表示这个时间段内的活动次数
//读取今日消耗的卡路里,单位千卡
@property (nonatomic, assign) double calorie;//表示这个时间段内活动消耗的卡路里，单位千卡
//读取今日的运动距离 米
@property (nonatomic, assign) double distance;//表示这个时间段内活动的距离，单位米
//修改时间，秒级时间戳
@property (nonatomic, assign) long modifyTime;

//NSArray* arr = @[
//    @"target.target_calories",//
//    @"target.target_distance",//
//    @"target.target_modify_time",
//    @"target.target_stand_time",//
//    @"target.target_steps",//
//    @"target.target_sport_time",//
//    @"target.target_sport_num"//
//];

@end


#endif /* SportTargetModel_h */
