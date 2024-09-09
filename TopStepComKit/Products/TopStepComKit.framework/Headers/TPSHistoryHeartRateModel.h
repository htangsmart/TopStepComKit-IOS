//
//  HistoryHeartRateModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/8/1.
//

#ifndef TPSHistoryHeartRateModel_h
#define TPSHistoryHeartRateModel_h

@interface TPSHistoryHeartRateModel : NSObject

@property (nonatomic, assign) long timestamp;
@property (nonatomic, assign) int heartRate;


-(instancetype)initWithTsDbDict:(NSDictionary *)dict;

-(instancetype)initWithNSData:(NSData*)jsonData;

-(NSData*)toJsonNSData;



+(NSArray<TPSHistoryHeartRateModel*>*)heartRateModelFormArray:(NSArray<NSDictionary*>*)fitcloudModelArray;



@end

#endif /* HistoryHeartRateModel */
