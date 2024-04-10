//
//  FwPrayModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef FwPrayModel_h
#define FwPrayModel_h

@interface FwPrayModel : NSObject

typedef NS_ENUM(UInt8, FwPrayModel_Type){
    FwPrayModel_Type_FAJR = 0,//晨礼
    FwPrayModel_Type_SUNRISE,//日出
    FwPrayModel_Type_DHUHR,//晌
    FwPrayModel_Type_ASR,//哺
    FwPrayModel_Type_SUNSET,//日落
    FwPrayModel_Type_MAGHRIB,//昏礼
    FwPrayModel_Type_ISHA,//宵礼
};

@property(nonatomic, assign) FwPrayModel_Type prayType;
/**
 相对于一天0时0点的分钟数。如凌晨1点30分，就是90
 */
@property(nonatomic, assign) int prayTime;
@property(nonatomic, assign) BOOL enable;

-(NSDictionary*)toDic;

@end



#endif /* FwWorldClockModel_h */
