//
//  IFwApplicationStoreAbility.h
//  flywearsdk
//
//  Created by 磐石 on 2025/3/6.
//

#import <flywearsdk/IFwWearBaseAbility.h>
#import <Foundation/Foundation.h>
#import "FwApplicationStoreModel.h"
NS_ASSUME_NONNULL_BEGIN


typedef void (^FWApplicationResultBlock)(NSArray<FwApplicationStoreModel *> *apps, NSError *_Nullable error);
typedef void (^FWApplicationDidChangedBlock)(FwApplicationStoreModel *app, NSError *_Nullable error);

@protocol IFwApplicationStoreAbility <NSObject, IFwWearBaseAbility>

- (void)getInstalledApplicationCompletion:(FWApplicationResultBlock)completion;

- (void)registerAppStateDidChangedBlock:(FWApplicationDidChangedBlock)didChangedBlock;

@end

NS_ASSUME_NONNULL_END
