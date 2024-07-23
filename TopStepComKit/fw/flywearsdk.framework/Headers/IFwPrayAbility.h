//
//  IFwPrayAbility.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef IFwPrayAbility_h
#define IFwPrayAbility_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwPrayModel.h>
#import <flywearsdk/FwDayPrayModel.h>

@protocol IFwPrayAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwPrayListCallback)(NSArray<FwDayPrayModel*> * bookList);

+(instancetype)share;

-(void)sendAllPrayList:(NSArray<FwDayPrayModel*>*)list block:(FwSendMsgResult)block;
-(void)getAllPrayListWithBlock:(FwPrayListCallback)block;
-(void)getIsOpenPray:(FwSendMsgResult)block;
-(void)setIsOpenPray:(BOOL)isOpen block:(FwSendMsgResult)block;

@end


#endif /* IFwWorldClockAbility_h */
