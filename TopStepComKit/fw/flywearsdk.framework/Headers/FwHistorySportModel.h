//
//  HistorySportModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/19.
//

#ifndef HistorySportModel_h
#define HistorySportModel_h

#import <flywearsdk/FwSportItemModel.h>
#import <flywearsdk/FwSportPreciseModel.h>

@interface FwHistorySportModel : NSObject

typedef NS_ENUM(UInt8, FwSportDes_Type){
    FwSportDes_Type_OutdoorRunning = 1, //      户外跑步
    FwSportDes_Type_Marathon = 2, //      马拉松
    FwSportDes_Type_OutdoorWalk = 3, //      户外健走
    FwSportDes_Type_Hiking = 4, //      户外徒步
    FwSportDes_Type_Mountaineering = 5, //      登山
    FwSportDes_Type_CrossCountryRunning = 6, //      越野跑
    FwSportDes_Type_Treadmill = 7, //      跑步机
    FwSportDes_Type_IndoorRunning = 8, //      室内跑步
    FwSportDes_Type_IndoorWalking = 9, //      室内走路
    FwSportDes_Type_Stepper = 10, //      踏步机
    FwSportDes_Type_OutdoorCycling = 11, //      户外骑行
    FwSportDes_Type_IndoorCycling = 12, //      室内骑行
    FwSportDes_Type_OutdoorSkating = 13, //      户外滑冰
    FwSportDes_Type_Hunt = 14, //      打猎
    FwSportDes_Type_Equestrian = 15, //      马术
    FwSportDes_Type_Rower = 16, //      划船机
    FwSportDes_Type_ToGoUpstairs = 17, //      爬楼梯
    FwSportDes_Type_IndoorFitness = 18, //      室内健身
    FwSportDes_Type_EllipticalMachine = 19, //      椭圆机
    FwSportDes_Type_StairClimbingMachine = 20, //      爬楼机
    FwSportDes_Type_FreeTraining = 21, //      自由训练
    FwSportDes_Type_CoreTraining = 22, //      核心训练
    FwSportDes_Type_MixedAerobic = 23, //      混合有氧
    FwSportDes_Type_MaxO2IntakeTest = 24, //      最大摄氧量测试
    FwSportDes_Type_StrengthTraining = 25, //      力量训练
    FwSportDes_Type_Stretch = 26, //      拉伸
    FwSportDes_Type_FloorExercise = 27, //      自由体操
    FwSportDes_Type_FlexibilityTraining = 28, //      柔韧训练
    FwSportDes_Type_StepTraining = 29, //      踏步训练
    FwSportDes_Type_Gymnastic = 30, //      体操
    FwSportDes_Type_HIIT = 31, //      高强度间歇训练
    FwSportDes_Type_Crossfit = 32, //      交叉训练
    FwSportDes_Type_PhysicalTraining = 33, //      体能训练
    FwSportDes_Type_DumbbellWorkout = 34, //      哑铃训练
    FwSportDes_Type_DumbbellWorkout1 = 35, //      杠铃训练
    FwSportDes_Type_Bodybuilding = 36, //      举重
    FwSportDes_Type_Deadlift = 37, //      硬拉
    FwSportDes_Type_Burpee = 38, //      波比跳
    FwSportDes_Type_JumpingJack = 39, //      开合跳
    FwSportDes_Type_SitUp = 40, //      仰卧起坐
    FwSportDes_Type_FunctionalTraining = 41, //      功能性训练
    FwSportDes_Type_UpperBodyWorkout = 42, //      上肢训练
    FwSportDes_Type_LowerBodyWorkout = 43, //      下肢训练
    FwSportDes_Type_WaistAndAbdomenTraining = 44, //      腰腹训练
    FwSportDes_Type_BackTraining = 45, //      背部训练
    FwSportDes_Type_HorizontalBar = 46, //      单杠
    FwSportDes_Type_ParallelBars = 47, //      双杠
    FwSportDes_Type_HighJumping = 48, //      跳高
    FwSportDes_Type_LongJumping = 49, //      跳远
    FwSportDes_Type_Pullups = 50, //      引体向上
    FwSportDes_Type_Pushups = 51, //      俯卧撑
    FwSportDes_Type_Planking = 52, //      平板支撑
    FwSportDes_Type_FoamRollerStretching = 53, //      泡沫轴筋膜放松
    FwSportDes_Type_FitnessGames = 54, //      健身游戏
    FwSportDes_Type_CalmingMeditation = 55, //      舒缓冥想
    FwSportDes_Type_AirWalker = 56, //      漫步机
    FwSportDes_Type_RockClimbing = 57, //      攀岩
    FwSportDes_Type_Atv = 58, //      沙滩车
    FwSportDes_Type_Paragliding = 59, //      滑翔伞
    FwSportDes_Type_Parkour = 60, //      跑酷
    FwSportDes_Type_Basketball = 61, //      篮球
    FwSportDes_Type_Football = 62, //      足球
    FwSportDes_Type_AustralianRulesFootball = 63, //      澳式足球
    FwSportDes_Type_TableTennis = 64, //      乒乓球
    FwSportDes_Type_Badminton = 65, //      羽毛球
    FwSportDes_Type_Cricket = 66, //      板球
    FwSportDes_Type_Baseball = 67, //      棒球
    FwSportDes_Type_Bowling = 68, //      保龄球
    FwSportDes_Type_Squash = 69, //      壁球
    FwSportDes_Type_Softball = 70, //      垒球
    FwSportDes_Type_Croquet = 71, //      门球
    FwSportDes_Type_Volleyball = 72, //      排球
    FwSportDes_Type_Handball = 73, //      手球
    FwSportDes_Type_WaterPolo = 74, //      水球
    FwSportDes_Type_Rugby = 75, //      橄榄球
    FwSportDes_Type_AmericanFootball = 76, //      美式橄榄球
    FwSportDes_Type_Hockey = 77, //      曲棍球
    FwSportDes_Type_Lacrosse = 78, //      长曲棍球
    FwSportDes_Type_Tennis = 79, //      网球
    FwSportDes_Type_Billiards = 80, //      台球
    FwSportDes_Type_Flying = 81, //      毽球
    FwSportDes_Type_SepakTakraw = 82, //      藤球
    FwSportDes_Type_Golf = 83, //      高尔夫
    FwSportDes_Type_Pickleball = 84, //      匹克球
    FwSportDes_Type_Yoga = 85, //      瑜伽
    FwSportDes_Type_Pilates = 86, //      普拉提
    FwSportDes_Type_SnowSports = 87, //      雪上运动
    FwSportDes_Type_Snowmobile = 88, //      雪地摩托
    FwSportDes_Type_Sled = 89, //      雪橇
    FwSportDes_Type_Curling = 90, //      冰壶
    FwSportDes_Type_IndoorSkating = 91, //      室内滑冰
    FwSportDes_Type_Puck = 92, //      冰球
    FwSportDes_Type_Ski = 93, //      滑雪
    FwSportDes_Type_CrossCountrySkiing = 94, //      越野滑雪
    FwSportDes_Type_SkiBoard = 95, //      滑雪板
    FwSportDes_Type_AlpineSkiing = 96, //      高山滑雪
    FwSportDes_Type_Snowboarding = 97, //      单板滑雪
    FwSportDes_Type_Ballet = 98, //      芭蕾舞
    FwSportDes_Type_BellyDance = 99, //      肚皮舞
    FwSportDes_Type_SquareDance = 100, //      广场舞
    FwSportDes_Type_StreetDance = 101, //      街舞
    FwSportDes_Type_BallroomDance = 102, //      交际舞
    FwSportDes_Type_Dance = 103, //      舞蹈
    FwSportDes_Type_Zumba = 104, //      尊巴
    FwSportDes_Type_Aerobics = 105, //      健身操
    FwSportDes_Type_NationalDance = 106, //      民族舞
    FwSportDes_Type_Jazz = 107, //      爵士舞
    FwSportDes_Type_LatinDance = 108, //      拉丁舞
    FwSportDes_Type_GroupCallisthenics = 109, //      团体操
    FwSportDes_Type_KickBoxing = 110, //      搏击操
    FwSportDes_Type_Archery = 111, //      射箭
    FwSportDes_Type_Darts = 112, //      飞镖
    FwSportDes_Type_TugOfWar = 113, //      拔河
    FwSportDes_Type_HulaHoop = 114, //      呼啦圈
    FwSportDes_Type_FlyAKite = 115, //      放风筝
    FwSportDes_Type_Fishing = 116, //      钓鱼
    FwSportDes_Type_Frisbee = 117, //      飞盘
    FwSportDes_Type_Kabaddi = 118, //      卡巴迪
    FwSportDes_Type_BungeeJumping = 119, //      蹦极
    FwSportDes_Type_Handcar = 120, //      手摇车
    FwSportDes_Type_HoverBoard = 121, //      平衡车
    FwSportDes_Type_LeisureSports = 122, //      休闲运动
    FwSportDes_Type_Fencing = 123, //      击剑
    FwSportDes_Type_TrackAndField = 124, //      田径
    FwSportDes_Type_Races = 125, //      赛车
    FwSportDes_Type_Triathlon = 126, //      铁人三项
    FwSportDes_Type_Karate = 127, //      空手道
    FwSportDes_Type_Boxing = 128, //      拳击
    FwSportDes_Type_Judo = 129, //      柔道
    FwSportDes_Type_Wrestling = 130, //      摔跤
    FwSportDes_Type_TaiChi = 131, //      太极
    FwSportDes_Type_MuayThai = 132, //      泰拳
    FwSportDes_Type_Taekwondo = 133, //      跆拳道
    FwSportDes_Type_MartialArts = 134, //      武术
    FwSportDes_Type_FreeSparring = 135, //      自由搏击
    FwSportDes_Type_Shooting = 136, //      射击
    FwSportDes_Type_Trampolining = 137, //      蹦床
    FwSportDes_Type_RopeSkipping = 138, //      跳绳
    FwSportDes_Type_OutdoorSoccer = 139, //      户外足球
    FwSportDes_Type_WallBall = 140, //      墙球
    FwSportDes_Type_SnowCar = 141, //      雪车
    FwSportDes_Type_Kickboxing = 142, //      踢拳
    FwSportDes_Type_RollerSkating = 143, //      轮滑
    FwSportDes_Type_Skateboard = 144, //      滑板

};

@property (nonatomic, assign) long sport_id;
@property (nonatomic, assign) FwSportDes_Type type;
@property (nonatomic, assign) int device_type;//0--手机运动  1--手表运动
@property (nonatomic, assign) long start_time;//单位秒
@property (nonatomic, assign) long end_time;//单位秒
@property (nonatomic, assign) long duration;//单位秒
@property (nonatomic, assign) double distance;//距离米
@property (nonatomic, assign) double calories;//单位千卡
@property (nonatomic, assign) int heartrate;
//一些总结数据，20240828后添加
@property (nonatomic, assign) int maxHeartrate;
@property (nonatomic, assign) int minHeartrate;
@property (nonatomic, assign) int avgHeartrate;
@property (nonatomic, assign) int maxCadence;
@property (nonatomic, assign) int minCadence;
@property (nonatomic, assign) int avgCadence;
@property (nonatomic, assign) int maxPace;
@property (nonatomic, assign) int minPace;
@property (nonatomic, assign) int avgPace;
/**
 配速 单位秒/千米
 */
@property (nonatomic, assign) double pace;//单位秒/千米

//step  跳绳：代表次数，划船：代表划船次数，运动就是 步数
@property (nonatomic, assign) int step;
/**
 步频，单位步/分钟
 */
@property (nonatomic, assign) double cadence;//单位步/分钟
/**
 热身级别的运动时长，单位second
 */
@property (nonatomic, assign) double warm_time;
/**
 燃脂级别的运动时长，单位second
 */
@property (nonatomic, assign) double light_time;
/**
 有氧级别的运动时长，单位second
 */
@property (nonatomic, assign) double high_time;
/**
 无氧级别的运动时长，单位second
 */
@property (nonatomic, assign) double critical_time;
/**
 极限级别的运动时长，单位second
 */
@property (nonatomic, assign) double limit_time;//单位分钟

// 绊绳次数
@property (nonatomic, assign) double stop;
// 最大连跳
@property (nonatomic, assign) double jump;




@property (nonatomic, strong) NSMutableArray<FwSportItemModel*>* detailItemList;
@property (nonatomic, strong) FwSportPreciseModel* sportPreciseModel;
@property (nonatomic, strong) NSMutableDictionary* extraInfo;

-(instancetype)initWithTsDbDict:(NSDictionary *)dict;
-(instancetype)initWithNSData:(NSData*)jsonData;
-(NSData*)toJsonNSData;
-(void)caculateOtherWithStep:(int)step distance:(double)distance duration:(double)duration weight:(double)weight;
-(double)getSpeedInMeterPerSecond;

@end


#endif /* HistorySportModel_h */
