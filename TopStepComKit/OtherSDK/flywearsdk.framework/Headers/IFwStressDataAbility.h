//
//  IWearHistoryStressSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef IWearHistoryStressSync_h
#define IWearHistoryStressSync_h

#import <flywearsdk/FwHistoryStressModel.h>
#import <flywearsdk/FwStressConfigModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>

@protocol IFwStressDataAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwHistoryStressCallback)(NSArray<FwHistoryStressModel*>* _Nullable historyStressModelList);
typedef void(^FwStressConfigCallback)(FwStressConfigModel* _Nullable configModel);

+(instancetype _Nonnull )share;

-(void)getHistoryStress:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistoryStressCallback _Nullable)block;
-(void)getHrConfig:(FwStressConfigCallback _Nonnull )block;
-(void)setHrConfig:(FwStressConfigModel*)model block:(FwSendMsgResult)block;

@end


#endif /* IWearCurDayActivitySync_h */
