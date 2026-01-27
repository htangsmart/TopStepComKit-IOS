//
//  ContactModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/31.
//

//#ifndef TPSContactModel_h
//#define TPSContactModel_h

#import <Foundation/Foundation.h>
#import <TopStepComKit/TSJConnectorAbility.h>

@class FitCloudContactObject;
@class FitCloudEmergencyContactObject;
@class FwContactModel;
@class WMContactModel;
@class WMEmergencyContactModel;
@interface TPSContactModel : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

-(instancetype)initWithName:(NSString*)name phone:(NSString*)phone initial:(NSString*)initial;

@property(nonatomic, strong) NSString* name;
@property(nonatomic, strong) NSString* phone;
@property(nonatomic, strong) NSString* initial;

-(instancetype)initWithFwModel:(FwContactModel*)fwContactModel;
+(NSArray<TPSContactModel*>*)toTPSArrWithFwArr:(NSArray<FwContactModel*>*)fwArr;
+(NSArray<FwContactModel*>*)toFwArrWithTPSArr:(NSArray<TPSContactModel*>*)tpsArr;
-(FwContactModel*)toFwModel;


+(NSArray<TPSContactModel*>*)toTPSArrWithFCPArr:(NSArray<FitCloudContactObject*>*)fwArr;

+(NSArray<FitCloudContactObject*>*)toFCPArrWithTPSArr:(NSArray<TPSContactModel*>*)tpsArr;

// 拼装紧急联系人
+ (NSArray<FitCloudEmergencyContactObject *>*)emergencyToTFCPEmergencyArr:(TPSContactModel *)model;
+ (NSMutableArray <TPSContactModel *> *)emergencyToArrWithFCPArr:(NSArray <FitCloudEmergencyContactObject *>*)fwArr;




-(instancetype)initWithWMModel:(WMContactModel*)wmContactModel;
-(instancetype)initWithWMEmergencyModel:(WMEmergencyContactModel*)wmEmergencyModel;
-(WMContactModel*)toWMModel;
- (WMEmergencyContactModel *)toWMEmergencyModel;
+(NSArray<WMContactModel*>*)toWMModelArrayWithTPSArray:(NSArray *)tpsArray;

+(NSArray<TPSContactModel*>*)tpsModelArrayWithEmergencyArray:(NSArray *)emergencyArray;
+(NSArray<TPSContactModel*>*)tpsModelArrayWithWMArray:(NSArray *)wmArray;


@end


//#endif /* ContactModel_h */
