//
//  ITPSSynchronousDataAbility.h
//  TopStepComKit
//
//  Created by luigi on 2024/4/12.
//

#ifndef ITPSSynchronousDataAbility_h
#define ITPSSynchronousDataAbility_h
#import <TopStepComKit/ITPSWearBaseAbility.h>

typedef NS_OPTIONS(NSInteger, TSDataType) {
    ///
    TSDataType_None         = 0,
    /// 睡眠
    TSDataType_Sleep        = 1 << 0,
    /// 心率
    TSDataType_HeartRate    = 1 << 1,
    /// 步数
    TSDataType_Step         = 1 << 2,
    /// 血压
    TSDataType_BP           = 1 << 3,
    /// 血氧
    TSDataType_BO           = 1 << 4,
    /// 压力
    TSDataType_Stress       = 1 << 5,
    /// 运动
    TSDataType_Sport        = 1 << 6,
    /// 运动模式GPS
    TSDataType_SportGPS     = 1 << 7,
    /// 活动
    TSDataType_Activity     = 1 << 8,
    /// 静态心率
    TSDataType_RestQuietHeartRate     = 1 << 9,
    /// 当日活动
    TSDataType_TodayTotalActivity     = 1 << 10,
    /// 实时心率
    TSDataType_RealTimeHeartRate     = 1 << 11,
    /// 实时血氧
    TSDataType_RealTimeSPO2     = 1 << 12,

    /// 全部
    TSDataType_All = TSDataType_HeartRate | TSDataType_Step | TSDataType_BP | TSDataType_BO | TSDataType_Stress | TSDataType_Sport | TSDataType_SportGPS | TSDataType_Activity | TSDataType_RestQuietHeartRate | TSDataType_TodayTotalActivity | TSDataType_RealTimeHeartRate | TSDataType_RealTimeSPO2,
};

@protocol ITPSSynchronousDataAbility <NSObject, ITPSWearBaseAbility>

+ (instancetype _Nonnull )share;

/// 将手表数据同步到SDK
///  @param userID 当前用户的ID 用于标识数据属于哪个用户
///  @param block 同步完成后返回的结果，包含了同步失败的类型
- (void)synchronousDataWithUserID:(NSString *_Nullable)userID result:(void(^_Nullable)(TSDataType errorTypes))block;


- (void)synchronousDataWithType:(TSDataType)type userID:(NSString *)userID result:(void(^)(TSDataType errorTypes))block;


/// 删除SDK缓存数据
/// @param type 删除数据的类型
/// @param userID 有值删除指定用户的数据，空值删除所有用户的数据
- (void)clearDataCacheWithType:(TSDataType)type userID:(nullable NSString*)userID;

/// 查询SDK缓存数据
/// @param type 查询的数据的类型
/// @param timeStart 查询开始时间戳
/// @param timeEnd 查询结束时间戳
/// @param block 查询结果{ TSDataType : array }
- (void)getHistoryDataWithType:(TSDataType)type userID:(NSString *_Nullable)userID timeStart:(NSTimeInterval)timeStart timeEnd:(NSTimeInterval)timeEnd resultBlock:(void(^_Nullable)(NSDictionary<NSNumber *, NSArray *> * _Nullable result))block;
@end


#endif /* ITPSSynchronousDataAbility_h */
