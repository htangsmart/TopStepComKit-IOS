//
//  FwSportPreciseStepItem.h
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/8/22.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#ifndef FwSportPreciseStepItem_h
#define FwSportPreciseStepItem_h

@interface FwSportPreciseStepItem : NSObject
//这个interval时间段所运动的步数
@property(nonatomic, assign) int step;
//到这个时间点时，运动所累计的距离，步
@property(nonatomic, assign) int cumulativeValue;
@property(nonatomic, assign) long startTime;
@property(nonatomic, assign) int interval;

@end


#endif /* FwSportPreciseStepItem_h */
