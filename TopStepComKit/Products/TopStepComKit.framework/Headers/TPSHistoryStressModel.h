//
//  HistoryStressModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/19.
//

#ifndef TPSHistoryStressModel_h
#define TPSHistoryStressModel_h

@interface TPSHistoryStressModel : NSObject

@property (nonatomic, assign) long record_time;
@property (nonatomic, assign) int stress;//百分数取其百分号前的整数

-(instancetype)initWithTsDbDict:(NSDictionary *)dict;
-(instancetype)initWithNSData:(NSData*)jsonData;
-(NSData*)toJsonNSData;
+(NSArray<TPSHistoryStressModel*>*)stressModelFormArray:(NSArray<NSDictionary*>*)fitcloudModelArray;

@end


#endif /* HistoryStressModel_h */
