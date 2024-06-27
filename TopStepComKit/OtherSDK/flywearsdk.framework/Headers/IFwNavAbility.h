//
//  IWearNavSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/1.
//

#ifndef IWearNavSync_h
#define IWearNavSync_h

#import <flywearsdk/IFwWearBaseAbility.h>

@class RACSubject<ValueType>;
@protocol IFwNavAbility <NSObject,IFwWearBaseAbility>

typedef NS_ENUM(UInt8, FwWearNav_Map_Type){
    FwWearNav_Map_Type_Baidu = 1,
    FwWearNav_Map_Type_Gaode = 2,
};

typedef NS_ENUM(UInt8, FwWearNav_Trip_Mode){
    FwWearNav_Trip_Mode_Bike = 1,
    FwWearNav_Trip_Mode_EleBike = 2,
    FwWearNav_Trip_Mode_Walk = 3,
};

typedef NS_ENUM(UInt8, FwWearNav_Direction){
    //0是非法
    FwWearNav_Direction_Error = 0,
    //开始导航 1
    FwWearNav_Direction_Start = 1,
    //直行 2
    FwWearNav_Direction_Straight = 2,
    //右前方转弯 3
    FwWearNav_Direction_TurnRightAlong = 3,
    //右转 4
    FwWearNav_Direction_TurnRight = 4,
    //右后方转弯 5
    FwWearNav_Direction_turnRightBackArr = 5,
    //左后方转弯 6
    FwWearNav_Direction_turnLeftBackArr = 6,
    //左转 7
    FwWearNav_Direction_turnLeftArr = 7,
    //左前转弯 8
    FwWearNav_Direction_turnLeftAlongArr = 8,
    //左掉头 9
    FwWearNav_Direction_leftBackArr = 9,
    //右掉头 10
    FwWearNav_Direction_rightBackArr = 10,
    //到达 11
    FwWearNav_Direction_arriveArr = 11,
    //楼梯 12
    FwWearNav_Direction_stairArr = 12,
};

+(instancetype)share;

-(void)sendBeginNav;

///地图类型和出行方式
///@param mapType 1--百度地图  2--高德地图
///@param tripmMode  1--自行车  2-电动车  3--步行
-(void)sendMapType:(FwWearNav_Map_Type)mapType tripMode:(FwWearNav_Trip_Mode)tripmMode;

-(void)sendNavDirection:(FwWearNav_Direction)direction;

-(void)sendExitNav;

-(void)sendArriveDestination;

-(void)sendRemainTime:(int)senconds;

-(void)sendRemainDistance:(int)distance;

-(void)sendNavInfo:(NSString*)info;

-(RACSubject*)observeNavExit;

@end


#endif /* IWearNavSync_h */
