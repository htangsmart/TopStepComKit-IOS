//
//  IWearHistoryActivitySync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSActivityDataAbility_h
#define ITPSActivityDataAbility_h

#import <TopStepComKit/TPSHistoryActivityModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

@protocol ITPSActivityDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistoryActivityCallback)(NSArray<TPSHistoryActivityModel*>* _Nullable historyActivityModelList);
typedef void(^TPSTodayAllActivityCallback)(TPSHistoryActivityModel* _Nullable historyActivityModel);

+(instancetype _Nonnull )share;

-(void)getHistoryActivity:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistoryActivityCallback _Nullable)block;
-(void)getTodayTotalActivity:(TPSTodayAllActivityCallback _Nullable)block;

@end


#endif /* IWearCurDayActivitySync_h */
