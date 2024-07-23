//
//  TPSTodayWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef TPSTodayWeatherModel_h
#define TPSTodayWeatherModel_h

#import <TopStepComKit/TPSWeatherDescribeType.h>
#import <TopStepComKit/TPSFutureHourWeatherModel.h>

@class FwTodayWeatherModel;
@interface TPSTodayWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

@property (nonatomic, assign) TPSWeatherDescribeType_ENUM describe;
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
@property(nonatomic, assign) CGFloat visibility;

@property (nonatomic, strong) NSArray<TPSFutureHourWeatherModel*>* futureHourWeather;

-(instancetype)initWithCurTemperature:(int)curTemperature 
                       minTemperature:(int)minTemperature
                       maxTemperature:(int)maxTemperature 
                          airpressure:(int)airpressure
                                 wind:(int)wind
                            windAngle:(int)windAngle
                            windSpeed:(int)windSpeed
                             humidity:(int)humidity
                              uvIndex:(NSInteger)uvIndex
                           visibility:(CGFloat)visibility
                       futureHourList:(NSArray<TPSFutureHourWeatherModel*>*)futureHourWeather;




-(instancetype)initWithFwModel:(FwTodayWeatherModel*)fwTodayWeatherModel;
+(NSArray<TPSTodayWeatherModel*>*)toTPSArrWithFwArr:(NSArray<FwTodayWeatherModel*>*)fwArr;
-(FwTodayWeatherModel*)toFwModel;

@end


#endif /* TPSTodayWeatherModel_h */
