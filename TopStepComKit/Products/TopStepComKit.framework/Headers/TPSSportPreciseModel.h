//
//  TPSSportPreciseModel.h
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/8/22.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#ifndef TPSSportPreciseModel_h
#define TPSSportPreciseModel_h

#import <TopStepComKit/TPSSportPreciseHeartRateItem.h>
#import <TopStepComKit/TPSSportPreciseCaloriesItem.h>
#import <TopStepComKit/TPSSportPreciseDistanceItem.h>
#import <TopStepComKit/TPSSportPreciseStepItem.h>

@interface TPSSportPreciseModel : NSObject

@property(nonatomic, assign) long sport_id;
@property(nonatomic, assign) int hrInterval;
@property(nonatomic, assign) int distanceInterval;
@property(nonatomic, assign) int stepInterval;
@property(nonatomic, assign) int caloriesInterval;
@property(nonatomic, strong) NSMutableArray<TPSSportPreciseHeartRateItem*>* preciseHrItemList;
@property(nonatomic, strong) NSMutableArray<TPSSportPreciseCaloriesItem*>* preciseCaloriesItemList;
@property(nonatomic, strong) NSMutableArray<TPSSportPreciseDistanceItem*>* preciseDistanceItemList;
@property(nonatomic, strong) NSMutableArray<TPSSportPreciseStepItem*>* preciseStepItemList;


@end


#endif /* TPSSportPreciseModel */
