//
//  IWearHistoryStressSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSStressDataAbility_h
#define ITPSStressDataAbility_h

#import <TopStepComKit/TPSHistoryStressModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSStressConfigModel.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

@protocol ITPSStressDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistoryStressCallback)(NSArray<TPSHistoryStressModel*>* _Nullable historyStressModelList);
typedef void(^TPSStressConfigCallback)(TPSStressConfigModel* _Nullable configModel);

+(instancetype _Nonnull )share;

-(void)getHistoryStress:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryStressCallback _Nullable)block;
-(void)getHrConfig:(TPSStressConfigCallback _Nonnull )block;
-(void)setHrConfig:(TPSStressConfigModel*)model block:(TPSSendMsgResult)block;

@end


#endif /* IWearCurDayActivitySync_h */
