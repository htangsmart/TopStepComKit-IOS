//
//  WalletModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/11.
//

#ifndef TPSWalletModel_h
#define TPSWalletModel_h

@class FwWalletModel;
@interface TPSWalletModel : NSObject

@property(nonatomic, strong) NSString* company;
@property(nonatomic, strong) NSString* qrCode;

-(instancetype)initWithFwModel:(FwWalletModel*)fwNameCardModel;

+(NSArray<TPSWalletModel*>*)toArrayWithFwModelArr:(NSArray<FwWalletModel*>*)fwArr;
+(NSArray<FwWalletModel*>*)toFwArrayWithTPSModelArr:(NSArray<TPSWalletModel*>*)tpsArr;
-(FwWalletModel*)toFwModel;

@end

#endif /* WalletModel_h */
