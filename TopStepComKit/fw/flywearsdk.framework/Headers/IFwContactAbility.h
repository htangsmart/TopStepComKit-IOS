//
//  IWearContactSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/31.
//

#ifndef IWearContactSync_h
#define IWearContactSync_h


#import <flywearsdk/FwContactModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
//#import <ReactiveObjC.h>

@class RACSubject<ValueType>;
@protocol IFwContactAbility <NSObject, IFwWearBaseAbility>

typedef void(^FwContactListCallback)(NSMutableArray<FwContactModel*>* list);

//1表情符号换*号；2传首字母排序；3长度都32
+(instancetype)share;

-(void)getEmergencyContact:(FwContactListCallback)block;
///
-(void)sendEmergencyContact:(FwContactModel*)contactModel;

-(RACSubject<NSArray<FwContactModel*>*>*)getAllContact;

-(void)sendCommonContact:(NSArray<FwContactModel*>*)list;

-(RACSubject*)observeContactChange;


@end


#endif /* IWearContactSync_h */
