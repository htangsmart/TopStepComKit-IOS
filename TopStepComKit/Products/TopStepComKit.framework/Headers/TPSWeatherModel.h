//
//  TPSWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef TPSWeatherModel_h
#define TPSWeatherModel_h

#import <TopStepComKit/TPSWeatherDescribeType.h>
#import <TopStepComKit/TPSMiscSettingModel.h>
#import <TopStepComKit/TPSFutureDayWeatherModel.h>
#import <TopStepComKit/TPSFutureHourWeatherModel.h>
#import <TopStepComKit/TPSTodayWeatherModel.h>

@interface TPSWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

@property (nonatomic, strong) NSString* city;
@property (nonatomic, assign) TPSMiscSettingModel_Temperature_Unit temperatureUnit;
@property (nonatomic, assign) long updateTime;
@property (nonatomic, strong) TPSTodayWeatherModel* todayWeather;
@property (nonatomic, strong) NSArray<TPSFutureDayWeatherModel*>* futureDayWeather;

-(instancetype)initWithCity:(NSString*)city temperatureUnit:(TPSMiscSettingModel_Temperature_Unit)temperatureUnit updateTime:(long)updateTime todayWeather:(TPSTodayWeatherModel*)todayWeather futureDayWeather:(NSArray<TPSFutureDayWeatherModel*>*)futureDayWeather;

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


#endif /* TPSWeatherModel_h */
