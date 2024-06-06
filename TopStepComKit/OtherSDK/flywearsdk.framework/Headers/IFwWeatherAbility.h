//
//  IWearWeatherSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//

#ifndef IWearWeatherSync_h
#define IWearWeatherSync_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwWeatherModel.h>

@protocol IFwWeatherAbility <NSObject,IFwWearBaseAbility>

+(instancetype)share;

-(void)sendWeather:(FwWeatherModel*)weatherModel block:(FwSendMsgResult)block;


@end


#endif /* IWearDevInfoSync_h */
