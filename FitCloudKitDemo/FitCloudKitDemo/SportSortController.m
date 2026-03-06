//
//  SportSortController.m
//  FitCloudKitDemo
//
//  Created by Topstep on 2026/3/6.
//  Copyright © 2026 HetangSmart. All rights reserved.
//

#import "SportSortController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

static NSString * const kCellIdentifier = @"SportSlotCell";

#pragma mark - 运动槽位展示模型

/**
 * 运动槽位展示模型，用于在列表中展示运动类型信息
 */
@interface SportSlotDisplayModel : NSObject

/** 槽位索引 */
@property (nonatomic, assign) NSUInteger slotIndex;
/** 运动类型编号 */
@property (nonatomic, assign) UInt16 sportType;
/** 运动类型名称 */
@property (nonatomic, copy) NSString *sportName;

@end

@implementation SportSlotDisplayModel
@end

#pragma mark - SportSortController

@interface SportSortController () <UITableViewDataSource, UITableViewDelegate>

/** 运动槽位列表 */
@property (nonatomic, strong) NSMutableArray<SportSlotDisplayModel *> *slotList;
/** 列表视图 */
@property (nonatomic, strong) UITableView *tableView;
/** 顶部操作栏 */
@property (nonatomic, strong) UIView *headerBar;
/** 返回按钮 */
@property (nonatomic, strong) UIButton *backButton;
/** 查询按钮 */
@property (nonatomic, strong) UIButton *queryButton;
/** 保存排序按钮 */
@property (nonatomic, strong) UIButton *saveButton;
/** 状态标签 */
@property (nonatomic, strong) UILabel *statusLabel;
/** 加载指示器 */
@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;
/** 是否正在操作 */
@property (nonatomic, assign) BOOL isBusy;

@end

@implementation SportSortController

#pragma mark - Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.slotList = [NSMutableArray array];
    self.isBusy = NO;

    [self setupHeaderBar];
    [self setupTableView];
    [self setupStatusLabel];

    [self queryEditableSportSlots];
}

#pragma mark - UI 搭建

/**
 * 搭建顶部操作栏
 */
- (void)setupHeaderBar {
    self.headerBar = [[UIView alloc] init];
    self.headerBar.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:self.headerBar];

    // 返回按钮
    self.backButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [self.backButton setTitle:@"Back" forState:UIControlStateNormal];
    [self.backButton addTarget:self action:@selector(onGoBack) forControlEvents:UIControlEventTouchUpInside];
    [self.headerBar addSubview:self.backButton];

    // 标题
    UILabel *titleLabel = [[UILabel alloc] init];
    titleLabel.text = @"Sport Sort";
    titleLabel.font = [UIFont fontWithName:@"Menlo-Bold" size:18];
    titleLabel.textAlignment = NSTextAlignmentCenter;
    titleLabel.tag = 100;
    [self.headerBar addSubview:titleLabel];

    // 查询按钮
    self.queryButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [self.queryButton setTitle:@"Query" forState:UIControlStateNormal];
    self.queryButton.titleLabel.font = [UIFont fontWithName:@"Menlo-Bold" size:14];
    [self.queryButton addTarget:self action:@selector(onQuerySlots) forControlEvents:UIControlEventTouchUpInside];
    [self.headerBar addSubview:self.queryButton];

    // 保存按钮
    self.saveButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [self.saveButton setTitle:@"Save" forState:UIControlStateNormal];
    self.saveButton.titleLabel.font = [UIFont fontWithName:@"Menlo-Bold" size:14];
    [self.saveButton setTitleColor:[UIColor systemGreenColor] forState:UIControlStateNormal];
    [self.saveButton addTarget:self action:@selector(onSaveSortOrder) forControlEvents:UIControlEventTouchUpInside];
    [self.headerBar addSubview:self.saveButton];

    // 加载指示器
    self.activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleMedium];
    self.activityIndicator.hidesWhenStopped = YES;
    [self.headerBar addSubview:self.activityIndicator];
}

/**
 * 搭建列表视图
 */
- (void)setupTableView {
    self.tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
    self.tableView.editing = YES;
    self.tableView.allowsSelectionDuringEditing = NO;
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:kCellIdentifier];
    self.tableView.tableFooterView = [[UIView alloc] init];
    [self.view addSubview:self.tableView];
}

/**
 * 搭建底部状态标签
 */
- (void)setupStatusLabel {
    self.statusLabel = [[UILabel alloc] init];
    self.statusLabel.font = [UIFont fontWithName:@"Menlo-Regular" size:12];
    self.statusLabel.textColor = [UIColor grayColor];
    self.statusLabel.textAlignment = NSTextAlignmentCenter;
    self.statusLabel.numberOfLines = 0;
    self.statusLabel.text = @"Drag to reorder, then tap Save.";
    [self.view addSubview:self.statusLabel];
}

/**
 * 使用Frame布局
 */
- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];

    CGFloat topInset = self.view.safeAreaInsets.top;
    CGFloat bottomInset = self.view.safeAreaInsets.bottom;
    CGFloat width = self.view.bounds.size.width;
    CGFloat height = self.view.bounds.size.height;

    CGFloat headerHeight = 50.0;
    self.headerBar.frame = CGRectMake(0, topInset, width, headerHeight);

    self.backButton.frame = CGRectMake(16, 10, 60, 30);

    UILabel *titleLabel = [self.headerBar viewWithTag:100];
    titleLabel.frame = CGRectMake(80, 10, width - 160, 30);

    self.saveButton.frame = CGRectMake(width - 70, 10, 50, 30);
    self.queryButton.frame = CGRectMake(width - 130, 10, 55, 30);
    self.activityIndicator.frame = CGRectMake(width / 2 + 40, 15, 20, 20);

    CGFloat statusHeight = 40.0;
    self.statusLabel.frame = CGRectMake(16, height - bottomInset - statusHeight, width - 32, statusHeight);

    CGFloat tableTop = topInset + headerHeight;
    CGFloat tableBottom = height - bottomInset - statusHeight;
    self.tableView.frame = CGRectMake(0, tableTop, width, tableBottom - tableTop);
}

#pragma mark - 操作回调

/**
 * 返回上一页
 */
- (void)onGoBack {
    [self.navigationController popViewControllerAnimated:YES];
}

/**
 * 查询可编辑运动槽位
 */
- (void)onQuerySlots {
    [self queryEditableSportSlots];
}

/**
 * 保存排序结果到设备
 */
- (void)onSaveSortOrder {
    [self saveEditableSportSlots];
}

#pragma mark - 运动槽位查询

/**
 * 从设备查询可编辑的运动槽位
 */
- (void)queryEditableSportSlots {
    if (self.isBusy) {
        XLOG_INFO(@"[SportSort] busy, ignore query request");
        return;
    }
    self.isBusy = YES;
    [self.activityIndicator startAnimating];
    self.statusLabel.text = @"Querying editable sport slots...";

    __weak typeof(self) weakSelf = self;

    [TPSSdk.share.sportDataAbility queryEditableSportSlots:^(NSArray *sportSlotList) {
        dispatch_async(dispatch_get_main_queue(), ^{
            __strong typeof(weakSelf) strongSelf = weakSelf;
            if (!strongSelf) return;

            [strongSelf.activityIndicator stopAnimating];
            strongSelf.isBusy = NO;

            if (sportSlotList && sportSlotList.count > 0) {
                [strongSelf.slotList removeAllObjects];
                for (NSUInteger i = 0; i < sportSlotList.count; i++) {
                    id slotObj = sportSlotList[i];
                    SportSlotDisplayModel *displayModel = [[SportSlotDisplayModel alloc] init];

                    // 通过KVC安全获取属性值
                    NSUInteger slotIndex = i;
                    UInt16 sportType = 0;
                    @try {
                        slotIndex = [[slotObj valueForKey:@"slotIndex"] unsignedIntegerValue];
                        sportType = [[slotObj valueForKey:@"sportType"] unsignedShortValue];
                    } @catch (NSException *exception) {
                        XLOG_INFO(@"[SportSort] KVC failed: %@", exception);
                    }

                    displayModel.slotIndex = slotIndex;
                    displayModel.sportType = sportType;
                    displayModel.sportName = [strongSelf sportNameForType:sportType];

                    [strongSelf.slotList addObject:displayModel];
                    XLOG_INFO(@"[SportSort] slot[%lu] sportType=%d name=%@", (unsigned long)slotIndex, sportType, displayModel.sportName);
                }

                [strongSelf.tableView reloadData];
                strongSelf.statusLabel.text = [NSString stringWithFormat:@"Loaded %lu slots. Drag to reorder.", (unsigned long)sportSlotList.count];
                ConsoleResultToastTip(strongSelf.view);
            } else {
                strongSelf.statusLabel.text = @"No editable sport slots found. Try Query again.";
                XLOG_INFO(@"[SportSort] no editable slots returned");
                OpResultToastTip(strongSelf.view, NO);
            }
        });
    }];
}

#pragma mark - 运动槽位保存

/**
 * 将重新排序后的运动槽位发送到设备
 */
- (void)saveEditableSportSlots {
    if (self.isBusy) {
        XLOG_INFO(@"[SportSort] busy, ignore save request");
        return;
    }
    if (self.slotList.count == 0) {
        self.statusLabel.text = @"No slots to save. Query first.";
        return;
    }

    self.isBusy = YES;
    [self.activityIndicator startAnimating];
    self.statusLabel.text = @"Saving new sort order...";

    // 打印当前排序
    XLOG_INFO(@"[SportSort] saving new order (%lu slots):", (unsigned long)self.slotList.count);
    NSMutableArray *slotsToSend = [NSMutableArray array];
    for (NSUInteger i = 0; i < self.slotList.count; i++) {
        SportSlotDisplayModel *model = self.slotList[i];
        XLOG_INFO(@"[SportSort]   position[%lu] -> sportType=%d (%@)", (unsigned long)i, model.sportType, model.sportName);

        // 构建 TPSSportSlotModel 对象（通过KVC设置属性）
        Class slotModelClass = NSClassFromString(@"TPSSportSlotModel");
        if (slotModelClass) {
            id slotModel = [[slotModelClass alloc] init];
            @try {
                [slotModel setValue:@(i) forKey:@"slotIndex"];
                [slotModel setValue:@(model.sportType) forKey:@"sportType"];
            } @catch (NSException *exception) {
                XLOG_INFO(@"[SportSort] KVC set failed: %@", exception);
            }
            [slotsToSend addObject:slotModel];
        }
    }

    __weak typeof(self) weakSelf = self;

    if (slotsToSend.count > 0) {
        [TPSSdk.share.sportDataAbility updateEditableSportSlots:slotsToSend completion:^(BOOL isSuccess, NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                __strong typeof(weakSelf) strongSelf = weakSelf;
                if (!strongSelf) return;

                [strongSelf.activityIndicator stopAnimating];
                strongSelf.isBusy = NO;

                if (isSuccess) {
                    strongSelf.statusLabel.text = @"Sort order saved successfully!";
                    XLOG_INFO(@"[SportSort] save succeeded");
                } else {
                    strongSelf.statusLabel.text = [NSString stringWithFormat:@"Save failed: %@", error.localizedDescription ?: @"Unknown"];
                    XLOG_INFO(@"[SportSort] save failed: %@", error);
                }
                OpResultToastTip(strongSelf.view, isSuccess);
            });
        }];
    } else {
        self.activityIndicator.hidden = YES;
        self.isBusy = NO;
        self.statusLabel.text = @"TPSSportSlotModel class not found. Cannot save.";
        XLOG_INFO(@"[SportSort] TPSSportSlotModel class not found at runtime");
        OpResultToastTip(self.view, NO);
    }
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.slotList.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kCellIdentifier forIndexPath:indexPath];
    SportSlotDisplayModel *model = self.slotList[indexPath.row];

    cell.textLabel.text = [NSString stringWithFormat:@"[%lu] %@ (type:%d)",
                           (unsigned long)indexPath.row,
                           model.sportName,
                           model.sportType];
    cell.textLabel.font = [UIFont fontWithName:@"Menlo-Regular" size:14];
    cell.showsReorderControl = YES;
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

#pragma mark - UITableViewDelegate (拖拽排序)

- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    return YES;
}

- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath {
    SportSlotDisplayModel *movedItem = self.slotList[sourceIndexPath.row];
    [self.slotList removeObjectAtIndex:sourceIndexPath.row];
    [self.slotList insertObject:movedItem atIndex:destinationIndexPath.row];

    XLOG_INFO(@"[SportSort] moved slot from position %ld to %ld (sportType=%d, %@)",
              (long)sourceIndexPath.row, (long)destinationIndexPath.row,
              movedItem.sportType, movedItem.sportName);

    self.statusLabel.text = [NSString stringWithFormat:@"Moved \"%@\" to position %ld. Tap Save to apply.",
                             movedItem.sportName, (long)destinationIndexPath.row];
}

- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath {
    return UITableViewCellEditingStyleNone;
}

- (BOOL)tableView:(UITableView *)tableView shouldIndentWhileEditingRowAtIndexPath:(NSIndexPath *)indexPath {
    return NO;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 54.0;
}

#pragma mark - 运动类型名称映射

/**
 * 根据运动类型编号返回运动类型名称
 */
- (NSString *)sportNameForType:(UInt16)sportType {
    static NSDictionary<NSNumber *, NSString *> *sportNameMap = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sportNameMap = @{
            @(0)   : @"Other",
            @(1)   : @"Outdoor Running",
            @(2)   : @"Marathon",
            @(3)   : @"Outdoor Walk",
            @(4)   : @"Hiking",
            @(5)   : @"Mountaineering",
            @(6)   : @"Cross Country Running",
            @(7)   : @"Treadmill",
            @(8)   : @"Indoor Running",
            @(9)   : @"Indoor Walking",
            @(10)  : @"Stepper",
            @(11)  : @"Outdoor Cycling",
            @(12)  : @"Indoor Cycling",
            @(13)  : @"Outdoor Skating",
            @(14)  : @"Hunt",
            @(15)  : @"Equestrian",
            @(16)  : @"Rower",
            @(17)  : @"To Go Upstairs",
            @(18)  : @"Indoor Fitness",
            @(19)  : @"Elliptical Machine",
            @(20)  : @"Stair Climbing Machine",
            @(21)  : @"Free Training",
            @(22)  : @"Core Training",
            @(23)  : @"Mixed Aerobic",
            @(24)  : @"Max O2 Intake Test",
            @(25)  : @"Strength Training",
            @(26)  : @"Stretch",
            @(27)  : @"Floor Exercise",
            @(28)  : @"Flexibility Training",
            @(29)  : @"Step Training",
            @(30)  : @"Gymnastic",
            @(31)  : @"HIIT",
            @(32)  : @"Crossfit",
            @(33)  : @"Physical Training",
            @(34)  : @"Dumbbell Workout",
            @(35)  : @"Barbell Workout",
            @(36)  : @"Bodybuilding",
            @(37)  : @"Deadlift",
            @(38)  : @"Burpee",
            @(39)  : @"Jumping Jack",
            @(40)  : @"Sit Up",
            @(41)  : @"Functional Training",
            @(42)  : @"Upper Body Workout",
            @(43)  : @"Lower Body Workout",
            @(44)  : @"Waist And Abdomen Training",
            @(45)  : @"Back Training",
            @(46)  : @"Horizontal Bar",
            @(47)  : @"Parallel Bars",
            @(48)  : @"High Jumping",
            @(49)  : @"Long Jumping",
            @(50)  : @"Pullups",
            @(51)  : @"Pushups",
            @(52)  : @"Planking",
            @(53)  : @"Foam Roller Stretching",
            @(54)  : @"Fitness Games",
            @(55)  : @"Calming Meditation",
            @(56)  : @"Air Walker",
            @(57)  : @"Rock Climbing",
            @(58)  : @"ATV",
            @(59)  : @"Paragliding",
            @(60)  : @"Parkour",
            @(61)  : @"Basketball",
            @(62)  : @"Football",
            @(63)  : @"Australian Rules Football",
            @(64)  : @"Table Tennis",
            @(65)  : @"Badminton",
            @(66)  : @"Cricket",
            @(67)  : @"Baseball",
            @(68)  : @"Bowling",
            @(69)  : @"Squash",
            @(70)  : @"Softball",
            @(71)  : @"Croquet",
            @(72)  : @"Volleyball",
            @(73)  : @"Handball",
            @(74)  : @"Water Polo",
            @(75)  : @"Rugby",
            @(76)  : @"American Football",
            @(77)  : @"Hockey",
            @(78)  : @"Lacrosse",
            @(79)  : @"Tennis",
            @(80)  : @"Billiards",
            @(81)  : @"Flying",
            @(82)  : @"Sepak Takraw",
            @(83)  : @"Golf",
            @(84)  : @"Pickleball",
            @(85)  : @"Yoga",
            @(86)  : @"Pilates",
            @(87)  : @"Snow Sports",
            @(88)  : @"Snowmobile",
            @(89)  : @"Sled",
            @(90)  : @"Curling",
            @(91)  : @"Indoor Skating",
            @(92)  : @"Puck",
            @(93)  : @"Ski",
            @(94)  : @"Cross Country Skiing",
            @(95)  : @"Ski Board",
            @(96)  : @"Alpine Skiing",
            @(97)  : @"Snowboarding",
            @(98)  : @"Ballet",
            @(99)  : @"Belly Dance",
            @(100) : @"Square Dance",
            @(101) : @"Street Dance",
            @(102) : @"Ballroom Dance",
            @(103) : @"Dance",
            @(104) : @"Zumba",
            @(105) : @"Aerobics",
            @(106) : @"National Dance",
            @(107) : @"Jazz",
            @(108) : @"Latin Dance",
            @(109) : @"Group Callisthenics",
            @(110) : @"Kick Boxing",
            @(111) : @"Archery",
            @(112) : @"Darts",
            @(113) : @"Tug Of War",
            @(114) : @"Hula Hoop",
            @(115) : @"Fly A Kite",
            @(116) : @"Fishing",
            @(117) : @"Frisbee",
            @(118) : @"Kabaddi",
            @(119) : @"Bungee Jumping",
            @(120) : @"Handcar",
            @(121) : @"Hover Board",
            @(122) : @"Leisure Sports",
            @(123) : @"Fencing",
            @(124) : @"Track And Field",
            @(125) : @"Races",
            @(126) : @"Triathlon",
            @(127) : @"Karate",
            @(128) : @"Boxing",
            @(129) : @"Judo",
            @(130) : @"Wrestling",
            @(131) : @"Tai Chi",
            @(132) : @"Muay Thai",
            @(133) : @"Taekwondo",
            @(134) : @"Martial Arts",
            @(135) : @"Free Sparring",
            @(136) : @"Shooting",
            @(137) : @"Trampolining",
            @(138) : @"Rope Skipping",
            @(139) : @"Outdoor Soccer",
            @(140) : @"Wall Ball",
            @(141) : @"Snow Car",
            @(142) : @"Kickboxing",
            @(143) : @"Roller Skating",
            @(144) : @"Skateboard",
            @(145) : @"Pool Swimming",
            @(146) : @"Open Water Swimming",
            @(255) : @"None",
        };
    });

    NSString *name = sportNameMap[@(sportType)];
    return name ?: [NSString stringWithFormat:@"Sport(%d)", sportType];
}

@end
