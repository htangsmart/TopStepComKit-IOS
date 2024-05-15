//
//  HistorySportModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/19.
//

#ifndef TPSHistorySportModel_h
#define TPSHistorySportModel_h

#import <TopStepComKit/TPSSportItemModel.h>

@class FwHistorySportModel;
@interface TPSHistorySportModel : NSObject

typedef NS_ENUM(UInt8, TPSSportDes_Type){
    TPSSportDes_Type_OutdoorRunning = 1, //      户外跑步
    TPSSportDes_Type_Marathon = 2, //      马拉松
    TPSSportDes_Type_OutdoorWalk = 3, //      户外健走
    TPSSportDes_Type_Hiking = 4, //      户外徒步
    TPSSportDes_Type_Mountaineering = 5, //      登山
    TPSSportDes_Type_CrossCountryRunning = 6, //      越野跑
    TPSSportDes_Type_Treadmill = 7, //      跑步机
    TPSSportDes_Type_IndoorRunning = 8, //      室内跑步
    TPSSportDes_Type_IndoorWalking = 9, //      室内走路
    TPSSportDes_Type_Stepper = 10, //      踏步机
    TPSSportDes_Type_OutdoorCycling = 11, //      户外骑行
    TPSSportDes_Type_IndoorCycling = 12, //      室内骑行
    TPSSportDes_Type_OutdoorSkating = 13, //      户外滑冰
    TPSSportDes_Type_Hunt = 14, //      打猎
    TPSSportDes_Type_Equestrian = 15, //      马术
    TPSSportDes_Type_Rower = 16, //      划船机
    TPSSportDes_Type_ToGoUpstairs = 17, //      爬楼梯
    TPSSportDes_Type_IndoorFitness = 18, //      室内健身
    TPSSportDes_Type_EllipticalMachine = 19, //      椭圆机
    TPSSportDes_Type_StairClimbingMachine = 20, //      爬楼机
    TPSSportDes_Type_FreeTraining = 21, //      自由训练
    TPSSportDes_Type_CoreTraining = 22, //      核心训练
    TPSSportDes_Type_MixedAerobic = 23, //      混合有氧
    TPSSportDes_Type_MaxO2IntakeTest = 24, //      最大摄氧量测试
    TPSSportDes_Type_StrengthTraining = 25, //      力量训练
    TPSSportDes_Type_Stretch = 26, //      拉伸
    TPSSportDes_Type_FloorExercise = 27, //      自由体操
    TPSSportDes_Type_FlexibilityTraining = 28, //      柔韧训练
    TPSSportDes_Type_StepTraining = 29, //      踏步训练
    TPSSportDes_Type_Gymnastic = 30, //      体操
    TPSSportDes_Type_HIIT = 31, //      高强度间歇训练
    TPSSportDes_Type_Crossfit = 32, //      交叉训练
    TPSSportDes_Type_PhysicalTraining = 33, //      体能训练
    TPSSportDes_Type_DumbbellWorkout = 34, //      哑铃训练
    TPSSportDes_Type_DumbbellWorkout1 = 35, //      杠铃训练
    TPSSportDes_Type_Bodybuilding = 36, //      举重
    TPSSportDes_Type_Deadlift = 37, //      硬拉
    TPSSportDes_Type_Burpee = 38, //      波比跳
    TPSSportDes_Type_JumpingJack = 39, //      开合跳
    TPSSportDes_Type_SitUp = 40, //      仰卧起坐
    TPSSportDes_Type_FunctionalTraining = 41, //      功能性训练
    TPSSportDes_Type_UpperBodyWorkout = 42, //      上肢训练
    TPSSportDes_Type_LowerBodyWorkout = 43, //      下肢训练
    TPSSportDes_Type_WaistAndAbdomenTraining = 44, //      腰腹训练
    TPSSportDes_Type_BackTraining = 45, //      背部训练
    TPSSportDes_Type_HorizontalBar = 46, //      单杠
    TPSSportDes_Type_ParallelBars = 47, //      双杠
    TPSSportDes_Type_HighJumping = 48, //      跳高
    TPSSportDes_Type_LongJumping = 49, //      跳远
    TPSSportDes_Type_Pullups = 50, //      引体向上
    TPSSportDes_Type_Pushups = 51, //      俯卧撑
    TPSSportDes_Type_Planking = 52, //      平板支撑
    TPSSportDes_Type_FoamRollerStretching = 53, //      泡沫轴筋膜放松
    TPSSportDes_Type_FitnessGames = 54, //      健身游戏
    TPSSportDes_Type_CalmingMeditation = 55, //      舒缓冥想
    TPSSportDes_Type_AirWalker = 56, //      漫步机
    TPSSportDes_Type_RockClimbing = 57, //      攀岩
    TPSSportDes_Type_Atv = 58, //      沙滩车
    TPSSportDes_Type_Paragliding = 59, //      滑翔伞
    TPSSportDes_Type_Parkour = 60, //      跑酷
    TPSSportDes_Type_Basketball = 61, //      篮球
    TPSSportDes_Type_Football = 62, //      足球
    TPSSportDes_Type_AustralianRulesFootball = 63, //      澳式足球
    TPSSportDes_Type_TableTennis = 64, //      乒乓球
    TPSSportDes_Type_Badminton = 65, //      羽毛球
    TPSSportDes_Type_Cricket = 66, //      板球
    TPSSportDes_Type_Baseball = 67, //      棒球
    TPSSportDes_Type_Bowling = 68, //      保龄球
    TPSSportDes_Type_Squash = 69, //      壁球
    TPSSportDes_Type_Softball = 70, //      垒球
    TPSSportDes_Type_Croquet = 71, //      门球
    TPSSportDes_Type_Volleyball = 72, //      排球
    TPSSportDes_Type_Handball = 73, //      手球
    TPSSportDes_Type_WaterPolo = 74, //      水球
    TPSSportDes_Type_Rugby = 75, //      橄榄球
    TPSSportDes_Type_AmericanFootball = 76, //      美式橄榄球
    TPSSportDes_Type_Hockey = 77, //      曲棍球
    TPSSportDes_Type_Lacrosse = 78, //      长曲棍球
    TPSSportDes_Type_Tennis = 79, //      网球
    TPSSportDes_Type_Billiards = 80, //      台球
    TPSSportDes_Type_Flying = 81, //      毽球
    TPSSportDes_Type_SepakTakraw = 82, //      藤球
    TPSSportDes_Type_Golf = 83, //      高尔夫
    TPSSportDes_Type_Pickleball = 84, //      匹克球
    TPSSportDes_Type_Yoga = 85, //      瑜伽
    TPSSportDes_Type_Pilates = 86, //      普拉提
    TPSSportDes_Type_SnowSports = 87, //      雪上运动
    TPSSportDes_Type_Snowmobile = 88, //      雪地摩托
    TPSSportDes_Type_Sled = 89, //      雪橇
    TPSSportDes_Type_Curling = 90, //      冰壶
    TPSSportDes_Type_IndoorSkating = 91, //      室内滑冰
    TPSSportDes_Type_Puck = 92, //      冰球
    TPSSportDes_Type_Ski = 93, //      滑雪
    TPSSportDes_Type_CrossCountrySkiing = 94, //      越野滑雪
    TPSSportDes_Type_SkiBoard = 95, //      滑雪板
    TPSSportDes_Type_AlpineSkiing = 96, //      高山滑雪
    TPSSportDes_Type_Snowboarding = 97, //      单板滑雪
    TPSSportDes_Type_Ballet = 98, //      芭蕾舞
    TPSSportDes_Type_BellyDance = 99, //      肚皮舞
    TPSSportDes_Type_SquareDance = 100, //      广场舞
    TPSSportDes_Type_StreetDance = 101, //      街舞
    TPSSportDes_Type_BallroomDance = 102, //      交际舞
    TPSSportDes_Type_Dance = 103, //      舞蹈
    TPSSportDes_Type_Zumba = 104, //      尊巴
    TPSSportDes_Type_Aerobics = 105, //      健身操
    TPSSportDes_Type_NationalDance = 106, //      民族舞
    TPSSportDes_Type_Jazz = 107, //      爵士舞
    TPSSportDes_Type_LatinDance = 108, //      拉丁舞
    TPSSportDes_Type_GroupCallisthenics = 109, //      团体操
    TPSSportDes_Type_KickBoxing = 110, //      搏击操
    TPSSportDes_Type_Archery = 111, //      射箭
    TPSSportDes_Type_Darts = 112, //      飞镖
    TPSSportDes_Type_TugOfWar = 113, //      拔河
    TPSSportDes_Type_HulaHoop = 114, //      呼啦圈
    TPSSportDes_Type_FlyAKite = 115, //      放风筝
    TPSSportDes_Type_Fishing = 116, //      钓鱼
    TPSSportDes_Type_Frisbee = 117, //      飞盘
    TPSSportDes_Type_Kabaddi = 118, //      卡巴迪
    TPSSportDes_Type_BungeeJumping = 119, //      蹦极
    TPSSportDes_Type_Handcar = 120, //      手摇车
    TPSSportDes_Type_HoverBoard = 121, //      平衡车
    TPSSportDes_Type_LeisureSports = 122, //      休闲运动
    TPSSportDes_Type_Fencing = 123, //      击剑
    TPSSportDes_Type_TrackAndField = 124, //      田径
    TPSSportDes_Type_Races = 125, //      赛车
    TPSSportDes_Type_Triathlon = 126, //      铁人三项
    TPSSportDes_Type_Karate = 127, //      空手道
    TPSSportDes_Type_Boxing = 128, //      拳击
    TPSSportDes_Type_Judo = 129, //      柔道
    TPSSportDes_Type_Wrestling = 130, //      摔跤
    TPSSportDes_Type_TaiChi = 131, //      太极
    TPSSportDes_Type_MuayThai = 132, //      泰拳
    TPSSportDes_Type_Taekwondo = 133, //      跆拳道
    TPSSportDes_Type_MartialArts = 134, //      武术
    TPSSportDes_Type_FreeSparring = 135, //      自由搏击
    TPSSportDes_Type_Shooting = 136, //      射击
    TPSSportDes_Type_Trampolining = 137, //      蹦床
    TPSSportDes_Type_RopeSkipping = 138, //      跳绳
    TPSSportDes_Type_OutdoorSoccer = 139, //      户外足球
    TPSSportDes_Type_WallBall = 140, //      墙球
    TPSSportDes_Type_SnowCar = 141, //      雪车
    TPSSportDes_Type_Kickboxing = 142, //      踢拳
    TPSSportDes_Type_RollerSkating = 143, //      轮滑
    TPSSportDes_Type_Skateboard = 144, //      滑板
};

@property (nonatomic, assign) long sport_id;
@property (nonatomic, assign) TPSSportDes_Type type;
@property (nonatomic, assign) int device_type;//0--手机运动  1--手表运动
@property (nonatomic, assign) long start_time;//单位秒
@property (nonatomic, assign) long end_time;//单位秒
@property (nonatomic, assign) long duration;//单位秒
@property (nonatomic, assign) double distance;//距离米
@property (nonatomic, assign) double calories;//单位千卡
@property (nonatomic, assign) int heartrate;
@property (nonatomic, assign) double pace;//单位秒/百米
@property (nonatomic, assign) int step;
@property (nonatomic, assign) double cadence;//单位步/分钟
/**
 热身级别的运动时长，单位分钟
 */
@property (nonatomic, assign) double warm_time;
/**
 燃脂级别的运动时长，单位分钟
 */
@property (nonatomic, assign) double light_time;//单位分钟
/**
 有氧级别的运动时长，单位分钟
 */
@property (nonatomic, assign) double high_time;//单位分钟
/**
 无氧级别的运动时长，单位分钟
 */
@property (nonatomic, assign) double critical_time;//单位分钟
/**
 极限级别的运动时长，单位分钟
 */
@property (nonatomic, assign) double limit_time;//单位分钟

@property (nonatomic, strong) NSArray<TPSSportItemModel*>* detailItemList;

-(instancetype)initWithTsDbDict:(NSDictionary *)dict;
-(instancetype)initWithNSData:(NSData*)jsonData;
-(NSData*)toJsonNSData;
-(void)caculateOtherWithStep:(int)step distance:(double)distance duration:(double)duration weight:(double)weight;
-(double)getSpeedInMeterPerSecond;

-(instancetype)initWithFwModel:(FwHistorySportModel*)fwHistorySportModel;

@end


#endif /* HistorySportModel_h */
