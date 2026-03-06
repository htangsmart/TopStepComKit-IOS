//
//  TPSSportSlotModel.h
//  TopStepComKit
//
//  Created by Topstep on 2024/1/18.
//

#ifndef TPSSportSlotModel_h
#define TPSSportSlotModel_h

#import <Foundation/Foundation.h>
#import <TopStepComKit/TPSHistorySportModel.h>

/**
 * @brief Sport slot model for sport types on the device
 * @chinese 设备运动类型的槽位模型
 *
 * @discussion
 * [EN]: Represents a single sport type slot on the wearable device.
 * Each slot has an index and an associated sport type that can be queried or updated.
 * [CN]: 表示穿戴设备上的一个运动类型槽位。
 * 每个槽位有一个索引和一个关联的运动类型，支持查询和更新操作。
 */
@class FitCloudEditableWorkoutSlotModel;

@interface TPSSportSlotModel : NSObject

/**
 * @brief Slot index on the device
 * @chinese 设备上的槽位索引
 *
 * @discussion
 * [EN]: The position index of the sport type slot on the device.
 * Index starts from 0 and must be less than the total number of slots.
 * For example, if there are 10 slots, the valid index range is 0-9.
 * [CN]: 运动类型槽位在设备上的位置索引。
 * 索引从0开始，不能大于等于槽位总数。
 * 例如：如果有10个槽位，则索引范围为0-9。
 *
 * @note
 * [EN]: Valid range: 0 <= slotIndex < totalSlotCount
 * [CN]: 有效范围：0 <= slotIndex < 槽位总数
 */
@property (nonatomic, assign) NSInteger slotIndex;

/**
 * @brief Sport type associated with this slot
 * @chinese 该槽位关联的运动类型
 *
 * @discussion
 * [EN]: The sport type assigned to this slot. Refer to TPSSportDes_Type for all available sport types.
 * When the slot has no sport assigned, this value is TPSSportDes_Type_None (255).
 * [CN]: 分配给该槽位的运动类型。所有可用运动类型参见 TPSSportDes_Type 枚举。
 * 当槽位未分配运动时，该值为 TPSSportDes_Type_None (255)。
 *
 * @note
 * [EN]: Default value is TPSSportDes_Type_None, indicating an empty slot with no sport assigned.
 * [CN]: 默认值为 TPSSportDes_Type_None，表示空槽位，未分配任何运动类型。
 */
@property (nonatomic, assign) TPSSportDes_Type sportType;

/**
 * @brief Convert FitCloudEditableWorkoutSlotModel to TPSSportSlotModel
 * @chinese 将FitCloudEditableWorkoutSlotModel转换为TPSSportSlotModel
 *
 * @param fcSlot
 * EN: FitCloudEditableWorkoutSlotModel object to be converted
 * CN: 需要转换的FitCloudEditableWorkoutSlotModel对象
 *
 * @return
 * EN: Converted TPSSportSlotModel object, nil if fcSlot is nil
 * CN: 转换后的TPSSportSlotModel对象，fcSlot为nil时返回nil
 */
+ (nullable TPSSportSlotModel *)modelWithFitCloudEditableSlot:(nullable FitCloudEditableWorkoutSlotModel *)fcSlot;

/**
 * @brief Batch convert FitCloudEditableWorkoutSlotModel array to TPSSportSlotModel array
 * @chinese 批量将FitCloudEditableWorkoutSlotModel数组转换为TPSSportSlotModel数组
 *
 * @param fcSlots
 * EN: Array of FitCloudEditableWorkoutSlotModel objects to be converted
 * CN: 需要转换的FitCloudEditableWorkoutSlotModel对象数组
 *
 * @return
 * EN: Array of converted TPSSportSlotModel objects, nil if fcSlots is nil or empty
 * CN: 转换后的TPSSportSlotModel对象数组，fcSlots为nil或空时返回nil
 */
+ (nullable NSArray<TPSSportSlotModel *> *)modelsWithFitCloudEditableSlots:(nullable NSArray<FitCloudEditableWorkoutSlotModel *> *)fcSlots;

/**
 * @brief Convert TPSSportSlotModel to FitCloudEditableWorkoutSlotModel
 * @chinese 将TPSSportSlotModel转换为FitCloudEditableWorkoutSlotModel
 *
 * @return
 * EN: Converted FitCloudEditableWorkoutSlotModel object
 * CN: 转换后的FitCloudEditableWorkoutSlotModel对象
 */
- (nonnull FitCloudEditableWorkoutSlotModel *)toFitCloudEditableSlot;

/**
 * @brief Batch convert TPSSportSlotModel array to FitCloudEditableWorkoutSlotModel array
 * @chinese 批量将TPSSportSlotModel数组转换为FitCloudEditableWorkoutSlotModel数组
 *
 * @param models
 * EN: Array of TPSSportSlotModel objects to be converted
 * CN: 需要转换的TPSSportSlotModel对象数组
 *
 * @return
 * EN: Array of converted FitCloudEditableWorkoutSlotModel objects, nil if models is nil or empty
 * CN: 转换后的FitCloudEditableWorkoutSlotModel对象数组，models为nil或空时返回nil
 */
+ (nullable NSArray<FitCloudEditableWorkoutSlotModel *> *)toFitCloudEditableSlotsWithModels:(nullable NSArray<TPSSportSlotModel *> *)models;

/**
 * @brief Convert workoutType to TPSSportDes_Type
 * @chinese 将workoutType转换为TPSSportDes_Type
 *
 * @param workoutType
 * EN: Workout type value (0-157)
 * CN: 运动类型值（0-157）
 *
 * @return
 * EN: Corresponding TPSSportDes_Type enum value, returns TPSSportDes_Type_Other if not found
 * CN: 对应的TPSSportDes_Type枚举值，未找到时返回TPSSportDes_Type_Other
 */
+ (TPSSportDes_Type)convertWorkoutTypeToTPSSportType:(NSInteger)workoutType;

/**
 * @brief Convert TPSSportDes_Type to workoutType
 * @chinese 将TPSSportDes_Type转换为workoutType
 *
 * @param tpsType
 * EN: TPSSportDes_Type enum value
 * CN: TPSSportDes_Type枚举值
 *
 * @return
 * EN: Corresponding workoutType value, returns 21 (自由运动) if not found
 * CN: 对应的workoutType值，未找到时返回21（自由运动）
 */
+ (NSInteger)convertTPSSportTypeToWorkoutType:(TPSSportDes_Type)tpsType;

@end

#endif /* TPSSportSlotModel_h */
