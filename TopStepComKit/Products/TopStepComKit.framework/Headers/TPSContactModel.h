//
//  ContactModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/31.
//

//#ifndef TPSContactModel_h
//#define TPSContactModel_h

#import <Foundation/Foundation.h>

@class FitCloudContactObject;
@class FitCloudEmergencyContactObject;

/**
 * @brief Contact information model
 * @chinese 联系人信息模型
 *
 * @discussion
 * [EN]: This model represents contact information including name, phone number, and initial.
 * It provides conversion methods between TPS format and FitCloud format.
 * [CN]: 此模型表示联系人信息，包括姓名、电话号码和首字母。
 * 它提供了TPS格式和FitCloud格式之间的转换方法。
 *
 * @note
 * [EN]: 1. Name maximum length is 32 bytes; 2. Phone maximum length is 20 bytes.
 * [CN]: 1. 姓名最大长度为32字节；2. 电话最大长度为20字节。
 */
@interface TPSContactModel : NSObject

/**
 * @brief Contact name
 * @chinese 联系人姓名
 *
 * @discussion
 * [EN]: The name of the contact, automatically truncated to maximum 32 bytes.
 * [CN]: 联系人的姓名，自动截断到最大32字节。
 */
@property(nonatomic, strong) NSString* name;

/**
 * @brief Contact phone number
 * @chinese 联系人电话号码
 *
 * @discussion
 * [EN]: The phone number of the contact, automatically truncated to maximum 20 bytes.
 * [CN]: 联系人的电话号码，自动截断到最大20字节。
 */
@property(nonatomic, strong) NSString* phone;

/**
 * @brief First letter of contact name
 * @chinese 联系人姓名首字母
 *
 * @discussion
 * [EN]: The first letter of the contact name, used for sorting and grouping.
 * [CN]: 联系人姓名的首字母，用于排序和分组。
 */
@property(nonatomic, strong) NSString* initial;



+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

/**
 * @brief Initialize with contact information
 * @chinese 使用联系人信息初始化
 *
 * @param name Contact name
 * @chinese 联系人姓名
 * @param phone Contact phone number
 * @chinese 联系人电话号码
 * @param initial First letter of the contact name
 * @chinese 联系人姓名的首字母
 *
 * @return Initialized TPSContactModel instance
 * @chinese 初始化后的TPSContactModel实例
 */
-(instancetype)initWithName:(NSString*)name phone:(NSString*)phone initial:(NSString*)initial;


/**
 * @brief Convert FitCloud contact array to TPS contact array
 * @chinese 将FitCloud联系人数组转换为TPS联系人数组
 *
 * @param fwArr Array of FitCloudContactObject
 * @chinese FitCloudContactObject数组
 *
 * @return Array of TPSContactModel
 * @chinese TPSContactModel数组
 */
+(NSArray<TPSContactModel*>*)toTPSArrWithFCPArr:(NSArray<FitCloudContactObject*>*)fwArr;

/**
 * @brief Convert TPS contact array to FitCloud contact array
 * @chinese 将TPS联系人数组转换为FitCloud联系人数组
 *
 * @param tpsArr Array of TPSContactModel
 * @chinese TPSContactModel数组
 *
 * @return Array of FitCloudContactObject
 * @chinese FitCloudContactObject数组
 */
+(NSArray<FitCloudContactObject*>*)toFCPArrWithTPSArr:(NSArray<TPSContactModel*>*)tpsArr;

/**
 * @brief Convert TPS emergency contact to FitCloud emergency contact array
 * @chinese 将TPS紧急联系人转换为FitCloud紧急联系人数组
 *
 * @param model TPSContactModel instance
 * @chinese TPSContactModel实例
 *
 * @return Array of FitCloudEmergencyContactObject
 * @chinese FitCloudEmergencyContactObject数组
 */
+ (NSArray<FitCloudEmergencyContactObject *>*)emergencyToTFCPEmergencyArr:(TPSContactModel *)model;

/**
 * @brief Convert FitCloud emergency contact array to TPS emergency contact array
 * @chinese 将FitCloud紧急联系人数组转换为TPS紧急联系人数组
 *
 * @param fwArr Array of FitCloudEmergencyContactObject
 * @chinese FitCloudEmergencyContactObject数组
 *
 * @return Mutable array of TPSContactModel
 * @chinese TPSContactModel可变数组
 */
+ (NSMutableArray <TPSContactModel *> *)emergencyToArrWithFCPArr:(NSArray <FitCloudEmergencyContactObject *>*)fwArr;

@end

//#endif /* ContactModel_h */
