//
//  TPSSportItemModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/4/1.
//

#ifndef TPSSportItemModel_h
#define TPSSportItemModel_h

@class FwSportItemModel;
@interface TPSSportItemModel : NSObject

@property (nonatomic, assign) long sport_id;
@property (nonatomic, assign) int type;
@property (nonatomic, assign) long timestamp;// 采样时间 单位秒
@property (nonatomic, assign) long start_time;//单位秒
@property (nonatomic, assign) long duration;//单位秒
@property (nonatomic, assign) double distance;//距离米
@property (nonatomic, assign) double calories;//单位卡（小卡）
@property (nonatomic, assign) int heartrate;//次/min
///平均配速，指的是该运动到这一时刻为止的总时间除以总距离，单位秒/千米
@property (nonatomic, assign) double pace;//单位秒/千米
///瞬时配速，指的是该运动在这一个duration里的时间除以距离，单位秒/千米
@property (nonatomic, assign) double instantPace;//单位秒/千米
@property (nonatomic, assign) int step;
@property (nonatomic, assign) double cadence;//单位步/分钟

@property (nonatomic, assign) int swimStyle;    /* 泳姿   1: 自由泳 2:蛙泳 3:仰泳 4:蝶泳 */
@property (nonatomic, assign) int swimLaps;  /* 游泳趟数 */
@property (nonatomic, assign) int swimStrokes;/* 游泳划水次数 */
@property (nonatomic, assign) int swimStrokeFreq;/* 游泳划水频率 */
@property (nonatomic, assign) int swolf;/* 游泳效率 */

@property (nonatomic, assign) int jumpCount;/* 跳绳-触发次数 */
@property (nonatomic, assign) int jumpBkCount;/* 跳绳-中断次数 */
@property (nonatomic, assign) int jumpConsCount;/* 跳绳-连续次数 */

@property (nonatomic, assign) int elCount; /* 椭圆机-触发次数 */
@property (nonatomic, assign) int elFrequecy;/* 椭圆机-触发频率 */
@property (nonatomic, assign) int elMaxFrequecy;/* 椭圆机-最大触发频率 */
@property (nonatomic, assign) int elMinFrequecy;/* 椭圆机-最小触发频率 */

@property (nonatomic, assign) int rowCount;/* 划船机-触发次数 */
@property (nonatomic, assign) int rowFrequecy;/* 划船机-触发频率 */
@property (nonatomic, assign) int rowMaxFrequecy;/* 划船机-最大触发频率 */
@property (nonatomic, assign) int rowMinFrequecy;/* 划船机-最小触发频率 */


-(instancetype)initWithFwModel:(FwSportItemModel*)fwModel;
+(NSArray<TPSSportItemModel*>*)toTPSArrayWithFwModelArr:(NSArray<FwSportItemModel*>*)fwArr;

@end

#endif /* FwSportItemModel_h */
