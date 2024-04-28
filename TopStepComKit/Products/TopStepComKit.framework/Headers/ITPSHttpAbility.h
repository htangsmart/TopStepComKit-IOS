//
//  ITPSHttpAbility.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef ITPSHttpAbility_h
#define ITPSHttpAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSWebRequestModel.h>
#import <TopStepComKit/TPSWebResponseModel.h>

@class RACSubject<ValueType>;
@protocol ITPSHttpAbility <NSObject,ITPSWearBaseAbility>

+(instancetype)share;

-(RACSubject<TPSWebRequestModel*>*)observeHttpRequest;
-(void)respondHttpToWatch:(TPSWebResponseModel*)model block:(TPSSendMsgResult)block;

@end


#endif /* IFwWorldClockAbility_h */
