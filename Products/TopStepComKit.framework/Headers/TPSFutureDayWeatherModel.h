//
//  TPSFutureDayWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef TPSFutureDayWeatherModel_h
#define TPSFutureDayWeatherModel_h

#import <TopStepComKit/TPSWeatherDescribeType.h>

@class FwFutureDayWeatherModel;
@interface TPSFutureDayWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;



@property (nonatomic, assign) long timestamp;
@property (nonatomic, assign) TPSWeatherDescribeType_ENUM describe;
@property (nonatomic, assign) int minTemperature;
@property (nonatomic, assign) int maxTemperature;

-(instancetype)initWithTimestamp:(long)timestamp describe:(TPSWeatherDescribeType_ENUM)describe minTemperature:(int)minTemperature maxTemperature:(int)maxTemperature;
-(instancetype)initWithFwModel:(FwFutureDayWeatherModel*)fwFutureDayWeatherModel;
+(NSArray<TPSFutureDayWeatherModel*>*)toTPSArrWithFwArr:(NSArray<FwFutureDayWeatherModel*>*)fwArr;
+(NSArray<FwFutureDayWeatherModel*>*)toFwArrWithTPSArr:(NSArray<TPSFutureDayWeatherModel*>*)tpsArr;
-(FwFutureDayWeatherModel*)toFwModel;

//@"timestamp":t,
//@"describe":[self getDesWithCode:[next7DayArr[i][@"code"] intValue]],
//@"min":min,
//@"max":max,

@end


#endif /* TPSFutureDayWeatherModel_h */
