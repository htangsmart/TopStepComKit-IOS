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
@class FwContactModel;
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

@end


//#endif /* ContactModel_h */
