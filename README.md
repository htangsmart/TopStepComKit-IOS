安装方法
1、podfile文件中增加以下路径
```
pod 'TopStepComKit', git: 'https://github.com/htangsmart/TopStepComKit-IOS.git'
```
2、初始化sdk，在AppDelegate中执行以下语句
```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
        ...
        [[TPSSDK share] initSdk];
        ...
}
```
接口说明
1、蓝牙连接
1、获取蓝牙状态
```
-(CBManagerState)getCBManagerState
```
调用举例：
```
- (void)checkBlueToothState{
    if ([[FwSdk share].connectorAbility getCBManagerState]==CBManagerStatePoweredOn) {
        [self setState:eTSBlueToothStateOpen];
    }else{
        [self setState:eTSBlueToothStateClose];
    }
}

- (void)setState:(TSBlueToothState)state{
    _state = state;
    if (_state == eTSBlueToothStateClose) {
        self.tipLabe.text  = kJL_TXT("蓝牙未开启");
        self.descLabe.text  = @"";//kJL_TXT("绑定设备后可在APP上更清晰的分析数据");
        self.descLabe.hidden = YES;
        [self.operationButton setTitle:kJL_TXT("开启") forState:UIControlStateNormal];
    }else{
        self.tipLabe.text  = kJL_TXT("绑定设备");
        self.descLabe.text  = kJL_TXT("绑定设备后可在APP上更清晰的分析数据");
        self.descLabe.hidden = NO;
        [self.operationButton setTitle:kJL_TXT("开始搜索") forState:UIControlStateNormal];
    }
    [self layoutViews];
}
```

2、获得连接
```
-(TPSConnnectResult_State)getConnectState
```
调用举例
```
- (IBAction)backBtn:(UIButton *)sender {
    if([[FwSdk share].connectorAbility getConnectState]==FwConnnectResult_State_Connected){
        [self.navigationController popViewControllerAnimated:YES];
    }else{
        UIAlertController *actionSheet = [UIAlertController alertControllerWithTitle:kJL_TXT("提示") message:kJL_TXT("您正在与蓝牙连接，退出该页面会导致连接失败，是否继续？")
                                                                      preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *btnCancel = [UIAlertAction actionWithTitle:kJL_TXT("取消") style:UIAlertActionStyleCancel handler:nil];
        UIAlertAction *btnConfirm = [UIAlertAction actionWithTitle:kJL_TXT("确认") style:UIAlertActionStyleDefault
                                                           handler:^(UIAlertAction * _Nonnull action) {
            if([[FwSdk share].connectorAbility getConnectState]!=FwConnnectResult_State_Connected){//如果在阅读文字的过程中已经绑定成功，则不关闭
                [[FwSdk share].connectorAbility disconnect];
            }
            [self.navigationController popViewControllerAnimated:YES];
        }];
        [btnCancel setValue:kDF_RGBA(152, 152, 152, 1.0) forKey:@"_titleTextColor"];
        [actionSheet addAction:btnCancel];
        [actionSheet addAction:btnConfirm];
        [self presentViewController:actionSheet animated:YES completion:nil];
    }
}
```

3、扫描状态
```
-(RACSubject<TPSScanResult*>*)startScan
```
调用举例：
```
- (void)searchDevice{
    //search
    id<IFwConnectorAbility> connectorSync = [FwWearFactory createSingleInstance:@protocol(IFwConnectorAbility)];
    self.scanRacSubject = [connectorSync startScan];
    [self.scanRacSubject subscribeNext:^(FwScanResult * _Nullable x) {
        if (x.peripheral.name.length >0) {
            NSString *peripheralName = x.peripheral.name;
            NSString *mac = x.mac ? x.mac : @"";
            [self insertTableView:x.peripheral macAddr: mac RSSI:x.RSSI];
        }
    }];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(kSearchTime * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self stopScan];
    });
}

- (void)stopScan{
    [self checkIfHasDevice];
    [[FwSdk share].connectorAbility stopScan];
    if(self.scanRacSubject){[self.scanRacSubject sendCompleted];}
    [JL_Tools post:kUI_JL_BLE_SCAN_CLOSE Object:nil];
}
```

4、停止扫描
```
-(void)stopScan
```
调用举例
```
- (void)stopScan{
    [self checkIfHasDevice];
    [[FwSdk share].connectorAbility stopScan];
    if(self.scanRacSubject){[self.scanRacSubject sendCompleted];}
    [JL_Tools post:kUI_JL_BLE_SCAN_CLOSE Object:nil];
}

- (void)checkIfHasDevice{
    [self setSearchState:eTSBlueToothSearchFinished];
    if (self.deviceArray.count>0) {
//        self.deviceTable.bounces = YES;
        [self.deviceTable beginUpdates];
        self.tableHeaderHeight = 0.001;
        self.emptyCellHeight = 80;
        [self.deviceTable endUpdates];
    }else{
//        self.deviceTable.bounces = NO;
        [self.deviceTable beginUpdates];
        [self.deviceTable reloadSections:[NSIndexSet indexSetWithIndex:0] withRowAnimation:UITableViewRowAnimationNone];
        [self.deviceTable endUpdates];
    }
}

```
5、连接地址
```
-(RACSubject<TPSConnectResult*>*)connectWithMac:(NSString*)mac extraParam:(TPSExtraConnectParam*)extraParam
调用举例：
-(void)setScanDict:(NSDictionary*)dict{
    [JL_Tools delay:1.0 Task:^{
        self.mScanDict = dict;
        self->edrText    = dict[@"MAC"];
        self->nameText   = dict[@"BleName"];
        self->label_2.text= [NSString stringWithFormat:@"%@%@",kJL_TXT("当前配对设备"),self->nameText];
        FwExtraConnectParam* extraParam = [[FwExtraConnectParam alloc] initWithUserId:[HOETool getUserId] gender:[HOETool getGender] age:[HOETool getUserAge] height:[HOETool getHeight] weight:[HOETool getWeight]];
        id<IFwConnectorAbility> connectorSync = [FwWearFactory createSingleInstance:@protocol(IFwConnectorAbility)];
        self->macConnectRacDispose = [[connectorSync connectWithMac:self->edrText extraParam:extraParam] subscribeNext:^(FwConnectResult * _Nullable x) {
            [self handleConnectResult:x];
        }];;
    }];
}

-(void)handleConnectResult:(FwConnectResult*)x{
    NSLog(@"handleConnectResult handleConnectResult is %d",x.state);
    if(x.state == FwConnnectResult_State_Connected){
        self->isWaitingReboot = NO;
        [self showUIConnectOK];
    }else if(x.state == FwConnnectResult_State_Connecting){
        NSLog(@"FwConnnectResult_State_Connecting");
    }else if(x.state == FwConnnectResult_State_Disconnected){
        if(x.errorCode == FwConnnectResult_Error_Code_Low_Battery){
            [self showUIConnectOther:kJL_TXT("温馨提示") info2:kJL_TXT("手表电量不足，无法重新绑定，请充电")];
        }else if(x.errorCode == FwConnnectResult_Error_Code_Wait_Reboot){
            self->isWaitingReboot = YES;
            [self showUIConnectOther:kJL_TXT("温馨提示") info2:kJL_TXT("切换用户需等待手表重启，请稍候，并注意手表上的提示")];
        }else{
            if(!self->isWaitingReboot){//等待手表重启，此时会发生一次断链，但是不要把这个断链当异常来显示
                [self showUIConnectFail];
            }
        }
    }
}

```
6、连接设备
```
-(RACSubject<TPSConnectResult*>*)connectWithCBPeripheral:(CBPeripheral*)peripheral mac:(NSString*)mac extraParam:(TPSExtraConnectParam*)extraParam
```
调用举例
```
-(void)connectDevWithCBPeripheral:(CBPeripheral*)peripheral mac:(NSString*)mac{
    // 手动设置为绑定状态
    [self setConnectState:eTSConnectStateConnecting];
    id<IFwConnectorAbility> connectorSync = [FwWearFactory createSingleInstance:@protocol(IFwConnectorAbility)];
    FwExtraConnectParam* extraParam = [[FwExtraConnectParam alloc] initWithUserId:[HOETool getUserId] gender:[HOETool getGender] age:[HOETool getUserAge] height:[HOETool getHeight] weight:[HOETool getWeight]];
    self.peripheralConnectRacDispose = [[connectorSync connectWithCBPeripheral:peripheral mac:mac extraParam:extraParam] subscribeNext:^(FwConnectResult * _Nullable x) {
        [self handleConnectResult:x];
    }];
}

-(void)handleConnectResult:(FwConnectResult*)x{
    if(x.state == FwConnnectResult_State_Connected){
        self.isWaitingRestart = NO;
        [self setConnectState:eTSConnectStateSuccess];
    }else if(x.state == FwConnnectResult_State_Connecting){
        [self setConnectState:eTSConnectStateConnecting];
    }else if(x.state == FwConnnectResult_State_Disconnected){
        if(x.errorCode == FwConnnectResult_Error_Code_Low_Battery){
            [self setConnectState:eTSConnectStateLowPower];
        }else if(x.errorCode == FwConnnectResult_Error_Code_Wait_Reboot){
            self.isWaitingRestart = YES;
            [self setConnectState:eTSConnectStateWaitReboot];
        }else{
            if(!self.isWaitingRestart){//等待手表重启，此时会发生一次断链，但是不要把这个断链当异常来显示
                [self setConnectState:eTSConnectStateFailed];
            }
        }
    }
}

```
7、通过用户信息自动连接之前的设备
```
-(RACSubject<TPSConnectResult*>*)autoConnectLastPeripheralWithUserInfo:(TPSExtraConnectParam*)extraParam
```
调用举例：

```
-(void)initShareInstance{
    //demo,com.sztopstep.sdkdemo：ohgtmacsmqt4btan1uh05l341urtpanl
    //Oraimo,com.transsion.oraimohealth：q1d0i3ruvqqo2f3p0c1l737bgcfmklj9
//    [[FwSdk share] initSdkWithLincese:@"b3riel7r56r41792ffdlgp3ddv19cifj"];
//    [[FwSdk share] initSdkWithLincese:@"ohgtmacsmqt4btan1uh05l341urtpanl"];
    
    [[FwSdk share] initSdk];

    [SyncDataManager share];
    [[WeatherManager share] start];
    id<IFwConnectorAbility> connectorSync = [FwWearFactory createSingleInstance:@protocol(IFwConnectorAbility)];
    if ([HOETool isUserDeleteWatch]) {
        [connectorSync cancelAutoConnectLastPeripheral];
    }else{
        FwExtraConnectParam* extraParam = [[FwExtraConnectParam alloc] initWithUserId:[HOETool getUserId] gender:[HOETool getGender] age:[HOETool getUserAge] height:[HOETool getHeight] weight:[HOETool getWeight]];
        [connectorSync autoConnectLastPeripheralWithUserInfo:extraParam];
    }
}
```
8、取消自动连接
```
-(void)cancelAutoConnectLastPeripheral
```
调用举例
```
-(void)initShareInstance{
    [[FwSdk share] initSdk];

    [SyncDataManager share];
    [[WeatherManager share] start];
    id<IFwConnectorAbility> connectorSync = [FwWearFactory createSingleInstance:@protocol(IFwConnectorAbility)];
    if ([HOETool isUserDeleteWatch]) {
        [connectorSync cancelAutoConnectLastPeripheral];
    }else{
        FwExtraConnectParam* extraParam = [[FwExtraConnectParam alloc] initWithUserId:[HOETool getUserId] gender:[HOETool getGender] age:[HOETool getUserAge] height:[HOETool getHeight] weight:[HOETool getWeight]];
        [connectorSync autoConnectLastPeripheralWithUserInfo:extraParam];
    }
}
```


9、观察连接结果
```
-(RACSubject<TPSConnectResult*>*)observeConnectResult
```
调用举例：
```
- (void)viewDidLoad {
    [super viewDidLoad];
    isSendToWatch = NO;
    [JLGPSIntensityManager sharedInstance];//调用会申请gps权限
    
    tripType = NavStartEndView_Trip_Type_Bike;
    navSync =  [FwWearFactory createSingleInstance:@protocol(IFwNavAbility)];
    [self configUI];
    [self createMapView];
    [self createSearchToolView2];
    [self createRecommendView];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(applicationBecomeActive) name:UIApplicationDidBecomeActiveNotification object:nil];
    
    navExitRacDispose = [[[FwSdk share].navAbility observeNavExit] subscribeNext:^(id  _Nullable x) {
        [[BMKCycleNavigationManager sharedManager] exitCycleNomalNavi];
        [[BMKWalkNavigationManager sharedManager] exitWalkNomalNavi];
    }];
}
```



16.电子书
1、获取书本集
```
-(void)getBookList:(TPSEleBookListCallback)block
```
调用举例：
```
-(void)getBookListFromDev{
    [ebookSync getBookList:^(NSArray<FwEBookModel *> *bookList) {
        if(bookList==nil || bookList.count==0){
            self.imgNoData.hidden = NO;
            self.lbNoData.hidden = NO;
            self.scrollBookListContainer.hidden = YES;
            self.btnFinish.hidden = YES;
            self->isEditing = NO;
            self.btnAdd.enabled = YES;
        }else{
            self.imgNoData.hidden = YES;
            self.lbNoData.hidden = YES;
            self.scrollBookListContainer.hidden = NO;
            self->dataArray = [bookList mutableCopy];
            [self refreshTableData];
        }
    }];
}
```

2、导入电子书到设备
```
-(void)pushBookToDev:(NSString*)phoneFilePath fileName:(NSString*)fileName block:(onTPSProgressResult)block
```
调用举例：
```
-(void)startTransfer:(NSString*)fileName{
    [self convertToUTF16LE:fileName];
    transferFileName = fileName;
    progress = [[EbookProgressView alloc] initAndLoadNib];
    progress.delegate = self;
    [self.view addSubview:progress];
    [progress mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(0);
        make.trailing.mas_equalTo(0);
        make.bottom.mas_equalTo(0);
        make.top.mas_equalTo(0);
    }];
    [progress showProgress];
    progress.lbBookName.text = fileName;
    NSString *filePath = [JL_Tools findPath:NSDocumentDirectory MiddlePath:@"ebook" File:fileName];
    [ebookSync pushBookToDev:filePath fileName:fileName block:^(FwProgressModel *model) {
        if(model.eventType == FwProgressModel_Event_Type_OnSuccess){
            [DFUITools showText:kJL_TXT("文件传输成功") onView:self.view delay:1.0];
        }else if(model.eventType == FwProgressModel_Event_Type_OnFailed){
            self->progress.lbTipInfo.text = kJL_TXT("文件传输失败");
        }else if(model.eventType == FwProgressModel_Event_Type_OnProcess){
            self->progress.percent = model.percent;
        }else if(model.eventType == FwProgressModel_Event_Type_OnCompleted){
            [self->progress removeFromSuperview];
            [self getBookListFromDev];
        }
    }];
}
```

3、取消导入
```
-(void)cancelPush:(NSString*)fileName
```
调用举例：


4、删除设备上的电子书
```
-(void)delBookOnDev:(NSString*)fileName block:(TPSSendMsgResult)block
```
调用举例：
```
-(void)onDelClick:(UIButton*)btn{
    NSString *message = kJL_TXT("是否删除手表中的电子书?");
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:kJL_TXT("") message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:kJL_TXT("取消") style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
    }];
    
    UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:kJL_TXT("确定") style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self->ebookSync delBookOnDev:self->dataArray[btn.tag].bookName block:^(BOOL isSendOK) {
            [DFUITools showText:kJL_TXT("删除完毕") onView:self.view delay:0.8];
            [self getBookListFromDev];
        }];
    }];
    
    [alert addAction:confirmAction];
    [alert addAction:cancelAction];
    [self presentViewController:alert animated:YES completion:nil];
}
```



17.文件操作
1、获取文件夹和手表文件路径
```
-(void)getDevFileListWithWatchFilePath:(NSString*)watchFilePath block:(TPSFileListCallback)block
```
调用举例：


2.从本地路径导入文件到设备
```
-(void)pushFileToDevWithLocalPath:(NSString*)localPath remotePath:(NSString*)remotePath block:(onTPSProgressResult)block
```
调用举例：
```
- (void)beginPushZipToWatch:(NSString *)zipPath dial:(NSString *)dialName{
    
    __weak typeof(self)weakSelf = self;
    [self.pusToWatchButton beginAnimation];
    [[FwSdk share].fileAbility pushFileToDevWithLocalPath:zipPath remotePath:[TSDialFilePath watchZipPath] block:^(FwProgressModel *model) {
        __strong typeof(weakSelf)strongSelf = weakSelf;
        if (model.eventType == FwProgressModel_Event_Type_OnProcess) {
            [strongSelf updateProcess:model.percent];
        }else if (model.eventType == FwProgressModel_Event_Type_OnSuccess) {
            // save dial name
            [strongSelf sendInstructionsToWatch:dialName];
        }else if (model.eventType == FwProgressModel_Event_Type_OnFailed){
            [strongSelf pushFailed];
        }
    }];
}
```
3、删除文件夹中的文件
```
-(void)delFileWithFolder:(NSString*)watchFolder fileName:(NSString*)fileName block:(TPSSendMsgResult)block
```
调用举例：


4、删除整个文件
```
-(void)delFileWithWholePath:(NSString*)wholePath block:(TPSSendMsgResult)block
```
调用举例：


5、取消导入文件名字
```
-(void)cancelPushWithFileName:(NSString*)fileName
```
调用举例：
```
-(void)onCancelTransfer:(UIView*)sender{
    [progress removeFromSuperview];
    id<IFwFileAbility> tmpFileSync = [FwWearFactory createSingleInstance:@protocol(IFwFileAbility)];
    [tmpFileSync cancelPushWithFileName:transferFileName];
}
```

6、获取设备文件夹与手表文件路径
```
-(void)getDevFileTreeWithWatchFilePath:(NSString*)watchFilePath block:(TPSFileListCallback)block
```
调用举例：


7、在修改之前通知设备
```
-(void)notifyDevAfterUpdate:(TPSFileUpdateModel*)model remoteAppId:(NSString*)remoteAppId
```
调用举例：


8、获取目录大小
```
-(void)getDirSizeInfo:(NSString*)remoteFolder block:(TPSFileSizeCallback)block
```
调用举例：
```
- (void)fetchResidualSpace:(dispatch_group_t)group{
    dispatch_group_enter(group);
    __weak typeof(self)weakSelf = self;
    [self.fileync getDirSizeInfo:@"/data/share/com.realthread.LocalMusic/music/" block:^(float sizeInByte) {
        __strong typeof(weakSelf)strongSelf = weakSelf;
        strongSelf.residualSpace = (sizeInByte/1024/1024);
        dispatch_group_leave(group);
    }];
}
```



18.闹钟
1、获取所有闹钟
```
-(void)getAlarmList:(TPSAlarmListCallback)block
```
调用举例：
```
-(void)initWithData{
    titleHeight.constant = kJL_HeightNavBar+10;
    titleLab.text = kJL_TXT("闹钟");
    alarmSync = [FwWearFactory createSingleInstance:@protocol(IFwAlarmAbility)];
    if(self->alarmTable == nil){
        self->alarmTable = [[UITableView alloc] initWithFrame:CGRectMake(16, kJL_HeightNavBar+20, [DFUITools screen_2_W]-16*2, self->itemArray.count*AlarmClockVC_Table_Height)];
    }
    self->alarmTable.dataSource = self;
    self->alarmTable.delegate = self;
    self->alarmTable.rowHeight = AlarmClockVC_Table_Height;
    self->alarmTable.separatorColor = kDF_RGBA(247.0, 247.0, 247.0, 1.0);
    self->alarmTable.layer.cornerRadius = 15;
    self->alarmTable.tableFooterView = [UIView new];
    self->alarmTable.backgroundColor = [UIColor whiteColor];
    [self->alarmTable registerNib:[UINib nibWithNibName:@"AlarmClockCell" bundle:nil] forCellReuseIdentifier:@"AlarmClockCell"];
    self->syncDateBtn.layer.cornerRadius = 25.0;
    self->syncDateBtn.layer.masksToBounds = YES;
    [self.view addSubview:self->alarmTable];
    
    [alarmSync getAlarmList:^(NSArray<FwAlarmModel *> * _Nullable alarmList) {
        if(!alarmList){
            [DFUITools showText:kJL_TXT("连接失败") onView:self.view delay:1.5];
            return;
        }
        self->itemArray = [alarmList mutableCopy];
        [self->alarmTable reloadData];
        if(self->watchLabel == nil){
            self->watchLabel = [[UILabel alloc] init];
        }
        [self refreshTableFrame];
        self->watchLabel.font = [UIFont fontWithName:@"PingFangSC" size:14];
        self->watchLabel.textColor = kDF_RGBA(114.0, 114.0, 114.0, 1.0);
        self->watchLabel.text = kJL_TXT("设置好闹钟，同步到手表后，手表将会震动提醒您。您最多可以设置5个闹钟。");
        [self.view addSubview:self->watchLabel];
        
        if(self->itemArray.count==0){
            self->watchLabel.hidden = YES;
        }else{
            self->watchLabel.hidden = NO;
        }
    }];
}
```

2、发送所有闹钟
```
-(void)sendAlarmList:(NSArray<TPSAlarmModel*>*)alarmList block:(TPSSendMsgResult)block
```
调用举例：
```
-(void)sendDataToDevice{
    if(isBusy){
        return;
    }
    isBusy = YES;
    id<IFwAlarmAbility> alarmSync = [FwWearFactory createSingleInstance:@protocol(IFwAlarmAbility)];
    [alarmSync sendAlarmList:_alarmEntityList block:^(BOOL isSendOK) {
        self->isBusy = NO;
        if(isSendOK){
            if(self.delegate && [self.delegate respondsToSelector:@selector(didChangeAlarmAction:)]){
                [self.delegate didChangeAlarmAction:self.alarmEntityList];
            }
            [self.navigationController  popViewControllerAnimated:YES];
        }else{
            [DFUITools showText:kJL_TXT("连接失败") onView:self.view delay:1.5];
        }
    }];
}
```

3、观察闹钟变化
```
-(RACSubject*)observeAlarmChange
```
调用举例：
```
- (void)initData {
    self.alarmAbility = [FwWearFactory createSingleInstance:@protocol(IFwAlarmAbility)];
    self.alarmModels = [NSMutableArray new];
    self.cellModels = [NSMutableArray new];
    [self updateAlarmList];
    @weakify(self)
    [[[self.alarmAbility observeAlarmChange] throttle:0.5] subscribeNext:^(id  _Nullable x) {
       
        @strongify(self)
        [self updateAlarmList];
    }];
}

/// 更新闹钟列表
- (void)updateAlarmList {
    [self.alarmAbility getAlarmList:^(NSArray<FwAlarmModel *> * _Nullable alarmList) {
        
        [self.alarmModels removeAllObjects];
        [self.cellModels removeAllObjects];
        [self.alarmModels addObjectsFromArray:alarmList];
        // 生成cellModels
        [self.alarmModels enumerateObjectsUsingBlock:^(FwAlarmModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            
            [self.cellModels addObject:[self getCellModelWithAlarmModel:obj]];
        }];
        self.cellModels = self.cellModels;//手动出发监听
    }];
}
```



19.杂项设置
1、获取所有设置地址
```
-(void)getAllMiscSetting:(TPSMiscSettingCallback)block
```
调用举例：
```
-(void)start{
    miscSettingSync = [FwWearFactory createSingleInstance:@protocol(IFwMiscSettingAbility)];
    [miscSettingSync getAllMiscSetting:^(FwMiscSettingModel *miscSettingModel) {
        self->_hasData = YES;
        self->_target_drink_warn = miscSettingModel.target_drink_warn;
        self->_target_sit_warn = miscSettingModel.target_sit_warn;
        self->_ht_health_enhanced = miscSettingModel.ht_health_enhanced;
        self->_ht_sleep_allDay = miscSettingModel.ht_sleep_allDay;
        self->_system_timing_method = miscSettingModel.system_timing_method;
        self->_weather_temp_unit = miscSettingModel.weather_temp_unit==FwMiscSettingModel_Temperature_Unit_C ? @"C" : @"F";
        self->_sport_sportUnit = miscSettingModel.sport_sportUnit;
        self->_habit_wear_hand = miscSettingModel.habit_wear_hand;
        self->_screen_raise_to_wake = miscSettingModel.screen_raise_to_wake;
        self->_weather_sync_mode = miscSettingModel.weather_sync_mode;
        self->_bloodoxygen_auto_mode = miscSettingModel.bloodoxygen_auto_mode;
        self->_heartrate_auto_mode = miscSettingModel.heartrate_auto_mode;
        self->_heartRateSettingData = [HeartRateSettingData configeWithinfo:miscSettingModel.heartrate_config];
    }];
}
```

2、发送饮水目标的警告
```
-(void)sendTarget_drink_warn:(TPSMiscSettingModel_State)target_drink_warn
```
调用举例：
```
-(void)setTarget_drink_warn:(int)target_drink_warn{
    self->_target_drink_warn = target_drink_warn;
    [miscSettingSync sendTarget_drink_warn:target_drink_warn];
}
```

3、发送站立警告
```
-(void)sendTarget_sit_warn:(TPSMiscSettingModel_State)target_sit_warn
```
调用举例：
```
-(void)setTarget_sit_warn:(int)target_sit_warn{
    self->_target_sit_warn = target_sit_warn;
    [miscSettingSync sendTarget_sit_warn:target_sit_warn];
}
```

4、发送心率健康的高预警
```
-(void)sendHt_health_enhanced:(TPSMiscSettingModel_State)ht_health_enhanced
```
调用举例：
```
-(void)setHt_health_enhanced:(int)ht_health_enhanced{
    self->_ht_health_enhanced = ht_health_enhanced;
    [miscSettingSync sendHt_health_enhanced:ht_health_enhanced];
}
```

5、发送所有天的睡眠中的心率
```
-(void)sendHt_sleep_allDay:(TPSMiscSettingModel_State)ht_sleep_allDay
```
调用举例：
```
-(void)setHt_sleep_allDay:(int)ht_sleep_allDay{
    self->_ht_sleep_allDay = ht_sleep_allDay;
    [miscSettingSync sendHt_sleep_allDay:ht_sleep_allDay];
}
```

6、发送系统的方法时机
```
-(void)sendSystem_timing_method:(TPSMiscSettingModel_Time_Format)system_timing_method
```
调用举例：
```
-(void)setSystem_timing_method:(int)system_timing_method{
    self->_system_timing_method = system_timing_method;
    [miscSettingSync sendSystem_timing_method:system_timing_method];
}
```

7、发送天气的临时单位
```
-(void)sendWeather_temp_unit:(TPSMiscSettingModel_Temperature_Unit)weather_temp_unit
```
调用举例：
```
-(void)setWeather_temp_unit:(NSString*)weather_temp_unit{
    self->_weather_temp_unit = weather_temp_unit;
    FwMiscSettingModel_Temperature_Unit unit = [weather_temp_unit isEqualToString:@"C"] ? FwMiscSettingModel_Temperature_Unit_C : FwMiscSettingModel_Temperature_Unit_F;
    [miscSettingSync sendWeather_temp_unit:(unit)];
}
```

8、发送运动的单位
```
-(void)sendSport_sportUnit:(TPSMiscSettingModel_System_Unit)sport_sportUnit
```
调用举例：
```
-(void)setSport_sportUnit:(int)sport_sportUnit{
    self->_sport_sportUnit = sport_sportUnit;
    [miscSettingSync sendSport_sportUnit:sport_sportUnit];
}
```

9、发送佩戴的习惯
```
-(void)sendHabit_wear_hand:(TPSMiscSettingModel_Wear_Hand)habit_wear_hand
```
调用举例：
```
-(void)setHabit_wear_hand:(int)habit_wear_hand{
    self->_habit_wear_hand = habit_wear_hand;
    [miscSettingSync sendHabit_wear_hand:habit_wear_hand];
}
```

10、发送屏幕提高之后
```
-(void)sendScreen_raise_to_wake:(TPSMiscSettingModel_State)screen_raise_to_wake
```
调用举例：
```
-(void)setScreen_raise_to_wake:(int)screen_raise_to_wake{
    self->_screen_raise_to_wake = screen_raise_to_wake;
    [miscSettingSync sendScreen_raise_to_wake:screen_raise_to_wake];
}
```

11、发送天气同步的模式
```
-(void)sendWeather_sync_mode:(TPSMiscSettingModel_State)weather_sync_mode
```
调用举例：
```
-(void)setWeather_sync_mode:(int)weather_sync_mode{
    self->_weather_sync_mode = weather_sync_mode;
    [miscSettingSync sendWeather_sync_mode:weather_sync_mode];
}
```

12自动发送血氧模式
```
-(void)sendBloodoxygen_auto_mode:(TPSMiscSettingModel_State)bloodoxygen_auto_mode
```
调用举例：
```
-(void)setBloodoxygen_auto_mode:(int)bloodoxygen_auto_mode{
    self->_bloodoxygen_auto_mode = bloodoxygen_auto_mode;
    [miscSettingSync sendBloodoxygen_auto_mode:bloodoxygen_auto_mode];
}
```

13、自动发送心率模式
```
(void)sendHeartrate_auto_mode:(TPSMiscSettingModel_State)heartrate_auto_mode
```
调用举例：
```
-(void)setHeartrate_auto_mode:(int)heartrate_auto_mode{
    self->_heartrate_auto_mode = heartrate_auto_mode;
    [miscSettingSync sendHeartrate_auto_mode:heartrate_auto_mode];
}
```

14、发送用户名字
```
-(void)sendUserNickName:(NSString*)nickName
```
调用举例：
```
-(void)syncUnitAndUserProfile{
    id<IFwMiscSettingAbility> miscSettingSync = [FwWearFactory createSingleInstance:@protocol(IFwMiscSettingAbility)];
    [miscSettingSync sendUserNickName:[HOETool getNickname]];
    if([[HOETool getTemperatureUnit] isEqualToString:@"C"]){
        [miscSettingSync sendWeather_temp_unit:(FwMiscSettingModel_Temperature_Unit_C)];
    }else{
        [miscSettingSync sendWeather_temp_unit:(FwMiscSettingModel_Temperature_Unit_F)];
    }
    if([HOETool isMetricSystem]){
        [miscSettingSync sendSport_sportUnit:(MiscSettingModel_TSFW_Sport_Unit_Metric_System)];
    }else{
        [miscSettingSync sendSport_sportUnit:(MiscSettingModel_TSFW_Sport_Unit_British_System)];
    }
    
}
```

15、发送心率警报
```
-(void)sendHt_sos:(TPSMiscSettingModel_State)ht_sos
```
调用举例：


16、发送心率值
```
- (void)sendHeartRateValue:(NSDictionary *)value complete:(void(^)(BOOL isSendOK))complete
```
调用举例：
```
- (void)setHeartRateSettingData:(HeartRateSettingData *)heartRateSettingData complete:(void(^)(BOOL isSendOK))complete{
    self->_heartRateSettingData = heartRateSettingData;
    [miscSettingSync sendHeartRateValue:[self->_heartRateSettingData heartRateDict]  complete:^(BOOL isSendOK) {
        complete(isSendOK);
    }];

}
```

17、发送设备的数据
```
-(void)sendDataToDevice:(NSDictionary*)dic complete:(void(^)(BOOL isSendOK))complete
```
调用举例：
```
-(void)sendDataToDevice{
    /*改成自定义协议后不用此段
    NSMutableArray <JLwSettingModel *>* models = [NSMutableArray new];
    
    WatchTimer *startTimer = [[WatchTimer alloc] initWith:startHour Min:startMin];
    WatchTimer *endTimer = [[WatchTimer alloc] initWith:endHour Min:endMin];

    JLSedentaryRmdModel *model1 = [[JLSedentaryRmdModel alloc] initWithModel:WatchRemind_BrightScreen Status:switch1.on DoNotDisturb:switch2.on Begin:startTimer End:endTimer];
    [models addObject:model1];
    
    JLWearable *w = [JLWearable sharedInstance];
    [w w_SettingDeviceFuncWith:models withEntity:kJL_BLE_EntityM result:^(BOOL succeed) {
    }];*/
    int statusCode = switch1.on ? 1 : 0;
    int noonNotDisturb = switch2.on ? 1 : 0;
    [HOETool setJiuzuoRemindData:statusCode startHour:startHour startMin:startMin endHour:endHour endMin:endMin noonNotDisturb:noonNotDisturb];
    [[HOECmdCustomManager shareInstance] sendJiuzuoRemind:statusCode startHour:startHour startMin:startMin endHour:endHour endMin:endMin noonNotDisturb:noonNotDisturb];
}
```



20.OTA
1、修改本地路径
```
-(void)otaUpdateWithLocalPath:(NSString*)localPath block:(onTPSProgressResult)block
```
调用举例：
```
-(void)pushOtaPackage{
    NSString *filePath = [JL_Tools findPath:NSLibraryDirectory MiddlePath:@"webLoader" File:fileName];
    if(fileName==nil || filePath == nil){
        [DFUITools showText:@"请先上传文件" onView:self.view delay:2.0];
        return;
    }
    NSLog(@"pushOtaPackage filePath %@",filePath);
    id<IFwOTAAbility> otaSync = [FwWearFactory createSingleInstance:@protocol(IFwOTAAbility)];
    [otaSync otaUpdateWithLocalPath:filePath block:^(FwProgressModel *model) {
        if(model.eventType == FwProgressModel_Event_Type_OnSuccess){
            [self->checkOrUpdateBtn setEnabled:NO];
            [self->checkOrUpdateBtn setTitle:kJL_TXT("传输完毕,请等待手表自动重启") forState:UIControlStateNormal];
            self->tipInfoLabel.text = kJL_TXT("传输完毕,请等待手表自动重启");
            NSLog(@"TSOtaUpdateVC 文件传输成功!");
        }else if (model.eventType == FwProgressModel_Event_Type_OnFailed){
            self->isBusy = NO;
            [DFUITools showText:kJL_TXT("设备响应超时") onView:self.view delay:1.5];
            NSLog(@"TSOtaUpdateVC 文件传输失败!");
        }else if (model.eventType == FwProgressModel_Event_Type_OnProcess){
            self->progressView.percent = model.percent;
            NSLog(@"TSOtaUpdateVC pushOtaPackage trans,process:%.2f,total", model.percent);
        }
    }];
}
```



21.音乐
1、获取音乐集
```
-(void)getMusicListWithblock:(TPSMusicListCallback)block
```
调用举例：
```
-(void)getDevMusicList{
    [musicSync getMusicListWithblock:^(NSArray<FwMusicModel *> *musicList) {
        if(musicList){
            self->entities = [NSMutableArray new];
            for(int i=0;i<musicList.count;i++){
                [self->entities addObject:@{@"fileName":musicList[i].fileName}];
            }
            [self->mindListView setMusicList:self->entities];
            self->musicCountInfo.secondTitle = [NSString stringWithFormat:@"%@%lu%@",kJL_TXT("已有"),self->entities.count,kJL_TXT("首")];
        }else{
            [DFUITools showText:kJL_TXT("连接失败") onView:self.view delay:2.0];
        }
    }];
}
```

2、从手机文件路径导入音乐
```
-(void)pushMusicToDevWithPhoneFilePath:(NSString*)phoneFilePath remoteFileName:(NSString*)remoteFileName block:(onTPSProgressResult)block
```
调用举例：
```
- (void)uploadSong:(TSMusicModel *)song{
    __weak typeof(self)weakSelf = self;
    [self.musicSync pushMusicToDevWithPhoneFilePath:[self filePathWithName:song.musicName] remoteFileName:song.musicName block:^(FwProgressModel *model) {
        __strong typeof(weakSelf)strongSelf = weakSelf;
        if(model.eventType == FwProgressModel_Event_Type_OnSuccess){
            NSLog(@"文件传输成功!");
            song.uploadResult = eTSMusicUploadResultSuccess;
            if (strongSelf.uploadSuccessBlock) {strongSelf.uploadSuccessBlock(song);}
        }else if(model.eventType == FwProgressModel_Event_Type_OnFailed){
            NSLog(@"文件传输失败!");
            song.uploadResult = eTSMusicUploadResultFailed;
        }else if(model.eventType == FwProgressModel_Event_Type_OnProcess){
            NSLog(@"file trans,process:%.2f,total", model.percent);
            if (strongSelf.uploadProgressBlock) {strongSelf.uploadProgressBlock(model.percent);}
        }else if(model.eventType == FwProgressModel_Event_Type_OnCompleted ){
            //eTSMusicUploadStateCancled 主动取消，则不触发completeBlock
            if (strongSelf.uploadState == eTSMusicUploadStateCancled) {
                // 删除当前文件
            }else{
                strongSelf.uploadIndex++;
                if (strongSelf.uploadIndex>=strongSelf.needUploadArray.count) {
                    [strongSelf uploadFinished];
                }else{
                    [strongSelf uploadNextSong];
                }
            }
        }
    }];
}
```

3、通过文件名删除音乐
```
-(void)delMusicWithFileName:(NSString*)fileName block:(TPSSendMsgResult)block
```
调用举例：
```
-(void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(nonnull NSIndexPath *)indexPath{
    if (editingStyle == UITableViewCellEditingStyleDelete){
        deleteIndex = indexPath.row;
        [musicSync delMusicWithFileName:dataArray[indexPath.row][@"fileName"] block:^(BOOL isSendOK) {
            if(isSendOK){
                [self->dataArray removeObjectAtIndex:self->deleteIndex];
                [self->_listTable reloadData];
                if ([self.delegate respondsToSelector:@selector(deleteOneMucis)]) {
                    [self.delegate deleteOneMucis];
                }
            }else{
                [self->_listTable reloadData];
                [DFUITools showText:kJL_TXT("连接失败") onView:self delay:2.0];
            }
        }];
     }
}
```

4、取消上传文件夹导入音乐中的操作
```
-(void)cancelPushMusicWithFileName:(NSString*)fileName
```
调用举例：
```
- (void)stopUploading{
    if (_uploadState == eTSMusicUploadStateUploading &&
        _uploadingFileName && _uploadingFileName.length>0) {
        _uploadState = eTSMusicUploadStateCancled;
        [self.musicSync cancelPushMusicWithFileName:_uploadingFileName];
        _uploadingFileName = nil;
        _uploadIndex = 0;
        if (self.uploadCancledBlock) {self.uploadCancledBlock([self needUploadArray]);}
    }
}
```



22.运动目标
1、获取运动目标
```
-(void)getSportTargets:(TPSSportTargetCallback)block
```
调用举例：
```
-(void)syncSportTargets{
    id<IFwSportTargetAbility> sportTargetSync = [FwWearFactory createSingleInstance:@protocol(IFwSportTargetAbility)];
    [sportTargetSync getSportTargets:^(FwSportTargetModel *sportTargetModel) {
        if(sportTargetModel.modifyTime > [HOETool getTargetModifyTime]){
            [HOETool setCaloriesGoal:sportTargetModel.calorie];
            [HOETool setDistanceGoal:sportTargetModel.distance];
            [HOETool setTargetModifyTime:sportTargetModel.modifyTime];
            [HOETool setActivityDurationGoal:sportTargetModel.stand_time];
            [HOETool setStepGoal:sportTargetModel.steps];
            [HOETool setSportTimeGoal:sportTargetModel.sport_time];
            [HOETool setActivityCountGoal:sportTargetModel.sport_num];
        }else{
            FwSportTargetModel* model = [[FwSportTargetModel alloc] init];
            model.calorie = ((int)[HOETool getCaloriesGoal]);
            model.distance = ([HOETool getDistanceGoal]);
            model.stand_time = ([HOETool getActivityDurationGoal]);
            model.steps = [HOETool getStepGoal];
            model.sport_time = [HOETool getSportTimeGoal];
            model.sport_num = [HOETool getActivityCountGoal];
            model.modifyTime = [HOETool getTargetModifyTime];
            [sportTargetSync sendSportTargets:model block:^(BOOL isSendOK) {
                    
            }];
        }
    }];
}

```
2、发送运动目标
```
-(void)sendSportTargets:(TPSSportTargetModel*)sportTargetModel block:(TPSSendMsgResult)block
```
调用举例：
```
-(void)sendDataToDev{
    id<IFwSportTargetAbility> sportTargetSync = [FwWearFactory createSingleInstance:@protocol(IFwSportTargetAbility)];
    FwSportTargetModel* model = [[FwSportTargetModel alloc] init];
    model.calorie = ((int)[HOETool getCaloriesGoal]);
    model.distance = ([HOETool getDistanceGoal]);
    model.stand_time = ([HOETool getActivityDurationGoal]);
    model.steps = [HOETool getStepGoal];
    model.sport_time = [HOETool getSportTimeGoal];
    model.sport_num = [HOETool getActivityCountGoal];
    model.modifyTime = [HOETool getTargetModifyTime];
    [sportTargetSync sendSportTargets:model block:^(BOOL isSendOK) {
            
    }];
}
```



23.天气
1、发送天气
```
-(void)sendWeather:(TPSWeatherModel*)weatherModel block:(TPSSendMsgResult)block
```
调用举例：
```
-(void)sendWeatherToDev2{
    NSLog(@"开始给手表发天气");
    NSMutableArray<FwFutureDayWeatherModel*>* preDays = [NSMutableArray new];
    int firstDayMaxTemp;
    int firstDayMinTemp;
    
    for(int i=0;i<next7DayArr.count;i++){
        NSDate* d = [NSDate dateWtihString:[NSString stringWithFormat:@"%@ 00:00:00",next7DayArr[i][@"time"]]];
        FwFutureDayWeatherModel* futureDay = [[FwFutureDayWeatherModel alloc] initWithTimestamp:[d timeIntervalSince1970] describe:[self getDesTypeWithCode:[next7DayArr[i][@"code"] intValue]] minTemperature:[next7DayArr[i][@"tempMin"] intValue] maxTemperature:[next7DayArr[i][@"tempMax"] intValue]];
        [preDays addObject:futureDay];
        if(i == 0){
            firstDayMinTemp = [next7DayArr[i][@"tempMin"] intValue];
            firstDayMaxTemp = [next7DayArr[i][@"tempMax"] intValue];
        }
    }
    
    NSMutableArray<FwFutureHourWeatherModel*>* hours = [NSMutableArray new];
    for (NSDictionary *hourInfo in future_hours) {
        NSString *dateString = [NSDate dateStringFormateUTCDate:hourInfo[@"time"]];
        NSDate* date = [NSDate dateWtihString:dateString];
        NSTimeInterval stamp = [date timeIntervalSince1970];
        FwFutureHourWeatherModel* hourWeather = [[FwFutureHourWeatherModel alloc] initWithTimestamp:stamp describe:[self getDesTypeWithCode:[hourInfo[@"code"] intValue]] temperature:[hourInfo[@"temp"] intValue]];
        [hours addObject:hourWeather];
    }
    
    FwTodayWeatherModel* todayWeather = [[FwTodayWeatherModel alloc] initWithCurTemperature:[currentDic[@"temp"] intValue] minTemperature:firstDayMinTemp maxTemperature:firstDayMaxTemp airpressure:airpressure wind:wind windAngle:wind_angle windSpeed:wind_speed humidity:humidity futureHourList:hours];
    
    FwWeatherModel* weatherModel = [[FwWeatherModel alloc] initWithCity:cityName temperatureUnit:(FwMiscSettingModel_Temperature_Unit_C) updateTime:currentTime todayWeather:todayWeather futureDayWeather:preDays];
    
    [weatherSync sendWeather:weatherModel block:^(BOOL isSendOK) {
        if(isSendOK){
            NSLog(@"传输天气连接成功");
        }else{
            NSLog(@"传输天气连接失败");
        }
    }];
}
```



24.表盘
1、通过本地路径导入表盘
```
-(void)pushDialWithLocalPath:(NSString*)localPath dialId:(NSString*)dialId block:(TPSDialProgressCallback)block
```
调用举例：
```
-(void)pushFile{
    NSString *localPath = [JL_Tools listPath:NSLibraryDirectory MiddlePath:kTS_WATCH_FACE File:self->dial_watch_id];
    [dialSync pushDialWithLocalPath:localPath dialId:self->dial_watch_id block:^(FwDialProgressModel *model) {
        if(model.eventType == FwDialProgressModel_Event_Type_OnProcess){
            self->barProgress.percent = model.percent;
        }else if(model.eventType == FwDialProgressModel_Event_Type_OnSuccess){
            NSLog(@"pushDialWithLocalPath transfer %@",@"onSuccess");
        }else if(model.eventType == FwDialProgressModel_Event_Type_OnFailed){
            NSLog(@"pushDialWithLocalPath push or install %@",@"onFailed");
            self->titleLabel.text = kJL_TXT("表盘传输失败");
            self->isLoading = NO;
            [self dismissAfterDelay:1];
        }else if(model.eventType == FwDialProgressModel_Event_Type_OnInstalling){
            NSLog(@"pushDialWithLocalPath %@",@"onInstalling");
        }else if(model.eventType == FwDialProgressModel_Event_Type_OnCompleted){
            NSLog(@"pushDialWithLocalPath %@",@"onInstallSuccess");
            self->isLoading = NO;
            self->titleLabel.text = kJL_TXT("表盘安装成功");
            [self dismissAfterDelay:1];
        }
        
    }];
}

- (void)dismissAfterDelay:(CGFloat)delay{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        self.hidden = YES;
    });
}
```

2、获取所有表盘信息
```
-(void)getAllDialInfo:(TPSGetAllDialCallback)block
```
调用举例：
```
-(void)onClickEnter{
    [dialSync getAllDialInfo:^(NSArray<FwDialModel *> *modelList) {
        if(modelList){
            BOOL hasInstall = NO;
            for(int i=0;i<modelList.count;i++){
                if([modelList[i].dialId isEqualToString:self->dial_watch_id]){
                    hasInstall = YES;
                    break;
                }
            }
            if(hasInstall){
                [self changeDial];
            }else{
                [self startLoad];
            }
        }else{
            [DFUITools showText:kJL_TXT("连接失败") onView:self delay:1.5];
        }
    }];
}

-(void)changeDial{
    [dialSync changeDialWithDialId:self->dial_watch_id block:^(BOOL isSendOK) {
        if(isSendOK){
            self->titleLabel.text = kJL_TXT("当前表盘");
            [DFUITools showText:kJL_TXT("切换成功") onView:self delay:1.5];
        }else{
            [DFUITools showText:kJL_TXT("连接失败") onView:self delay:1.5];
        }
    }];
}

-(void)startLoad{
    [TSWatchHttp requestWatchDetailWith:[HOETool getProjectId] dialId:dial_sql_id Result:^(NSDictionary *info) {
        if ([HOETool checkIsInfoExist:info]) {
            self->binFileUrl = info[@"data"][@"bin_file"];
            [JL_Tools mainTask:^{
                NSString *updatePath = [JL_Tools listPath:NSLibraryDirectory MiddlePath:kTS_WATCH_FACE File:self->dial_watch_id];
                [JL_Tools removePath:updatePath];
                [[User_Http shareInstance] downloadUrl:self->binFileUrl Path:updatePath Result:^(float progress, JLHTTP_Result result) {
                    [JL_Tools mainTask:^{
                        self->titleLabel.text = kJL_TXT("下载中...");
                        if (result == JLHTTP_ResultDownload) {
                            NSLog(@"dial download progress %f", progress);
                            self->barProgress.percent = progress;
                        }
                        if (result == JLHTTP_ResultSuccess) {
                            self->titleLabel.text = kJL_TXT("表盘推送中...");
                            self->barProgress.percent = 0.1;//刷新一下进度条，由于建立请求的时候等待时间比较长，给个假进度
                            [self pushFile];
                        }
                        if (result == JLHTTP_ResultFail) {
                            self->isLoading = NO;
                            [DFUITools showText:kJL_TXT("下载失败") onView:self delay:2.0];
                            NSLog(@"dial download fail");
                        }
                    }];
                }];
            }];
        }else{
            NSLog(@"Err: requestWatchDetailWith Watch info null 0.");
        }
    }];
}
```

3、通关表盘ID改变表盘
```
-(void)changeDialWithDialId:(NSString*)dialId block:(TPSSendMsgResult)block
```
调用举例：
```
-(void)changeDial{
    [dialSync changeDialWithDialId:self->dial_watch_id block:^(BOOL isSendOK) {
        if(isSendOK){
            self->titleLabel.text = kJL_TXT("当前表盘");
            [DFUITools showText:kJL_TXT("切换成功") onView:self delay:1.5];
        }else{
            [DFUITools showText:kJL_TXT("连接失败") onView:self delay:1.5];
        }
    }];
}

```
4、获取当前的表盘
```
-(void)getCurrentDial:(TPSDialGetCurDialCallback)block
```
调用举例：
```
- (void)requireValue{
    
    [self.dialCreationView requestValues];

    self.watchOperationView = [[WatchOperateView alloc] initWithFrame:CGRectMake(0, 0, [DFUITools screen_2_W], [DFUITools screen_2_H])];
    [self.view addSubview:self.watchOperationView];
    self.watchOperationView.hidden = YES;
    
    [dialSync getCurrentDial:^(FwDialModel *model) {
           //原意图似乎要在这里把当前表盘高亮显示出来，目前没处理
    }];
}
```

5、通过名字删除远程的表盘
```
-(RACSubject *)deleteRemoteWatchDialWithName:(NSString *)dialName block:(TPSSendMsgResult)block
```
调用举例：
```
- (void)deleteRemoteWatchDial{
    // delete watch dial
    [[[FwSdk share].dialAbility deleteRemoteWatchDialWithName:_dialItemModel.dialName block:^(BOOL isSendOK) {
        if (!isSendOK) {
            [DFUITools showText:kJL_TXT("删除失败，请重试") onView:self.view delay:2.0f];
        }
    }] subscribeNext:^(id  _Nullable x) {
        NSDictionary *jsonMsg = (NSDictionary *)x;
        if (![TSChecker isEmptyDictonary:jsonMsg]) {
            NSString *values = [jsonMsg objectForKey:@"values"];
            if ([values isEqualToString:@"successMessage"]) {
                NSLog(@"delete file success");
                [self deleteLocalDial];
            }else{
                NSLog(@"delete file failed");
                [DFUITools removeHUD];
                [DFUITools showText:kJL_TXT("删除失败，请重试") onView:self.view delay:2.0f];
            }
        }
    }];
}

- (void)deleteLocalDial{
    if ([TSDialFileOperation deleteDial:_dialItemModel.dialName]) {
        [DFUITools removeHUD];
        [DFUITools showText:kJL_TXT("删除成功") onView:self.view delay:2.0f];
        // dismiss
        __weak typeof(self)weakSelf = self;
        [self dismissAfterDelay:kAnimationTime complete:^{
            __strong typeof(weakSelf)strongSelf = weakSelf;
            // post notification
            [strongSelf postNotification];
        }];
    }else{
        [DFUITools removeHUD];
        // 删除失败
        [DFUITools showText:kJL_TXT("删除失败，请重试") onView:self.view delay:2.0f];
    }
}
```



25.消息通知设置
1、获取所有通知并启用
```
-(void)getNotificationEnableList:(TPSNotificationEnableListCallback)block
```
调用举例：
```
-(void)initUI{
    notificationDic = [NSMutableDictionary new];
    notificationSync = [FwWearFactory createSingleInstance:@protocol(IFwNotificationEnableAbility)];
    self.view.backgroundColor = kDF_RGBA(248, 250, 252, 1.0);
    
    float sW = [DFUITools screen_2_W];
    float sH = [DFUITools screen_2_H];

    
    headView = [[UIView alloc] init];
    headView.backgroundColor = kDF_RGBA(255, 255, 255, 1.0);
    headView.frame = CGRectMake(0, 0, sW, kJL_HeightStatusBar+44);
    [self.view addSubview:headView];
    
    exitBtn = [[UIButton alloc] init];
    exitBtn.frame  = CGRectMake(4, kJL_HeightStatusBar, 44, 44);
    [exitBtn setImage:[UIImage imageNamed:@"icon_return_nol"] forState:UIControlStateNormal];
    [exitBtn addTarget:self action:@selector(onClickBack) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:exitBtn];
    
    titleName = [[UILabel alloc] init];//System Heavy 18.0
    titleName.text = kJL_TXT("消息提醒");
    titleName.textAlignment = NSTextAlignmentCenter;
    titleName.bounds = CGRectMake(0, 0, 200, 20);
    titleName.font = [UIFont systemFontOfSize:18];
    titleName.center = CGPointMake(sW/2.0, kJL_HeightStatusBar+20);
    [self.view addSubview:titleName];
    
   
    NSArray* allNameArray =  @[
        @{@"icon":@"device_msg_all",@"msg_title":kJL_TXT("消息一键开启"),@"tool_id":@"all",@"visible":@(1)},
        @{@"icon":@"device_msg_phone",@"msg_title":kJL_TXT("来电提醒"),@"tool_id":@"telephony",@"visible":@(1)},
        @{@"icon":@"device_msg_msg",@"msg_title":kJL_TXT("短信"),@"tool_id":@"sms",@"visible":@(1)},
        @{@"icon":@"device_msg_email",@"msg_title":kJL_TXT("邮件"),@"tool_id":@"mail",@"visible":@(1)},
        @{@"icon":@"device_msg_wx",@"msg_title":kJL_TXT("微信"),@"tool_id":@"wechat",@"visible":@(1)},
        @{@"icon":@"device_msg_qq",@"msg_title":kJL_TXT("QQ"),@"tool_id":@"qq",@"visible":@(1)},
        @{@"icon":@"device_msg_fb",@"msg_title":kJL_TXT("Facebook"),@"tool_id":@"facebook",@"visible":@(1)},
        @{@"icon":@"device_msg_tw",@"msg_title":kJL_TXT("X"),@"tool_id":@"twitter",@"visible":@(1)},
        @{@"icon":@"device_msg_whatsapp",@"msg_title":kJL_TXT("WhatsApp"),@"tool_id":@"whatsapp",@"visible":@(1)},
        @{@"icon":@"device_msg_linkedin",@"msg_title":kJL_TXT("LinkedIn"),@"tool_id":@"linkedin",@"visible":@(1)},
        @{@"icon":@"device_msg_instagram",@"msg_title":kJL_TXT("Instagram"),@"tool_id":@"instagram",@"visible":@(1)},
        @{@"icon":@"device_msg_messenger",@"msg_title":kJL_TXT("Messenger"),@"tool_id":@"facebookmessenger",@"visible":@(1)},
        @{@"icon":@"device_msg_snapchat",@"msg_title":kJL_TXT("Snapchat"),@"tool_id":@"snapchat",@"visible":@(1)},
        @{@"icon":@"device_msg_line",@"msg_title":kJL_TXT("Line"),@"tool_id":@"line",@"visible":@(1)},
        @{@"icon":@"device_msg_kaokaotalk",@"msg_title":kJL_TXT("Kaokao Talk"),@"tool_id":@"kakaotalk",@"visible":@(1)},
        @{@"icon":@"device_msg_instaviber",@"msg_title":kJL_TXT("Viber"),@"tool_id":@"viber",@"visible":@(1)},
        @{@"icon":@"device_msg_skype",@"msg_title":kJL_TXT("Skype"),@"tool_id":@"skype",@"visible":@(1)},
        @{@"icon":@"device_msg_telegram",@"msg_title":kJL_TXT("Telegram"),@"tool_id":@"telegram",@"visible":@(1)},
        @{@"icon":@"device_msg_pinterest",@"msg_title":kJL_TXT("Pinterest"),@"tool_id":@"pinterest",@"visible":@(1)},
        @{@"icon":@"device_msg_youtube",@"msg_title":kJL_TXT("Youtube"),@"tool_id":@"youtube",@"visible":@(1)},
        @{@"icon":@"device_msg_applemusic",@"msg_title":kJL_TXT("Applemusic"),@"tool_id":@"applemusic",@"visible":@(1)},
        @{@"icon":@"device_msg_zoom",@"msg_title":kJL_TXT("Zoom"),@"tool_id":@"zoom",@"visible":@(1)},
        @{@"icon":@"device_msg_tiktok",@"msg_title":kJL_TXT("Tiktok"),@"tool_id":@"tiktok",@"visible":@(1)},
        @{@"icon":@"device_msg_hike",@"msg_title":kJL_TXT("Hike"),@"tool_id":@"hike",@"visible":@(0)},
        @{@"icon":@"device_msg_default",@"msg_title":kJL_TXT("更多提醒"),@"tool_id":@"default",@"visible":@(1)},
    ];
    nameArray = [NSMutableArray new];
    invisibleArr = [NSMutableArray new];
    for(int i=0;i<allNameArray.count;i++){
        if([allNameArray[i][@"visible"] intValue] == 1){
            [nameArray addObject:allNameArray[i]];
        }else{
            [invisibleArr addObject:allNameArray[i]];
        }
    }
        
    self->mTableView = [[UITableView alloc] initWithFrame:CGRectMake(16, headView.frame.size.height+12, sW-16*2, floor((sH-headView.frame.size.height-12-25)/54.0)*54)];
    self->mTableView.rowHeight = 54.0;
    self->mTableView.delegate = self;
    self->mTableView.dataSource =self;
    self->mTableView.scrollEnabled = YES;
    mTableView.layer.cornerRadius=15.0f;
//    mTableView.layer.masksToBounds=YES;
    [self->mTableView setSeparatorColor:[UIColor colorWithRed:238/255.0 green:238/255.0 blue:238/255.0 alpha:1.0]];
    [self->mTableView registerNib:[UINib nibWithNibName:@"MsgEnableCell" bundle:nil] forCellReuseIdentifier:@"MsgEnableCell"];
    [self.view addSubview:self->mTableView];
    [self->mTableView reloadData];
    
    [notificationSync getNotificationEnableList:^(NSMutableArray<FwNotificationEnableModel *> *list) {
        self->notificationDic = [NSMutableDictionary new];
        for(int i=0;i<list.count;i++){
            self->notificationDic[list[i].name] = list[i].enable ? @(1) : @(0);
        }
        [self->mTableView reloadData];
    }];
}
```

2、发送所有通知并启用
```
-(void)sendNotificationEnableList:(NSArray<TPSNotificationEnableModel*>*)list block:(TPSSendMsgResult)block
```
调用举例：
```
-(void)onSwitchToggle:(int)index from:(UISwitch*)from{
    int open = from.isOn ? 1 : 0;
    
    NSLog(@"index is %d",index);
    
    if(index == 0){//点击到所有一键开关
        [notificationDic enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
            notificationDic[key] = @(open);
        }];
    }else{
        NSString* msgName = nameArray[index][@"tool_id"];
        if([msgName isEqualToString:@"default"]){//点到更多消息按钮
            notificationDic[@"default"] = @(open);
            for(int i=0;i<invisibleArr.count;i++){//不可见条目暗中归入default里
                NSString* toolId = invisibleArr[i][@"tool_id"];
                notificationDic[toolId] = @(open);
            }
        }else{
            notificationDic[msgName] = @(open);
        }
    }
    
    
    NSMutableArray<FwNotificationEnableModel*>* resultList = [NSMutableArray new];
    [notificationDic enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        FwNotificationEnableModel* model = [[FwNotificationEnableModel alloc] init];
        model.name = key;
        model.enable = (([obj intValue])==1);
        model.type = [notificationSync getTypeByName:key];
        [resultList addObject:model];
    }];
    
    [notificationSync sendNotificationEnableList:resultList block:^(BOOL isSendOK) {
        if(!isSendOK){
            [DFUITools showText:kJL_TXT("连接失败") onView:self.view delay:1.5];
        }
    }];
    [mTableView reloadData];
}
```

3、通过名字获取类型
```
-(TPSNotification_Type)getTypeByName:(NSString*)name
```
调用举例：




26.联系人
1、获取紧急联系人
```
-(void)getEmergencyContact:(TPSContactListCallback)block
```
调用举例：


2、发送紧急联系人
```
-(void)sendEmergencyContact:(TPSContactModel*)contactModel
```
调用举例：
```
-(void)sendData{

    NSMutableArray<FwContactModel*>* list = [NSMutableArray new];
    for(int i=0;i<emergencyArr.count;i++){
        NSString* phone = emergencyArr[i][@"phone"];
        NSString* name = emergencyArr[i][@"name"];
        FwContactModel* model = [[FwContactModel alloc] initWithName:name phone:phone initial:[self getInitial:name]];
        [list addObject:model];
    }
    for(int i=0;i<commonContactArr.count;i++){
        NSString* phone = commonContactArr[i][@"phone"];
        NSString* name = commonContactArr[i][@"name"];
        FwContactModel* model = [[FwContactModel alloc] initWithName:name phone:phone initial:[self getInitial:name]];
        [list addObject:model];
    }
    [contactSync sendCommonContact:list];
    
    if(emergencyArr.count > 0){
        NSString* userName = emergencyArr[0][@"name"];
        NSString* initial = [self getInitial:userName];
        FwContactModel* emergencyModel = [[FwContactModel alloc] initWithName:userName phone:emergencyArr[0][@"phone"] initial:initial];
        [contactSync sendEmergencyContact:emergencyModel];
    }else{
        [contactSync sendEmergencyContact:nil];
    }
}
```

3、获得所有联系
```
-(RACSubject<NSArray<TPSContactModel*>*>*)getAllContact
```
调用举例：


4、发送常用联系人
```
-(void)sendCommonContact:(NSArray<TPSContactModel*>*)list
```
调用举例：
```
-(void)sendData{

    NSMutableArray<FwContactModel*>* list = [NSMutableArray new];
    for(int i=0;i<emergencyArr.count;i++){
        NSString* phone = emergencyArr[i][@"phone"];
        NSString* name = emergencyArr[i][@"name"];
        FwContactModel* model = [[FwContactModel alloc] initWithName:name phone:phone initial:[self getInitial:name]];
        [list addObject:model];
    }
    for(int i=0;i<commonContactArr.count;i++){
        NSString* phone = commonContactArr[i][@"phone"];
        NSString* name = commonContactArr[i][@"name"];
        FwContactModel* model = [[FwContactModel alloc] initWithName:name phone:phone initial:[self getInitial:name]];
        [list addObject:model];
    }
    [contactSync sendCommonContact:list];
    
    if(emergencyArr.count > 0){
        NSString* userName = emergencyArr[0][@"name"];
        NSString* initial = [self getInitial:userName];
        FwContactModel* emergencyModel = [[FwContactModel alloc] initWithName:userName phone:emergencyArr[0][@"phone"] initial:initial];
        [contactSync sendEmergencyContact:emergencyModel];
    }else{
        [contactSync sendEmergencyContact:nil];
    }
}
```

5、观察常用联系人
```
-(RACSubject*)observeContactChange
```
调用举例：




27.查找设备
1、回复查找手机
```
-(void)replyFindPhone
```
调用举例：
```
- (IBAction)closeBtnAction:(id)sender {
    id<IFwFinderAbility> finderSync = [FwWearFactory createSingleInstance:@protocol(IFwFinderAbility)];
    [finderSync replyFindPhone];
    [self stopVoice];
}

```
2、查找手机
```
-(void)findWatch
```
调用举例：
```
-(void)onClickBtn:(UIButton*)sender{
    if(isFinding){
        isFinding = NO;
        [finderSync stopFindWatch];
        [self showReFindUI];
        [TSAnimationTool stopSearchAnimation];
    }else{
        isFinding = YES;
        [finderSync findWatch];
        self.findStateLb.text = kJL_TXT("正在查找手表...");
        [registerBtn setTitle:kJL_TXT("结束查找") forState:UIControlStateNormal];
        [registerBtn setBackgroundImage:[UIImage imageNamed:@"findwatch_red_btn_bg"] forState:UIControlStateNormal];
        [TSAnimationTool startSearchAnimationTime:animationTimeCount container:self.animationCon block:^{
            [self showReFindUI];
        }];
    }
}
```

3、停止查找手机
```
-(void)stopFindWatch
```
调用举例：
```
-(void)onClickBtn:(UIButton*)sender{
    if(isFinding){
        isFinding = NO;
        [finderSync stopFindWatch];
        [self showReFindUI];
        [TSAnimationTool stopSearchAnimation];
    }else{
        isFinding = YES;
        [finderSync findWatch];
        self.findStateLb.text = kJL_TXT("正在查找手表...");
        [registerBtn setTitle:kJL_TXT("结束查找") forState:UIControlStateNormal];
        [registerBtn setBackgroundImage:[UIImage imageNamed:@"findwatch_red_btn_bg"] forState:UIControlStateNormal];
        [TSAnimationTool startSearchAnimationTime:animationTimeCount container:self.animationCon block:^{
            [self showReFindUI];
        }];
    }
}

-(void)showReFindUI{
    isFinding = NO;
    self.findStateLb.text = kJL_TXT("停止查找");
    [registerBtn setTitle:kJL_TXT("重新查找") forState:UIControlStateNormal];
    [registerBtn setBackgroundImage:[UIImage imageNamed:@"btn_bg_bluegreen"] forState:UIControlStateNormal];
}
```

4、观察查找手机
```
-(RACSubject*)observeFindingPhone
```
调用举例：


6、停止从手表查找手机
```
-(RACSubject*)observeWatchStopFindingPhone
```
调用举例：



28.运动排序
1、查询可编辑运动槽位
```
-(void)queryEditableSportSlots:(TPSSportSlotListCallback)block
```
调用举例：
```
[TPSSdk.share.sportDataAbility queryEditableSportSlots:^(NSArray *sportSlotList) {
    for (id slot in sportSlotList) {
        NSUInteger slotIndex = [[slot valueForKey:@"slotIndex"] unsignedIntegerValue];
        UInt16 sportType = [[slot valueForKey:@"sportType"] unsignedShortValue];
        NSLog(@"slot[%lu] sportType=%d", (unsigned long)slotIndex, sportType);
    }
}];
```

2、更新运动槽位排序
```
-(void)updateEditableSportSlots:(NSArray<TPSSportSlotModel *> *)slots completion:(TPSCompletionBlock)completion
```
调用举例：
```
// 构建重新排序后的槽位数组
NSMutableArray *slotsToSend = [NSMutableArray array];
Class slotModelClass = NSClassFromString(@"TPSSportSlotModel");
for (NSUInteger i = 0; i < reorderedList.count; i++) {
    id slotModel = [[slotModelClass alloc] init];
    [slotModel setValue:@(i) forKey:@"slotIndex"];
    [slotModel setValue:@(sportType) forKey:@"sportType"];
    [slotsToSend addObject:slotModel];
}
[TPSSdk.share.sportDataAbility updateEditableSportSlots:slotsToSend completion:^(BOOL isSuccess, NSError *error) {
    NSLog(@"save result: %@", isSuccess ? @"success" : error.localizedDescription);
}];
```
说明：测试页面为 SportSortController，可以在 Demo 菜单中找到 "sport sort" 入口。
进入页面后自动查询设备运动槽位列表，支持拖拽排序，点击 Save 按钮将新排序发送到设备。


