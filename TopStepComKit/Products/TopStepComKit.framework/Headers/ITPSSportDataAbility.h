//
//  ITPSSportDataAbility.h
//  TopStepComKit
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSSportDataAbility_h
#define ITPSSportDataAbility_h

#import <TopStepComKit/TPSHistorySportModel.h>
#import <TopStepComKit/TPSSportSlotModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

/**
 * @brief Historical sport data ability protocol
 * @chinese 历史运动数据能力协议
 *
 * @discussion
 * [EN]: This protocol defines the interface for querying historical sport data from the wearable device.
 * It provides methods to retrieve sport records within a specified time range.
 * [CN]: 该协议定义了从穿戴设备查询历史运动数据的接口。
 * 提供了根据指定时间范围检索运动记录的方法。
 */
@protocol ITPSSportDataAbility <NSObject,ITPSWearBaseAbility>

/**
 * @brief Callback block for historical sport data query
 * @chinese 历史运动数据查询的回调block
 *
 * @discussion
 * [EN]: Called when historical sport data query completes. Returns an array of TPSHistorySportModel objects,
 * or nil if no data is available or an error occurred.
 * [CN]: 历史运动数据查询完成时调用。返回TPSHistorySportModel对象数组，
 * 如果没有数据或发生错误则返回nil。
 */
typedef void(^TPSHistorySportCallback)(NSArray<TPSHistorySportModel*>* _Nullable historySportModelList);

/**
 * @brief Get the shared singleton instance
 * @chinese 获取共享单例实例
 *
 * @return
 * EN: The shared singleton instance conforming to ITPSSportDataAbility protocol
 * CN: 遵循ITPSSportDataAbility协议的共享单例实例
 */
+(instancetype _Nonnull )share;

/**
 * @brief Get historical sport data within a specified time range
 * @chinese 根据时间范围获取历史运动数据
 *
 * @param startTime
 * EN: The start time of the query range, as a Unix timestamp in seconds
 * CN: 查询范围的起始时间，Unix时间戳（秒）
 *
 * @param endTime
 * EN: The end time of the query range, as a Unix timestamp in seconds. Note: some devices do not support end time filtering.
 * CN: 查询范围的截止时间，Unix时间戳（秒）。注意：部分设备不支持截止时间查询。
 *
 * @param block
 * EN: Callback block that returns an array of TPSHistorySportModel objects, nil if query fails or no data
 * CN: 回调block，返回TPSHistorySportModel对象数组，查询失败或无数据时返回nil
 *
 * @discussion
 * [EN]: Queries historical sport data recorded on the wearable device within the given time range.
 * The returned data includes sport type, duration, calories, heart rate, distance, and other metrics.
 * [CN]: 查询穿戴设备在给定时间范围内记录的历史运动数据。
 * 返回的数据包括运动类型、时长、卡路里、心率、距离等指标。
 */
-(void)getHistorySport:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistorySportCallback _Nullable)block;

/**
 * @brief Callback block for sport slot query
 * @chinese 运动槽位查询的回调block
 *
 * @discussion
 * [EN]: Called when the sport slot query completes. Returns an array of TPSSportSlotModel objects
 * representing the editable sport type slots on the device, or nil if query fails.
 * [CN]: 运动槽位查询完成时调用。返回TPSSportSlotModel对象数组，
 * 表示设备上可编辑的运动类型槽位信息，查询失败时返回nil。
 */
typedef void(^TPSSportSlotListCallback)(NSArray<TPSSportSlotModel *> * _Nullable sportSlotList);


/**
 * @brief Query the editable sport type slot information from the device
 * @chinese 查询设备上可编辑运动类型的槽位信息
 *
 * @param block
 * EN: Callback block that returns an array of TPSSportSlotModel objects, nil if query fails or no data
 * CN: 回调block，返回TPSSportSlotModel对象数组，查询失败或无数据时返回nil
 *
 * @discussion
 * [EN]: Queries the wearable device for only the editable sport type slots.
 * The device may have some sport slots that are fixed and cannot be changed by the user.
 * This method returns only the slots that the user is allowed to modify.
 * [CN]: 仅查询穿戴设备上可编辑的运动类型槽位。
 * 设备上部分运动槽位是固定的，用户无法更改。
 * 此方法仅返回用户可以修改的槽位。
 */
-(void)queryEditableSportSlots:(TPSSportSlotListCallback _Nullable)block;

/**
 * @brief Update sport type slot information on the device
 * @chinese 更新设备上的运动类型槽位信息
 *
 * @param slots
 * EN: An array of TPSSportSlotModel objects containing the updated slot information
 * CN: 包含更新槽位信息的TPSSportSlotModel对象数组
 *
 * @param completion
 * EN: Callback block indicating whether the update was successful, with an error object if it failed
 * CN: 回调block，指示更新是否成功，失败时包含错误对象
 *
 * @discussion
 * [EN]: Updates the sport type slot configuration on the wearable device.
 * Pass an array of TPSSportSlotModel objects with the desired slot index and sport type assignments.
 * [CN]: 更新穿戴设备上的运动类型槽位配置。
 * 传入包含目标槽位索引和运动类型分配的TPSSportSlotModel对象数组。
 */
-(void)updateEditableSportSlots:(NSArray<TPSSportSlotModel *> * _Nonnull)slots completion:(TPSCompletionBlock _Nullable)completion;

@end


#endif /* ITPSSportDataAbility_h */
