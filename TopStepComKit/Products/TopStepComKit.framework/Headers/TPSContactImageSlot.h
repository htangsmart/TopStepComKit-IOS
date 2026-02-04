//
//  TPSContactImageSlot.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/8/11.
//

#import <Foundation/Foundation.h>

@class FitCloudIncomingCallPhotoSlotModel;

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Contact background image slot information model
 * @chinese 联系人背景图片卡槽信息模型
 *
 * @discussion
 * [EN]: This model contains information about a contact background image slot,
 * including slot index, contact phone number, and background image status.
 * [CN]: 此模型包含联系人背景图片卡槽的信息，包括卡槽下标、联系人电话和背景图状态。
 */
@interface TPSContactImageSlot : NSObject

/**
 * @brief Slot index
 * @chinese 卡槽下标
 *
 * @discussion
 * [EN]: The index/position of the image slot in the device.
 * [CN]: 图片卡槽在设备中的索引/位置。
 *
 * @note
 * [EN]: Used to identify the specific slot for image operations.
 * [CN]: 用于标识图片操作的具体卡槽。
 */
@property (nonatomic, assign) NSInteger slotIndex;

/**
 * @brief Contact phone number
 * @chinese 联系人电话
 *
 * @discussion
 * [EN]: The phone number associated with this image slot.
 * [CN]: 与此图片卡槽关联的电话号码。
 *
 * @note
 * [EN]: Can be nil if no contact is assigned to this slot.
 * [CN]: 如果没有联系人分配到此卡槽，可以为nil。
 */
@property (nonatomic, strong, nullable) NSString *contactPhone;

/**
 * @brief Whether the slot has a background image
 * @chinese 卡槽是否有背景图
 *
 * @discussion
 * [EN]: Indicates whether this slot contains a background image.
 * [CN]: 表示此卡槽是否包含背景图片。
 *
 * @note
 * [EN]: YES if the slot has an image, NO if it's empty.
 * [CN]: 如果卡槽有图片则为YES，如果为空则为NO。
 */
@property (nonatomic, assign) BOOL hasBackgroundImage;

/**
 * @brief Initialize with slot parameters
 * @chinese 使用卡槽参数初始化
 *
 * @param slotIndex The index of the slot
 * @chinese 卡槽的索引
 * @param contactPhone The phone number of the contact
 * @chinese 联系人的电话号码
 * @param hasBackgroundImage Whether the slot has a background image
 * @chinese 卡槽是否有背景图
 *
 * @return Initialized TPSContactImageSlot instance
 * @chinese 初始化后的TPSContactImageSlot实例
 */
- (instancetype)initWithSlotIndex:(NSInteger)slotIndex
                     contactPhone:(nullable NSString *)contactPhone
                hasBackgroundImage:(BOOL)hasBackgroundImage;

/**
 * @brief Convert FitCloudIncomingCallPhotoSlotModel to TPSContactImageSlot
 * @chinese 将FitCloudIncomingCallPhotoSlotModel转换为TPSContactImageSlot
 *
 * @discussion
 * [EN]: This method converts a FitCloudIncomingCallPhotoSlotModel to TPSContactImageSlot.
 * It maps the properties from the FitCloud model to the corresponding TPS model properties.
 * [CN]: 此方法将FitCloudIncomingCallPhotoSlotModel转换为TPSContactImageSlot。
 * 它将FitCloud模型的属性映射到相应的TPS模型属性。
 *
 * @param fitCloudModel FitCloudIncomingCallPhotoSlotModel object to be converted
 * @chinese 需要转换的FitCloudIncomingCallPhotoSlotModel对象
 *
 * @return Converted TPSContactImageSlot object, nil if conversion fails
 * @chinese 转换后的TPSContactImageSlot对象，转换失败时返回nil
 *
 * @note
 * [EN]: 1. slotIndex maps to slotIndex
 * 2. phoneNumber maps to contactPhone
 * 3. hasPhoto maps to hasBackgroundImage
 * 4. Returns nil if the input model is nil
 * [CN]: 1. slotIndex映射到slotIndex
 * 2. phoneNumber映射到contactPhone
 * 3. hasPhoto映射到hasBackgroundImage
 * 4. 如果输入模型为nil则返回nil
 */
+ (nullable instancetype)modelWithFitCloudModel:(nullable FitCloudIncomingCallPhotoSlotModel *)fitCloudModel;

/**
 * @brief Convert FitCloudIncomingCallPhotoSlotModel array to TPSContactImageSlot array
 * @chinese 将FitCloudIncomingCallPhotoSlotModel数组转换为TPSContactImageSlot数组
 *
 * @discussion
 * [EN]: This method converts an array of FitCloudIncomingCallPhotoSlotModel to an array of TPSContactImageSlot.
 * It processes each model in the array and converts them individually using the single model conversion method.
 * [CN]: 此方法将FitCloudIncomingCallPhotoSlotModel数组转换为TPSContactImageSlot数组。
 * 它处理数组中的每个模型，并使用单个模型转换方法将它们分别转换。
 *
 * @param fitCloudModelArray Array of FitCloudIncomingCallPhotoSlotModel objects to be converted
 * @chinese 需要转换的FitCloudIncomingCallPhotoSlotModel对象数组
 *
 * @return Converted TPSContactImageSlot array, empty array if input is nil or empty
 * @chinese 转换后的TPSContactImageSlot数组，如果输入为nil或空则返回空数组
 *
 * @note
 * [EN]: 1. Returns an empty array if the input array is nil or empty
 * 2. Filters out nil results from individual conversions
 * 3. The order of elements in the result array matches the input array
 * 4. Each element is converted using modelWithFitCloudModel: method
 * [CN]: 1. 如果输入数组为nil或空则返回空数组
 * 2. 过滤掉单个转换中的nil结果
 * 3. 结果数组中元素的顺序与输入数组匹配
 * 4. 每个元素都使用modelWithFitCloudModel:方法进行转换
 */
+ (NSArray<TPSContactImageSlot *> *)modelArrayWithFitCloudModelArray:(nullable NSArray<FitCloudIncomingCallPhotoSlotModel *> *)fitCloudModelArray;

@end

NS_ASSUME_NONNULL_END
