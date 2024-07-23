//
//  FwWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef FwWeatherModel_h
#define FwWeatherModel_h

#import <flywearsdk/FwWeatherDescribeType.h>
#import <flywearsdk/FwMiscSettingModel.h>
#import <flywearsdk/FwFutureDayWeatherModel.h>
#import <flywearsdk/FwFutureHourWeatherModel.h>
#import <flywearsdk/FwTodayWeatherModel.h>


@interface FwWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

@property (nonatomic, strong) NSString* city;
@property (nonatomic, assign) FwMiscSettingModel_Temperature_Unit temperatureUnit;
@property (nonatomic, assign) long updateTime;
@property (nonatomic, strong) FwTodayWeatherModel* todayWeather;
@property (nonatomic, strong) NSArray<FwFutureDayWeatherModel*>* futureDayWeather;

-(instancetype)initWithCity:(NSString*)city temperatureUnit:(FwMiscSettingModel_Temperature_Unit)temperatureUnit updateTime:(long)updateTime todayWeather:(FwTodayWeatherModel*)todayWeather futureDayWeather:(NSArray<FwFutureDayWeatherModel*>*)futureDayWeather;

//@"weather.city":self->cityName,
//@"weather.describe":[self getDesWithCode:[currentDic[@"code"] intValue]],
//@"weather.temperature":currentDic[@"temp"],
//@"weather.temp_unit":@"C",
//@"weather.update_time":[NSString stringWithFormat:@"%.f",currentTime],
//@"weather.min":firstDayMinTemp,
//@"weather.max":firstDayMaxTemp,
//@"weather.future_days":preDays,
//
//// new add
//@"weather.airpressure":[NSNumber numberWithInteger:self->airpressure],
//@"weather.wind":[NSNumber numberWithInteger:self->wind],
//@"weather.wind_angle":[NSNumber numberWithInteger:self->wind_angle],
//@"weather.wind_speed":[NSNumber numberWithInteger:self->wind_speed],
//@"weather.humidity":[NSNumber numberWithInteger:self->humidity],
//@"weather.future_hours":hours,

@end


#endif /* FwWeatherModel_h */
