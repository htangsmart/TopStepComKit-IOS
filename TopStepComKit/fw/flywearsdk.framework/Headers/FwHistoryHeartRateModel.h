//
//  HistoryHeartRateModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/8/1.
//

#ifndef HistoryHeartRateModel_h
#define HistoryHeartRateModel_h

@interface FwHistoryHeartRateModel : NSObject

@property (nonatomic, assign) long timestamp;
@property (nonatomic, assign) int heartRate;

-(instancetype)initWithTsDbDict:(NSDictionary *)dict;
-(instancetype)initWithNSData:(NSData*)jsonData;
-(NSData*)toJsonNSData;

@end

#endif /* HistoryHeartRateModel */
