//
//  TPSDayPrayModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/19.
//

#ifndef TPSDayPrayModel_h
#define TPSDayPrayModel_h

#import <TopStepComKit/TPSPrayModel.h>


@interface TPSDayPrayModel : NSObject

@property(nonatomic, assign) long prayDayTimeStamp;
@property(nonatomic, strong) NSArray<TPSPrayModel*>* eachDayPrayModel;


@end


#endif /* FwDayPrayModel_h */
