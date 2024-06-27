//
//  IWearHistorySportSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef IWearHistorySportSync_h
#define IWearHistorySportSync_h

#import <flywearsdk/FwHistorySportModel.h>
#import <flywearsdk/IFwWearBaseAbility.h>

@protocol IFwSportDataAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwHistorySportCallback)(NSArray<FwHistorySportModel*>* _Nullable historySportModelList);
typedef void(^FwSportDetailItemCallback)(NSArray<FwSportItemModel*>* _Nullable sportItemModelList);

+(instancetype _Nonnull )share;

-(void)getHistorySport:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistorySportCallback _Nullable)block;

@end


#endif /* IWearCurDayActivitySync_h */
