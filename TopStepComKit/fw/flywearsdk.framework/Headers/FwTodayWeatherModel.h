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

@property (nonatomic, assign) FwWeatherLargeCategory describe;
@property (nonatomic, assign) FwWeatherSubType subType;
@property (nonatomic, assign) int curTemperature;
@property (nonatomic, assign) int minTemperature;
@property (nonatomic, assign) int maxTemperature;
@property (nonatomic, assign) int airpressure;
@property (nonatomic, assign) int wind;
@property (nonatomic, assign) int windAngle;
@property (nonatomic, assign) int windSpeed;
@property (nonatomic, assign) int humidity;

/// 紫外线等级
@property(nonatomic, assign) NSInteger uvIndex;

/// 能见度，最大30000米，单位：米
@property(nonatomic, assign) NSInteger visibility;

@property (nonatomic, strong) NSArray<FwFutureHourWeatherModel*>* futureHourWeather;

-(instancetype)initWithCurTemperature:(int)curTemperature
                       minTemperature:(int)minTemperature
                       maxTemperature:(int)maxTemperature
                             describe:(FwWeatherLargeCategory)describe subType:(FwWeatherSubType)subType
                          airpressure:(int)airpressure
                                 wind:(int)wind
                            windAngle:(int)windAngle
                            windSpeed:(int)windSpeed
                             humidity:(int)humidity
                              uvIndex:(NSInteger)uvIndex
                           visibility:(NSInteger)visibility
                       futureHourList:(NSArray<FwFutureHourWeatherModel*>*)futureHourWeather;

@end


#endif /* FwTodayWeatherModel_h */
