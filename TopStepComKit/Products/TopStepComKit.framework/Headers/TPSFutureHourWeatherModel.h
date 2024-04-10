//
//  TPSFutureHourWeatherModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/2.
//

#ifndef TPSFutureHourWeatherModel_h
#define TPSFutureHourWeatherModel_h

#import <TopStepComKit/TPSWeatherDescribeType.h>

@class FwFutureHourWeatherModel;
@interface TPSFutureHourWeatherModel : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

@property (nonatomic, assign) long timestamp;
@property (nonatomic, assign) TPSWeatherDescribeType_ENUM describe;
@property (nonatomic, assign) int temperature;

-(instancetype)initWithTimestamp:(long)timestamp describe:(TPSWeatherDescribeType_ENUM)describe temperature:(int)temperature;
-(instancetype)initWithFwModel:(FwFutureHourWeatherModel*)fwFutureHourWeatherModel;
+(NSArray<TPSFutureHourWeatherModel*>*)toTPSArrWithFwArr:(NSArray<FwFutureHourWeatherModel*>*)fwArr;
+(NSArray<FwFutureHourWeatherModel*>*)toFwArrWithTPSArr:(NSArray<TPSFutureHourWeatherModel*>*)tpsArr;
-(FwFutureHourWeatherModel*)toFwModel;

@end


#endif /* TPSFutureHourWeatherModel_h */
