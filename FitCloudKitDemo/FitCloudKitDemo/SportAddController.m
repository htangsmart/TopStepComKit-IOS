//
//  SportAddController.m
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/7/29.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SportAddController.h"
#import "SportAddModel.h"
#import <SDWebImage/UIImageView+WebCache.h>

#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

/// 用于 SportAddController TableView 展示的槽位视图模型
@interface SportSlotEditModel : NSObject
@property(nonatomic, assign) NSUInteger slotIndex;
@property(nonatomic, assign) BOOL isEmpty;       // sportType 为 TPSSportDes_Type_None 时为 YES
@property(nonatomic, assign) TPSSportDes_Type sportType;
@property(nonatomic, copy)   NSString *sportName;
@end

@implementation SportSlotEditModel
@end


@interface SportAddController (){
    // 所有可编辑槽位（来自 TPSSdk queryEditableSportSlots）
    NSArray<TPSSportSlotModel *> *editableSlots;
    // 所有支持的运动类型（从 editableSlots 提取去重）
    NSMutableArray<SportAddModel *> *allSportTypes;
    // 拼装后供 TableView 使用的显示模型
    NSMutableArray<SportSlotEditModel *> *displayList;

    UIActivityIndicatorView *activityIndicator;
    BOOL hasUnsavedChanges; // 标记是否有未保存的修改
}
- (IBAction)OnGoBack:(id)sender;
@end


@implementation SportAddController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"运动槽位管理";
    displayList      = [NSMutableArray new];
    allSportTypes    = [NSMutableArray new];
    hasUnsavedChanges = NO;

    // 右上角保存按钮
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]
                                              initWithTitle:@"保存"
                                              style:UIBarButtonItemStyleDone
                                              target:self
                                              action:@selector(onSave)];

    self.tableView.delegate                     = self;
    self.tableView.dataSource                   = self;
    self.tableView.allowsSelection              = YES;
    self.tableView.editing                      = YES;
    self.tableView.allowsSelectionDuringEditing = YES;

    [self queryAllWorkoutSlots];
}

#pragma mark - 方法1: 查询所有运动槽位信息

/// 所有槽位均可编辑，直接查询可编辑槽位（sportType 为 TPSSportDes_Type_None 表示空）
-(void)queryAllWorkoutSlots {
    [self showProgress];
    [TPSSdk.share.sportDataAbility queryEditableSportSlots:^(NSArray<TPSSportSlotModel *> * _Nullable sportSlotList) {
        if (sportSlotList && sportSlotList.count > 0) {
            self->editableSlots = sportSlotList;
            NSLog(@"queryEditableSportSlots: 共 %lu 个槽位", (unsigned long)sportSlotList.count);
        } else {
            NSLog(@"queryEditableSportSlots: 无槽位数据");
            self->editableSlots = @[];
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            [self queryAllSportTypes];
        });
    }];
}

#pragma mark - 方法2: 查询所有运动类型（从 SDK）

-(void)queryAllSportTypes {
    [TPSSdk.share.sportDataAbility queryAllSportTypes:^(NSArray<NSNumber *> * _Nullable sportTypes, NSError * _Nullable error) {
        [self->allSportTypes removeAllObjects];

        if (sportTypes && sportTypes.count > 0) {
            for (NSNumber *typeNum in sportTypes) {
                TPSSportDes_Type type = (TPSSportDes_Type)typeNum.unsignedIntValue;
                SportAddModel *model = [[SportAddModel alloc] init];
                model.sportType = type;
                model.sportName = [self sportNameForType:type] ?: [NSString stringWithFormat:@"Sport(%d)", type];
                [self->allSportTypes addObject:model];
            }
            NSLog(@"queryAllSportTypes: 共 %lu 种运动类型", (unsigned long)self->allSportTypes.count);
        } else {
            NSLog(@"queryAllSportTypes failed: %@", error.localizedDescription ?: @"无数据");
        }

        dispatch_async(dispatch_get_main_queue(), ^{
            [self buildDisplayList];
            [self removeProgress];
            [self.tableView reloadData];
        });
    }];
}

#pragma mark - 拼装显示模型

-(void)buildDisplayList {
    [displayList removeAllObjects];

    // 按 slotIndex 升序排列
    NSArray *sorted = [editableSlots sortedArrayUsingComparator:^NSComparisonResult(TPSSportSlotModel *a,
                                                                                     TPSSportSlotModel *b) {
        return a.slotIndex < b.slotIndex ? NSOrderedAscending : NSOrderedDescending;
    }];

    for (TPSSportSlotModel *slot in sorted) {
        SportSlotEditModel *dm = [[SportSlotEditModel alloc] init];
        dm.slotIndex = slot.slotIndex;
        dm.sportType = slot.sportType;
        dm.isEmpty   = (slot.sportType == TPSSportDes_Type_None);

        if (!dm.isEmpty) {
            dm.sportName = [self sportNameForType:dm.sportType] ?: @"Unknown";
        }

        [displayList addObject:dm];
    }
}

#pragma mark - TableView DataSource / Delegate

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return displayList.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"SlotCell"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:@"SlotCell"];
    }

    SportSlotEditModel *dm = displayList[indexPath.row];
    cell.accessoryType  = UITableViewCellAccessoryDisclosureIndicator;
    cell.selectionStyle = UITableViewCellSelectionStyleDefault;
    cell.showsReorderControl = YES; // 显示拖动手柄

    if (dm.isEmpty) {
        cell.textLabel.text      = [NSString stringWithFormat:@"槽位 %lu", (unsigned long)dm.slotIndex];
        cell.textLabel.textColor = [UIColor systemGrayColor];
        cell.detailTextLabel.text      = @"空，点击添加";
        cell.detailTextLabel.textColor = [UIColor systemGreenColor];
    } else {
        cell.textLabel.text      = [NSString stringWithFormat:@"槽位 %lu  —  %@", (unsigned long)dm.slotIndex, dm.sportName];
        cell.textLabel.textColor = [UIColor labelColor];
        cell.detailTextLabel.text      = @"点击修改";
        cell.detailTextLabel.textColor = [UIColor systemBlueColor];
    }

    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    NSLog(@"[SportAdd] didSelectRow: %ld, displayList.count: %lu, allSportTypes.count: %lu",
          (long)indexPath.row, (unsigned long)displayList.count, (unsigned long)allSportTypes.count);
    [self showSportPickerForSlot:displayList[indexPath.row]];
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 54.0;
}

#pragma mark - TableView 拖动排序

// 允许所有行拖动
-(BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    return YES;
}

// 拖动完成后更新数据源
-(void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath {
    SportSlotEditModel *movedItem = displayList[sourceIndexPath.row];
    [displayList removeObjectAtIndex:sourceIndexPath.row];
    [displayList insertObject:movedItem atIndex:destinationIndexPath.row];

    NSLog(@"[SportAdd] 拖动槽位 %lu 从位置 %ld → %ld",
          (unsigned long)movedItem.slotIndex, (long)sourceIndexPath.row, (long)destinationIndexPath.row);

    // 拖动后需要更新所有槽位的 slotIndex，使其与新位置对应
    [self updateSlotIndicesAfterReorder];
}

// 禁用编辑模式下的删除按钮（只允许拖动，不允许删除）
-(UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath {
    return UITableViewCellEditingStyleNone;
}

// 禁用编辑模式下的缩进
-(BOOL)tableView:(UITableView *)tableView shouldIndentWhileEditingRowAtIndexPath:(NSIndexPath *)indexPath {
    return NO;
}

// 拖动后更新所有槽位的 slotIndex（仅更新本地数据，不立即同步）
-(void)updateSlotIndicesAfterReorder {
    for (NSUInteger i = 0; i < displayList.count; i++) {
        SportSlotEditModel *dm = displayList[i];
        dm.slotIndex = i;
    }
    hasUnsavedChanges = YES;
    NSLog(@"[SportAdd] 槽位排序已更新（未保存），请点击保存按钮同步到手表");
}

#pragma mark - 运动类型选择弹窗

-(void)showSportPickerForSlot:(SportSlotEditModel *)slotModel {
    NSLog(@"[SportAdd] showSportPickerForSlot: slotIndex=%lu, allSportTypes.count=%lu",
          (unsigned long)slotModel.slotIndex, (unsigned long)allSportTypes.count);

    if (allSportTypes.count == 0) {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"提示"
                                                                       message:@"暂无可选运动类型，请稍后重试"
                                                                preferredStyle:UIAlertControllerStyleAlert];
        [alert addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:nil]];
        [self presentViewController:alert animated:YES completion:nil];
        return;
    }

    // 收集已被其他槽位使用的运动类型（排除当前槽位）
    NSMutableSet<NSNumber *> *usedSportTypes = [NSMutableSet new];
    for (SportSlotEditModel *dm in displayList) {
        if (dm.slotIndex != slotModel.slotIndex && !dm.isEmpty) {
            [usedSportTypes addObject:@(dm.sportType)];
        }
    }

    // 过滤出可选的运动类型（未被其他槽位使用）
    NSMutableArray<SportAddModel *> *availableSportTypes = [NSMutableArray new];
    for (SportAddModel *sport in allSportTypes) {
        if (![usedSportTypes containsObject:@(sport.sportType)]) {
            [availableSportTypes addObject:sport];
        }
    }

    if (availableSportTypes.count == 0) {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"提示"
                                                                       message:@"所有运动类型已被使用，无可选项"
                                                                preferredStyle:UIAlertControllerStyleAlert];
        [alert addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:nil]];
        [self presentViewController:alert animated:YES completion:nil];
        return;
    }

    NSString *title = slotModel.isEmpty
        ? [NSString stringWithFormat:@"槽位 %lu — 选择运动类型", (unsigned long)slotModel.slotIndex]
        : [NSString stringWithFormat:@"槽位 %lu — 修改运动类型", (unsigned long)slotModel.slotIndex];

    UIAlertController *alert = [UIAlertController alertControllerWithTitle:title
                                                                    message:nil
                                                             preferredStyle:UIAlertControllerStyleActionSheet];

    __weak typeof(self) weakSelf = self;
    for (SportAddModel *sport in availableSportTypes) {
        UIAlertAction *action = [UIAlertAction actionWithTitle:sport.sportName
                                                         style:UIAlertActionStyleDefault
                                                       handler:^(UIAlertAction *act) {
            [weakSelf assignSport:sport toSlot:slotModel];
        }];
        [alert addAction:action];
    }

    [alert addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil]];

    if (UIDevice.currentDevice.userInterfaceIdiom == UIUserInterfaceIdiomPad) {
        alert.popoverPresentationController.sourceView = self.view;
        alert.popoverPresentationController.sourceRect = CGRectMake(self.view.bounds.size.width / 2,
                                                                     self.view.bounds.size.height / 2, 0, 0);
    }

    [self presentViewController:alert animated:YES completion:nil];
}

-(void)assignSport:(SportAddModel *)sport toSlot:(SportSlotEditModel *)slotModel {
    NSLog(@"用户选择：槽位 %lu ← 运动类型 %@ (type=%d)", (unsigned long)slotModel.slotIndex, sport.sportName, sport.sportType);

    slotModel.isEmpty   = NO;
    slotModel.sportType = (TPSSportDes_Type)sport.sportType;
    slotModel.sportName = sport.sportName;

    hasUnsavedChanges = YES;
    [self.tableView reloadData];
    NSLog(@"[SportAdd] 运动类型已更新（未保存），请点击保存按钮同步到手表");
}

#pragma mark - 辅助

-(NSString *)sportNameForType:(TPSSportDes_Type)sportType {
    static NSDictionary<NSNumber *, NSString *> *sportNameMap = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sportNameMap = @{
            @(TPSSportDes_Type_None)   : @"None",
            @(TPSSportDes_Type_Other)   : @"Other",
            @(TPSSportDes_Type_OutdoorRunning)   : @"Outdoor Running",
            @(TPSSportDes_Type_Marathon)   : @"Marathon",
            @(TPSSportDes_Type_OutdoorWalk)   : @"Outdoor Walk",
            @(TPSSportDes_Type_Hiking)   : @"Hiking",
            @(TPSSportDes_Type_Mountaineering)   : @"Mountaineering",
            @(TPSSportDes_Type_CrossCountryRunning)   : @"Cross Country Running",
            @(TPSSportDes_Type_Treadmill)   : @"Treadmill",
            @(TPSSportDes_Type_IndoorRunning)   : @"Indoor Running",
            @(TPSSportDes_Type_IndoorWalking)   : @"Indoor Walking",
            @(TPSSportDes_Type_Stepper)  : @"Stepper",
            @(TPSSportDes_Type_OutdoorCycling)  : @"Outdoor Cycling",
            @(TPSSportDes_Type_IndoorCycling)  : @"Indoor Cycling",
            @(TPSSportDes_Type_OutdoorSkating)  : @"Outdoor Skating",
            @(TPSSportDes_Type_Hunt)  : @"Hunt",
            @(TPSSportDes_Type_Equestrian)  : @"Equestrian",
            @(TPSSportDes_Type_Rower)  : @"Rower",
            @(TPSSportDes_Type_ToGoUpstairs)  : @"To Go Upstairs",
            @(TPSSportDes_Type_IndoorFitness)  : @"Indoor Fitness",
            @(TPSSportDes_Type_EllipticalMachine)  : @"Elliptical Machine",
            @(TPSSportDes_Type_StairClimbingMachine)  : @"Stair Climbing Machine",
            @(TPSSportDes_Type_FreeTraining)  : @"Free Training",
            @(TPSSportDes_Type_CoreTraining)  : @"Core Training",
            @(TPSSportDes_Type_MixedAerobic)  : @"Mixed Aerobic",
            @(TPSSportDes_Type_MaxO2IntakeTest)  : @"Max O2 Intake Test",
            @(TPSSportDes_Type_StrengthTraining)  : @"Strength Training",
            @(TPSSportDes_Type_Stretch)  : @"Stretch",
            @(TPSSportDes_Type_FloorExercise)  : @"Floor Exercise",
            @(TPSSportDes_Type_FlexibilityTraining)  : @"Flexibility Training",
            @(TPSSportDes_Type_StepTraining)  : @"Step Training",
            @(TPSSportDes_Type_Gymnastic)  : @"Gymnastic",
            @(TPSSportDes_Type_HIIT)  : @"HIIT",
            @(TPSSportDes_Type_Crossfit)  : @"Crossfit",
            @(TPSSportDes_Type_PhysicalTraining)  : @"Physical Training",
            @(TPSSportDes_Type_DumbbellWorkout)  : @"Dumbbell Workout",
            @(TPSSportDes_Type_DumbbellWorkout1)  : @"Barbell Workout",
            @(TPSSportDes_Type_Bodybuilding)  : @"Bodybuilding",
            @(TPSSportDes_Type_Deadlift)  : @"Deadlift",
            @(TPSSportDes_Type_Burpee)  : @"Burpee",
            @(TPSSportDes_Type_JumpingJack)  : @"Jumping Jack",
            @(TPSSportDes_Type_SitUp)  : @"Sit Up",
            @(TPSSportDes_Type_FunctionalTraining)  : @"Functional Training",
            @(TPSSportDes_Type_UpperBodyWorkout)  : @"Upper Body Workout",
            @(TPSSportDes_Type_LowerBodyWorkout)  : @"Lower Body Workout",
            @(TPSSportDes_Type_WaistAndAbdomenTraining)  : @"Waist And Abdomen Training",
            @(TPSSportDes_Type_BackTraining)  : @"Back Training",
            @(TPSSportDes_Type_HorizontalBar)  : @"Horizontal Bar",
            @(TPSSportDes_Type_ParallelBars)  : @"Parallel Bars",
            @(TPSSportDes_Type_HighJumping)  : @"High Jumping",
            @(TPSSportDes_Type_LongJumping)  : @"Long Jumping",
            @(TPSSportDes_Type_Pullups)  : @"Pullups",
            @(TPSSportDes_Type_Pushups)  : @"Pushups",
            @(TPSSportDes_Type_Planking)  : @"Planking",
            @(TPSSportDes_Type_FoamRollerStretching)  : @"Foam Roller Stretching",
            @(TPSSportDes_Type_FitnessGames)  : @"Fitness Games",
            @(TPSSportDes_Type_CalmingMeditation)  : @"Calming Meditation",
            @(TPSSportDes_Type_AirWalker)  : @"Air Walker",
            @(TPSSportDes_Type_RockClimbing)  : @"Rock Climbing",
            @(TPSSportDes_Type_Atv)  : @"ATV",
            @(TPSSportDes_Type_Paragliding)  : @"Paragliding",
            @(TPSSportDes_Type_Parkour)  : @"Parkour",
            @(TPSSportDes_Type_Basketball)  : @"Basketball",
            @(TPSSportDes_Type_Football)  : @"Football",
            @(TPSSportDes_Type_AustralianRulesFootball)  : @"Australian Rules Football",
            @(TPSSportDes_Type_TableTennis)  : @"Table Tennis",
            @(TPSSportDes_Type_Badminton)  : @"Badminton",
            @(TPSSportDes_Type_Cricket)  : @"Cricket",
            @(TPSSportDes_Type_Baseball)  : @"Baseball",
            @(TPSSportDes_Type_Bowling)  : @"Bowling",
            @(TPSSportDes_Type_Squash)  : @"Squash",
            @(TPSSportDes_Type_Softball)  : @"Softball",
            @(TPSSportDes_Type_Croquet)  : @"Croquet",
            @(TPSSportDes_Type_Volleyball)  : @"Volleyball",
            @(TPSSportDes_Type_Handball)  : @"Handball",
            @(TPSSportDes_Type_WaterPolo)  : @"Water Polo",
            @(TPSSportDes_Type_Rugby)  : @"Rugby",
            @(TPSSportDes_Type_AmericanFootball)  : @"American Football",
            @(TPSSportDes_Type_Hockey)  : @"Hockey",
            @(TPSSportDes_Type_Lacrosse)  : @"Lacrosse",
            @(TPSSportDes_Type_Tennis)  : @"Tennis",
            @(TPSSportDes_Type_Billiards)  : @"Billiards",
            @(TPSSportDes_Type_Flying)  : @"Flying",
            @(TPSSportDes_Type_SepakTakraw)  : @"Sepak Takraw",
            @(TPSSportDes_Type_Golf)  : @"Golf",
            @(TPSSportDes_Type_Pickleball)  : @"Pickleball",
            @(TPSSportDes_Type_Yoga)  : @"Yoga",
            @(TPSSportDes_Type_Pilates)  : @"Pilates",
            @(TPSSportDes_Type_SnowSports)  : @"Snow Sports",
            @(TPSSportDes_Type_Snowmobile)  : @"Snowmobile",
            @(TPSSportDes_Type_Sled)  : @"Sled",
            @(TPSSportDes_Type_Curling)  : @"Curling",
            @(TPSSportDes_Type_IndoorSkating)  : @"Indoor Skating",
            @(TPSSportDes_Type_Puck)  : @"Puck",
            @(TPSSportDes_Type_Ski)  : @"Ski",
            @(TPSSportDes_Type_CrossCountrySkiing)  : @"Cross Country Skiing",
            @(TPSSportDes_Type_SkiBoard)  : @"Ski Board",
            @(TPSSportDes_Type_AlpineSkiing)  : @"Alpine Skiing",
            @(TPSSportDes_Type_Snowboarding)  : @"Snowboarding",
            @(TPSSportDes_Type_Ballet)  : @"Ballet",
            @(TPSSportDes_Type_BellyDance)  : @"Belly Dance",
            @(TPSSportDes_Type_SquareDance) : @"Square Dance",
            @(TPSSportDes_Type_StreetDance) : @"Street Dance",
            @(TPSSportDes_Type_BallroomDance) : @"Ballroom Dance",
            @(TPSSportDes_Type_Dance) : @"Dance",
            @(TPSSportDes_Type_Zumba) : @"Zumba",
            @(TPSSportDes_Type_Aerobics) : @"Aerobics",
            @(TPSSportDes_Type_NationalDance) : @"National Dance",
            @(TPSSportDes_Type_Jazz) : @"Jazz",
            @(TPSSportDes_Type_LatinDance) : @"Latin Dance",
            @(TPSSportDes_Type_GroupCallisthenics) : @"Group Callisthenics",
            @(TPSSportDes_Type_KickBoxing) : @"Kick Boxing",
            @(TPSSportDes_Type_Archery) : @"Archery",
            @(TPSSportDes_Type_Darts) : @"Darts",
            @(TPSSportDes_Type_TugOfWar) : @"Tug Of War",
            @(TPSSportDes_Type_HulaHoop) : @"Hula Hoop",
            @(TPSSportDes_Type_FlyAKite) : @"Fly A Kite",
            @(TPSSportDes_Type_Fishing) : @"Fishing",
            @(TPSSportDes_Type_Frisbee) : @"Frisbee",
            @(TPSSportDes_Type_Kabaddi) : @"Kabaddi",
            @(TPSSportDes_Type_BungeeJumping) : @"Bungee Jumping",
            @(TPSSportDes_Type_Handcar) : @"Handcar",
            @(TPSSportDes_Type_HoverBoard) : @"Hover Board",
            @(TPSSportDes_Type_LeisureSports) : @"Leisure Sports",
            @(TPSSportDes_Type_Fencing) : @"Fencing",
            @(TPSSportDes_Type_TrackAndField) : @"Track And Field",
            @(TPSSportDes_Type_Races) : @"Races",
            @(TPSSportDes_Type_Triathlon) : @"Triathlon",
            @(TPSSportDes_Type_Karate) : @"Karate",
            @(TPSSportDes_Type_Boxing) : @"Boxing",
            @(TPSSportDes_Type_Judo) : @"Judo",
            @(TPSSportDes_Type_Wrestling) : @"Wrestling",
            @(TPSSportDes_Type_TaiChi) : @"Tai Chi",
            @(TPSSportDes_Type_MuayThai) : @"Muay Thai",
            @(TPSSportDes_Type_Taekwondo) : @"Taekwondo",
            @(TPSSportDes_Type_MartialArts) : @"Martial Arts",
            @(TPSSportDes_Type_FreeSparring) : @"Free Sparring",
            @(TPSSportDes_Type_Shooting) : @"Shooting",
            @(TPSSportDes_Type_Trampolining) : @"Trampolining",
            @(TPSSportDes_Type_RopeSkipping) : @"Rope Skipping",
            @(TPSSportDes_Type_OutdoorSoccer) : @"Outdoor Soccer",
            @(TPSSportDes_Type_WallBall) : @"Wall Ball",
            @(TPSSportDes_Type_SnowCar) : @"Snow Car",
            @(TPSSportDes_Type_Kickboxing) : @"Kickboxing",
            @(TPSSportDes_Type_RollerSkating) : @"Roller Skating",
            @(TPSSportDes_Type_Skateboard) : @"Skateboard",
            @(TPSSportDes_Type_PoolSwimming) : @"Pool Swimming",
            @(TPSSportDes_Type_OpenWaterSwimming) : @"Open Water Swimming",
        };
    });
    return sportNameMap[@(sportType)];
}

#pragma mark - 其他

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

-(void)showProgress {
    activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    activityIndicator.center = CGPointMake(self.view.bounds.size.width / 2, self.view.bounds.size.height / 2);
    activityIndicator.color  = [UIColor systemBlueColor];
    [self.view addSubview:activityIndicator];
    [activityIndicator startAnimating];
}

-(void)removeProgress {
    [activityIndicator stopAnimating];
    [activityIndicator removeFromSuperview];
}

#pragma mark - 保存按钮点击事件

-(void)onSave {
    if (!hasUnsavedChanges) {
        [self.view makeToast:@"没有需要保存的修改" duration:2.0f position:CSToastPositionTop];
        return;
    }

    NSMutableArray<TPSSportSlotModel *> *updatedSlots = [NSMutableArray new];
    for (SportSlotEditModel *dm in displayList) {
        TPSSportSlotModel *slot = [[TPSSportSlotModel alloc] init];
        slot.slotIndex = dm.slotIndex;
        slot.sportType = dm.sportType;
        [updatedSlots addObject:slot];
    }

    if (updatedSlots.count == 0) {
        NSLog(@"[SportAdd] onSave: 没有槽位数据可保存");
        return;
    }

    [self showProgress];
    [TPSSdk.share.sportDataAbility updateEditableSportSlots:updatedSlots completion:^(BOOL isSuccess, NSError * _Nullable error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self removeProgress];
            OpResultToastTip(self.view, isSuccess);
            if (isSuccess) {
                self->hasUnsavedChanges = NO;
                NSLog(@"[SportAdd] 所有槽位已成功同步到手表");
            } else {
                NSLog(@"[SportAdd] 槽位同步失败: %@", error.localizedDescription);
            }
        });
    }];
}

@end
