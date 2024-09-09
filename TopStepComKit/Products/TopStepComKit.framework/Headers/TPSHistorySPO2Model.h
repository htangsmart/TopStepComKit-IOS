//
//  HistorySPO2Model.h
//  JieliJianKang
//
//  Created by Topstep on 2023/8/1.
//

#ifndef TPSHistorySPO2Model_h
#define TPSHistorySPO2Model_h


@interface TPSHistorySPO2Model : NSObject

@property (nonatomic, assign) long record_time;
@property (nonatomic, assign) int blood_oxy;//百分数取其百分号前的整数

-(instancetype)initWithTsDbDict:(NSDictionary *)dict;
-(instancetype)initWithNSData:(NSData*)jsonData;
-(NSData*)toJsonNSData;





@end

#endif /* HistoryHeartRateModel */
