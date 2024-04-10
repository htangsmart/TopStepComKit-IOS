//
//  FwHistoryBloodPressureModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/21.
//

#ifndef FwHistoryBloodPressureModel_h
#define FwHistoryBloodPressureModel_h

@interface FwHistoryBloodPressureModel : NSObject

@property (nonatomic, assign) long record_time;
@property (nonatomic, assign) int sbp;//收缩压，俗称高压
@property (nonatomic, assign) int dbp;//舒张压，俗称低压

-(instancetype)initWithTsDbDict:(NSDictionary *)dict;
-(instancetype)initWithNSData:(NSData*)jsonData;
-(NSData*)toJsonNSData;

@end


#endif /* FwHistoryBloodPressureModel_h */
