//
//  FwFutureDayWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef FwFutureDayWeatherModel_h
#define FwFutureDayWeatherModel_h

#import <flywearsdk/FwWeatherDescribeType.h>

@interface FwFutureDayWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;



@property (nonatomic, assign) long timestamp;
@property (nonatomic, assign) FwWeatherLargeCategory describe;
@property (nonatomic, assign) FwWeatherSubType subType;
@property (nonatomic, assign) int minTemperature;
@property (nonatomic, assign) int maxTemperature;

-(instancetype)initWithTimestamp:(long)timestamp describe:(FwWeatherLargeCategory)describe subType:(FwWeatherSubType)subType minTemperature:(int)minTemperature maxTemperature:(int)maxTemperature;

//@"timestamp":t,
//@"describe":[self getDesWithCode:[next7DayArr[i][@"code"] intValue]],
//@"min":min,
//@"max":max,

@end


#endif /* FwFutureDayWeatherModel_h */
