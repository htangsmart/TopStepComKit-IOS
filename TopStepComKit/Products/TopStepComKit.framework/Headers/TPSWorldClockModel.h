//
//  TPSWorldClockModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef TPSWorldClockModel_h
#define TPSWorldClockModel_h

@class FwWorldClockModel;
@interface TPSWorldClockModel : NSObject

@property(nonatomic, strong) NSString* cityName;
@property(nonatomic, strong) NSString* clockZoneName;
@property(nonatomic, assign) float UTC;

-(FwWorldClockModel*)toFwModel;
+(NSArray<FwWorldClockModel*>*)toFwArrWithTPSArr:(NSArray<TPSWorldClockModel*>*)tpsArr;

@end



#endif /* FwWorldClockModel_h */
