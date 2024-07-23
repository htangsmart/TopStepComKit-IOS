//
//  IWearHistoryActivitySync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef IWearHistoryActivitySync_h
#define IWearHistoryActivitySync_h

#import <flywearsdk/FwHistoryActivityModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>

@protocol IFwActivityDataAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwHistoryActivityCallback)(NSArray<FwHistoryActivityModel*>* _Nullable historyActivityModelList);
typedef void(^FwTodayAllActivityCallback)(FwHistoryActivityModel* _Nullable historyActivityModel);

+(instancetype _Nonnull )share;

-(void)getHistoryActivity:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistoryActivityCallback _Nullable)block;
-(void)getTodayTotalActivity:(FwTodayAllActivityCallback _Nullable)block;

@end


#endif /* IWearCurDayActivitySync_h */
