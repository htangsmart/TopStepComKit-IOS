//
//  IFwHttpAbility.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef IFwHttpAbility_h
#define IFwHttpAbility_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwWebRequestModel.h>
#import <flywearsdk/FwWebResponseModel.h>

@class RACSubject<ValueType>;
@protocol IFwHttpAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwHttpCallback)(NSArray<FwWebRequestModel*> * bookList);

+(instancetype)share;

-(RACSubject<FwWebRequestModel*>*)observeHttpRequest;
-(void)respondHttpToWatch:(FwWebResponseModel*)model block:(FwSendMsgResult)block;

@end


#endif /* IFwWorldClockAbility_h */
