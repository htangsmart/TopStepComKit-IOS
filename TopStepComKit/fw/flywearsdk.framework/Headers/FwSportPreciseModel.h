//
//  FwSportPreciseModel.h
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/8/22.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#ifndef FwSportPreciseModel_h
#define FwSportPreciseModel_h

#import <flywearsdk/FwSportPreciseHeartRateItem.h>
#import <flywearsdk/FwSportPreciseCaloriesItem.h>
#import <flywearsdk/FwSportPreciseDistanceItem.h>
#import <flywearsdk/FwSportPreciseStepItem.h>

@interface FwSportPreciseModel : NSObject

@property(nonatomic, assign) long sport_id;
@property(nonatomic, assign) int hrInterval;
@property(nonatomic, assign) int distanceInterval;
@property(nonatomic, assign) int stepInterval;
@property(nonatomic, assign) int caloriesInterval;
@property(nonatomic, strong) NSMutableArray<FwSportPreciseHeartRateItem*>* preciseHrItemList;
@property(nonatomic, strong) NSMutableArray<FwSportPreciseCaloriesItem*>* preciseCaloriesItemList;
@property(nonatomic, strong) NSMutableArray<FwSportPreciseDistanceItem*>* preciseDistanceItemList;
@property(nonatomic, strong) NSMutableArray<FwSportPreciseStepItem*>* preciseStepItemList;

-(void)parse:(NSString*)path sportId:(long)sportId;

@end


#endif /* FwSportPreciseModel */
