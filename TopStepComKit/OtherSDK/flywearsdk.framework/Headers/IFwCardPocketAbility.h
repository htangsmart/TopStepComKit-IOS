//
//  IWearCardPocketSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/11.
//

#ifndef IWearCardPocketSync_h
#define IWearCardPocketSync_h

#import <flywearsdk/FwWalletModel.h>
#import <flywearsdk/FwNameCardModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>

@protocol IFwCardPocketAbility <NSObject, IFwWearBaseAbility>

typedef void(^FwCardPocketWalletListCallback)(NSMutableArray<FwWalletModel*>* walletList);
typedef void(^FwCardPocketNameCardListCallback)(NSMutableArray<FwNameCardModel*>* nameCardList);

+(instancetype)share;

-(void)getWalletCards:(FwCardPocketWalletListCallback)block;

-(void)sendWalletCards:(NSArray<FwWalletModel*>*) walletList;

-(void)getNameCards:(FwCardPocketNameCardListCallback)block;

-(void)sendNameCards:(NSArray<FwNameCardModel*>*) namcCardList;


@end


#endif /* IWearCardPocketSync_h */
