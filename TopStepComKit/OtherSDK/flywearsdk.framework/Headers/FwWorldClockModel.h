//
//  FwWorldClockModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef FwWorldClockModel_h
#define FwWorldClockModel_h

@interface FwWorldClockModel : NSObject

@property(nonatomic, strong) NSString* cityName;
@property(nonatomic, strong) NSString* clockZoneName;
@property(nonatomic, assign) float UTC;

@end



#endif /* FwWorldClockModel_h */
