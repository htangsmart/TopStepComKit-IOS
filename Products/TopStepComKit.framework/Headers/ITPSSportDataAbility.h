//
//  IWearHistorySportSync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef ITPSSportDataAbility_h
#define ITPSSportDataAbility_h

#import <TopStepComKit/TPSHistorySportModel.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

@protocol ITPSSportDataAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSHistorySportCallback)(NSArray<TPSHistorySportModel*>* _Nullable historySportModelList);

+(instancetype _Nonnull )share;

-(void)getHistorySport:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(TPSHistorySportCallback _Nullable)block;

@end


#endif /* IWearCurDayActivitySync_h */
