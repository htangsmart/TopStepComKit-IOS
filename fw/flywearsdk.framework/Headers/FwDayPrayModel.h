//
//  FwDayPrayModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/19.
//

#ifndef FwDayPrayModel_h
#define FwDayPrayModel_h

#import <flywearsdk/FwPrayModel.h>

@interface FwDayPrayModel : NSObject

@property(nonatomic, assign) long prayDayTimeStamp;
@property(nonatomic, strong) NSArray<FwPrayModel*>* eachDayPrayModel;

-(NSDictionary*)toDic;

@end


#endif /* FwDayPrayModel_h */
