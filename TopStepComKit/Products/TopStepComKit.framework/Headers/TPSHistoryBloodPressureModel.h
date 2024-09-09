//
//  TPSHistoryBloodPressureModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/2/21.
//

#ifndef TPSHistoryBloodPressureModel_h
#define TPSHistoryBloodPressureModel_h


@interface TPSHistoryBloodPressureModel : NSObject

@property (nonatomic, assign) long record_time;
@property (nonatomic, assign) int sbp;//收缩压，俗称高压
@property (nonatomic, assign) int dbp;//舒张压，俗称低压

-(instancetype)initWithTsDbDict:(NSDictionary *)dict;
-(instancetype)initWithNSData:(NSData*)jsonData;
-(NSData*)toJsonNSData;

@end


#endif /* TPSHistoryBloodPressureModel_h */
