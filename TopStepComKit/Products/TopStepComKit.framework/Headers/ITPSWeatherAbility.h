//
//  IWearWeatherSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//

#ifndef ITPSWeatherAbility_h
#define ITPSWeatherAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSWeatherModel.h>

@protocol ITPSWeatherAbility <NSObject,ITPSWearBaseAbility>

+(instancetype)share;

-(void)sendWeather:(TPSWeatherModel*)weatherModel block:(TPSSendMsgResult)block;


@end


#endif /* IWearDevInfoSync_h */
