//
//  NameCardModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/11.
//

#ifndef TPSNameCardModel_h
#define TPSNameCardModel_h

@class FwNameCardModel;
@interface TPSNameCardModel : NSObject

@property(nonatomic, strong) NSString* company;
@property(nonatomic, strong) NSString* qrCode;

-(instancetype)initWithFwModel:(FwNameCardModel*)fwNameCardModel;
+(NSArray<TPSNameCardModel*>*)toArrayWithFwModelArr:(NSArray<FwNameCardModel*>*)fwArr;
+(NSArray<FwNameCardModel*>*)toFwArrayWithTPSModelArr:(NSArray<TPSNameCardModel*>*)tpsArr;
-(FwNameCardModel*)toFwModel;

@end


#endif /* NameCardModel_h */
