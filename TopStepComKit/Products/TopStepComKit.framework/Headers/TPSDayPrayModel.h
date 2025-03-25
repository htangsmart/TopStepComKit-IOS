//
//  TPSDayPrayModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/19.
//

#ifndef TPSDayPrayModel_h
#define TPSDayPrayModel_h

#import <TopStepComKit/TPSPrayModel.h>

@class FwDayPrayModel;
@interface TPSDayPrayModel : NSObject

@property(nonatomic, assign) long prayDayTimeStamp;
@property(nonatomic, strong) NSArray<TPSPrayModel*>* eachDayPrayModel;

-(instancetype)initWithFwModel:(FwDayPrayModel*)fwModel;
+(NSArray<TPSDayPrayModel*>*)toTPSArrWithFwArr:(NSArray<FwDayPrayModel*>*)fwArr;
-(FwDayPrayModel*)toFwModel;
+(NSArray<FwDayPrayModel*>*)toFwArrWithTPSArr:(NSArray<TPSDayPrayModel*>*)tpsArr;

@end


#endif /* FwDayPrayModel_h */
