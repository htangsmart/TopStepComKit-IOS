//
//  TSWorkoutSlotEditModel.h
//  TopStepComKit
//
//  Created by luigi on 2026/1/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class TSWorkoutSlotEditModel
 * @brief 运动槽位编辑模型类 / Workout Slot Edit Model Class
 * 
 * @discussion 该类用于编辑智能穿戴设备上的运动槽位配置。通过创建该模型的实例并设置相应的属性，
 *             可以修改设备上指定槽位的运动类型，或者删除槽位中的运动配置。
 * 
 *             使用场景：
 *             1. 设置槽位：创建模型，设置slotIndex和workoutType（非nil）
 *             2. 删除槽位：创建模型，设置slotIndex，workoutType设置为nil
 * 
 *             This class is used to edit workout slot configurations on wearable devices. 
 *             By creating instances of this model and setting the corresponding properties, 
 *             you can modify the sport type of a specified slot on the device, or delete 
 *             the sport configuration in a slot.
 * 
 *             Usage scenarios:
 *             1. Set slot: Create model, set slotIndex and workoutType (non-nil)
 *             2. Delete slot: Create model, set slotIndex, set workoutType to nil
 * 
 * @note 该模型类通常与 ITPSSportDataAbility 协议的 editWorkoutSlotsOnWatch:completion: 方法
 *       配合使用，用于批量编辑多个运动槽位
 *       This model class is typically used with the editWorkoutSlotsOnWatch:completion: method 
 *       of the ITPSSportDataAbility protocol to batch edit multiple workout slots
 */
@interface TSWorkoutSlotEditModel : NSObject

/**
 * @property slotIndex
 * @brief 要编辑的槽位索引位置 / The index position of the slot to edit
 * 
 * @discussion 指定要编辑的运动槽位在设备上的位置编号，通常从0开始递增。
 *             例如：0表示编辑第一个槽位，1表示编辑第二个槽位，以此类推。
 * 
 *             Specifies the position number of the workout slot to edit on the device, 
 *             usually starting from 0 and incrementing. For example: 0 represents editing 
 *             the first slot, 1 represents editing the second slot, and so on.
 * 
 * @warning 请确保slotIndex的值在设备支持的槽位范围内，否则编辑操作可能会失败
 *          Please ensure the slotIndex value is within the range of slots supported by the device, 
 *          otherwise the edit operation may fail
 */
@property(nonatomic, assign) NSUInteger slotIndex;

/**
 * @property workoutType
 * @brief 要设置的运动类型标识符 / The workout type identifier to set
 * 
 * @discussion 指定要设置到该槽位的运动类型。该值应该参考 TPSHistorySportModel 中定义的
 *             TPSSportDes_Type 枚举值，并使用 NSNumber 包装。
 * 
 *             特殊说明：
 *             - 如果设置为非nil值（如 @(1)），表示将该槽位设置为对应的运动类型
 *             - 如果设置为nil，表示删除该槽位中的运动配置（清空槽位）
 * 
 *             Specifies the sport type to set for this slot. This value should refer to the 
 *             TPSSportDes_Type enum values defined in TPSHistorySportModel, and be wrapped 
 *             in an NSNumber.
 * 
 *             Special notes:
 *             - If set to a non-nil value (e.g., @(1)), it means setting the slot to the 
 *               corresponding sport type
 *             - If set to nil, it means deleting the sport configuration in this slot (clearing the slot)
 * 
 * @note 运动类型标识符的常见值示例：
 *       - @(1): 户外跑步 (Outdoor Running)
 *       - @(7): 跑步机 (Treadmill)
 *       - @(11): 户外骑行 (Outdoor Cycling)
 *       - @(85): 瑜伽 (Yoga)
 *       更多运动类型请参考 TPSHistorySportModel.h 中的 TPSSportDes_Type 枚举定义
 * 
 *       Common workout type identifier examples:
 *       - @(1): Outdoor Running
 *       - @(7): Treadmill
 *       - @(11): Outdoor Cycling
 *       - @(85): Yoga
 *       For more sport types, please refer to the TPSSportDes_Type enum definition in TPSHistorySportModel.h
 * 
 * @example 使用示例 / Usage Example:
 * @code
 * // 设置槽位0为户外跑步 / Set slot 0 to outdoor running
 * TSWorkoutSlotEditModel *model = [[TSWorkoutSlotEditModel alloc] init];
 * model.slotIndex = 0;
 * model.workoutType = @(TPSSportDes_Type_OutdoorRunning);
 * 
 * // 删除槽位1的运动配置 / Delete sport configuration in slot 1
 * TSWorkoutSlotEditModel *deleteModel = [[TSWorkoutSlotEditModel alloc] init];
 * deleteModel.slotIndex = 1;
 * deleteModel.workoutType = nil;
 * @endcode
 */
@property(nonatomic, copy, nullable) NSNumber* workoutType;

@end

NS_ASSUME_NONNULL_END
