//
//  FwFutureHourWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef FwFutureHourWeatherModel_h
#define FwFutureHourWeatherModel_h

#import <flywearsdk/FwWeatherDescribeType.h>

@interface FwFutureHourWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

@property (nonatomic, assign) long timestamp;
@property (nonatomic, assign) FwWeatherLargeCategory describe;
@property (nonatomic, assign) FwWeatherSubType subType;
@property (nonatomic, assign) int temperature;

-(instancetype)initWithTimestamp:(long)timestamp describe:(FwWeatherLargeCategory)describe subType:(FwWeatherSubType)subType temperature:(int)temperature;

@end


#endif /* FwFutureHourWeatherModel_h */
