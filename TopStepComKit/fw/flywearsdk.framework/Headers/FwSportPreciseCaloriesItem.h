//
//  FwSportPreciseCaloriesItem.h
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/8/22.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#ifndef FwSportPreciseCaloriesItem_h
#define FwSportPreciseCaloriesItem_h

@interface FwSportPreciseCaloriesItem : NSObject

//这个interval时间段所消耗的千卡
@property(nonatomic, assign) double calories;
//到这个时间点时，运动所累计的千卡
@property(nonatomic, assign) double cumulativeValue;
@property(nonatomic, assign) long startTime;
@property(nonatomic, assign) int interval;

@end


#endif /* FwSportPreciseCaloriesItem_h */
