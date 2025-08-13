//
//  IWearContactSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/31.
//

#ifndef ITPSContactAbility_h
#define ITPSContactAbility_h
#import <UIKit/UIKit.h>

#import <TopStepComKit/TPSContactModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSContactImageSlot.h>

@class RACSubject<ValueType>;

/**
 * @brief Contact management ability protocol
 * @chinese 联系人管理能力协议
 *
 * @discussion
 * [EN]: This protocol defines the interface for managing contacts on wearable devices,
 * including emergency contacts, common contacts, and contact synchronization.
 * [CN]: 此协议定义了可穿戴设备上联系人管理的接口，包括紧急联系人、
 * 普通联系人和联系人同步等功能。
 *
 * @note
 * [EN]: Implements ITPSWearBaseAbility for basic wearable device functionality.
 * [CN]: 实现ITPSWearBaseAbility以获得基本的可穿戴设备功能。
 */
@protocol ITPSContactAbility <NSObject, ITPSWearBaseAbility>

/**
 * @brief Contact list callback block type
 * @chinese 联系人列表回调块类型
 *
 * @discussion
 * [EN]: Callback block for returning contact list data.
 * [CN]: 用于返回联系人列表数据的回调块。
 *
 * @param list Array of contact models
 * @chinese 联系人模型数组
 */
typedef void(^TPSContactListCallback)(NSArray<TPSContactModel*>* list);

/**
 * @brief Get shared instance
 * @chinese 获取共享实例
 *
 * @discussion
 * [EN]: Returns the singleton instance of the contact ability implementation.
 * [CN]: 返回联系人能力实现的单例实例。
 *
 * @return Shared instance of ITPSContactAbility
 * @chinese ITPSContactAbility的共享实例
 *
 * @note
 * [EN]: 1. Emoji symbols are replaced with *; 2. Contacts are sorted by first letter; 3. Maximum length is 32.
 * [CN]: 1. 表情符号换*号；2. 传首字母排序；3. 长度都32。
 */
+(instancetype)share;

/**
 * @brief Get emergency contact list
 * @chinese 获取紧急联系人列表
 *
 * @discussion
 * [EN]: Retrieves the list of emergency contacts configured on the device.
 * [CN]: 获取设备上配置的紧急联系人列表。
 *
 * @param block Callback block to receive the emergency contact list
 * @chinese 接收紧急联系人列表的回调块
 */
-(void)getEmergencyContact:(TPSContactListCallback)block;

/**
 * @brief Send emergency contact to device
 * @chinese 向设备发送紧急联系人
 *
 * @discussion
 * [EN]: Sends an emergency contact to the wearable device with SOS status.
 * [CN]: 向可穿戴设备发送紧急联系人，包含SOS状态。
 *
 * @param contactModel Contact model to send
 * @chinese 要发送的联系人模型
 * @param isSOSOn Whether SOS is enabled
 * @chinese SOS是否启用
 * @param complete Completion callback with success status and error information
 * @chinese 完成回调，包含成功状态和错误信息
 */
-(void)sendEmergencyContact:(TPSContactModel*)contactModel 
                      isSOSOn:(BOOL)isSOSOn 
                     complete:(void(^)(BOOL success,NSError *error))complete;

/**
 * @brief Get all contacts (excluding emergency contacts)
 * @chinese 获取所有联系人（不包含紧急联系人）
 *
 * @discussion
 * [EN]: Returns a reactive subject that provides all common contacts.
 * [CN]: 返回一个响应式主题，提供所有普通联系人。
 *
 * @return RACSubject that emits contact list arrays
 * @chinese 发出联系人列表数组的RACSubject
 *
 * @note
 * [EN]: This method excludes emergency contacts from the result.
 * [CN]: 此方法的结果中不包含紧急联系人。
 */
-(RACSubject<NSArray<TPSContactModel*>*>*)getAllContact;

/**
 * @brief Send common contacts to device
 * @chinese 向设备发送普通联系人
 *
 * @discussion
 * [EN]: Sends a list of common contacts to the wearable device.
 * [CN]: 向可穿戴设备发送普通联系人列表。
 *
 * @param list Array of contact models to send
 * @chinese 要发送的联系人模型数组
 * @param complete Completion callback with success status and error information
 * @chinese 完成回调，包含成功状态和错误信息
 */
-(void)sendCommonContact:(NSArray<TPSContactModel*>*)list 
                 complete:(void (^)(BOOL success, NSError *error))complete;

/**
 * @brief Observe contact changes
 * @chinese 观察联系人变化
 *
 * @discussion
 * [EN]: Returns a reactive subject that emits notifications when contacts change.
 * [CN]: 返回一个响应式主题，当联系人发生变化时发出通知。
 *
 * @return RACSubject that emits contact change notifications
 * @chinese 发出联系人变化通知的RACSubject
 *
 * @note
 * [EN]: Use this to monitor real-time changes in the contact list.
 * [CN]: 使用此方法来监控联系人列表的实时变化。
 */
-(RACSubject*)observeContactChange;

/**
 * @brief Query contact background image dimensions
 * @chinese 查询联系人背景图尺寸
 *
 * @discussion
 * [EN]: Retrieves the dimensions of the background image for contacts
 * on the wearable device. All contact background images have the same dimensions.
 * [CN]: 获取可穿戴设备上联系人背景图的尺寸。所有联系人背景图尺寸都一样。
 *
 * @param complete Completion callback with image dimensions and error information
 * @chinese 完成回调，包含图片尺寸和错误信息
 *
 * @note
 * [EN]: The dimensions are returned in pixels. If no background image exists,
 * the size will be CGSizeZero.
 * [CN]: 尺寸以像素为单位返回。如果没有背景图片，尺寸将为CGSizeZero。
 */
-(void)queryContactBackgroundImageDimensions:(void(^)(CGSize imageSize, NSError *error))complete;

/**
 * @brief Query contact background image slot information
 * @chinese 查询联系人背景图卡槽信息
 *
 * @discussion
 * [EN]: Retrieves the slot information for contact background images
 * on the wearable device, including slot status and image details.
 * [CN]: 获取可穿戴设备上联系人背景图的卡槽信息，包括卡槽状态和图片详情。
 *
 * @param success Success callback with slot array
 * @chinese 成功回调，包含卡槽数组
 * @param failure Failure callback with error information
 * @chinese 失败回调，包含错误信息
 *
 * @note
 * [EN]: On success, the success callback provides TPSContactImageSlot array.
 * On failure, the failure callback provides NSError details.
 * The array contains information about all available image slots.
 * [CN]: 成功时，成功回调提供TPSContactImageSlot数组。
 * 失败时，失败回调提供NSError详情。
 * 数组包含所有可用图片卡槽的信息。
 */
-(void)queryContactBackgroundImageSlotsSuccess:(void(^)(NSArray<TPSContactImageSlot*>* slots))success
                                       failure:(void(^)(NSError *error))failure;

/**
 * @brief Update contact background image at specified slot position
 * @chinese 在指定卡槽位置更新联系人背景图
 *
 * @discussion
 * [EN]: Updates the background image for a contact at the specified slot position.
 * This method supports progress tracking and completion notification.
 * [CN]: 在指定的卡槽位置更新联系人的背景图片。此方法支持进度跟踪和完成通知。
 *
 * @param slotIndex The index/position of the slot to update
 * @chinese 要更新的卡槽索引/位置
 * @param contactPhone The phone number of the contact
 * @chinese 联系人的电话号码
 * @param backgroundImage The background image to set
 * @chinese 要设置的背景图片
 * @param progress Progress callback block for tracking update progress
 * @chinese 进度回调块，用于跟踪更新进度
 * @param completion Completion callback block with success status and error information
 * @chinese 完成回调块，包含成功状态和错误信息
 *
 * @note
 * [EN]: 1. The progress callback provides a value between 0.0 and 1.0 indicating update progress.
 * 2. The completion callback is called when the update operation finishes (success or failure).
 * 3. The background image should match the dimensions returned by queryContactBackgroundImageDimensions:.
 * 4. If the slot is already occupied, the existing image will be replaced.
 * [CN]: 1. 进度回调提供0.0到1.0之间的值，表示更新进度。
 * 2. 完成回调在更新操作完成时调用（成功或失败）。
 * 3. 背景图片应该与queryContactBackgroundImageDimensions:返回的尺寸匹配。
 * 4. 如果卡槽已被占用，现有图片将被替换。
 */
-(void)updateContactBackgroundImageAtSlot:(NSInteger)slotIndex
                             contactPhone:(NSString *)contactPhone
                           backgroundImage:(UIImage *)backgroundImage
                                 progress:(void(^)(CGFloat progress))progress
                                completion:(void(^)(BOOL success, NSError *error))completion;

/**
 * @brief Delete contact background image at specified slot position
 * @chinese 删除指定卡槽位置的联系人背景图
 *
 * @discussion
 * [EN]: Removes the background image from the specified slot position.
 * This method only deletes the background image information associated with the slot,
 * and does not delete the actual contact information from the device.
 * [CN]: 删除指定卡槽位置的背景图片。此方法仅删除与卡槽关联的背景图信息，
 * 不会删除设备上的实际联系人信息。
 *
 * @param slotIndex The index/position of the slot to delete
 * @chinese 要删除的卡槽索引/位置
 * @param completion Completion callback block with success status and error information
 * @chinese 完成回调块，包含成功状态和错误信息
 *
 * @note
 * [EN]: 1. The completion callback is called when the delete operation finishes (success or failure).
 * 2. After successful deletion, the slot will be empty and available for new background image assignments.
 * 3. If the slot is already empty, the operation will still return success.
 * 4. Only the background image is removed; the contact phone number and other contact data remain unchanged.
 * 5. This operation does not affect the contact list or emergency contacts on the device.
 * [CN]: 1. 完成回调在删除操作完成时调用（成功或失败）。
 * 2. 删除成功后，卡槽将变为空状态，可用于新的背景图分配。
 * 3. 如果卡槽已经是空的，操作仍会返回成功。
 * 4. 仅删除背景图片；联系人电话号码和其他联系人数据保持不变。
 * 5. 此操作不会影响设备上的联系人列表或紧急联系人。
 */
-(void)deleteContactBackgroundImageAtSlot:(NSInteger)slotIndex
                               completion:(void(^)(BOOL success, NSError *error))completion;

@end

#endif /* ITPSContactSync_h */
