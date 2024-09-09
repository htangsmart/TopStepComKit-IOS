//
//  TPSFutureHourWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef TPSFutureHourWeatherModel_h
#define TPSFutureHourWeatherModel_h

#import <TopStepComKit/TPSWeatherDescribeType.h>

@class FitCloudHourWeatherObject;
@interface TPSFutureHourWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

@property (nonatomic, assign) long timestamp;
@property (nonatomic, assign) TPSWeatherLargeCategory describe;
@property (nonatomic, assign) TPSWeatherSubType subType;
@property (nonatomic, assign) int temperature;

@property (nonatomic, assign) int windScale;

@property (nonatomic, assign) int uvIndex;

@property (nonatomic, assign) int visibility;


-(instancetype)initWithTimestamp:(long)timestamp describe:(TPSWeatherLargeCategory)describe temperature:(int)temperature;

-(FitCloudHourWeatherObject*)toFitModel;

@end


#endif /* TPSFutureHourWeatherModel_h */
