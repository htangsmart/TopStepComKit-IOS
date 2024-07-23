//
//  IFwFemalHeltheAbility.h
//  flywearsdk
//
//  Created by luigi on 2024/3/27.
//

#ifndef IFwFemalHeltheAbility_h
#define IFwFemalHeltheAbility_h

#import <flywearsdk/FwFemalHeltheModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>

@protocol IFwFemalHeltheAbility <NSObject, IFwWearBaseAbility>

typedef void(^FwFemalHeltheCallback)(FwFemalHeltheModel * femalHeltheModel);

+ (instancetype)share;

- (void)getFemalHeltheData:(FwFemalHeltheCallback)block;

- (void)sendFemalHeltheData:(FwFemalHeltheModel *)dataModel block:(FwSendMsgResult)block;

@end

#endif /* IFwFemalHeltheAbility_h */
