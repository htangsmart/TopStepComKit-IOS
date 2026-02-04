//
//  ITPSPrayAbility.h
//
//
//  Created by Topstep on 2024/3/18.
//

#ifndef ITPSPrayAbility_h
#define ITPSPrayAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSPrayModel.h>
#import <TopStepComKit/TPSDayPrayModel.h>

@protocol ITPSPrayAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSPrayListCallback)(NSArray<TPSDayPrayModel*> * bookList);

+(instancetype)share;

-(void)sendAllPrayList:(NSArray<TPSDayPrayModel*>*)list block:(TPSSendMsgResult)block;
-(void)getAllPrayListWithBlock:(TPSPrayListCallback)block;
-(void)getIsOpenPray:(TPSSendMsgResult)block;
-(void)setIsOpenPray:(BOOL)isOpen block:(TPSSendMsgResult)block;

@end


#endif /* IFwWorldClockAbility_h */
