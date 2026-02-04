//
//  TPSPrayModel.h
//
//
//  Created by Topstep on 2024/3/18.
//

#ifndef TPSPrayModel_h
#define TPSPrayModel_h

@class FwPrayModel;
@interface TPSPrayModel : NSObject

typedef NS_ENUM(UInt8, TPSPrayModel_Type){
    TPSPrayModel_Type_FAJR = 0,//晨礼
    TPSPrayModel_Type_SUNRISE,//日出
    TPSPrayModel_Type_DHUHR,//晌
    TPSPrayModel_Type_ASR,//哺
    TPSPrayModel_Type_SUNSET,//日落
    TPSPrayModel_Type_MAGHRIB,//昏礼
    TPSPrayModel_Type_ISHA,//宵礼
};

@property(nonatomic, assign) TPSPrayModel_Type prayType;
/**
 相对于一天0时0点的分钟数。如凌晨1点30分，就是90
 */
@property(nonatomic, assign) int prayTime;
@property(nonatomic, assign) BOOL enable;

-(instancetype)initWithFwModel:(FwPrayModel*)fwModel;
+(NSArray<TPSPrayModel*>*)toTPSArrWithFwArr:(NSArray<FwPrayModel*>*)fwArr;
-(FwPrayModel*)toFwModel;
+(NSArray<FwPrayModel*>*)toFwArrWithTPSArr:(NSArray<TPSPrayModel*>*)tpsArr;

@end



#endif /* FwWorldClockModel_h */
