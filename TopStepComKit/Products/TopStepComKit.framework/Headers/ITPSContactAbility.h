//
//  IWearContactSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/31.
//

#ifndef ITPSContactAbility_h
#define ITPSContactAbility_h


#import <TopStepComKit/TPSContactModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
//#import <ReactiveObjC.h>

@class RACSubject<ValueType>;
@protocol ITPSContactAbility <NSObject, ITPSWearBaseAbility>

typedef void(^TPSContactListCallback)(NSMutableArray<TPSContactModel*>* list);

//1表情符号换*号；2传首字母排序；3长度都32
+(instancetype)share;

-(void)getEmergencyContact:(TPSContactListCallback)block;
///
-(void)sendEmergencyContact:(TPSContactModel*)contactModel;

/**
 所有联系人不包含紧急联系人
 */
-(RACSubject<NSArray<TPSContactModel*>*>*)getAllContact;

-(void)sendCommonContact:(NSArray<TPSContactModel*>*)list;

-(RACSubject*)observeContactChange;


@end


#endif /* IWearContactSync_h */
