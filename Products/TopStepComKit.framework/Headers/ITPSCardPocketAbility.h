//
//  IWearCardPocketSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/11.
//

#ifndef ITPSCardPocketAbility_h
#define ITPSCardPocketAbility_h

#import <TopStepComKit/TPSWalletModel.h>
#import <TopStepComKit/TPSNameCardModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

@protocol ITPSCardPocketAbility <NSObject, ITPSWearBaseAbility>

typedef void(^TPSCardPocketWalletListCallback)(NSMutableArray<TPSWalletModel*>* walletList);
typedef void(^TPSCardPocketNameCardListCallback)(NSMutableArray<TPSNameCardModel*>* nameCardList);

+(instancetype)share;

-(void)getWalletCards:(TPSCardPocketWalletListCallback)block;

-(void)sendWalletCards:(NSArray<TPSWalletModel*>*) walletList;

-(void)getNameCards:(TPSCardPocketNameCardListCallback)block;

-(void)sendNameCards:(NSArray<TPSNameCardModel*>*) namcCardList;


@end


#endif /* IWearCardPocketSync_h */
