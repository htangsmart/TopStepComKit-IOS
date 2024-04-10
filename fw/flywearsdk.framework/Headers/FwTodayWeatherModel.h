//
//  FwTodayWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef FwTodayWeatherModel_h
#define FwTodayWeatherModel_h

#import <flywearsdk/FwWeatherDescribeType.h>
#import <flywearsdk/FwFutureHourWeatherModel.h>

@interface FwTodayWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

@property (nonatomic, assign) FwWeatherDescribeType_ENUM describe;
@property (nonatomic, assign) int curTemperature;
@property (nonatomic, assign) int minTemperature;
@property (nonatomic, assign) int maxTemperature;
@property (nonatomic, assign) int airpressure;
@property (nonatomic, assign) int wind;
@property (nonatomic, assign) int windAngle;
@property (nonatomic, assign) int windSpeed;
@property (nonatomic, assign) int humidity;
@property (nonatomic, strong) NSArray<FwFutureHourWeatherModel*>* futureHourWeather;

-(instancetype)initWithCurTemperature:(int)curTemperature minTemperature:(int)minTemperature maxTemperature:(int)maxTemperature airpressure:(int)airpressure wind:(int)wind windAngle:(int)windAngle windSpeed:(int)windSpeed humidity:(int)humidity futureHourList:(NSArray<FwFutureHourWeatherModel*>*)futureHourWeather;

@end


#endif /* FwTodayWeatherModel_h */
