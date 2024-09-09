//
//  TPSWorldClockModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef TPSWorldClockModel_h
#define TPSWorldClockModel_h


@interface TPSWorldClockModel : NSObject

@property(nonatomic, strong) NSString* cityName;
@property(nonatomic, strong) NSString* clockZoneName;
@property(nonatomic, assign) float UTC;


@end



#endif /* FwWorldClockModel_h */
