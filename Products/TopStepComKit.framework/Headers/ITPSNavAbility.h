//
//  IWearNavSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/1.
//

#ifndef ITPSNavAbility_h
#define ITPSNavAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>

@class RACSubject<ValueType>;
@protocol ITPSNavAbility <NSObject,ITPSWearBaseAbility>

typedef NS_ENUM(UInt8, TPSWearNav_Map_Type){
    TPSWearNav_Map_Type_Baidu = 1,
    TPSWearNav_Map_Type_Gaode = 2,
};

typedef NS_ENUM(UInt8, TPSWearNav_Trip_Mode){
    TPSWearNav_Trip_Mode_Bike = 1,
    TPSWearNav_Trip_Mode_EleBike = 2,
    TPSWearNav_Trip_Mode_Walk = 3,
};

typedef NS_ENUM(UInt8, TPSWearNav_Direction){
    //0是非法
    TPSWearNav_Direction_Error = 0,
    //开始导航 1
    TPSWearNav_Direction_Start = 1,
    //直行 2
    TPSWearNav_Direction_Straight = 2,
    //右前方转弯 3
    TPSWearNav_Direction_TurnRightAlong = 3,
    //右转 4
    TPSWearNav_Direction_TurnRight = 4,
    //右后方转弯 5
    TPSWearNav_Direction_turnRightBackArr = 5,
    //左后方转弯 6
    TPSWearNav_Direction_turnLeftBackArr = 6,
    //左转 7
    TPSWearNav_Direction_turnLeftArr = 7,
    //左前转弯 8
    TPSWearNav_Direction_turnLeftAlongArr = 8,
    //左掉头 9
    TPSWearNav_Direction_leftBackArr = 9,
    //右掉头 10
    TPSWearNav_Direction_rightBackArr = 10,
    //到达 11
    TPSWearNav_Direction_arriveArr = 11,
    //楼梯 12
    TPSWearNav_Direction_stairArr = 12,
};

+(instancetype)share;

-(void)sendBeginNav;

///地图类型和出行方式
///@param mapType 1--百度地图  2--高德地图
///@param tripmMode  1--自行车  2-电动车  3--步行
-(void)sendMapType:(TPSWearNav_Map_Type)mapType tripMode:(TPSWearNav_Trip_Mode)tripmMode;

-(void)sendNavDirection:(TPSWearNav_Direction)direction;

-(void)sendExitNav;

-(void)sendArriveDestination;

-(void)sendRemainTime:(int)senconds;

-(void)sendRemainDistance:(int)distance;

-(void)sendNavInfo:(NSString*)info;

-(RACSubject*)observeNavExit;

@end


#endif /* IWearNavSync_h */
