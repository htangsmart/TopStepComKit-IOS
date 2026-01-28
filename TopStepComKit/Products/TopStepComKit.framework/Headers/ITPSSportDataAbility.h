//
//  IWearHistorySportSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSSportDataAbility_h
#define ITPSSportDataAbility_h

#import <TopStepComKit/TPSHistorySportModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TSWorkoutSlotEditModel.h>

/**
 * @protocol ITPSSportDataAbility
 * @brief 运动数据能力协议接口 / Sports Data Ability Protocol Interface
 * 
 * @discussion 该协议定义了与智能穿戴设备进行运动数据交互的能力，包括：
 *             1. 获取历史运动数据
 *             2. 查询和编辑设备上的运动槽位配置
 * 
 *             This protocol defines the ability to interact with sports data from wearable devices, including:
 *             1. Retrieving historical sports data
 *             2. Querying and editing workout slot configurations on the device
 * 
 * @note 该协议继承自 ITPSWearBaseAbility，提供了基础的设备连接能力
 *       This protocol inherits from ITPSWearBaseAbility, providing basic device connection capabilities
 */
@protocol ITPSSportDataAbility <NSObject,ITPSWearBaseAbility>

/**
 * @typedef TPSHistorySportCallback
 * @brief 历史运动数据查询回调类型 / Historical Sports Data Query Callback Type
 * 
 * @param historySportModelList 历史运动数据模型数组，可能为nil
 *                              Array of historical sports data models, may be nil
 * 
 * @discussion 当获取历史运动数据完成时，会通过此回调返回结果
 *             This callback is invoked when historical sports data retrieval is completed
 */
typedef void(^TPSHistorySportCallback)(NSArray<TPSHistorySportModel*>* _Nullable historySportModelList);

/**
 * @method share
 * @brief 获取协议实现的单例实例 / Get the singleton instance of the protocol implementation
 * 
 * @return 返回 ITPSSportDataAbility 协议的单例实现对象
 *         Returns the singleton implementation object of ITPSSportDataAbility protocol
 * 
 * @discussion 使用单例模式确保整个应用中只有一个运动数据能力实例
 *             Uses singleton pattern to ensure only one sports data ability instance in the entire application
 */
+(instancetype _Nonnull )share;

/**
 * @method getHistorySport:endTime:block:
 * @brief 根据时间范围获取历史运动数据 / Get historical sports data based on time range
 * 
 * @param startTime 查询的起始时间戳（秒级时间戳，自1970年1月1日以来的秒数）
 *                  Start timestamp for query (seconds since January 1, 1970)
 * 
 * @param endTime 查询的结束时间戳（秒级时间戳，自1970年1月1日以来的秒数）
 *                注意：部分设备（如绅聚）不支持查询截止时间，此时endTime参数可能被忽略
 *                End timestamp for query (seconds since January 1, 1970)
 *                Note: Some devices (such as Shenju) do not support query end time, 
 *                in which case the endTime parameter may be ignored
 * 
 * @param block 查询完成后的回调块，返回历史运动数据数组
 *              Callback block invoked when query completes, returns array of historical sports data
 * 
 * @discussion 该方法会从连接的智能穿戴设备中获取指定时间范围内的所有历史运动记录。
 *             返回的数据包括运动类型、开始时间、结束时间、持续时间、距离、卡路里、
 *             心率、配速、步数等详细信息。
 * 
 *             This method retrieves all historical sports records within the specified time range 
 *             from the connected wearable device. The returned data includes detailed information 
 *             such as sport type, start time, end time, duration, distance, calories, heart rate, 
 *             pace, steps, etc.
 * 
 * @note 部分设备不支持查询截止时间（如绅聚设备），在这种情况下，endTime参数可能被忽略，
 *       设备会返回从startTime开始的所有可用历史运动数据
 *       Some devices do not support query end time (such as Shenju devices). In this case, 
 *       the endTime parameter may be ignored, and the device will return all available 
 *       historical sports data starting from startTime
 * 
 * @warning 请确保设备已连接且支持历史运动数据查询功能
 *          Please ensure the device is connected and supports historical sports data query functionality
 */
-(void)getHistorySport:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistorySportCallback _Nullable)block;

/**
 * @property allowEditWorkoutSlots
 * @brief 是否支持编辑运动槽位 / Whether editing workout slots is supported
 * 
 * @discussion 该属性指示当前连接的设备是否支持运动槽位的编辑功能。
 *             运动槽位是设备上预配置的运动类型快捷入口，用户可以通过编辑槽位
 *             来快速启动常用的运动模式。
 * 
 *             This property indicates whether the currently connected device supports 
 *             editing workout slots. Workout slots are pre-configured quick access entries 
 *             for sport types on the device. Users can edit slots to quickly start 
 *             commonly used sport modes.
 * 
 * @note 在使用 queryWorkoutSlotsOnWatchWithCompletion: 或 editWorkoutSlotsOnWatch:completion: 
 *       方法之前，建议先检查此属性的值，以确保设备支持相应功能
 *       Before using queryWorkoutSlotsOnWatchWithCompletion: or editWorkoutSlotsOnWatch:completion: 
 *       methods, it is recommended to check the value of this property to ensure the device 
 *       supports the corresponding functionality
 */
@property (nonatomic, assign) BOOL allowEditWorkoutSlots;

/**
 * @method queryWorkoutSlotsOnWatchWithCompletion:
 * @brief 查询手表当前运动槽位配置 / Query current workout slot configuration on the watch
 * 
 * @param completion 查询完成后的回调块 / Callback block invoked when query completes
 *   @param success 查询是否成功 / Whether the query was successful
 *   @param workoutSlots 运动槽位数组，包含每个槽位的索引、运动类型和推送通知设置等信息。
 *                       如果查询失败，此参数为nil
 *                       Array of workout slots, containing information such as slot index, 
 *                       workout type, and push notification settings for each slot.
 *                       This parameter is nil if the query fails
 *   @param error 如果查询失败，此参数包含错误信息；如果成功，此参数为nil
 *                If the query fails, this parameter contains error information; 
 *                if successful, this parameter is nil
 * 
 * @discussion 该方法会从连接的智能穿戴设备中查询当前配置的所有运动槽位信息。
 *             每个槽位包含以下信息：
 *             - 槽位索引（slotIndex）：槽位在设备上的位置编号
 *             - 运动类型（workoutType）：该槽位对应的运动类型标识符
 *
 *             This method queries all currently configured workout slot information from 
 *             the connected wearable device. Each slot contains the following information:
 *             - Slot Index (slotIndex): The position number of the slot on the device
 *             - Workout Type (workoutType): The sport type identifier corresponding to this slot
 *
 * @note 在调用此方法前，建议先检查 allowEditWorkoutSlots 属性，确保设备支持此功能
 *       Before calling this method, it is recommended to check the allowEditWorkoutSlots 
 *       property to ensure the device supports this functionality
 * 
 * @warning 如果设备不支持运动槽位查询功能，completion回调中的success参数将为NO，
 *          且error参数会包含相应的错误信息
 *          If the device does not support workout slot query functionality, the success 
 *          parameter in the completion callback will be NO, and the error parameter 
 *          will contain corresponding error information
 */
- (void)queryEditableWorkoutSlotsOnWatchWithCompletion:(void (^_Nullable)(BOOL success, NSArray<TSWorkoutSlotEditModel *> *_Nullable workoutSlots, NSError *_Nullable error))completion;

/**
 * @method editWorkoutSlotsOnWatch:completion:
 * @brief 编辑运动槽位配置 / Edit workout slot configuration
 * 
 * @param workoutSlots 要编辑的运动槽位数组，每个 TSWorkoutSlotEditModel 对象代表一个槽位的编辑操作
 *                     Array of workout slots to edit. Each TSWorkoutSlotEditModel object 
 *                     represents an edit operation for one slot
 * 
 * @param completion 编辑完成后的回调块 / Callback block invoked when editing completes
 *   @param success 编辑是否成功 / Whether the editing was successful
 *   @param error 如果编辑失败，此参数包含错误信息；如果成功，此参数为nil
 *                If editing fails, this parameter contains error information; 
 *                if successful, this parameter is nil
 * 
 * @discussion 该方法用于修改智能穿戴设备上的运动槽位配置。通过传入 TSWorkoutSlotEditModel 数组，
 *             可以同时编辑多个槽位。每个编辑模型包含：
 *             - slotIndex：要编辑的槽位索引
 *             - workoutType：要设置的运动类型（NSNumber类型）。如果设置为nil，表示删除该槽位中的运动
 * 
 *             使用示例：
 *             - 设置槽位0为跑步类型：workoutType = @(1)
 *             - 删除槽位1的运动：workoutType = nil
 * 
 *             This method is used to modify workout slot configurations on the wearable device. 
 *             By passing an array of TSWorkoutSlotEditModel objects, multiple slots can be edited 
 *             simultaneously. Each edit model contains:
 *             - slotIndex: The index of the slot to edit
 *             - workoutType: The sport type to set (NSNumber type). If set to nil, 
 *               it means deleting the sport in this slot
 * 
 *             Usage example:
 *             - Set slot 0 to running type: workoutType = @(1)
 *             - Delete sport in slot 1: workoutType = nil
 * 
 * @note 在调用此方法前，建议先检查 allowEditWorkoutSlots 属性，确保设备支持此功能
 *       Before calling this method, it is recommended to check the allowEditWorkoutSlots 
 *       property to ensure the device supports this functionality
 * 
 * @note 运动类型标识符（workoutType）的值应该参考 TPSHistorySportModel 中定义的 
 *       TPSSportDes_Type 枚举值，例如：
 *       - TPSSportDes_Type_OutdoorRunning = 1 (户外跑步)
 *       - TPSSportDes_Type_Treadmill = 7 (跑步机)
 *       - TPSSportDes_Type_Yoga = 85 (瑜伽)
 * 
 *       The workout type identifier (workoutType) value should refer to the TPSSportDes_Type 
 *       enum values defined in TPSHistorySportModel, for example:
 *       - TPSSportDes_Type_OutdoorRunning = 1 (Outdoor Running)
 *       - TPSSportDes_Type_Treadmill = 7 (Treadmill)
 *       - TPSSportDes_Type_Yoga = 85 (Yoga)
 * 
 * @warning 如果设备不支持运动槽位编辑功能，completion回调中的success参数将为NO，
 *          且error参数会包含相应的错误信息
 *          If the device does not support workout slot editing functionality, the success 
 *          parameter in the completion callback will be NO, and the error parameter 
 *          will contain corresponding error information
 */
- (void)updateEditableWorkoutSlotsOnWatch:(NSArray<TSWorkoutSlotEditModel*>*_Nonnull)workoutSlots completion:(void(^_Nonnull)(BOOL success, NSError *_Nullable error))completion;
@end

#endif /* IWearCurDayActivitySync_h */
