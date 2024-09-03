//
//  FwSportPreciseDistanceItem.h
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/8/22.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#ifndef FwSportPreciseDistanceItem_h
#define FwSportPreciseDistanceItem_h

@interface FwSportPreciseDistanceItem : NSObject
//这个interval时间段所运动的距离，米
@property(nonatomic, assign) int distance;
//到这个时间点时，运动所累计的距离，米
@property(nonatomic, assign) int cumulativeValue;
@property(nonatomic, assign) long startTime;
@property(nonatomic, assign) int interval;

@end


#endif /* FwSportPreciseDistanceItem_h */
