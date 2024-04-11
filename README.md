__TopstepComKit\-ios说明__

<a id="heading_0"></a>__安装方法__

<a id="heading_1"></a>__1、podfile文件中增加以下路径__

SQLpod 'TopStepComKit', git: 'https://github\.com/htangsmart/TopStepComKit\-IOS\.git'

<a id="heading_2"></a>__2、初始化sdk，在AppDelegate中执行以下语句__

SQL\- \(BOOL\)application:\(UIApplication \*\)application didFinishLaunchingWithOptions:\(NSDictionary \*\)launchOptions \{        \.\.\.        \[\[TPSSDK share\] initSdk\];        \.\.\.\}

<a id="heading_3"></a>__接口说明__

<a id="heading_4"></a>__1、蓝牙连接__

<a id="heading_5"></a>__1、获取蓝牙状态__

\-\(CBManagerState\)getCBManagerState

调用举例：

Plain Text\- \(void\)checkBlueToothState\{    if \(\[\[FwSdk share\]\.connectorAbility getCBManagerState\]==CBManagerStatePoweredOn\) \{        \[self setState:eTSBlueToothStateOpen\];    \}else\{        \[self setState:eTSBlueToothStateClose\];    \}\}\- \(void\)setState:\(TSBlueToothState\)state\{    \_state = state;    if \(\_state == eTSBlueToothStateClose\) \{        self\.tipLabe\.text  = kJL\_TXT\("蓝牙未开启"\);        self\.descLabe\.text  = @"";//kJL\_TXT\("绑定设备后可在APP上更清晰的分析数据"\);        self\.descLabe\.hidden = YES;        \[self\.operationButton setTitle:kJL\_TXT\("开启"\) forState:UIControlStateNormal\];    \}else\{        self\.tipLabe\.text  = kJL\_TXT\("绑定设备"\);        self\.descLabe\.text  = kJL\_TXT\("绑定设备后可在APP上更清晰的分析数据"\);        self\.descLabe\.hidden = NO;        \[self\.operationButton setTitle:kJL\_TXT\("开始搜索"\) forState:UIControlStateNormal\];    \}    \[self layoutViews\];\}

<a id="heading_6"></a>__2、获得连接__

\-\(TPSConnnectResult\_State\)getConnectState

调用举例

Go\- \(IBAction\)backBtn:\(UIButton \*\)sender \{    if\(\[\[FwSdk share\]\.connectorAbility getConnectState\]==FwConnnectResult\_State\_Connected\)\{        \[self\.navigationController popViewControllerAnimated:YES\];    \}else\{        UIAlertController \*actionSheet = \[UIAlertController alertControllerWithTitle:kJL\_TXT\("提示"\) message:kJL\_TXT\("您正在与蓝牙连接，退出该页面会导致连接失败，是否继续？"\)                                                                      preferredStyle:UIAlertControllerStyleAlert\];        UIAlertAction \*btnCancel = \[UIAlertAction actionWithTitle:kJL\_TXT\("取消"\) style:UIAlertActionStyleCancel handler:nil\];        UIAlertAction \*btnConfirm = \[UIAlertAction actionWithTitle:kJL\_TXT\("确认"\) style:UIAlertActionStyleDefault                                                           handler:^\(UIAlertAction \* \_Nonnull action\) \{            if\(\[\[FwSdk share\]\.connectorAbility getConnectState\]\!=FwConnnectResult\_State\_Connected\)\{//如果在阅读文字的过程中已经绑定成功，则不关闭                \[\[FwSdk share\]\.connectorAbility disconnect\];            \}            \[self\.navigationController popViewControllerAnimated:YES\];        \}\];        \[btnCancel setValue:kDF\_RGBA\(152, 152, 152, 1\.0\) forKey:@"\_titleTextColor"\];        \[actionSheet addAction:btnCancel\];        \[actionSheet addAction:btnConfirm\];        \[self presentViewController:actionSheet animated:YES completion:nil\];    \}\}

<a id="heading_7"></a>__3、扫描状态__

\-\(RACSubject<TPSScanResult\*>\*\)startScan

调用举例：

Plain Text\- \(void\)searchDevice\{    //search    id<IFwConnectorAbility> connectorSync = \[FwWearFactory createSingleInstance:@protocol\(IFwConnectorAbility\)\];    self\.scanRacSubject = \[connectorSync startScan\];    \[self\.scanRacSubject subscribeNext:^\(FwScanResult \* \_Nullable x\) \{        if \(x\.peripheral\.name\.length >0\) \{            NSString \*peripheralName = x\.peripheral\.name;            NSString \*mac = x\.mac ? x\.mac : @"";            \[self insertTableView:x\.peripheral macAddr: mac RSSI:x\.RSSI\];        \}    \}\];    dispatch\_after\(dispatch\_time\(DISPATCH\_TIME\_NOW, \(int64\_t\)\(kSearchTime \* NSEC\_PER\_SEC\)\), dispatch\_get\_main\_queue\(\), ^\{        \[self stopScan\];    \}\);\}\- \(void\)stopScan\{    \[self checkIfHasDevice\];    \[\[FwSdk share\]\.connectorAbility stopScan\];    if\(self\.scanRacSubject\)\{\[self\.scanRacSubject sendCompleted\];\}    \[JL\_Tools post:kUI\_JL\_BLE\_SCAN\_CLOSE Object:nil\];\}

<a id="heading_8"></a>__4、停止扫描__

\-\(void\)stopScan

调用举例

Python\- \(void\)stopScan\{    \[self checkIfHasDevice\];    \[\[FwSdk share\]\.connectorAbility stopScan\];    if\(self\.scanRacSubject\)\{\[self\.scanRacSubject sendCompleted\];\}    \[JL\_Tools post:kUI\_JL\_BLE\_SCAN\_CLOSE Object:nil\];\}\- \(void\)checkIfHasDevice\{    \[self setSearchState:eTSBlueToothSearchFinished\];    if \(self\.deviceArray\.count>0\) \{//        self\.deviceTable\.bounces = YES;        \[self\.deviceTable beginUpdates\];        self\.tableHeaderHeight = 0\.001;        self\.emptyCellHeight = 80;        \[self\.deviceTable endUpdates\];    \}else\{//        self\.deviceTable\.bounces = NO;        \[self\.deviceTable beginUpdates\];        \[self\.deviceTable reloadSections:\[NSIndexSet indexSetWithIndex:0\] withRowAnimation:UITableViewRowAnimationNone\];        \[self\.deviceTable endUpdates\];    \}\}

<a id="heading_9"></a>__5、连接地址__

\-\(RACSubject<TPSConnectResult\*>\*\)connectWithMac:\(NSString\*\)mac extraParam:\(TPSExtraConnectParam\*\)extraParam

调用举例：

Plain Text\-\(void\)setScanDict:\(NSDictionary\*\)dict\{    \[JL\_Tools delay:1\.0 Task:^\{        self\.mScanDict = dict;        self\->edrText    = dict\[@"MAC"\];        self\->nameText   = dict\[@"BleName"\];        self\->label\_2\.text= \[NSString stringWithFormat:@"%@%@",kJL\_TXT\("当前配对设备"\),self\->nameText\];        FwExtraConnectParam\* extraParam = \[\[FwExtraConnectParam alloc\] initWithUserId:\[HOETool getUserId\] gender:\[HOETool getGender\] age:\[HOETool getUserAge\] height:\[HOETool getHeight\] weight:\[HOETool getWeight\]\];        id<IFwConnectorAbility> connectorSync = \[FwWearFactory createSingleInstance:@protocol\(IFwConnectorAbility\)\];        self\->macConnectRacDispose = \[\[connectorSync connectWithMac:self\->edrText extraParam:extraParam\] subscribeNext:^\(FwConnectResult \* \_Nullable x\) \{            \[self handleConnectResult:x\];        \}\];;    \}\];\}\-\(void\)handleConnectResult:\(FwConnectResult\*\)x\{    NSLog\(@"handleConnectResult handleConnectResult is %d",x\.state\);    if\(x\.state == FwConnnectResult\_State\_Connected\)\{        self\->isWaitingReboot = NO;        \[self showUIConnectOK\];    \}else if\(x\.state == FwConnnectResult\_State\_Connecting\)\{        NSLog\(@"FwConnnectResult\_State\_Connecting"\);    \}else if\(x\.state == FwConnnectResult\_State\_Disconnected\)\{        if\(x\.errorCode == FwConnnectResult\_Error\_Code\_Low\_Battery\)\{            \[self showUIConnectOther:kJL\_TXT\("温馨提示"\) info2:kJL\_TXT\("手表电量不足，无法重新绑定，请充电"\)\];        \}else if\(x\.errorCode == FwConnnectResult\_Error\_Code\_Wait\_Reboot\)\{            self\->isWaitingReboot = YES;            \[self showUIConnectOther:kJL\_TXT\("温馨提示"\) info2:kJL\_TXT\("切换用户需等待手表重启，请稍候，并注意手表上的提示"\)\];        \}else\{            if\(\!self\->isWaitingReboot\)\{//等待手表重启，此时会发生一次断链，但是不要把这个断链当异常来显示                \[self showUIConnectFail\];            \}        \}    \}\}

<a id="heading_10"></a>__6、连接设备__

\-\(RACSubject<TPSConnectResult\*>\*\)connectWithCBPeripheral:\(CBPeripheral\*\)peripheral mac:\(NSString\*\)mac extraParam:\(TPSExtraConnectParam\*\)extraParam

调用举例

Python\-\(void\)connectDevWithCBPeripheral:\(CBPeripheral\*\)peripheral mac:\(NSString\*\)mac\{    // 手动设置为绑定状态    \[self setConnectState:eTSConnectStateConnecting\];    id<IFwConnectorAbility> connectorSync = \[FwWearFactory createSingleInstance:@protocol\(IFwConnectorAbility\)\];    FwExtraConnectParam\* extraParam = \[\[FwExtraConnectParam alloc\] initWithUserId:\[HOETool getUserId\] gender:\[HOETool getGender\] age:\[HOETool getUserAge\] height:\[HOETool getHeight\] weight:\[HOETool getWeight\]\];    self\.peripheralConnectRacDispose = \[\[connectorSync connectWithCBPeripheral:peripheral mac:mac extraParam:extraParam\] subscribeNext:^\(FwConnectResult \* \_Nullable x\) \{        \[self handleConnectResult:x\];    \}\];\}\-\(void\)handleConnectResult:\(FwConnectResult\*\)x\{    if\(x\.state == FwConnnectResult\_State\_Connected\)\{        self\.isWaitingRestart = NO;        \[self setConnectState:eTSConnectStateSuccess\];    \}else if\(x\.state == FwConnnectResult\_State\_Connecting\)\{        \[self setConnectState:eTSConnectStateConnecting\];    \}else if\(x\.state == FwConnnectResult\_State\_Disconnected\)\{        if\(x\.errorCode == FwConnnectResult\_Error\_Code\_Low\_Battery\)\{            \[self setConnectState:eTSConnectStateLowPower\];        \}else if\(x\.errorCode == FwConnnectResult\_Error\_Code\_Wait\_Reboot\)\{            self\.isWaitingRestart = YES;            \[self setConnectState:eTSConnectStateWaitReboot\];        \}else\{            if\(\!self\.isWaitingRestart\)\{//等待手表重启，此时会发生一次断链，但是不要把这个断链当异常来显示                \[self setConnectState:eTSConnectStateFailed\];            \}        \}    \}\}

<a id="heading_11"></a>__7、通过用户信息自动连接之前的设备__

\-\(RACSubject<TPSConnectResult\*>\*\)autoConnectLastPeripheralWithUserInfo:\(TPSExtraConnectParam\*\)extraParam

调用举例：

Plain Text\-\(void\)initShareInstance\{    //demo,com\.sztopstep\.sdkdemo：ohgtmacsmqt4btan1uh05l341urtpanl    //Oraimo,com\.transsion\.oraimohealth：q1d0i3ruvqqo2f3p0c1l737bgcfmklj9//    \[\[FwSdk share\] initSdkWithLincese:@"b3riel7r56r41792ffdlgp3ddv19cifj"\];//    \[\[FwSdk share\] initSdkWithLincese:@"ohgtmacsmqt4btan1uh05l341urtpanl"\];        \[\[FwSdk share\] initSdk\];    \[SyncDataManager share\];    \[\[WeatherManager share\] start\];    id<IFwConnectorAbility> connectorSync = \[FwWearFactory createSingleInstance:@protocol\(IFwConnectorAbility\)\];    if \(\[HOETool isUserDeleteWatch\]\) \{        \[connectorSync cancelAutoConnectLastPeripheral\];    \}else\{        FwExtraConnectParam\* extraParam = \[\[FwExtraConnectParam alloc\] initWithUserId:\[HOETool getUserId\] gender:\[HOETool getGender\] age:\[HOETool getUserAge\] height:\[HOETool getHeight\] weight:\[HOETool getWeight\]\];        \[connectorSync autoConnectLastPeripheralWithUserInfo:extraParam\];    \}\}

<a id="heading_12"></a>__8、取消自动连接__

\-\(void\)cancelAutoConnectLastPeripheral

调用举例

Java\-\(void\)initShareInstance\{    //demo,com\.sztopstep\.sdkdemo：ohgtmacsmqt4btan1uh05l341urtpanl    //Oraimo,com\.transsion\.oraimohealth：q1d0i3ruvqqo2f3p0c1l737bgcfmklj9//    \[\[FwSdk share\] initSdkWithLincese:@"b3riel7r56r41792ffdlgp3ddv19cifj"\];//    \[\[FwSdk share\] initSdkWithLincese:@"ohgtmacsmqt4btan1uh05l341urtpanl"\];        \[\[FwSdk share\] initSdk\];    \[SyncDataManager share\];    \[\[WeatherManager share\] start\];    id<IFwConnectorAbility> connectorSync = \[FwWearFactory createSingleInstance:@protocol\(IFwConnectorAbility\)\];    if \(\[HOETool isUserDeleteWatch\]\) \{        \[connectorSync cancelAutoConnectLastPeripheral\];    \}else\{        FwExtraConnectParam\* extraParam = \[\[FwExtraConnectParam alloc\] initWithUserId:\[HOETool getUserId\] gender:\[HOETool getGender\] age:\[HOETool getUserAge\] height:\[HOETool getHeight\] weight:\[HOETool getWeight\]\];        \[connectorSync autoConnectLastPeripheralWithUserInfo:extraParam\];    \}\}

<a id="heading_13"></a>__9、观察连接结果__

\-\(RACSubject<TPSConnectResult\*>\*\)observeConnectResult

调用举例：

Plain Text\-\(void\)syncAfterConnected\{    id<IFwConnectorAbility> connectorSync = \[FwWearFactory createSingleInstance:@protocol\(IFwConnectorAbility\)\];    \[\[connectorSync observeConnectResult\] subscribeNext:^\(FwConnectResult \* \_Nullable connectResult\) \{        if\(connectResult\.state == FwConnnectResult\_State\_Connected\)\{            \[HOETool setHasConnectedOnce\];            \[self syncTime\];            \[self syncUnitAndUserProfile\];            \[self syncSportTargets\];        \}else if\(connectResult\.state == FwConnnectResult\_State\_Connecting\)\{            if\(connectResult\.errorCode == FwConnnectResult\_Error\_Code\_Binding\)\{                id<IFwDevInfoAbility> devInfoSync = \[FwWearFactory createSingleInstance:@protocol\(IFwDevInfoAbility\)\];                \[\[devInfoSync observeBattery\] subscribeNext:^\(NSNumber \* \_Nullable x\) \{                    NSLog\(@"observeBattery %d",\[x intValue\]\) ;                    \[HOETool setBattery:\[x intValue\]\];                \}\];                \[\[devInfoSync getDevInfo\] subscribeNext:^\(FwDevInfoModel \* \_Nullable x\) \{                    NSLog\(@"syncAfterConnected devInfoSync getDevInfo %@",x\) ;                    \[HOETool setProjectId:x\.projectId\];                    \[HOETool setMobo:x\.mobo\];                    \[HOETool setJsVersion:x\.jsVersion\];                    \[HOETool setFirmVersion:x\.firmVersion\];                    if\(x\.mac\)\{                        //确实有一种拿不到mac的情况，如果用户连接成功后，又卸载app，此时系统的ble还连接，然后用户再次安装app，扫描的时候不会扫描到（因为属于还在系统连接中的），这时候就怎么也拿不到mac。（要考虑绑定成功后通过js返回mac）                        \[\[FwSdk share\]\.connectorAbility getPeripheral\]\.mac = x\.mac;                        \[HOETool setDeviceMac:x\.mac\];                    \}                    self\->hasGetMac = YES;                \}\];            \}        \}    \}\];\}\-\(void\)syncSportTargets\{    id<IFwSportTargetAbility> sportTargetSync = \[FwWearFactory createSingleInstance:@protocol\(IFwSportTargetAbility\)\];    \[sportTargetSync getSportTargets:^\(FwSportTargetModel \*sportTargetModel\) \{        if\(sportTargetModel\.modifyTime > \[HOETool getTargetModifyTime\]\)\{            \[HOETool setCaloriesGoal:sportTargetModel\.calorie\];            \[HOETool setDistanceGoal:sportTargetModel\.distance\];            \[HOETool setTargetModifyTime:sportTargetModel\.modifyTime\];            \[HOETool setActivityDurationGoal:sportTargetModel\.stand\_time\];            \[HOETool setStepGoal:sportTargetModel\.steps\];            \[HOETool setSportTimeGoal:sportTargetModel\.sport\_time\];            \[HOETool setActivityCountGoal:sportTargetModel\.sport\_num\];        \}else\{            FwSportTargetModel\* model = \[\[FwSportTargetModel alloc\] init\];            model\.calorie = \(\(int\)\[HOETool getCaloriesGoal\]\);            model\.distance = \(\[HOETool getDistanceGoal\]\);            model\.stand\_time = \(\[HOETool getActivityDurationGoal\]\);            model\.steps = \[HOETool getStepGoal\];            model\.sport\_time = \[HOETool getSportTimeGoal\];            model\.sport\_num = \[HOETool getActivityCountGoal\];            model\.modifyTime = \[HOETool getTargetModifyTime\];            \[sportTargetSync sendSportTargets:model block:^\(BOOL isSendOK\) \{                                \}\];        \}    \}\];\}

<a id="heading_14"></a>__10、断开连接__

\-\(void\)disconnect

调用举例

Python\- \(void\)returnBack\{        if\(\_connectState == eTSConnectStateConnecting||       \_connectState == eTSConnectStateSuccess\)\{        \_\_weak typeof\(self\)weakSelf = self;        \[TSAlert presentAlertOnVC:self alertTitle:kJL\_TXT\("提示"\) alertContent:kJL\_TXT\("您正在与蓝牙连接，退出该页面会导致连接失败，是否继续？"\) confirm:kJL\_TXT\("确认"\) confirmBlock:^\(id actionValue\) \{            \_\_strong typeof\(weakSelf\)strongSelf = weakSelf;                        if\(\[\[FwSdk share\]\.connectorAbility getConnectState\]\!=FwConnnectResult\_State\_Connected\)\{//如果在阅读文字的过程中已经绑定成功，则不关闭                \[\[FwSdk share\]\.connectorAbility disconnect\];            \}            \[strongSelf\.navigationController popViewControllerAnimated:YES\];        \} cancel:kJL\_TXT\("取消"\) cancelBlock:^\(id actionValue\) \{\}\];    \}else\{        \[self\.navigationController popViewControllerAnimated:YES\];    \}\}

<a id="heading_15"></a>__11、未绑定账号__

\-\(void\)unbindDevWithUserId:\(NSString\*\)userId block:\(TPSSendMsgResult \_Nullable\)block

调用举例：

Plain Text\-\(void\)unbindBtnClick\{    UIAlertController \*actionSheet = \[UIAlertController alertControllerWithTitle:kJL\_TXT\("提示"\) message:kJL\_TXT\("解除绑定设备，此操作将从手表和手机app中删除所有数据"\)                                                                  preferredStyle:UIAlertControllerStyleAlert\];    UIAlertAction \*btnCancel = \[UIAlertAction actionWithTitle:kJL\_TXT\("取消"\) style:UIAlertActionStyleCancel handler:nil\];    UIAlertAction \*btnConfirm = \[UIAlertAction actionWithTitle:kJL\_TXT\("解绑"\) style:UIAlertActionStyleDefault                                                       handler:^\(UIAlertAction \* \_Nonnull action\) \{                id<IFwConnectorAbility> connectorSync = \[FwWearFactory createSingleInstance:@protocol\(IFwConnectorAbility\)\];        \[connectorSync unbindDevWithUserId:\[HOETool getUserId\] block:^\(BOOL isSendOK\) \{                    \}\];        \[DFUITools showText:kJL\_TXT\("解绑设备成功"\) onView:self\.view delay:2\.0\];    \}\];    \[btnCancel setValue:kDF\_RGBA\(152, 152, 152, 1\.0\) forKey:@"\_titleTextColor"\];    \[actionSheet addAction:btnCancel\];    \[actionSheet addAction:btnConfirm\];    \[self presentViewController:actionSheet animated:YES completion:nil\];\}

<a id="heading_16"></a>__12、获取设备__

\-\(TPSExPeripheral\*\)getPeripheral

调用举例

C\+\+\- \(void\)viewDidLoad \{    \[super viewDidLoad\];    //    \[self addNote\];    \_headHeight\.constant = kJL\_HeightNavBar;    self\.titleLab\.text = \[\[FwSdk share\]\.connectorAbility getPeripheral\]\.peripheral\.name;\#ifdef TEST\_A\_VIDEO\_FOR\_SOMEONE    if\(\[self\.titleLab\.text isEqualToString:@"BeS\_WaTcH\_9BE4"\]\)\{        self\.titleLab\.text = @"KUMI GW5";    \}\#endif    \_reConnectBtn\.layer\.cornerRadius = 24;    \_reConnectBtn\.layer\.masksToBounds = true;    \_deleteBtn\.layer\.cornerRadius = 24;    \_deleteBtn\.layer\.masksToBounds = true;    \[\_deleteBtn setTitle:kJL\_TXT\("删除设备"\) forState:UIControlStateNormal\];    \[\_reConnectBtn setTitle:kJL\_TXT\("重新连接"\) forState:UIControlStateNormal\];//    JL\_BLEMultiple \*mtpl = \[\[JL\_RunSDK sharedMe\] mBleMultiple\];//pingbi//    BOOL t = \[\[mtpl connectingEntity\]\.mPeripheral\.identifier\.UUIDString isEqualToString:self\.mainModel\.uuidStr\];//    if \(\[\[JL\_RunSDK getLinkedArray\] containsObject:self\.mainModel\.uuidStr\] || \(mtpl\.BLE\_IS\_CONNECTING == YES && t == YES\)\) \{//        \[\_reConnectBtn setTitle:kJL\_TXT\("断开连接"\) forState:UIControlStateNormal\];//        self\.reConnectBtn\.hidden = true;//    \}    self\.reConnectBtn\.hidden = true;    tipsView = \[DFUITools showHUDOnWindowWithLabel:kJL\_TXT\("正在连接"\)\];    \[tipsView hide:false\];    //    self\.macAdressLb\.text = \[self macToFormat:self\.mainModel\.mac\];    self\.macAdressLb\.text = \[\[FwSdk share\]\.connectorAbility getPeripheral\]\.mac;\}

<a id="heading_17"></a>__2\.设备基本信息__

<a id="heading_18"></a>__1、获取设备信息__

\-\(RACSubject<TPSDevInfoModel\*>\*\)getDevInfo

调用举例：

Plain Text\-\(void\)syncAfterConnected\{    id<IFwConnectorAbility> connectorSync = \[FwWearFactory createSingleInstance:@protocol\(IFwConnectorAbility\)\];    \[\[connectorSync observeConnectResult\] subscribeNext:^\(FwConnectResult \* \_Nullable connectResult\) \{        if\(connectResult\.state == FwConnnectResult\_State\_Connected\)\{            \[HOETool setHasConnectedOnce\];            \[self syncTime\];            \[self syncUnitAndUserProfile\];            \[self syncSportTargets\];        \}else if\(connectResult\.state == FwConnnectResult\_State\_Connecting\)\{            if\(connectResult\.errorCode == FwConnnectResult\_Error\_Code\_Binding\)\{                id<IFwDevInfoAbility> devInfoSync = \[FwWearFactory createSingleInstance:@protocol\(IFwDevInfoAbility\)\];                \[\[devInfoSync observeBattery\] subscribeNext:^\(NSNumber \* \_Nullable x\) \{                    NSLog\(@"observeBattery %d",\[x intValue\]\) ;                    \[HOETool setBattery:\[x intValue\]\];                \}\];                \[\[devInfoSync getDevInfo\] subscribeNext:^\(FwDevInfoModel \* \_Nullable x\) \{                    NSLog\(@"syncAfterConnected devInfoSync getDevInfo %@",x\) ;                    \[HOETool setProjectId:x\.projectId\];                    \[HOETool setMobo:x\.mobo\];                    \[HOETool setJsVersion:x\.jsVersion\];                    \[HOETool setFirmVersion:x\.firmVersion\];                    if\(x\.mac\)\{                        //确实有一种拿不到mac的情况，如果用户连接成功后，又卸载app，此时系统的ble还连接，然后用户再次安装app，扫描的时候不会扫描到（因为属于还在系统连接中的），这时候就怎么也拿不到mac。（要考虑绑定成功后通过js返回mac）                        \[\[FwSdk share\]\.connectorAbility getPeripheral\]\.mac = x\.mac;                        \[HOETool setDeviceMac:x\.mac\];                    \}                    self\->hasGetMac = YES;                \}\];            \}        \}    \}\];\}\-\(void\)syncSportTargets\{    id<IFwSportTargetAbility> sportTargetSync = \[FwWearFactory createSingleInstance:@protocol\(IFwSportTargetAbility\)\];    \[sportTargetSync getSportTargets:^\(FwSportTargetModel \*sportTargetModel\) \{        if\(sportTargetModel\.modifyTime > \[HOETool getTargetModifyTime\]\)\{            \[HOETool setCaloriesGoal:sportTargetModel\.calorie\];            \[HOETool setDistanceGoal:sportTargetModel\.distance\];            \[HOETool setTargetModifyTime:sportTargetModel\.modifyTime\];            \[HOETool setActivityDurationGoal:sportTargetModel\.stand\_time\];            \[HOETool setStepGoal:sportTargetModel\.steps\];            \[HOETool setSportTimeGoal:sportTargetModel\.sport\_time\];            \[HOETool setActivityCountGoal:sportTargetModel\.sport\_num\];        \}else\{            FwSportTargetModel\* model = \[\[FwSportTargetModel alloc\] init\];            model\.calorie = \(\(int\)\[HOETool getCaloriesGoal\]\);            model\.distance = \(\[HOETool getDistanceGoal\]\);            model\.stand\_time = \(\[HOETool getActivityDurationGoal\]\);            model\.steps = \[HOETool getStepGoal\];            model\.sport\_time = \[HOETool getSportTimeGoal\];            model\.sport\_num = \[HOETool getActivityCountGoal\];            model\.modifyTime = \[HOETool getTargetModifyTime\];            \[sportTargetSync sendSportTargets:model block:^\(BOOL isSendOK\) \{                                \}\];        \}    \}\];\}

<a id="heading_19"></a>__2、观察电池__

\-\(RACSubject<NSNumber\*>\*\)observeBattery

调用举例

Java\-\(void\)syncAfterConnected\{    id<IFwConnectorAbility> connectorSync = \[FwWearFactory createSingleInstance:@protocol\(IFwConnectorAbility\)\];    \[\[connectorSync observeConnectResult\] subscribeNext:^\(FwConnectResult \* \_Nullable connectResult\) \{        if\(connectResult\.state == FwConnnectResult\_State\_Connected\)\{            \[HOETool setHasConnectedOnce\];            \[self syncTime\];            \[self syncUnitAndUserProfile\];            \[self syncSportTargets\];        \}else if\(connectResult\.state == FwConnnectResult\_State\_Connecting\)\{            if\(connectResult\.errorCode == FwConnnectResult\_Error\_Code\_Binding\)\{                id<IFwDevInfoAbility> devInfoSync = \[FwWearFactory createSingleInstance:@protocol\(IFwDevInfoAbility\)\];                \[\[devInfoSync observeBattery\] subscribeNext:^\(NSNumber \* \_Nullable x\) \{                    NSLog\(@"observeBattery %d",\[x intValue\]\) ;                    \[HOETool setBattery:\[x intValue\]\];                \}\];                \[\[devInfoSync getDevInfo\] subscribeNext:^\(FwDevInfoModel \* \_Nullable x\) \{                    NSLog\(@"syncAfterConnected devInfoSync getDevInfo %@",x\) ;                    \[HOETool setProjectId:x\.projectId\];                    \[HOETool setMobo:x\.mobo\];                    \[HOETool setJsVersion:x\.jsVersion\];                    \[HOETool setFirmVersion:x\.firmVersion\];                    if\(x\.mac\)\{                        //确实有一种拿不到mac的情况，如果用户连接成功后，又卸载app，此时系统的ble还连接，然后用户再次安装app，扫描的时候不会扫描到（因为属于还在系统连接中的），这时候就怎么也拿不到mac。（要考虑绑定成功后通过js返回mac）                        \[\[FwSdk share\]\.connectorAbility getPeripheral\]\.mac = x\.mac;                        \[HOETool setDeviceMac:x\.mac\];                    \}                    self\->hasGetMac = YES;                \}\];            \}        \}    \}\];\}\-\(void\)syncSportTargets\{    id<IFwSportTargetAbility> sportTargetSync = \[FwWearFactory createSingleInstance:@protocol\(IFwSportTargetAbility\)\];    \[sportTargetSync getSportTargets:^\(FwSportTargetModel \*sportTargetModel\) \{        if\(sportTargetModel\.modifyTime > \[HOETool getTargetModifyTime\]\)\{            \[HOETool setCaloriesGoal:sportTargetModel\.calorie\];            \[HOETool setDistanceGoal:sportTargetModel\.distance\];            \[HOETool setTargetModifyTime:sportTargetModel\.modifyTime\];            \[HOETool setActivityDurationGoal:sportTargetModel\.stand\_time\];            \[HOETool setStepGoal:sportTargetModel\.steps\];            \[HOETool setSportTimeGoal:sportTargetModel\.sport\_time\];            \[HOETool setActivityCountGoal:sportTargetModel\.sport\_num\];        \}else\{            FwSportTargetModel\* model = \[\[FwSportTargetModel alloc\] init\];            model\.calorie = \(\(int\)\[HOETool getCaloriesGoal\]\);            model\.distance = \(\[HOETool getDistanceGoal\]\);            model\.stand\_time = \(\[HOETool getActivityDurationGoal\]\);            model\.steps = \[HOETool getStepGoal\];            model\.sport\_time = \[HOETool getSportTimeGoal\];            model\.sport\_num = \[HOETool getActivityCountGoal\];            model\.modifyTime = \[HOETool getTargetModifyTime\];            \[sportTargetSync sendSportTargets:model block:^\(BOOL isSendOK\) \{                                \}\];        \}    \}\];\}

<a id="heading_20"></a>__3、恢复出厂设置__

\-\(void\)resetToFactoryState:\(TPSSendMsgResult \_Nullable\)block

调用举例：

Plain Text\-\(void\)resetWatch\{        id<IFwDevInfoAbility> devInfoSync = \[FwWearFactory createSingleInstance:@protocol\(IFwDevInfoAbility\)\];    \[devInfoSync resetToFactoryState:^\(BOOL isSendOK\) \{        if\(isSendOK\)\{            \[DFUITools showText:kJL\_TXT\("手表正在恢复出厂设置"\) onView:self\.view delay:1\.0\];        \}else\{            \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self\.view delay:1\.0\];        \}    \}\];    \}

<a id="heading_21"></a>__4、获取基础信息__

\-\(TPSDevInfoModel\*\)getExistDevInfo

调用举例

Python\- \(void\)viewDidLoad \{    \[super viewDidLoad\];        imgTrimFilePathList = \[NSMutableArray new\];    id<IFwDevInfoAbility> devInfoSync = \[FwWearFactory createSingleInstance:@protocol\(IFwDevInfoAbility\)\];    self\->devInfoModel = \[devInfoSync getExistDevInfo\];        NSString\* path = \[\[NSBundle mainBundle\] pathForResource:@"wait0" ofType:@"gif"\];    NSData\* gifData = \[NSData dataWithContentsOfFile:path\];    FLAnimatedImage \*gifImage = \[FLAnimatedImage animatedImageWithGIFData:gifData\];    FLAnimatedImageView \*gifView = \[\[FLAnimatedImageView alloc\] init\];    gifView\.animatedImage = gifImage;    \[self\.viewProgressContainer addSubview:gifView\];    \[gifView mas\_makeConstraints:^\(MASConstraintMaker \*make\) \{        make\.leading\.mas\_equalTo\(0\);        make\.top\.mas\_equalTo\(0\);        make\.trailing\.mas\_equalTo\(0\);        make\.bottom\.mas\_equalTo\(0\);    \}\];                \[JL\_Tools subTask:^\{        for\(int i=0;i<self\.imgOriginFileList\.count;i\+\+\)\{            NSString\* path = self\.imgOriginFileList\[i\];            UIImage\* imgOrigin = \[UIImage imageWithContentsOfFile:path\];            UIImage\* imgTrim = \[self trimImage:imgOrigin\];            UIImage\* scaleOne = \[self resizeImageToScreenSize:imgTrim\];            NSString\* trimPath = \[self saveImage:scaleOne originPath:path\];            \[self\->imgTrimFilePathList addObject:trimPath\];        \}        \[JL\_Tools mainTask:^\{            AlbumCutVC\* vc = \[\[AlbumCutVC alloc\] init\];            vc\.imgFileList = self\->imgTrimFilePathList;            \[self\.navigationController pushViewController:vc animated:YES\];        \}\];    \}\];\}

<a id="heading_22"></a>__5、发送手机系统时间__

\-\(void\)sendPhoneSystemTime

调用举例：

Plain Text\-\(void\)syncTime\{    \[\[FwSdk share\]\.devInfoAbility sendPhoneSystemTime\];\}\-\(void\)syncUnitAndUserProfile\{    id<IFwMiscSettingAbility> miscSettingSync = \[FwWearFactory createSingleInstance:@protocol\(IFwMiscSettingAbility\)\];    \[miscSettingSync sendUserNickName:\[HOETool getNickname\]\];    if\(\[\[HOETool getTemperatureUnit\] isEqualToString:@"C"\]\)\{        \[miscSettingSync sendWeather\_temp\_unit:\(FwMiscSettingModel\_Temperature\_Unit\_C\)\];    \}else\{        \[miscSettingSync sendWeather\_temp\_unit:\(FwMiscSettingModel\_Temperature\_Unit\_F\)\];    \}    if\(\[HOETool isMetricSystem\]\)\{        \[miscSettingSync sendSport\_sportUnit:\(MiscSettingModel\_TSFW\_Sport\_Unit\_Metric\_System\)\];    \}else\{        \[miscSettingSync sendSport\_sportUnit:\(MiscSettingModel\_TSFW\_Sport\_Unit\_British\_System\)\];    \}    \}

<a id="heading_23"></a>__6\.重启手表__

\- \(RACSubject\*\)restartPeripheral

调用举例

Plain Text

<a id="heading_24"></a>__7、关机__

\- \(RACSubject\*\)shutdownPeripheral

调用举例：

Plain Text

<a id="heading_25"></a>__3\.历史心率数据__

<a id="heading_26"></a>__1、获取历史的静息心率__

\-\(void\)getHistoryRestQuietHeartRate:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistoryHeartRateCallback \_Nullable\)block

调用举例：

Plain Text\-\(void\)syncHeartRateDataWithCbTp:\(void\(^\)\(void\)\)block\{    if\(\!hasGetMac\)\{        return;    \}    id<IFwHeartRateDataAbility> sync = \[FwWearFactory createSingleInstance:@protocol\(IFwHeartRateDataAbility\)\];    \[JLSqliteHeartRate checkoutTheLastDataWithResultTp:^\(NSArray<TsDbEntity \*> \* \_Nonnull charts\) \{        NSTimeInterval lastTimestamp;        if\(charts\.count > 0\)\{            lastTimestamp = charts\[0\]\.timestamp \+ 1;        \}else\{            lastTimestamp = \[\[NSDate new\]\.toStartOfDate timeIntervalSince1970\];        \}        NSTimeInterval curTimestamp = \[\[NSDate new\]\.toEndOfDate timeIntervalSince1970\];        \[sync getHistoryHeartRate:lastTimestamp endTime:curTimestamp block:^\(NSArray<FwHistoryHeartRateModel \*> \* \_Nullable historyHeartRateModelList\) \{            \[JLSqliteHeartRate updateDataTp:historyHeartRateModelList\];            \[\[TSAppleHealth share\] saveValues:historyHeartRateModelList quaIndefier:HKQuantityTypeIdentifierHeartRate start:\[NSDate dateWithTimeIntervalSince1970:lastTimestamp\] end:\[NSDate dateWithTimeIntervalSince1970:curTimestamp\] finished:^\(BOOL success, NSError \*error\) \{\}\];        \}\];    \}\];        \[sync getHistoryRestQuietHeartRate:0 endTime:\[\[NSDate new\]\.toStartOfDate timeIntervalSince1970\] block:^\(NSArray<FwHistoryHeartRateModel \*> \* \_Nullable historyHeartRateModelList\) \{        \[JLSqliteHeartRate updateRestHeartRate:historyHeartRateModelList\];    \}\];\}

<a id="heading_27"></a>__2、获取历史心率__

\-\(void\)getHistoryHeartRate:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistoryHeartRateCallback \_Nullable\)block

调用举例

Java\-\(void\)syncHeartRateDataWithCbTp:\(void\(^\)\(void\)\)block\{    if\(\!hasGetMac\)\{        return;    \}    id<IFwHeartRateDataAbility> sync = \[FwWearFactory createSingleInstance:@protocol\(IFwHeartRateDataAbility\)\];    \[JLSqliteHeartRate checkoutTheLastDataWithResultTp:^\(NSArray<TsDbEntity \*> \* \_Nonnull charts\) \{        NSTimeInterval lastTimestamp;        if\(charts\.count > 0\)\{            lastTimestamp = charts\[0\]\.timestamp \+ 1;        \}else\{            lastTimestamp = \[\[NSDate new\]\.toStartOfDate timeIntervalSince1970\];        \}        NSTimeInterval curTimestamp = \[\[NSDate new\]\.toEndOfDate timeIntervalSince1970\];        \[sync getHistoryHeartRate:lastTimestamp endTime:curTimestamp block:^\(NSArray<FwHistoryHeartRateModel \*> \* \_Nullable historyHeartRateModelList\) \{            \[JLSqliteHeartRate updateDataTp:historyHeartRateModelList\];            \[\[TSAppleHealth share\] saveValues:historyHeartRateModelList quaIndefier:HKQuantityTypeIdentifierHeartRate start:\[NSDate dateWithTimeIntervalSince1970:lastTimestamp\] end:\[NSDate dateWithTimeIntervalSince1970:curTimestamp\] finished:^\(BOOL success, NSError \*error\) \{\}\];        \}\];    \}\];        \[sync getHistoryRestQuietHeartRate:0 endTime:\[\[NSDate new\]\.toStartOfDate timeIntervalSince1970\] block:^\(NSArray<FwHistoryHeartRateModel \*> \* \_Nullable historyHeartRateModelList\) \{        \[JLSqliteHeartRate updateRestHeartRate:historyHeartRateModelList\];    \}\];\}

<a id="heading_28"></a>__3、获取实时心率__

\-\(void\)getHistoryRealTimeHeartRate:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistoryHeartRateCallback \_Nullable\)block

调用举例：

Plain Text

<a id="heading_29"></a>__4、获取心率配置__

\-\(void\)getHrConfig:\(TPSHeartRateConfigCallback \_Nonnull \)block

调用举例

Plain Text

<a id="heading_30"></a>__5、设置心率配置__

\-\(void\)setHrConfig:\(TPSHrConfigModel\*\)model block:\(TPSSendMsgResult\)block

调用举例：

Plain Text

<a id="heading_31"></a>__4\.历史血氧数据__

<a id="heading_32"></a>__1、获取历史血氧__

\-\(void\)getHistorySPO2:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistorySPO2Callback \_Nullable\)block

调用举例：

Plain Text\-\(void\)syncBloodOxyDataWithCbTp:\(void\(^\)\(void\)\)block\{    if\(\!hasGetMac\)\{        return;    \}    \[JLSqliteOxyhemoglobinSaturation checkoutTheLastDataWithResultTp:^\(long recordTime, int blood\_oxy\) \{        id<IFwSPO2Ability> sync = \[FwWearFactory createSingleInstance:@protocol\(IFwSPO2Ability\)\];        \[sync getHistorySPO2:recordTime\+1 endTime:\[\[NSDate new\]\.toEndOfDate timeIntervalSince1970\] block:^\(NSArray<FwHistorySPO2Model \*> \* \_Nullable historySPO2ModelList\) \{            if\(historySPO2ModelList\)\{                \[JLSqliteOxyhemoglobinSaturation updateMulti:historySPO2ModelList\];            \}        \}\];    \}\];\}

<a id="heading_33"></a>__2、获取实时血氧__

\-\(void\)getHistoryRealTimeSPO2:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistorySPO2Callback \_Nullable\)block

调用举例

Plain Text

<a id="heading_34"></a>__3、获取血氧配置__

\-\(void\)getSpo2Config:\(TPSSpo2ConfigCallback \_Nonnull \)block

调用举例：

Plain Text

<a id="heading_35"></a>__4、设置血氧配置__

\-\(void\)setSpo2Config:\(TPSSpo2ConfigModel\*\)model block:\(TPSSendMsgResult\)block

调用举例

Plain Text

<a id="heading_36"></a>__5\.历史活动数据__

<a id="heading_37"></a>__1、获取历史活动__

\-\(void\)getHistoryActivity:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistoryActivityCallback \_Nullable\)block

调用举例：

Plain Text\-\(void\)syncActivityRecordWithBlock:\(void\(^\)\(void\)\)block\{    if\(\!hasGetMac\)\{        return;    \}    int recordTime = 0;\#ifdef ISTESTONLY    recordTime = 0;\#endif    id<IFwActivityDataAbility> sync = \[FwWearFactory createSingleInstance:@protocol\(IFwActivityDataAbility\)\];    \[sync getHistoryActivity:recordTime endTime:\[NSDate new\]\.timeIntervalSince1970 block:^\(NSArray<FwHistoryActivityModel \*> \* \_Nullable historyActivityModelList\) \{        NSLog\(@"syncActivityRecordWithBlock"\);        \[JLSqliteActivityRecord updateMulti:historyActivityModelList\];    \}\];\}

<a id="heading_38"></a>__2、获取今日总计活动__

\-\(void\)getTodayTotalActivity:\(TPSTodayAllActivityCallback \_Nullable\)block

调用举例

Plain Text

<a id="heading_39"></a>__6\.历史运动数据__

<a id="heading_40"></a>__1、获取历史运动__

\-\(void\)getHistorySport:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistorySportCallback \_Nullable\)block

调用举例：

Plain Text\-\(void\)syncSportRecordWithBlock:\(void\(^\)\(void\)\)block\{    if\(\!hasGetMac\)\{        return;    \}    \[JLSqliteSportRunningRecord checkoutTheLastDataWithBlock:^\(long recordTime, FwHistorySportModel \* \_Nonnull record\) \{        id<IFwSportDataAbility> sync = \[FwWearFactory createSingleInstance:@protocol\(IFwSportDataAbility\)\];        \[sync getHistorySport:recordTime\+1 endTime:\[\[NSDate new\]\.toEndOfDate timeIntervalSince1970\] block:^\(NSArray<FwHistorySportModel \*> \* \_Nullable historySportModelList\) \{            if\(historySportModelList\)\{                \[JLSqliteSportRunningRecord updateMulti:historySportModelList\];            \}        \}\];    \}\];\}

<a id="heading_41"></a>__7\.历史睡眠数据__

<a id="heading_42"></a>__1、获取历史睡眠__

\-\(void\)getHistorySleep:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistorySleepCallback \_Nullable\)block

调用举例：

Plain Text\-\(void\)syncSleepDataWithCbTp:\(void\(^\)\(void\)\)block\{    if\(\!hasGetMac\)\{        return;    \}    \[JLSqliteSleep checkoutTheLastDataWithResultTp:^\(long startTime\) \{        id<IFwSleepDataAbility> sync = \[FwWearFactory createSingleInstance:@protocol\(IFwSleepDataAbility\)\];\#ifdef ISTEMTEST        //注意将底下的0改成正式值\#endif        \[sync getHistorySleep:0 endTime:\[\[NSDate new\]\.toEndOfDate timeIntervalSince1970\] block:^\(NSArray<FwHistorySleepModel \*> \* \_Nullable historySleepModelList\) \{            if\(historySleepModelList\)\{                \[JLSqliteSleep updateMulti:historySleepModelList\];            \}        \}\];    \}\];\#ifdef ISTESTONLY//    \[HOETool bundleToDocuments:@"sleepfake" fileName:@"fakedata\.txt" existsCover:YES\];//    NSString \*binPath = \[JL\_Tools listPath:NSDocumentDirectory MiddlePath:@"sleepfake" File:@"fakedata\.txt"\];//    NSData\* jsData = \[NSData dataWithContentsOfFile:binPath\];//    NSDictionary\* dic = \[HOETool dictionaryWithJsonNSDate:jsData\];//    NSArray\* arrQuery = dic\[@"query"\];//    NSMutableArray<HistorySleepModel \*>\* tsDbArray = \[NSMutableArray new\];//    for\(int i=0;i<arrQuery\.count;i\+\+\)\{//        NSNumber\* timestamp = arrQuery\[i\]\[@"value"\]\[@"start"\];//        NSNumber\* hr = arrQuery\[i\]\[@"value"\]\[@"type"\];//        NSNumber\* du = arrQuery\[i\]\[@"value"\]\[@"duration"\];//        HistorySleepModel\* entity = \[\[HistorySleepModel alloc\] init\];//        entity\.start\_time = \[timestamp longValue\];//        entity\.record\_time = \[timestamp longValue\];//        entity\.type = \[hr intValue\];//        entity\.duration = \[du intValue\];//        \[tsDbArray addObject:entity\];//    \}//    \[JLSqliteSleep updateMulti:tsDbArray\];//    NSLog\(@"FAKE"\);\#endif\}

<a id="heading_43"></a>__8\.历史压力数据__

<a id="heading_44"></a>__1、获取历史压力__

\-\(void\)getHistoryStress:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistoryStressCallback \_Nullable\)block

调用举例：

Plain Text\-\(void\)syncStressDataWithCbTb:\(void\(^\)\(void\)\)block\{    if\(\!hasGetMac\)\{        return;    \}    \[JLSqliteStress checkoutTheLastDataWithResultTp:^\(long recordTime, int stress\) \{        id<IFwStressDataAbility> sync = \[FwWearFactory createSingleInstance:@protocol\(IFwStressDataAbility\)\];        \[sync getHistoryStress:recordTime\+1 endTime:\[\[NSDate new\]\.toEndOfDate timeIntervalSince1970\] block:^\(NSArray<FwHistoryStressModel \*> \* \_Nullable historyStressModelList\) \{            if\(historyStressModelList\)\{                \[JLSqliteStress updateMulti:historyStressModelList\];            \}        \}\];    \}\];\}

<a id="heading_45"></a>__2、获取心率配置__

\-\(void\)getHrConfig:\(TPSStressConfigCallback \_Nonnull \)block

调用举例

Plain Text

<a id="heading_46"></a>__3、设置心率配置__

\-\(void\)setHrConfig:\(TPSStressConfigModel\*\)model block:\(TPSSendMsgResult\)block

调用举例：

Plain Text

<a id="heading_47"></a>__9\.历史血压数据__

<a id="heading_48"></a>__1、获取历史血压__

\-\(void\)getHistoryBloodPressure:\(NSTimeInterval\)startTime endTime:\(NSTimeInterval\)endTime block:\(TPSHistoryBloodPressureCallback \_Nullable\)block

调用举例：

Plain Text\-\(void\)syncBloodPressureDataWithCbTb:\(void\(^\)\(void\)\)block\{    if\(\!hasGetMac\)\{        return;    \}    \[JLSqliteBloodPressure checkoutTheLastDataWithResultTp:^\(long recordTime, int sbp, int dbp\) \{        id<IFwBloodPressureDataAbility> sync = \[FwWearFactory createSingleInstance:@protocol\(IFwBloodPressureDataAbility\)\];        \[sync getHistoryBloodPressure:recordTime\+1 endTime:\[\[NSDate new\]\.toEndOfDate timeIntervalSince1970\] block:^\(NSArray<FwHistoryBloodPressureModel \*> \* \_Nullable bloodPressureList\) \{            if\(bloodPressureList\)\{                \[JLSqliteBloodPressure updateMulti:bloodPressureList\];            \}        \}\];    \}\];\}

<a id="heading_49"></a>__10\.提醒设置__

<a id="heading_50"></a>__1、提醒指数__

\- \(void\)resetRemindIndex:\(NSArray \*\_Nullable\)indexArray success:\(TPSSendMsgResult \_Nullable \)success

调用举例：

Plain Text\+ \(void\)changeRemindIndex:\(NSArray \*\)remindValueArray success:\(void \(^\)\(BOOL\)\)success\{        id<IFwRemindSettingAbility> remindSettingAbility = \[FwWearFactory createSingleInstance:@protocol\(IFwRemindSettingAbility\)\];    NSArray \*indexArray = \[TSRemindModel transferIndexRemindSettingModelToDict:remindValueArray\];    \[remindSettingAbility resetRemindIndex:indexArray success:^\(BOOL isSendOK\) \{        success\(isSendOK\);    \}\];\}

<a id="heading_51"></a>__2、手表成功请求提醒设置数据__

\- \(void\)requestRemindSettingDataFormWatchSuccess:\(TPSRemindSettingCallback \_Nullable\)success

调用举例：

Plain Text\- \(void\)requestValues\{    \_\_weak typeof\(self\)weakSelf = self;    \[TSRemindSettingDataOperation requestRemindSettingDataFormWatchSuccess:^\(NSMutableArray \* \_Nonnull remindSettingArray\) \{        \_\_strong typeof\(weakSelf\)strongSelf = weakSelf;        if \(remindSettingArray == nil || remindSettingArray\.count == 0\) \{            \[strongSelf insertSystemSettingItemIntoWatch\];        \}else\{            \[strongSelf\.remindHandle reloadRemindList:strongSelf\.remindTableView remindArray:remindSettingArray\];        \}    \}\];\}

<a id="heading_52"></a>__3、设置提醒值__

\- \(void\)setRemindValueWithValue:\(NSDictionary \*\_Nonnull\)valueDict index:\(NSArray \*\_Nullable\)indexArray success:\(TPSSendMsgResult \_Nullable\)success

调用举例：

Plain Text\+ \(void\)insertSystemRemindSettingDataIntoWatchSuccess:\(void \(^\)\(BOOL\)\)success\{    id<IFwRemindSettingAbility> remindSettingAbility = \[FwWearFactory createSingleInstance:@protocol\(IFwRemindSettingAbility\)\];    NSArray \*systemItemArray = \[TSRemindModel systemRemindSettingArray\];    NSDictionary \*systemDict = \[TSRemindModel transRemindSettingModelToDict:systemItemArray deletedArray:nil\];    NSArray \*indexArray = \[TSRemindModel transferIndexRemindSettingModelToDict:systemItemArray\];    \[remindSettingAbility setRemindValueWithValue:systemDict index:indexArray success:^\(BOOL isSendOK\) \{        success\(isSendOK\);    \}\];\}

<a id="heading_53"></a>__11\.遥控拍照__

<a id="heading_54"></a>__1、输入远程拍照__

\- \(RACSubject \*\)enterRemotePhotography

调用举例：

Plain Text

<a id="heading_55"></a>__2、退出摇一摇拍照__

\- \(void\)exitRemotePhotography

调用举例：

Plain Text

<a id="heading_56"></a>__12\.语言设置__

<a id="heading_57"></a>__1、查询当前的语言__

\- \(RACSubject<TPSLanguageModel \*>\*\)queryCurrentLanguage

调用举例：

Plain Text

<a id="heading_58"></a>__2、设置当前语言__

\- \(RACSubject\*\)setCurrentLangue:\(TPSLanguageModel \*\)language

调用举例：

Plain Text

<a id="heading_59"></a>__3、查询支持的语言__

\- \(void\)querySupportLanguageSuccess:\(void\(^\)\(NSArray <NSString \*>\*languages,NSArray <TPSLanguageModel \*>\*languagesModels\)\)success

调用举例：

Plain Text

<a id="heading_60"></a>__13\.相册__

<a id="heading_61"></a>__1、从本地路径选择图片__

\-\(void\)pushPictureWithLocalPath:\(NSString\*\)localPath catalogName:\(NSString\*\)catalogName fileName:\(NSString\*\)fileName block:\(onTPSProgressResult\)block

调用举例：

Plain Text\-\(void\)startPushFile\{    NSString\* localPath = \_imgFileList\[pushFileIndex\];    NSString\* catalogName = \[AlbumUtil getCatalogWithTrimPath:localPath\];    NSString\* fileName = localPath\.lastPathComponent;    \[albumSync pushPictureWithLocalPath:localPath catalogName:catalogName fileName:fileName block:^\(FwProgressModel \*model\) \{        if\(self\->pushFileIndex == self\->progressArr\.count\)\{            \[self\->progressArr addObject:model\];        \}else\{            self\->progressArr\[self\->pushFileIndex\] = model;        \}        \[self\->subCollectView reloadData\];        if\(model\.eventType == FwProgressModel\_Event\_Type\_OnCompleted || model\.eventType == FwProgressModel\_Event\_Type\_OnFailed\)\{            if\(model\.eventType == FwProgressModel\_Event\_Type\_OnFailed\)\{                \[self\->realFailList addObject:@\(self\->pushFileIndex\)\];            \}            self\->pushFileIndex\+\+;            self\.lbProgress\.text = \[NSString stringWithFormat:@"%@ %d/%lu",kJL\_TXT\("同步中"\),self\->pushFileIndex,self\.imgFileList\.count\];            if\(self\->pushFileIndex < self\.imgFileList\.count\)\{                \[self startPushFile\];//递归调用            \}else\{                AlbumVC\* vc = \[\[AlbumVC alloc\] init\];                \[self\.navigationController pushViewController:vc animated:YES\];            \}        \}    \}\];\}

<a id="heading_62"></a>__2、删除图片的目录名__

\-\(void\)delPictureWithCatalogName:\(NSString\*\)catalogName fileName:\(NSString\*\)fileName block:\(TPSSendMsgResult\)block

调用举例：

Plain Text\-\(void\)deleteOnDev\{    NSString\* catalogName = \[AlbumUtil getCatalogWithTrimPath:\_imgFileList\[chooseIndex\]\.relativePath\];    NSString\* fileName = \_imgFileList\[chooseIndex\]\.relativePath\.lastPathComponent;    \[albumSync delPictureWithCatalogName:catalogName fileName:catalogName block:^\(BOOL isSendOK\) \{        NSLog\(@"deleteOnDev11111"\);        NSString\* localPath = \[AlbumUtil getTrimPathWithRelativePath:self\.imgFileList\[self\->chooseIndex\]\.relativePath\];        NSLog\(@"deleteOnDev2222"\);        \[JL\_Tools removePath:localPath\];        NSLog\(@"deleteOnDev3333 %@",localPath\);        \[self\.imgFileList removeObjectAtIndex:self\->chooseIndex\];        NSLog\(@"deleteOnDev4444"\);        \[self\->subCollectView reloadData\];        NSLog\(@"deleteOnDev5555"\);        self\.vDeleteOpView\.hidden = YES;        NSLog\(@"deleteOnDev6666"\);    \}\];\}

<a id="heading_63"></a>__3、获取音乐文件夹__

\-\(void\)getMusicFileTreeWithBlock:\(TPSFileListCallback\)block

调用举例：

Plain Text\- \(void\)viewDidLoad \{    \[super viewDidLoad\];    imgFileList = \[NSMutableArray new\];    self\.viewNoData\.backgroundColor = UIColor\.clearColor;    self\.vAlbumListView\.backgroundColor = UIColor\.clearColor;    \[self\.btnAdd addTarget:self action:@selector\(onAddClick\) forControlEvents:\(UIControlEventTouchUpInside\)\];    \[self\.bntAddInHead addTarget:self action:@selector\(onAddClick\) forControlEvents:\(UIControlEventTouchUpInside\)\];        self\.tbAlbumTable\.rowHeight = 164;    self\.tbAlbumTable\.delegate = self;    self\.tbAlbumTable\.dataSource =self;    self\.tbAlbumTable\.scrollEnabled = YES;    self\.tbAlbumTable\.backgroundColor = UIColor\.clearColor;    self\.tbAlbumTable\.sectionFooterHeight = 30;//    mTableView\.layer\.masksToBounds=YES;    \[self\.tbAlbumTable setSeparatorColor:\[UIColor colorWithRed:238/255\.0 green:238/255\.0 blue:238/255\.0 alpha:0\.0\]\];    \[self\.tbAlbumTable registerNib:\[UINib nibWithNibName:@"TSAlbumCoverCell" bundle:nil\] forCellReuseIdentifier:@"TSAlbumCoverCell"\];        \[self\.view insertSubview:self\.viewNoData atIndex:0\];    \[self\.view insertSubview:self\.vAlbumListView atIndex:0\];    self\.viewNoData\.hidden = YES;    self\.vAlbumListView\.hidden = YES;        id<IFwAlbumAbility> albumSync = \[FwWearFactory createSingleInstance:@protocol\(IFwAlbumAbility\)\];    \[albumSync getMusicFileTreeWithBlock:^\(NSArray<FwDevFileDesModel \*> \*fileList\) \{        self\->fileDesList = \[self getExistFileList:fileList\];        if\(self\->fileDesList && self\->fileDesList\.count > 0\)\{            self\.viewNoData\.hidden = YES;            self\.vAlbumListView\.hidden = NO;            \[self\.tbAlbumTable reloadData\];        \}else\{            self\.viewNoData\.hidden = NO;            self\.vAlbumListView\.hidden = YES;        \}    \}\];\}

<a id="heading_64"></a>__4、通知设备之前修改__

\-\(void\)notifyDevAfterUpdate:\(TPSAlbumUpdateModel\*\)model

调用举例：

Plain Text

<a id="heading_65"></a>__14\.卡包__

<a id="heading_66"></a>__1、获取钱包卡片__

\-\(void\)getWalletCards:\(TPSCardPocketWalletListCallback\)block

调用举例：

Plain Text\- \(void\)viewDidLoad \{    \[super viewDidLoad\];        cardPocketSync = \[FwWearFactory createSingleInstance:@protocol\(IFwCardPocketAbility\)\];        self\.contentContainer\.backgroundColor = \[JLColor colorWithString:BG\_GRAY1\];        NSArray\* allNormalNameArray =  @\[        @\{@"icon":@"device\_msg\_qq",@"msg\_title":kJL\_TXT\("QQ"\),@"tool\_id":@"QQ"\},        @\{@"icon":@"device\_msg\_wx",@"msg\_title":kJL\_TXT\("微信"\),@"tool\_id":@"Wechat"\},        @\{@"icon":@"wallet\_zfb\_icon",@"msg\_title":kJL\_TXT\("支付宝"\),@"tool\_id":@"Alipay"\},        @\{@"icon":@"wallet\_paypal\_icon",@"msg\_title":kJL\_TXT\("Paypal"\),@"tool\_id":@"Paypal"\},        @\{@"icon":@"wallet\_paytm\_icon",@"msg\_title":kJL\_TXT\("Paytm"\),@"tool\_id":@"Paytm"\},        @\{@"icon":@"wallet\_phonepe\_icon",@"msg\_title":kJL\_TXT\("PhonePe"\),@"tool\_id":@"PhonePe"\},        @\{@"icon":@"wallet\_gpay\_icon",@"msg\_title":kJL\_TXT\("Gpay"\),@"tool\_id":@"Gpay"\},        @\{@"icon":@"wallet\_bhim\_icon",@"msg\_title":kJL\_TXT\("BHIM"\),@"tool\_id":@"BHIM"\},    \];        NSArray\*  allCustomNameArray = @\[        @\{@"icon":@"card\_custom\_add\_icon",@"msg\_title":kJL\_TXT\("自定义"\),@"tool\_id":@"Custom"\},    \];        normalNameArray = \[NSMutableArray new\];    customNameArray = \[NSMutableArray new\];    self\.tbMoneyCards\.rowHeight = 54\.0;        self\.tbMoneyCards\.delegate = self;    self\.tbMoneyCards\.dataSource =self;    self\.tbMoneyCards\.scrollEnabled = YES;    self\.tbMoneyCards\.layer\.cornerRadius=15\.0f;    \[self\.tbMoneyCards setSeparatorColor:\[UIColor colorWithRed:238/255\.0 green:238/255\.0 blue:238/255\.0 alpha:1\.0\]\];    \[self\.tbMoneyCards registerNib:\[UINib nibWithNibName:@"CommonStyle3Cell" bundle:nil\] forCellReuseIdentifier:@"CommonStyle3Cell"\];//    \[self\.tbMoneyCards reloadData\];    //    self\.tbCustomMoneyCards\.rowHeight = 54\.0;//    self\.constarintTable2Height\.constant = 54\*customNameArray\.count;//    self\.tbCustomMoneyCards\.delegate = self;//    self\.tbCustomMoneyCards\.dataSource =self;//    self\.tbCustomMoneyCards\.scrollEnabled = YES;//    self\.tbCustomMoneyCards\.layer\.cornerRadius=15\.0f;//    \[self\.tbCustomMoneyCards setSeparatorColor:\[UIColor colorWithRed:238/255\.0 green:238/255\.0 blue:238/255\.0 alpha:1\.0\]\];//    \[self\.tbCustomMoneyCards registerNib:\[UINib nibWithNibName:@"CommonStyle3Cell" bundle:nil\] forCellReuseIdentifier:@"CommonStyle3Cell"\];//    \[self\.tbCustomMoneyCards reloadData\];        \[cardPocketSync getWalletCards:^\(NSMutableArray<FwWalletModel \*> \*walletList\) \{        self\->watchDataArray = walletList;        self\->normalNameArray = \[NSMutableArray new\];        for\(int i=0;i<allNormalNameArray\.count;i\+\+\)\{            if\(\[self isInWatchArr:allNormalNameArray\[i\]\[@"tool\_id"\]\]\)\{                \[self\->normalNameArray addObject:allNormalNameArray\[i\]\];            \}        \}        self\->customNameArray = \[NSMutableArray new\];        if\(\[self isInWatchArr:@"Custom"\]\)\{            \[self\->customNameArray addObject:allCustomNameArray\[0\]\];        \}        \[self resetTableHeight\];        \[self\.tbMoneyCards reloadData\];    \}\];\}\-\(void\)resetTableHeight\{    self\.constarintTable1Height\.constant = 54\*\(normalNameArray\.count \+ customNameArray\.count\) \+ MoneyCardPocketVC\_footer\_height;\}

<a id="heading_67"></a>__2、发送钱包卡片__

\-\(void\)sendWalletCards:\(NSArray<TPSWalletModel\*>\*\) walletList

调用举例：

Plain Text\-\(void\)onCardPocketBind:\(NSString\*\)type qrCode:\(NSString\*\)qrCode\{    \[self getWalletModel:type\]\.qrCode = qrCode;    \[cardPocketSync sendWalletCards:watchDataArray\];\}\-\(FwWalletModel\*\)getWalletModel:\(NSString\*\)key\{    for\(int i=0;i<watchDataArray\.count;i\+\+\)\{        if\(\[watchDataArray\[i\]\.company isEqualToString:key\]\)\{            return watchDataArray\[i\];        \}    \}    return nil;\}

<a id="heading_68"></a>__3、获取卡片名字__

\-\(void\)getNameCards:\(TPSCardPocketNameCardListCallback\)block

调用举例：

Plain Text\- \(void\)viewDidLoad \{    \[super viewDidLoad\];        cardPocketSync = \[FwWearFactory createSingleInstance:@protocol\(IFwCardPocketAbility\)\];        self\.contentContainer\.backgroundColor = \[JLColor colorWithString:BG\_GRAY1\];        NSArray\* allNormalNameArray =  @\[        @\{@"icon":@"device\_msg\_qq",@"msg\_title":kJL\_TXT\("QQ"\),@"tool\_id":@"QQ"\},        @\{@"icon":@"device\_msg\_wx",@"msg\_title":kJL\_TXT\("微信"\),@"tool\_id":@"Wechat"\},        @\{@"icon":@"device\_msg\_fb",@"msg\_title":kJL\_TXT\("Facebook"\),@"tool\_id":@"Facebook"\},        @\{@"icon":@"device\_msg\_whatsapp",@"msg\_title":kJL\_TXT\("WhatsApp"\),@"tool\_id":@"Whatsapp"\},        @\{@"icon":@"device\_msg\_tw",@"msg\_title":kJL\_TXT\("X"\),@"tool\_id":@"Twitter"\},        @\{@"icon":@"device\_msg\_instagram",@"msg\_title":kJL\_TXT\("Instagram"\),@"tool\_id":@"Instagram"\},        @\{@"icon":@"device\_msg\_line",@"msg\_title":kJL\_TXT\("Line"\),@"tool\_id":@"Line"\},        @\{@"icon":@"device\_msg\_skype",@"msg\_title":kJL\_TXT\("Skype"\),@"tool\_id":@"Skype"\},    \];        NSArray\*  allCustomNameArray = @\[        @\{@"icon":@"card\_custom\_add\_icon",@"msg\_title":kJL\_TXT\("自定义"\),@"tool\_id":@"Custom"\},    \];        normalNameArray = \[NSMutableArray new\];    customNameArray = \[NSMutableArray new\];    self\.tbCards\.rowHeight = 54\.0;        self\.tbCards\.delegate = self;    self\.tbCards\.dataSource =self;    self\.tbCards\.scrollEnabled = YES;    self\.tbCards\.layer\.cornerRadius=15\.0f;    \[self\.tbCards setSeparatorColor:\[UIColor colorWithRed:238/255\.0 green:238/255\.0 blue:238/255\.0 alpha:1\.0\]\];    \[self\.tbCards registerNib:\[UINib nibWithNibName:@"CommonStyle3Cell" bundle:nil\] forCellReuseIdentifier:@"CommonStyle3Cell"\];//    \[self\.tbMoneyCards reloadData\];    //    self\.tbCustomMoneyCards\.rowHeight = 54\.0;//    self\.constarintTable2Height\.constant = 54\*customNameArray\.count;//    self\.tbCustomMoneyCards\.delegate = self;//    self\.tbCustomMoneyCards\.dataSource =self;//    self\.tbCustomMoneyCards\.scrollEnabled = YES;//    self\.tbCustomMoneyCards\.layer\.cornerRadius=15\.0f;//    \[self\.tbCustomMoneyCards setSeparatorColor:\[UIColor colorWithRed:238/255\.0 green:238/255\.0 blue:238/255\.0 alpha:1\.0\]\];//    \[self\.tbCustomMoneyCards registerNib:\[UINib nibWithNibName:@"CommonStyle3Cell" bundle:nil\] forCellReuseIdentifier:@"CommonStyle3Cell"\];//    \[self\.tbCustomMoneyCards reloadData\];        \[cardPocketSync getNameCards:^\(NSMutableArray<FwNameCardModel \*> \*nameCardList\) \{        self\->watchDataArray = nameCardList;        self\->normalNameArray = \[NSMutableArray new\];        for\(int i=0;i<allNormalNameArray\.count;i\+\+\)\{            if\(\[self isInWatchArr:allNormalNameArray\[i\]\[@"tool\_id"\]\]\)\{                \[self\->normalNameArray addObject:allNormalNameArray\[i\]\];            \}        \}        self\->customNameArray = \[NSMutableArray new\];        if\(\[self isInWatchArr:@"Custom"\]\)\{            \[self\->customNameArray addObject:allCustomNameArray\[0\]\];        \}        \[self resetTableHeight\];        \[self\.tbCards reloadData\];    \}\];    \}\-\(void\)resetTableHeight\{    self\.constarintTable1Height\.constant = 54\*\(normalNameArray\.count \+ customNameArray\.count\) \+ NameCardPocketVC\_footer\_height;\}

<a id="heading_69"></a>__4、发送卡片名字__

\-\(void\)sendNameCards:\(NSArray<TPSNameCardModel\*>\*\) namcCardList

调用举例：

Plain Text

<a id="heading_70"></a>__15\.导航__

<a id="heading_71"></a>__1、发送导航__

\-\(void\)sendBeginNav

调用举例：

Plain Text\-\(void\)onCardPocketBind:\(NSString\*\)type qrCode:\(NSString\*\)qrCode\{    \[self getWalletModel:type\]\.qrCode = qrCode;    \[cardPocketSync sendNameCards:watchDataArray\];    \}\-\(FwNameCardModel\*\)getWalletModel:\(NSString\*\)key\{    for\(int i=0;i<watchDataArray\.count;i\+\+\)\{        if\(\[watchDataArray\[i\]\.company isEqualToString:key\]\)\{            return watchDataArray\[i\];        \}    \}    return nil;\}

<a id="heading_72"></a>__2、发送导航类型__

\-\(void\)sendMapType:\(TPSWearNav\_Map\_Type\)mapType tripMode:\(TPSWearNav\_Trip\_Mode\)tripmMode

调用举例：

Plain Text\-\(void\)navStartEndViewTripTypeSelected:\(NavStartEndView\_Trip\_Type\)tripType\{    self\->tripType = tripType;    \[self startRouteSearch\];    int watchTripType;    if\(tripType == NavStartEndView\_Trip\_Type\_Bike\)\{        watchTripType = 1;    \}else if\(tripType == NavStartEndView\_Trip\_Type\_Ele\_Bike\)\{        watchTripType = 2;    \}else\{        watchTripType = 3;    \}    \[navSync sendMapType:\(FwWearNav\_Map\_Type\)1 tripMode:\(FwWearNav\_Trip\_Mode\)watchTripType\];\}

<a id="heading_73"></a>__3、发送导航方向__

\-\(void\)sendNavDirection:\(TPSWearNav\_Direction\)direction

调用举例：

Plain Text\- \(void\)onRouteGuideKind:\(BMKWalkCycleGuideKind\)guideKind naviType:\(BMKWalkCycleNavigationType\)naviType\{    NSLog\(@"SDK\-诱导kind%lu",\(unsigned long\)guideKind\);    int direction = \[self getGuideKind:guideKind\];    if\(direction \!= 0\)\{        \[navSync sendNavDirection:\(FwWearNav\_Direction\)direction\];    \}\}

<a id="heading_74"></a>__4、发送退出导航__

\-\(void\)sendExitNav

调用举例：

Plain Text\- \(void\)exitWalkCycleNaviView:\(BMKNaviExitType\)exitType naviType:\(BMKWalkCycleNavigationType\)naviType \{    NSLog\(@"SDK\-退出导航"\);    \[navSync sendExitNav\];//    \_\_weak typeof\(self\)weakSelf = self;//    \[TSAlert presentAlertOnVC:self alertTitle:@"" alertContent:kJL\_TXT\("是否确认结束导航？"\) confirm:kJL\_TXT\("确认"\) confirmBlock:^\(id actionValue\) \{//        \_\_strong typeof\(weakSelf\)strongSelf = weakSelf;//        \[strongSelf\->navSync sendExitNav\];//    \} cancel:kJL\_TXT\("取消"\) cancelBlock:^\(id actionValue\) \{//        \_\_strong typeof\(weakSelf\)strongSelf = weakSelf;////        \[strongSelf\->navSync sendBeginNav\];//        \[\[BMKCycleNavigationManager sharedManager\] resume\];//    \}\];\}

<a id="heading_75"></a>__5、发送到达方向__

\-\(void\)sendArriveDestination

调用举例：

Plain Text/\*\* 到达目的地 \*/\- \(void\)onArriveDest:\(BMKWalkCycleNavigationType\)naviType \{    NSLog\(@"SDK到达目的地"\);    \[navSync sendArriveDestination\];\}

<a id="heading_76"></a>__6、发送剩余时间__

\-\(void\)sendRemainTime:\(int\)senconds

调用举例：                                                                                                                                           

Plain Text/\*\* 总的剩余时间  @param remainTime 剩余时间，已经带有单位:（秒） \*/\- \(void\)onRemainTimeUpdate:\(NSString \*\)remainTime naviType:\(BMKWalkCycleNavigationType\)naviType\{    NSLog\(@"SDK\-剩余时间%@",remainTime\);    \[navSync sendRemainTime:\[remainTime intValue\]\];\}

<a id="heading_77"></a>__7、发送剩余距离__

\-\(void\)sendRemainDistance:\(int\)distance

调用举例：

Plain Text/\*\* 总的剩余距离  @param remainDistance 剩余距离，已经带有单位:（米） \*/\- \(void\)onRemainDistanceUpdate:\(NSString \*\)remainDistance naviType:\(BMKWalkCycleNavigationType\)naviType\{    NSLog\(@"SDK\-剩余距离%@",remainDistance\);    \[navSync sendRemainDistance:\[remainDistance intValue\]\];\}

<a id="heading_78"></a>__8、发送导航信息__

\-\(void\)sendNavInfo:\(NSString\*\)info

调用举例：

Plain Text\- \(void\)onPlayTTSText:\(NSString \*\)text prior:\(BOOL\)prior naviType:\(BMKWalkCycleNavigationType\)naviType\{    NSLog\(@"SDK\-tts播放：%@",text\);    if \(isSendToWatch\) \{        \[navSync sendNavInfo:text\];    \}    AVSpeechUtterance \*utterance = \[AVSpeechUtterance speechUtteranceWithString:text\];  //创建语音  Hello World 合成的文本    utterance\.voice = \[AVSpeechSynthesisVoice voiceWithLanguage:@"zh\-CN"\]; //合成英文 嗓音属性    utterance\.rate = 0\.5f;    //  播放速率    utterance\.pitchMultiplier = 0\.8f;  //改变音调    utterance\.postUtteranceDelay = 0\.1f;  //播放下一句是有个短时间的暂停    av = \[\[AVSpeechSynthesizer alloc\] init\];  //运用合成器    \[av speakUtterance:utterance\];            //变成音频输出\}

<a id="heading_79"></a>__9、退出导航__

\-\(RACSubject\*\)observeNavExit

调用举例：

Plain Text\- \(void\)viewDidLoad \{    \[super viewDidLoad\];    isSendToWatch = NO;    \[JLGPSIntensityManager sharedInstance\];//调用会申请gps权限        tripType = NavStartEndView\_Trip\_Type\_Bike;    navSync =  \[FwWearFactory createSingleInstance:@protocol\(IFwNavAbility\)\];    \[self configUI\];    \[self createMapView\];    \[self createSearchToolView2\];    \[self createRecommendView\];    \[\[NSNotificationCenter defaultCenter\] addObserver:self selector:@selector\(applicationBecomeActive\) name:UIApplicationDidBecomeActiveNotification object:nil\];        navExitRacDispose = \[\[\[FwSdk share\]\.navAbility observeNavExit\] subscribeNext:^\(id  \_Nullable x\) \{        \[\[BMKCycleNavigationManager sharedManager\] exitCycleNomalNavi\];        \[\[BMKWalkNavigationManager sharedManager\] exitWalkNomalNavi\];    \}\];\}

<a id="heading_80"></a>__16\.电子书__

<a id="heading_81"></a>__1、获取书本集__

\-\(void\)getBookList:\(TPSEleBookListCallback\)block

调用举例：

Plain Text\-\(void\)getBookListFromDev\{    \[ebookSync getBookList:^\(NSArray<FwEBookModel \*> \*bookList\) \{        if\(bookList==nil || bookList\.count==0\)\{            self\.imgNoData\.hidden = NO;            self\.lbNoData\.hidden = NO;            self\.scrollBookListContainer\.hidden = YES;            self\.btnFinish\.hidden = YES;            self\->isEditing = NO;            self\.btnAdd\.enabled = YES;        \}else\{            self\.imgNoData\.hidden = YES;            self\.lbNoData\.hidden = YES;            self\.scrollBookListContainer\.hidden = NO;            self\->dataArray = \[bookList mutableCopy\];            \[self refreshTableData\];        \}    \}\];\}\#pragma mark \- 加载数据\-\(void\)refreshTableData\{    \[self\->subCollectView reloadData\];    \[subCollectView\.mj\_header endRefreshing\];\}

<a id="heading_82"></a>__2、导入电子书到设备__

\-\(void\)pushBookToDev:\(NSString\*\)phoneFilePath fileName:\(NSString\*\)fileName block:\(onTPSProgressResult\)block

调用举例：

Plain Text\-\(void\)startTransfer:\(NSString\*\)fileName\{    \[self convertToUTF16LE:fileName\];    transferFileName = fileName;    progress = \[\[EbookProgressView alloc\] initAndLoadNib\];    progress\.delegate = self;    \[self\.view addSubview:progress\];    \[progress mas\_makeConstraints:^\(MASConstraintMaker \*make\) \{        make\.leading\.mas\_equalTo\(0\);        make\.trailing\.mas\_equalTo\(0\);        make\.bottom\.mas\_equalTo\(0\);        make\.top\.mas\_equalTo\(0\);    \}\];    \[progress showProgress\];    progress\.lbBookName\.text = fileName;    NSString \*filePath = \[JL\_Tools findPath:NSDocumentDirectory MiddlePath:@"ebook" File:fileName\];    \[ebookSync pushBookToDev:filePath fileName:fileName block:^\(FwProgressModel \*model\) \{        if\(model\.eventType == FwProgressModel\_Event\_Type\_OnSuccess\)\{            \[DFUITools showText:kJL\_TXT\("文件传输成功"\) onView:self\.view delay:1\.0\];        \}else if\(model\.eventType == FwProgressModel\_Event\_Type\_OnFailed\)\{            self\->progress\.lbTipInfo\.text = kJL\_TXT\("文件传输失败"\);        \}else if\(model\.eventType == FwProgressModel\_Event\_Type\_OnProcess\)\{            self\->progress\.percent = model\.percent;        \}else if\(model\.eventType == FwProgressModel\_Event\_Type\_OnCompleted\)\{            \[self\->progress removeFromSuperview\];            \[self getBookListFromDev\];        \}    \}\];\}

<a id="heading_83"></a>__3、取消导入__

\-\(void\)cancelPush:\(NSString\*\)fileName

调用举例：

Plain Text

<a id="heading_84"></a>__4、删除设备上的电子书__

\-\(void\)delBookOnDev:\(NSString\*\)fileName block:\(TPSSendMsgResult\)block

调用举例：

Plain Text\-\(void\)onDelClick:\(UIButton\*\)btn\{    NSString \*message = kJL\_TXT\("是否删除手表中的电子书?"\);    UIAlertController \*alert = \[UIAlertController alertControllerWithTitle:kJL\_TXT\(""\) message:message preferredStyle:UIAlertControllerStyleAlert\];    UIAlertAction \*cancelAction = \[UIAlertAction actionWithTitle:kJL\_TXT\("取消"\) style:UIAlertActionStyleCancel handler:^\(UIAlertAction \* \_Nonnull action\) \{            \}\];        UIAlertAction \*confirmAction = \[UIAlertAction actionWithTitle:kJL\_TXT\("确定"\) style:UIAlertActionStyleDefault handler:^\(UIAlertAction \* \_Nonnull action\) \{        \[self\->ebookSync delBookOnDev:self\->dataArray\[btn\.tag\]\.bookName block:^\(BOOL isSendOK\) \{            \[DFUITools showText:kJL\_TXT\("删除完毕"\) onView:self\.view delay:0\.8\];            \[self getBookListFromDev\];        \}\];    \}\];        \[alert addAction:confirmAction\];    \[alert addAction:cancelAction\];    \[self presentViewController:alert animated:YES completion:nil\];\}

<a id="heading_85"></a>__17\.文件操作__

<a id="heading_86"></a>__1、获取文件夹和手表文件路径__

\-\(void\)getDevFileListWithWatchFilePath:\(NSString\*\)watchFilePath block:\(TPSFileListCallback\)block

调用举例：

Plain Text

<a id="heading_87"></a>__2\.从本地路径导入文件到设备__

\-\(void\)pushFileToDevWithLocalPath:\(NSString\*\)localPath remotePath:\(NSString\*\)remotePath block:\(onTPSProgressResult\)block

调用举例：

Plain Text\- \(void\)beginPushZipToWatch:\(NSString \*\)zipPath dial:\(NSString \*\)dialName\{        \_\_weak typeof\(self\)weakSelf = self;    \[self\.pusToWatchButton beginAnimation\];    \[\[FwSdk share\]\.fileAbility pushFileToDevWithLocalPath:zipPath remotePath:\[TSDialFilePath watchZipPath\] block:^\(FwProgressModel \*model\) \{        \_\_strong typeof\(weakSelf\)strongSelf = weakSelf;        if \(model\.eventType == FwProgressModel\_Event\_Type\_OnProcess\) \{            \[strongSelf updateProcess:model\.percent\];        \}else if \(model\.eventType == FwProgressModel\_Event\_Type\_OnSuccess\) \{            // save dial name            \[strongSelf sendInstructionsToWatch:dialName\];        \}else if \(model\.eventType == FwProgressModel\_Event\_Type\_OnFailed\)\{            \[strongSelf pushFailed\];        \}    \}\];\}

<a id="heading_88"></a>__3、删除文件夹中的文件__

\-\(void\)delFileWithFolder:\(NSString\*\)watchFolder fileName:\(NSString\*\)fileName block:\(TPSSendMsgResult\)block

调用举例：

Plain Text

<a id="heading_89"></a>__4、删除整个文件__

\-\(void\)delFileWithWholePath:\(NSString\*\)wholePath block:\(TPSSendMsgResult\)block

调用举例：

Plain Text

<a id="heading_90"></a>__5、取消导入文件名字__

\-\(void\)cancelPushWithFileName:\(NSString\*\)fileName

调用举例：

Plain Text\-\(void\)onCancelTransfer:\(UIView\*\)sender\{    \[progress removeFromSuperview\];    id<IFwFileAbility> tmpFileSync = \[FwWearFactory createSingleInstance:@protocol\(IFwFileAbility\)\];    \[tmpFileSync cancelPushWithFileName:transferFileName\];\}

<a id="heading_91"></a>__6、获取设备文件夹与手表文件路径__

\-\(void\)getDevFileTreeWithWatchFilePath:\(NSString\*\)watchFilePath block:\(TPSFileListCallback\)block

调用举例：

Plain Text

<a id="heading_92"></a>__7、在修改之前通知设备__

\-\(void\)notifyDevAfterUpdate:\(TPSFileUpdateModel\*\)model remoteAppId:\(NSString\*\)remoteAppId

调用举例：

Plain Text

<a id="heading_93"></a>__8、获取目录大小__

\-\(void\)getDirSizeInfo:\(NSString\*\)remoteFolder block:\(TPSFileSizeCallback\)block

调用举例：

Plain Text\- \(void\)fetchResidualSpace:\(dispatch\_group\_t\)group\{    dispatch\_group\_enter\(group\);    \_\_weak typeof\(self\)weakSelf = self;    \[self\.fileync getDirSizeInfo:@"/data/share/com\.realthread\.LocalMusic/music/" block:^\(float sizeInByte\) \{        \_\_strong typeof\(weakSelf\)strongSelf = weakSelf;        strongSelf\.residualSpace = \(sizeInByte/1024/1024\);        dispatch\_group\_leave\(group\);    \}\];\}

<a id="heading_94"></a>__18\.闹钟__

<a id="heading_95"></a>__1、获取所有闹钟__

\-\(void\)getAlarmList:\(TPSAlarmListCallback\)block

调用举例：

Plain Text\-\(void\)initWithData\{    titleHeight\.constant = kJL\_HeightNavBar\+10;    titleLab\.text = kJL\_TXT\("闹钟"\);    alarmSync = \[FwWearFactory createSingleInstance:@protocol\(IFwAlarmAbility\)\];    if\(self\->alarmTable == nil\)\{        self\->alarmTable = \[\[UITableView alloc\] initWithFrame:CGRectMake\(16, kJL\_HeightNavBar\+20, \[DFUITools screen\_2\_W\]\-16\*2, self\->itemArray\.count\*AlarmClockVC\_Table\_Height\)\];    \}    self\->alarmTable\.dataSource = self;    self\->alarmTable\.delegate = self;    self\->alarmTable\.rowHeight = AlarmClockVC\_Table\_Height;    self\->alarmTable\.separatorColor = kDF\_RGBA\(247\.0, 247\.0, 247\.0, 1\.0\);    self\->alarmTable\.layer\.cornerRadius = 15;    self\->alarmTable\.tableFooterView = \[UIView new\];    self\->alarmTable\.backgroundColor = \[UIColor whiteColor\];    \[self\->alarmTable registerNib:\[UINib nibWithNibName:@"AlarmClockCell" bundle:nil\] forCellReuseIdentifier:@"AlarmClockCell"\];    self\->syncDateBtn\.layer\.cornerRadius = 25\.0;    self\->syncDateBtn\.layer\.masksToBounds = YES;    \[self\.view addSubview:self\->alarmTable\];        \[alarmSync getAlarmList:^\(NSArray<FwAlarmModel \*> \* \_Nullable alarmList\) \{        if\(\!alarmList\)\{            \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self\.view delay:1\.5\];            return;        \}        self\->itemArray = \[alarmList mutableCopy\];        \[self\->alarmTable reloadData\];        if\(self\->watchLabel == nil\)\{            self\->watchLabel = \[\[UILabel alloc\] init\];        \}        \[self refreshTableFrame\];        self\->watchLabel\.font = \[UIFont fontWithName:@"PingFangSC" size:14\];        self\->watchLabel\.textColor = kDF\_RGBA\(114\.0, 114\.0, 114\.0, 1\.0\);        self\->watchLabel\.text = kJL\_TXT\("设置好闹钟，同步到手表后，手表将会震动提醒您。您最多可以设置5个闹钟。"\);        \[self\.view addSubview:self\->watchLabel\];                if\(self\->itemArray\.count==0\)\{            self\->watchLabel\.hidden = YES;        \}else\{            self\->watchLabel\.hidden = NO;        \}    \}\];\}

<a id="heading_96"></a>__2、发送所有闹钟__

\-\(void\)sendAlarmList:\(NSArray<TPSAlarmModel\*>\*\)alarmList block:\(TPSSendMsgResult\)block

调用举例：

Plain Text\-\(void\)sendDataToDevice\{    if\(isBusy\)\{        return;    \}    isBusy = YES;    id<IFwAlarmAbility> alarmSync = \[FwWearFactory createSingleInstance:@protocol\(IFwAlarmAbility\)\];    \[alarmSync sendAlarmList:\_alarmEntityList block:^\(BOOL isSendOK\) \{        self\->isBusy = NO;        if\(isSendOK\)\{            if\(self\.delegate && \[self\.delegate respondsToSelector:@selector\(didChangeAlarmAction:\)\]\)\{                \[self\.delegate didChangeAlarmAction:self\.alarmEntityList\];            \}            \[self\.navigationController  popViewControllerAnimated:YES\];        \}else\{            \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self\.view delay:1\.5\];        \}    \}\];\}

<a id="heading_97"></a>__3、观察闹钟变化__

\-\(RACSubject\*\)observeAlarmChange

调用举例：

Plain Text\- \(void\)initData \{    self\.alarmAbility = \[FwWearFactory createSingleInstance:@protocol\(IFwAlarmAbility\)\];    self\.alarmModels = \[NSMutableArray new\];    self\.cellModels = \[NSMutableArray new\];    \[self updateAlarmList\];    @weakify\(self\)    \[\[\[self\.alarmAbility observeAlarmChange\] throttle:0\.5\] subscribeNext:^\(id  \_Nullable x\) \{               @strongify\(self\)        \[self updateAlarmList\];    \}\];\}/// 更新闹钟列表\- \(void\)updateAlarmList \{    \[self\.alarmAbility getAlarmList:^\(NSArray<FwAlarmModel \*> \* \_Nullable alarmList\) \{                \[self\.alarmModels removeAllObjects\];        \[self\.cellModels removeAllObjects\];        \[self\.alarmModels addObjectsFromArray:alarmList\];        // 生成cellModels        \[self\.alarmModels enumerateObjectsUsingBlock:^\(FwAlarmModel \* \_Nonnull obj, NSUInteger idx, BOOL \* \_Nonnull stop\) \{                        \[self\.cellModels addObject:\[self getCellModelWithAlarmModel:obj\]\];        \}\];        self\.cellModels = self\.cellModels;//手动出发监听    \}\];\}

<a id="heading_98"></a>__19\.杂项设置__

<a id="heading_99"></a>__1、获取所有设置地址__

\-\(void\)getAllMiscSetting:\(TPSMiscSettingCallback\)block

调用举例：

Plain Text\-\(void\)start\{    miscSettingSync = \[FwWearFactory createSingleInstance:@protocol\(IFwMiscSettingAbility\)\];    \[miscSettingSync getAllMiscSetting:^\(FwMiscSettingModel \*miscSettingModel\) \{        self\->\_hasData = YES;        self\->\_target\_drink\_warn = miscSettingModel\.target\_drink\_warn;        self\->\_target\_sit\_warn = miscSettingModel\.target\_sit\_warn;        self\->\_ht\_health\_enhanced = miscSettingModel\.ht\_health\_enhanced;        self\->\_ht\_sleep\_allDay = miscSettingModel\.ht\_sleep\_allDay;        self\->\_system\_timing\_method = miscSettingModel\.system\_timing\_method;        self\->\_weather\_temp\_unit = miscSettingModel\.weather\_temp\_unit==FwMiscSettingModel\_Temperature\_Unit\_C ? @"C" : @"F";        self\->\_sport\_sportUnit = miscSettingModel\.sport\_sportUnit;        self\->\_habit\_wear\_hand = miscSettingModel\.habit\_wear\_hand;        self\->\_screen\_raise\_to\_wake = miscSettingModel\.screen\_raise\_to\_wake;        self\->\_weather\_sync\_mode = miscSettingModel\.weather\_sync\_mode;        self\->\_bloodoxygen\_auto\_mode = miscSettingModel\.bloodoxygen\_auto\_mode;        self\->\_heartrate\_auto\_mode = miscSettingModel\.heartrate\_auto\_mode;        self\->\_heartRateSettingData = \[HeartRateSettingData configeWithinfo:miscSettingModel\.heartrate\_config\];    \}\];\}

<a id="heading_100"></a>__2、发送饮水目标的警告__

\-\(void\)sendTarget\_drink\_warn:\(TPSMiscSettingModel\_State\)target\_drink\_warn

调用举例：

Plain Text\-\(void\)setTarget\_drink\_warn:\(int\)target\_drink\_warn\{    self\->\_target\_drink\_warn = target\_drink\_warn;    \[miscSettingSync sendTarget\_drink\_warn:target\_drink\_warn\];\}

<a id="heading_101"></a>__3、发送站立警告__

\-\(void\)sendTarget\_sit\_warn:\(TPSMiscSettingModel\_State\)target\_sit\_warn

调用举例：

Plain Text\-\(void\)setTarget\_sit\_warn:\(int\)target\_sit\_warn\{    self\->\_target\_sit\_warn = target\_sit\_warn;    \[miscSettingSync sendTarget\_sit\_warn:target\_sit\_warn\];\}

<a id="heading_102"></a>__4、发送心率健康的高预警__

\-\(void\)sendHt\_health\_enhanced:\(TPSMiscSettingModel\_State\)ht\_health\_enhanced

调用举例：

Plain Text\-\(void\)setHt\_health\_enhanced:\(int\)ht\_health\_enhanced\{    self\->\_ht\_health\_enhanced = ht\_health\_enhanced;    \[miscSettingSync sendHt\_health\_enhanced:ht\_health\_enhanced\];\}

<a id="heading_103"></a>__5、发送所有天的睡眠中的心率__

\-\(void\)sendHt\_sleep\_allDay:\(TPSMiscSettingModel\_State\)ht\_sleep\_allDay

调用举例：

Plain Text\-\(void\)setHt\_sleep\_allDay:\(int\)ht\_sleep\_allDay\{    self\->\_ht\_sleep\_allDay = ht\_sleep\_allDay;    \[miscSettingSync sendHt\_sleep\_allDay:ht\_sleep\_allDay\];\}

<a id="heading_104"></a>__6、发送系统的方法时机__

\-\(void\)sendSystem\_timing\_method:\(TPSMiscSettingModel\_Time\_Format\)system\_timing\_method

调用举例：

Plain Text\-\(void\)setSystem\_timing\_method:\(int\)system\_timing\_method\{    self\->\_system\_timing\_method = system\_timing\_method;    \[miscSettingSync sendSystem\_timing\_method:system\_timing\_method\];\}

<a id="heading_105"></a>__7、发送天气的临时单位__

\-\(void\)sendWeather\_temp\_unit:\(TPSMiscSettingModel\_Temperature\_Unit\)weather\_temp\_unit

调用举例：

Plain Text\-\(void\)setWeather\_temp\_unit:\(NSString\*\)weather\_temp\_unit\{    self\->\_weather\_temp\_unit = weather\_temp\_unit;    FwMiscSettingModel\_Temperature\_Unit unit = \[weather\_temp\_unit isEqualToString:@"C"\] ? FwMiscSettingModel\_Temperature\_Unit\_C : FwMiscSettingModel\_Temperature\_Unit\_F;    \[miscSettingSync sendWeather\_temp\_unit:\(unit\)\];\}

<a id="heading_106"></a>__8、发送运动的单位__

\-\(void\)sendSport\_sportUnit:\(TPSMiscSettingModel\_System\_Unit\)sport\_sportUnit

调用举例：

Plain Text\-\(void\)setSport\_sportUnit:\(int\)sport\_sportUnit\{    self\->\_sport\_sportUnit = sport\_sportUnit;    \[miscSettingSync sendSport\_sportUnit:sport\_sportUnit\];\}

<a id="heading_107"></a>__9、发送佩戴的习惯__

\-\(void\)sendHabit\_wear\_hand:\(TPSMiscSettingModel\_Wear\_Hand\)habit\_wear\_hand

调用举例：

Plain Text\-\(void\)setHabit\_wear\_hand:\(int\)habit\_wear\_hand\{    self\->\_habit\_wear\_hand = habit\_wear\_hand;    \[miscSettingSync sendHabit\_wear\_hand:habit\_wear\_hand\];\}

<a id="heading_108"></a>__10、发送屏幕提高之后__

\-\(void\)sendScreen\_raise\_to\_wake:\(TPSMiscSettingModel\_State\)screen\_raise\_to\_wake

调用举例：

Plain Text\-\(void\)setScreen\_raise\_to\_wake:\(int\)screen\_raise\_to\_wake\{    self\->\_screen\_raise\_to\_wake = screen\_raise\_to\_wake;    \[miscSettingSync sendScreen\_raise\_to\_wake:screen\_raise\_to\_wake\];\}

<a id="heading_109"></a>__11、发送天气同步的模式__

\-\(void\)sendWeather\_sync\_mode:\(TPSMiscSettingModel\_State\)weather\_sync\_mode

调用举例：

Plain Text\-\(void\)setWeather\_sync\_mode:\(int\)weather\_sync\_mode\{    self\->\_weather\_sync\_mode = weather\_sync\_mode;    \[miscSettingSync sendWeather\_sync\_mode:weather\_sync\_mode\];\}

<a id="heading_110"></a>__12自动发送血氧模式__

\-\(void\)sendBloodoxygen\_auto\_mode:\(TPSMiscSettingModel\_State\)bloodoxygen\_auto\_mode

调用举例：

Plain Text\-\(void\)setBloodoxygen\_auto\_mode:\(int\)bloodoxygen\_auto\_mode\{    self\->\_bloodoxygen\_auto\_mode = bloodoxygen\_auto\_mode;    \[miscSettingSync sendBloodoxygen\_auto\_mode:bloodoxygen\_auto\_mode\];\}

<a id="heading_111"></a>__13、自动发送心率模式__

\-\(void\)sendHeartrate\_auto\_mode:\(TPSMiscSettingModel\_State\)heartrate\_auto\_mode

调用举例：

Plain Text\-\(void\)setHeartrate\_auto\_mode:\(int\)heartrate\_auto\_mode\{    self\->\_heartrate\_auto\_mode = heartrate\_auto\_mode;    \[miscSettingSync sendHeartrate\_auto\_mode:heartrate\_auto\_mode\];\}

<a id="heading_112"></a>__14、发送用户名字__

\-\(void\)sendUserNickName:\(NSString\*\)nickName

调用举例：

Plain Text\-\(void\)syncUnitAndUserProfile\{    id<IFwMiscSettingAbility> miscSettingSync = \[FwWearFactory createSingleInstance:@protocol\(IFwMiscSettingAbility\)\];    \[miscSettingSync sendUserNickName:\[HOETool getNickname\]\];    if\(\[\[HOETool getTemperatureUnit\] isEqualToString:@"C"\]\)\{        \[miscSettingSync sendWeather\_temp\_unit:\(FwMiscSettingModel\_Temperature\_Unit\_C\)\];    \}else\{        \[miscSettingSync sendWeather\_temp\_unit:\(FwMiscSettingModel\_Temperature\_Unit\_F\)\];    \}    if\(\[HOETool isMetricSystem\]\)\{        \[miscSettingSync sendSport\_sportUnit:\(MiscSettingModel\_TSFW\_Sport\_Unit\_Metric\_System\)\];    \}else\{        \[miscSettingSync sendSport\_sportUnit:\(MiscSettingModel\_TSFW\_Sport\_Unit\_British\_System\)\];    \}    \}

<a id="heading_113"></a>__15、发送心率警报__

\-\(void\)sendHt\_sos:\(TPSMiscSettingModel\_State\)ht\_sos

调用举例：

Plain Text

<a id="heading_114"></a>__16、发送心率值__

\- \(void\)sendHeartRateValue:\(NSDictionary \*\)value complete:\(void\(^\)\(BOOL isSendOK\)\)complete

调用举例：

Plain Text\- \(void\)setHeartRateSettingData:\(HeartRateSettingData \*\)heartRateSettingData complete:\(void\(^\)\(BOOL isSendOK\)\)complete\{    self\->\_heartRateSettingData = heartRateSettingData;    \[miscSettingSync sendHeartRateValue:\[self\->\_heartRateSettingData heartRateDict\]  complete:^\(BOOL isSendOK\) \{        complete\(isSendOK\);    \}\];\}

<a id="heading_115"></a>__17、发送设备的数据__

\-\(void\)sendDataToDevice:\(NSDictionary\*\)dic complete:\(void\(^\)\(BOOL isSendOK\)\)complete

调用举例：

Plain Text\-\(void\)sendDataToDevice\{    /\*改成自定义协议后不用此段    NSMutableArray <JLwSettingModel \*>\* models = \[NSMutableArray new\];        WatchTimer \*startTimer = \[\[WatchTimer alloc\] initWith:startHour Min:startMin\];    WatchTimer \*endTimer = \[\[WatchTimer alloc\] initWith:endHour Min:endMin\];    JLSedentaryRmdModel \*model1 = \[\[JLSedentaryRmdModel alloc\] initWithModel:WatchRemind\_BrightScreen Status:switch1\.on DoNotDisturb:switch2\.on Begin:startTimer End:endTimer\];    \[models addObject:model1\];        JLWearable \*w = \[JLWearable sharedInstance\];    \[w w\_SettingDeviceFuncWith:models withEntity:kJL\_BLE\_EntityM result:^\(BOOL succeed\) \{    \}\];\*/    int statusCode = switch1\.on ? 1 : 0;    int noonNotDisturb = switch2\.on ? 1 : 0;    \[HOETool setJiuzuoRemindData:statusCode startHour:startHour startMin:startMin endHour:endHour endMin:endMin noonNotDisturb:noonNotDisturb\];    \[\[HOECmdCustomManager shareInstance\] sendJiuzuoRemind:statusCode startHour:startHour startMin:startMin endHour:endHour endMin:endMin noonNotDisturb:noonNotDisturb\];\}

<a id="heading_116"></a>__20\.OTA__

<a id="heading_117"></a>__1、修改本地路径__

\-\(void\)otaUpdateWithLocalPath:\(NSString\*\)localPath block:\(onTPSProgressResult\)block

调用举例：

Plain Text\-\(void\)pushOtaPackage\{    NSString \*filePath = \[JL\_Tools findPath:NSLibraryDirectory MiddlePath:@"webLoader" File:fileName\];    if\(fileName==nil || filePath == nil\)\{        \[DFUITools showText:@"请先上传文件" onView:self\.view delay:2\.0\];        return;    \}    NSLog\(@"pushOtaPackage filePath %@",filePath\);    id<IFwOTAAbility> otaSync = \[FwWearFactory createSingleInstance:@protocol\(IFwOTAAbility\)\];    \[otaSync otaUpdateWithLocalPath:filePath block:^\(FwProgressModel \*model\) \{        if\(model\.eventType == FwProgressModel\_Event\_Type\_OnSuccess\)\{            \[self\->checkOrUpdateBtn setEnabled:NO\];            \[self\->checkOrUpdateBtn setTitle:kJL\_TXT\("传输完毕,请等待手表自动重启"\) forState:UIControlStateNormal\];            self\->tipInfoLabel\.text = kJL\_TXT\("传输完毕,请等待手表自动重启"\);            NSLog\(@"TSOtaUpdateVC 文件传输成功\!"\);        \}else if \(model\.eventType == FwProgressModel\_Event\_Type\_OnFailed\)\{            self\->isBusy = NO;            \[DFUITools showText:kJL\_TXT\("设备响应超时"\) onView:self\.view delay:1\.5\];            NSLog\(@"TSOtaUpdateVC 文件传输失败\!"\);        \}else if \(model\.eventType == FwProgressModel\_Event\_Type\_OnProcess\)\{            self\->progressView\.percent = model\.percent;            NSLog\(@"TSOtaUpdateVC pushOtaPackage trans,process:%\.2f,total", model\.percent\);        \}    \}\];\}

<a id="heading_118"></a>__21\.音乐__

<a id="heading_119"></a>__1、获取音乐集__

\-\(void\)getMusicListWithblock:\(TPSMusicListCallback\)block

调用举例：

Plain Text\-\(void\)getDevMusicList\{    \[musicSync getMusicListWithblock:^\(NSArray<FwMusicModel \*> \*musicList\) \{        if\(musicList\)\{            self\->entities = \[NSMutableArray new\];            for\(int i=0;i<musicList\.count;i\+\+\)\{                \[self\->entities addObject:@\{@"fileName":musicList\[i\]\.fileName\}\];            \}            \[self\->mindListView setMusicList:self\->entities\];            self\->musicCountInfo\.secondTitle = \[NSString stringWithFormat:@"%@%lu%@",kJL\_TXT\("已有"\),self\->entities\.count,kJL\_TXT\("首"\)\];        \}else\{            \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self\.view delay:2\.0\];        \}    \}\];\}

<a id="heading_120"></a>__2、从手机文件路径导入音乐__

\-\(void\)pushMusicToDevWithPhoneFilePath:\(NSString\*\)phoneFilePath remoteFileName:\(NSString\*\)remoteFileName block:\(onTPSProgressResult\)block

调用举例：

Plain Text\- \(void\)uploadSong:\(TSMusicModel \*\)song\{    \_\_weak typeof\(self\)weakSelf = self;    \[self\.musicSync pushMusicToDevWithPhoneFilePath:\[self filePathWithName:song\.musicName\] remoteFileName:song\.musicName block:^\(FwProgressModel \*model\) \{        \_\_strong typeof\(weakSelf\)strongSelf = weakSelf;        if\(model\.eventType == FwProgressModel\_Event\_Type\_OnSuccess\)\{            NSLog\(@"文件传输成功\!"\);            song\.uploadResult = eTSMusicUploadResultSuccess;            if \(strongSelf\.uploadSuccessBlock\) \{strongSelf\.uploadSuccessBlock\(song\);\}        \}else if\(model\.eventType == FwProgressModel\_Event\_Type\_OnFailed\)\{            NSLog\(@"文件传输失败\!"\);            song\.uploadResult = eTSMusicUploadResultFailed;        \}else if\(model\.eventType == FwProgressModel\_Event\_Type\_OnProcess\)\{            NSLog\(@"file trans,process:%\.2f,total", model\.percent\);            if \(strongSelf\.uploadProgressBlock\) \{strongSelf\.uploadProgressBlock\(model\.percent\);\}        \}else if\(model\.eventType == FwProgressModel\_Event\_Type\_OnCompleted \)\{            //eTSMusicUploadStateCancled 主动取消，则不触发completeBlock            if \(strongSelf\.uploadState == eTSMusicUploadStateCancled\) \{                // 删除当前文件            \}else\{                strongSelf\.uploadIndex\+\+;                if \(strongSelf\.uploadIndex>=strongSelf\.needUploadArray\.count\) \{                    \[strongSelf uploadFinished\];                \}else\{                    \[strongSelf uploadNextSong\];                \}            \}        \}    \}\];\}

<a id="heading_121"></a>__3、通过文件名删除音乐__

\-\(void\)delMusicWithFileName:\(NSString\*\)fileName block:\(TPSSendMsgResult\)block

调用举例：

Plain Text\-\(void\)tableView:\(UITableView \*\)tableView commitEditingStyle:\(UITableViewCellEditingStyle\)editingStyle forRowAtIndexPath:\(nonnull NSIndexPath \*\)indexPath\{    if \(editingStyle == UITableViewCellEditingStyleDelete\)\{        deleteIndex = indexPath\.row;        \[musicSync delMusicWithFileName:dataArray\[indexPath\.row\]\[@"fileName"\] block:^\(BOOL isSendOK\) \{            if\(isSendOK\)\{                \[self\->dataArray removeObjectAtIndex:self\->deleteIndex\];                \[self\->\_listTable reloadData\];                if \(\[self\.delegate respondsToSelector:@selector\(deleteOneMucis\)\]\) \{                    \[self\.delegate deleteOneMucis\];                \}            \}else\{                \[self\->\_listTable reloadData\];                \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self delay:2\.0\];            \}        \}\];     \}\}

<a id="heading_122"></a>__4、取消上传文件夹导入音乐中的操作__

\-\(void\)cancelPushMusicWithFileName:\(NSString\*\)fileName

调用举例：

Plain Text\- \(void\)stopUploading\{    if \(\_uploadState == eTSMusicUploadStateUploading &&        \_uploadingFileName && \_uploadingFileName\.length>0\) \{        \_uploadState = eTSMusicUploadStateCancled;        \[self\.musicSync cancelPushMusicWithFileName:\_uploadingFileName\];        \_uploadingFileName = nil;        \_uploadIndex = 0;        if \(self\.uploadCancledBlock\) \{self\.uploadCancledBlock\(\[self needUploadArray\]\);\}    \}\}

<a id="heading_123"></a>__22\.运动目标__

<a id="heading_124"></a>__1、获取运动目标__

\-\(void\)getSportTargets:\(TPSSportTargetCallback\)block

调用举例：

Plain Text\-\(void\)syncSportTargets\{    id<IFwSportTargetAbility> sportTargetSync = \[FwWearFactory createSingleInstance:@protocol\(IFwSportTargetAbility\)\];    \[sportTargetSync getSportTargets:^\(FwSportTargetModel \*sportTargetModel\) \{        if\(sportTargetModel\.modifyTime > \[HOETool getTargetModifyTime\]\)\{            \[HOETool setCaloriesGoal:sportTargetModel\.calorie\];            \[HOETool setDistanceGoal:sportTargetModel\.distance\];            \[HOETool setTargetModifyTime:sportTargetModel\.modifyTime\];            \[HOETool setActivityDurationGoal:sportTargetModel\.stand\_time\];            \[HOETool setStepGoal:sportTargetModel\.steps\];            \[HOETool setSportTimeGoal:sportTargetModel\.sport\_time\];            \[HOETool setActivityCountGoal:sportTargetModel\.sport\_num\];        \}else\{            FwSportTargetModel\* model = \[\[FwSportTargetModel alloc\] init\];            model\.calorie = \(\(int\)\[HOETool getCaloriesGoal\]\);            model\.distance = \(\[HOETool getDistanceGoal\]\);            model\.stand\_time = \(\[HOETool getActivityDurationGoal\]\);            model\.steps = \[HOETool getStepGoal\];            model\.sport\_time = \[HOETool getSportTimeGoal\];            model\.sport\_num = \[HOETool getActivityCountGoal\];            model\.modifyTime = \[HOETool getTargetModifyTime\];            \[sportTargetSync sendSportTargets:model block:^\(BOOL isSendOK\) \{                                \}\];        \}    \}\];\}

<a id="heading_125"></a>__2、发送运动目标__

\-\(void\)sendSportTargets:\(TPSSportTargetModel\*\)sportTargetModel block:\(TPSSendMsgResult\)block

调用举例：

Plain Text\-\(void\)sendDataToDev\{    id<IFwSportTargetAbility> sportTargetSync = \[FwWearFactory createSingleInstance:@protocol\(IFwSportTargetAbility\)\];    FwSportTargetModel\* model = \[\[FwSportTargetModel alloc\] init\];    model\.calorie = \(\(int\)\[HOETool getCaloriesGoal\]\);    model\.distance = \(\[HOETool getDistanceGoal\]\);    model\.stand\_time = \(\[HOETool getActivityDurationGoal\]\);    model\.steps = \[HOETool getStepGoal\];    model\.sport\_time = \[HOETool getSportTimeGoal\];    model\.sport\_num = \[HOETool getActivityCountGoal\];    model\.modifyTime = \[HOETool getTargetModifyTime\];    \[sportTargetSync sendSportTargets:model block:^\(BOOL isSendOK\) \{                \}\];\}

<a id="heading_126"></a>__23\.天气__

<a id="heading_127"></a>__1、发送天气__

\-\(void\)sendWeather:\(TPSWeatherModel\*\)weatherModel block:\(TPSSendMsgResult\)block

调用举例：

Plain Text\-\(void\)sendWeatherToDev2\{    NSLog\(@"开始给手表发天气"\);    NSMutableArray<FwFutureDayWeatherModel\*>\* preDays = \[NSMutableArray new\];    int firstDayMaxTemp;    int firstDayMinTemp;        for\(int i=0;i<next7DayArr\.count;i\+\+\)\{        NSDate\* d = \[NSDate dateWtihString:\[NSString stringWithFormat:@"%@ 00:00:00",next7DayArr\[i\]\[@"time"\]\]\];        FwFutureDayWeatherModel\* futureDay = \[\[FwFutureDayWeatherModel alloc\] initWithTimestamp:\[d timeIntervalSince1970\] describe:\[self getDesTypeWithCode:\[next7DayArr\[i\]\[@"code"\] intValue\]\] minTemperature:\[next7DayArr\[i\]\[@"tempMin"\] intValue\] maxTemperature:\[next7DayArr\[i\]\[@"tempMax"\] intValue\]\];        \[preDays addObject:futureDay\];        if\(i == 0\)\{            firstDayMinTemp = \[next7DayArr\[i\]\[@"tempMin"\] intValue\];            firstDayMaxTemp = \[next7DayArr\[i\]\[@"tempMax"\] intValue\];        \}    \}        NSMutableArray<FwFutureHourWeatherModel\*>\* hours = \[NSMutableArray new\];    for \(NSDictionary \*hourInfo in future\_hours\) \{        NSString \*dateString = \[NSDate dateStringFormateUTCDate:hourInfo\[@"time"\]\];        NSDate\* date = \[NSDate dateWtihString:dateString\];        NSTimeInterval stamp = \[date timeIntervalSince1970\];        FwFutureHourWeatherModel\* hourWeather = \[\[FwFutureHourWeatherModel alloc\] initWithTimestamp:stamp describe:\[self getDesTypeWithCode:\[hourInfo\[@"code"\] intValue\]\] temperature:\[hourInfo\[@"temp"\] intValue\]\];        \[hours addObject:hourWeather\];    \}        FwTodayWeatherModel\* todayWeather = \[\[FwTodayWeatherModel alloc\] initWithCurTemperature:\[currentDic\[@"temp"\] intValue\] minTemperature:firstDayMinTemp maxTemperature:firstDayMaxTemp airpressure:airpressure wind:wind windAngle:wind\_angle windSpeed:wind\_speed humidity:humidity futureHourList:hours\];        FwWeatherModel\* weatherModel = \[\[FwWeatherModel alloc\] initWithCity:cityName temperatureUnit:\(FwMiscSettingModel\_Temperature\_Unit\_C\) updateTime:currentTime todayWeather:todayWeather futureDayWeather:preDays\];        \[weatherSync sendWeather:weatherModel block:^\(BOOL isSendOK\) \{        if\(isSendOK\)\{            NSLog\(@"传输天气连接成功"\);        \}else\{            NSLog\(@"传输天气连接失败"\);        \}    \}\];\}

<a id="heading_128"></a>__24\.表盘__

<a id="heading_129"></a>__1、通过本地路径导入表盘__

\-\(void\)pushDialWithLocalPath:\(NSString\*\)localPath dialId:\(NSString\*\)dialId block:\(TPSDialProgressCallback\)block

调用举例：

Plain Text\-\(void\)pushFile\{    NSString \*localPath = \[JL\_Tools listPath:NSLibraryDirectory MiddlePath:kTS\_WATCH\_FACE File:self\->dial\_watch\_id\];    \[dialSync pushDialWithLocalPath:localPath dialId:self\->dial\_watch\_id block:^\(FwDialProgressModel \*model\) \{        if\(model\.eventType == FwDialProgressModel\_Event\_Type\_OnProcess\)\{            self\->barProgress\.percent = model\.percent;        \}else if\(model\.eventType == FwDialProgressModel\_Event\_Type\_OnSuccess\)\{            NSLog\(@"pushDialWithLocalPath transfer %@",@"onSuccess"\);        \}else if\(model\.eventType == FwDialProgressModel\_Event\_Type\_OnFailed\)\{            NSLog\(@"pushDialWithLocalPath push or install %@",@"onFailed"\);            self\->titleLabel\.text = kJL\_TXT\("表盘传输失败"\);            self\->isLoading = NO;            \[self dismissAfterDelay:1\];        \}else if\(model\.eventType == FwDialProgressModel\_Event\_Type\_OnInstalling\)\{            NSLog\(@"pushDialWithLocalPath %@",@"onInstalling"\);        \}else if\(model\.eventType == FwDialProgressModel\_Event\_Type\_OnCompleted\)\{            NSLog\(@"pushDialWithLocalPath %@",@"onInstallSuccess"\);            self\->isLoading = NO;            self\->titleLabel\.text = kJL\_TXT\("表盘安装成功"\);            \[self dismissAfterDelay:1\];        \}            \}\];\}\- \(void\)dismissAfterDelay:\(CGFloat\)delay\{    dispatch\_after\(dispatch\_time\(DISPATCH\_TIME\_NOW, \(int64\_t\)\(delay \* NSEC\_PER\_SEC\)\), dispatch\_get\_main\_queue\(\), ^\{        self\.hidden = YES;    \}\);\}

<a id="heading_130"></a>__2、获取所有表盘信息__

\-\(void\)getAllDialInfo:\(TPSGetAllDialCallback\)block

调用举例：

Plain Text\-\(void\)onClickEnter\{    \[dialSync getAllDialInfo:^\(NSArray<FwDialModel \*> \*modelList\) \{        if\(modelList\)\{            BOOL hasInstall = NO;            for\(int i=0;i<modelList\.count;i\+\+\)\{                if\(\[modelList\[i\]\.dialId isEqualToString:self\->dial\_watch\_id\]\)\{                    hasInstall = YES;                    break;                \}            \}            if\(hasInstall\)\{                \[self changeDial\];            \}else\{                \[self startLoad\];            \}        \}else\{            \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self delay:1\.5\];        \}    \}\];\}\-\(void\)changeDial\{    \[dialSync changeDialWithDialId:self\->dial\_watch\_id block:^\(BOOL isSendOK\) \{        if\(isSendOK\)\{            self\->titleLabel\.text = kJL\_TXT\("当前表盘"\);            \[DFUITools showText:kJL\_TXT\("切换成功"\) onView:self delay:1\.5\];        \}else\{            \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self delay:1\.5\];        \}    \}\];\}\-\(void\)startLoad\{    \[TSWatchHttp requestWatchDetailWith:\[HOETool getProjectId\] dialId:dial\_sql\_id Result:^\(NSDictionary \*info\) \{        if \(\[HOETool checkIsInfoExist:info\]\) \{            self\->binFileUrl = info\[@"data"\]\[@"bin\_file"\];            \[JL\_Tools mainTask:^\{                NSString \*updatePath = \[JL\_Tools listPath:NSLibraryDirectory MiddlePath:kTS\_WATCH\_FACE File:self\->dial\_watch\_id\];                \[JL\_Tools removePath:updatePath\];                \[\[User\_Http shareInstance\] downloadUrl:self\->binFileUrl Path:updatePath Result:^\(float progress, JLHTTP\_Result result\) \{                    \[JL\_Tools mainTask:^\{                        self\->titleLabel\.text = kJL\_TXT\("下载中\.\.\."\);                        if \(result == JLHTTP\_ResultDownload\) \{                            NSLog\(@"dial download progress %f", progress\);                            self\->barProgress\.percent = progress;                        \}                        if \(result == JLHTTP\_ResultSuccess\) \{                            self\->titleLabel\.text = kJL\_TXT\("表盘推送中\.\.\."\);                            self\->barProgress\.percent = 0\.1;//刷新一下进度条，由于建立请求的时候等待时间比较长，给个假进度                            \[self pushFile\];                        \}                        if \(result == JLHTTP\_ResultFail\) \{                            self\->isLoading = NO;                            \[DFUITools showText:kJL\_TXT\("下载失败"\) onView:self delay:2\.0\];                            NSLog\(@"dial download fail"\);                        \}                    \}\];                \}\];            \}\];        \}else\{            NSLog\(@"Err: requestWatchDetailWith Watch info null 0\."\);        \}    \}\];\}

<a id="heading_131"></a>__3、通关表盘ID改变表盘__

\-\(void\)changeDialWithDialId:\(NSString\*\)dialId block:\(TPSSendMsgResult\)block

调用举例：

Plain Text\-\(void\)changeDial\{    \[dialSync changeDialWithDialId:self\->dial\_watch\_id block:^\(BOOL isSendOK\) \{        if\(isSendOK\)\{            self\->titleLabel\.text = kJL\_TXT\("当前表盘"\);            \[DFUITools showText:kJL\_TXT\("切换成功"\) onView:self delay:1\.5\];        \}else\{            \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self delay:1\.5\];        \}    \}\];\}

<a id="heading_132"></a>__4、获取当前的表盘__

\-\(void\)getCurrentDial:\(TPSDialGetCurDialCallback\)block

调用举例：

Plain Text\- \(void\)requireValue\{        \[self\.dialCreationView requestValues\];    self\.watchOperationView = \[\[WatchOperateView alloc\] initWithFrame:CGRectMake\(0, 0, \[DFUITools screen\_2\_W\], \[DFUITools screen\_2\_H\]\)\];    \[self\.view addSubview:self\.watchOperationView\];    self\.watchOperationView\.hidden = YES;        \[dialSync getCurrentDial:^\(FwDialModel \*model\) \{           //原意图似乎要在这里把当前表盘高亮显示出来，目前没处理    \}\];\}

<a id="heading_133"></a>__5、通过名字删除远程的表盘__

\-\(RACSubject \*\)deleteRemoteWatchDialWithName:\(NSString \*\)dialName block:\(TPSSendMsgResult\)block

调用举例：

Plain Text\- \(void\)deleteRemoteWatchDial\{    // delete watch dial    \[\[\[FwSdk share\]\.dialAbility deleteRemoteWatchDialWithName:\_dialItemModel\.dialName block:^\(BOOL isSendOK\) \{        if \(\!isSendOK\) \{            \[DFUITools showText:kJL\_TXT\("删除失败，请重试"\) onView:self\.view delay:2\.0f\];        \}    \}\] subscribeNext:^\(id  \_Nullable x\) \{        NSDictionary \*jsonMsg = \(NSDictionary \*\)x;        if \(\!\[TSChecker isEmptyDictonary:jsonMsg\]\) \{            NSString \*values = \[jsonMsg objectForKey:@"values"\];            if \(\[values isEqualToString:@"successMessage"\]\) \{                NSLog\(@"delete file success"\);                \[self deleteLocalDial\];            \}else\{                NSLog\(@"delete file failed"\);                \[DFUITools removeHUD\];                \[DFUITools showText:kJL\_TXT\("删除失败，请重试"\) onView:self\.view delay:2\.0f\];            \}        \}    \}\];\}\- \(void\)deleteLocalDial\{    if \(\[TSDialFileOperation deleteDial:\_dialItemModel\.dialName\]\) \{        \[DFUITools removeHUD\];        \[DFUITools showText:kJL\_TXT\("删除成功"\) onView:self\.view delay:2\.0f\];        // dismiss        \_\_weak typeof\(self\)weakSelf = self;        \[self dismissAfterDelay:kAnimationTime complete:^\{            \_\_strong typeof\(weakSelf\)strongSelf = weakSelf;            // post notification            \[strongSelf postNotification\];        \}\];    \}else\{        \[DFUITools removeHUD\];        // 删除失败        \[DFUITools showText:kJL\_TXT\("删除失败，请重试"\) onView:self\.view delay:2\.0f\];    \}\}

<a id="heading_134"></a>__25\.消息通知设置__

<a id="heading_135"></a>__1、获取所有通知并启用__

\-\(void\)getNotificationEnableList:\(TPSNotificationEnableListCallback\)block

调用举例：

Plain Text\-\(void\)initUI\{    notificationDic = \[NSMutableDictionary new\];    notificationSync = \[FwWearFactory createSingleInstance:@protocol\(IFwNotificationEnableAbility\)\];    self\.view\.backgroundColor = kDF\_RGBA\(248, 250, 252, 1\.0\);        float sW = \[DFUITools screen\_2\_W\];    float sH = \[DFUITools screen\_2\_H\];        headView = \[\[UIView alloc\] init\];    headView\.backgroundColor = kDF\_RGBA\(255, 255, 255, 1\.0\);    headView\.frame = CGRectMake\(0, 0, sW, kJL\_HeightStatusBar\+44\);    \[self\.view addSubview:headView\];        exitBtn = \[\[UIButton alloc\] init\];    exitBtn\.frame  = CGRectMake\(4, kJL\_HeightStatusBar, 44, 44\);    \[exitBtn setImage:\[UIImage imageNamed:@"icon\_return\_nol"\] forState:UIControlStateNormal\];    \[exitBtn addTarget:self action:@selector\(onClickBack\) forControlEvents:UIControlEventTouchUpInside\];    \[self\.view addSubview:exitBtn\];        titleName = \[\[UILabel alloc\] init\];//System Heavy 18\.0    titleName\.text = kJL\_TXT\("消息提醒"\);    titleName\.textAlignment = NSTextAlignmentCenter;    titleName\.bounds = CGRectMake\(0, 0, 200, 20\);    titleName\.font = \[UIFont systemFontOfSize:18\];    titleName\.center = CGPointMake\(sW/2\.0, kJL\_HeightStatusBar\+20\);    \[self\.view addSubview:titleName\];           NSArray\* allNameArray =  @\[        @\{@"icon":@"device\_msg\_all",@"msg\_title":kJL\_TXT\("消息一键开启"\),@"tool\_id":@"all",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_phone",@"msg\_title":kJL\_TXT\("来电提醒"\),@"tool\_id":@"telephony",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_msg",@"msg\_title":kJL\_TXT\("短信"\),@"tool\_id":@"sms",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_email",@"msg\_title":kJL\_TXT\("邮件"\),@"tool\_id":@"mail",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_wx",@"msg\_title":kJL\_TXT\("微信"\),@"tool\_id":@"wechat",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_qq",@"msg\_title":kJL\_TXT\("QQ"\),@"tool\_id":@"qq",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_fb",@"msg\_title":kJL\_TXT\("Facebook"\),@"tool\_id":@"facebook",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_tw",@"msg\_title":kJL\_TXT\("X"\),@"tool\_id":@"twitter",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_whatsapp",@"msg\_title":kJL\_TXT\("WhatsApp"\),@"tool\_id":@"whatsapp",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_linkedin",@"msg\_title":kJL\_TXT\("LinkedIn"\),@"tool\_id":@"linkedin",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_instagram",@"msg\_title":kJL\_TXT\("Instagram"\),@"tool\_id":@"instagram",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_messenger",@"msg\_title":kJL\_TXT\("Messenger"\),@"tool\_id":@"facebookmessenger",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_snapchat",@"msg\_title":kJL\_TXT\("Snapchat"\),@"tool\_id":@"snapchat",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_line",@"msg\_title":kJL\_TXT\("Line"\),@"tool\_id":@"line",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_kaokaotalk",@"msg\_title":kJL\_TXT\("Kaokao Talk"\),@"tool\_id":@"kakaotalk",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_instaviber",@"msg\_title":kJL\_TXT\("Viber"\),@"tool\_id":@"viber",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_skype",@"msg\_title":kJL\_TXT\("Skype"\),@"tool\_id":@"skype",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_telegram",@"msg\_title":kJL\_TXT\("Telegram"\),@"tool\_id":@"telegram",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_pinterest",@"msg\_title":kJL\_TXT\("Pinterest"\),@"tool\_id":@"pinterest",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_youtube",@"msg\_title":kJL\_TXT\("Youtube"\),@"tool\_id":@"youtube",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_applemusic",@"msg\_title":kJL\_TXT\("Applemusic"\),@"tool\_id":@"applemusic",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_zoom",@"msg\_title":kJL\_TXT\("Zoom"\),@"tool\_id":@"zoom",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_tiktok",@"msg\_title":kJL\_TXT\("Tiktok"\),@"tool\_id":@"tiktok",@"visible":@\(1\)\},        @\{@"icon":@"device\_msg\_hike",@"msg\_title":kJL\_TXT\("Hike"\),@"tool\_id":@"hike",@"visible":@\(0\)\},        @\{@"icon":@"device\_msg\_default",@"msg\_title":kJL\_TXT\("更多提醒"\),@"tool\_id":@"default",@"visible":@\(1\)\},    \];    nameArray = \[NSMutableArray new\];    invisibleArr = \[NSMutableArray new\];    for\(int i=0;i<allNameArray\.count;i\+\+\)\{        if\(\[allNameArray\[i\]\[@"visible"\] intValue\] == 1\)\{            \[nameArray addObject:allNameArray\[i\]\];        \}else\{            \[invisibleArr addObject:allNameArray\[i\]\];        \}    \}            self\->mTableView = \[\[UITableView alloc\] initWithFrame:CGRectMake\(16, headView\.frame\.size\.height\+12, sW\-16\*2, floor\(\(sH\-headView\.frame\.size\.height\-12\-25\)/54\.0\)\*54\)\];    self\->mTableView\.rowHeight = 54\.0;    self\->mTableView\.delegate = self;    self\->mTableView\.dataSource =self;    self\->mTableView\.scrollEnabled = YES;    mTableView\.layer\.cornerRadius=15\.0f;//    mTableView\.layer\.masksToBounds=YES;    \[self\->mTableView setSeparatorColor:\[UIColor colorWithRed:238/255\.0 green:238/255\.0 blue:238/255\.0 alpha:1\.0\]\];    \[self\->mTableView registerNib:\[UINib nibWithNibName:@"MsgEnableCell" bundle:nil\] forCellReuseIdentifier:@"MsgEnableCell"\];    \[self\.view addSubview:self\->mTableView\];    \[self\->mTableView reloadData\];        \[notificationSync getNotificationEnableList:^\(NSMutableArray<FwNotificationEnableModel \*> \*list\) \{        self\->notificationDic = \[NSMutableDictionary new\];        for\(int i=0;i<list\.count;i\+\+\)\{            self\->notificationDic\[list\[i\]\.name\] = list\[i\]\.enable ? @\(1\) : @\(0\);        \}        \[self\->mTableView reloadData\];    \}\];\}

<a id="heading_136"></a>__2、发送所有通知并启用__

\-\(void\)sendNotificationEnableList:\(NSArray<TPSNotificationEnableModel\*>\*\)list block:\(TPSSendMsgResult\)block

调用举例：

Plain Text\-\(void\)onSwitchToggle:\(int\)index from:\(UISwitch\*\)from\{    int open = from\.isOn ? 1 : 0;        NSLog\(@"index is %d",index\);        if\(index == 0\)\{//点击到所有一键开关        \[notificationDic enumerateKeysAndObjectsUsingBlock:^\(id  \_Nonnull key, id  \_Nonnull obj, BOOL \* \_Nonnull stop\) \{            notificationDic\[key\] = @\(open\);        \}\];    \}else\{        NSString\* msgName = nameArray\[index\]\[@"tool\_id"\];        if\(\[msgName isEqualToString:@"default"\]\)\{//点到更多消息按钮            notificationDic\[@"default"\] = @\(open\);            for\(int i=0;i<invisibleArr\.count;i\+\+\)\{//不可见条目暗中归入default里                NSString\* toolId = invisibleArr\[i\]\[@"tool\_id"\];                notificationDic\[toolId\] = @\(open\);            \}        \}else\{            notificationDic\[msgName\] = @\(open\);        \}    \}            NSMutableArray<FwNotificationEnableModel\*>\* resultList = \[NSMutableArray new\];    \[notificationDic enumerateKeysAndObjectsUsingBlock:^\(id  \_Nonnull key, id  \_Nonnull obj, BOOL \* \_Nonnull stop\) \{        FwNotificationEnableModel\* model = \[\[FwNotificationEnableModel alloc\] init\];        model\.name = key;        model\.enable = \(\(\[obj intValue\]\)==1\);        model\.type = \[notificationSync getTypeByName:key\];        \[resultList addObject:model\];    \}\];        \[notificationSync sendNotificationEnableList:resultList block:^\(BOOL isSendOK\) \{        if\(\!isSendOK\)\{            \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self\.view delay:1\.5\];        \}    \}\];    \[mTableView reloadData\];\}

<a id="heading_137"></a>__3、通过名字获取类型__

\-\(TPSNotification\_Type\)getTypeByName:\(NSString\*\)name

调用举例：

Plain Text\-\(void\)onSwitchToggle:\(int\)index from:\(UISwitch\*\)from\{    int open = from\.isOn ? 1 : 0;        NSLog\(@"index is %d",index\);        if\(index == 0\)\{//点击到所有一键开关        \[notificationDic enumerateKeysAndObjectsUsingBlock:^\(id  \_Nonnull key, id  \_Nonnull obj, BOOL \* \_Nonnull stop\) \{            notificationDic\[key\] = @\(open\);        \}\];    \}else\{        NSString\* msgName = nameArray\[index\]\[@"tool\_id"\];        if\(\[msgName isEqualToString:@"default"\]\)\{//点到更多消息按钮            notificationDic\[@"default"\] = @\(open\);            for\(int i=0;i<invisibleArr\.count;i\+\+\)\{//不可见条目暗中归入default里                NSString\* toolId = invisibleArr\[i\]\[@"tool\_id"\];                notificationDic\[toolId\] = @\(open\);            \}        \}else\{            notificationDic\[msgName\] = @\(open\);        \}    \}            NSMutableArray<FwNotificationEnableModel\*>\* resultList = \[NSMutableArray new\];    \[notificationDic enumerateKeysAndObjectsUsingBlock:^\(id  \_Nonnull key, id  \_Nonnull obj, BOOL \* \_Nonnull stop\) \{        FwNotificationEnableModel\* model = \[\[FwNotificationEnableModel alloc\] init\];        model\.name = key;        model\.enable = \(\(\[obj intValue\]\)==1\);        model\.type = \[notificationSync getTypeByName:key\];        \[resultList addObject:model\];    \}\];        \[notificationSync sendNotificationEnableList:resultList block:^\(BOOL isSendOK\) \{        if\(\!isSendOK\)\{            \[DFUITools showText:kJL\_TXT\("连接失败"\) onView:self\.view delay:1\.5\];        \}    \}\];    \[mTableView reloadData\];\}

<a id="heading_138"></a>__26\.联系人__

<a id="heading_139"></a>__1、获取紧急联系人__

\-\(void\)getEmergencyContact:\(TPSContactListCallback\)block

调用举例：

Plain Text\- \(void\)viewDidLoad \{    \[super viewDidLoad\];        selectedArr = \[NSMutableArray new\];        self\.contentContainer\.backgroundColor = \[JLColor colorWithString:BG\_GRAY1\];        //开始先隐藏这些元素，去到数据后才决定要显示哪些    self\.btnDel\.hidden = YES;    self\.btnAll\.hidden = YES;    self\.imgNoData\.hidden = YES;    self\.lbNoData\.hidden = YES;    self\.tbContact\.hidden = YES;    self\.btnExitEdit\.hidden = YES;        self\.tbContact\.dataSource = self;    self\.tbContact\.delegate = self;    self\.tbContact\.scrollEnabled = YES;    self\.tbContact\.rowHeight = 99;    self\.tbContact\.backgroundColor = UIColor\.clearColor;    self\.tbContact\.separatorStyle = UITableViewCellSeparatorStyleNone;    \[self\.tbContact registerNib:\[UINib nibWithNibName:@"ContactBookCell" bundle:nil\] forCellReuseIdentifier:@"ContactBookCell"\];        \[self\.btnAll setImage:\[UIImage imageNamed:@"contact\_all\_no\_icon"\] forState:UIControlStateNormal\];    \[self\.btnAll setImage:\[UIImage imageNamed:@"contact\_all\_yes\_icon"\] forState:UIControlStateSelected\];    \[self\.btnAll setTitleColor:\[JLColor colorWithString:CHAR\_GRAY2\] forState:UIControlStateNormal\];    \[self\.btnAll setTitleColor:\[JLColor colorWithString:CHAR\_GREENBLUE1\] forState:UIControlStateSelected\];        \[self\.btnEdit addTarget:self action:@selector\(onEdit\) forControlEvents:UIControlEventTouchUpInside\];    \[self\.btnExitEdit addTarget:self action:@selector\(onExitEdit\) forControlEvents:UIControlEventTouchUpInside\];    \[self\.btnDel  addTarget:self action:@selector\(onDeleteSome\) forControlEvents:UIControlEventTouchUpInside\];    \[self\.btnAdd addTarget:self action:@selector\(onAddContact\) forControlEvents:UIControlEventTouchUpInside\];    \[self\.btnAll  addTarget:self action:@selector\(onAllChoose:\) forControlEvents:UIControlEventTouchUpInside\];        \[self setAllText\];        contactSync = \[FwWearFactory createSingleInstance:@protocol\(IFwContactAbility\)\];        \[\[contactSync getAllContact\] subscribeNext:^\(NSArray<FwContactModel \*> \* \_Nullable list\) \{        if\(list\)\{            self\->commonContactArr = \[NSMutableArray new\];            for\(int i=0;i<list\.count;i\+\+\)\{                \[self\->commonContactArr addObject:@\{@"phone":list\[i\]\.phone, @"name":list\[i\]\.name, @"short":list\[i\]\.initial\}\];            \}        \}        \[self tryLoadData\];    \}\];    \[contactSync getEmergencyContact:^\(NSMutableArray<FwContactModel \*> \*list\) \{        self\->emergencyArr = \[NSMutableArray new\];        if\(list\)\{            for\(int i=0;i<list\.count;i\+\+\)\{                \[self\->emergencyArr addObject:@\{@"phone":list\[i\]\.phone, @"name":list\[i\]\.name, @"short":list\[i\]\.initial\}\];            \}        \}        \[self tryLoadData\];    \}\];\}

<a id="heading_140"></a>__2、发送紧急联系人__

\-\(void\)sendEmergencyContact:\(TPSContactModel\*\)contactModel

调用举例：

Plain Text\-\(void\)sendData\{    NSMutableArray<FwContactModel\*>\* list = \[NSMutableArray new\];    for\(int i=0;i<emergencyArr\.count;i\+\+\)\{        NSString\* phone = emergencyArr\[i\]\[@"phone"\];        NSString\* name = emergencyArr\[i\]\[@"name"\];        FwContactModel\* model = \[\[FwContactModel alloc\] initWithName:name phone:phone initial:\[self getInitial:name\]\];        \[list addObject:model\];    \}    for\(int i=0;i<commonContactArr\.count;i\+\+\)\{        NSString\* phone = commonContactArr\[i\]\[@"phone"\];        NSString\* name = commonContactArr\[i\]\[@"name"\];        FwContactModel\* model = \[\[FwContactModel alloc\] initWithName:name phone:phone initial:\[self getInitial:name\]\];        \[list addObject:model\];    \}    \[contactSync sendCommonContact:list\];        if\(emergencyArr\.count > 0\)\{        NSString\* userName = emergencyArr\[0\]\[@"name"\];        NSString\* initial = \[self getInitial:userName\];        FwContactModel\* emergencyModel = \[\[FwContactModel alloc\] initWithName:userName phone:emergencyArr\[0\]\[@"phone"\] initial:initial\];        \[contactSync sendEmergencyContact:emergencyModel\];    \}else\{        \[contactSync sendEmergencyContact:nil\];    \}\}

<a id="heading_141"></a>__3、获得所有联系__

\-\(RACSubject<NSArray<TPSContactModel\*>\*>\*\)getAllContact

调用举例：

Plain Text\- \(void\)viewDidLoad \{    \[super viewDidLoad\];        selectedArr = \[NSMutableArray new\];        self\.contentContainer\.backgroundColor = \[JLColor colorWithString:BG\_GRAY1\];        //开始先隐藏这些元素，去到数据后才决定要显示哪些    self\.btnDel\.hidden = YES;    self\.btnAll\.hidden = YES;    self\.imgNoData\.hidden = YES;    self\.lbNoData\.hidden = YES;    self\.tbContact\.hidden = YES;    self\.btnExitEdit\.hidden = YES;        self\.tbContact\.dataSource = self;    self\.tbContact\.delegate = self;    self\.tbContact\.scrollEnabled = YES;    self\.tbContact\.rowHeight = 99;    self\.tbContact\.backgroundColor = UIColor\.clearColor;    self\.tbContact\.separatorStyle = UITableViewCellSeparatorStyleNone;    \[self\.tbContact registerNib:\[UINib nibWithNibName:@"ContactBookCell" bundle:nil\] forCellReuseIdentifier:@"ContactBookCell"\];        \[self\.btnAll setImage:\[UIImage imageNamed:@"contact\_all\_no\_icon"\] forState:UIControlStateNormal\];    \[self\.btnAll setImage:\[UIImage imageNamed:@"contact\_all\_yes\_icon"\] forState:UIControlStateSelected\];    \[self\.btnAll setTitleColor:\[JLColor colorWithString:CHAR\_GRAY2\] forState:UIControlStateNormal\];    \[self\.btnAll setTitleColor:\[JLColor colorWithString:CHAR\_GREENBLUE1\] forState:UIControlStateSelected\];        \[self\.btnEdit addTarget:self action:@selector\(onEdit\) forControlEvents:UIControlEventTouchUpInside\];    \[self\.btnExitEdit addTarget:self action:@selector\(onExitEdit\) forControlEvents:UIControlEventTouchUpInside\];    \[self\.btnDel  addTarget:self action:@selector\(onDeleteSome\) forControlEvents:UIControlEventTouchUpInside\];    \[self\.btnAdd addTarget:self action:@selector\(onAddContact\) forControlEvents:UIControlEventTouchUpInside\];    \[self\.btnAll  addTarget:self action:@selector\(onAllChoose:\) forControlEvents:UIControlEventTouchUpInside\];        \[self setAllText\];        contactSync = \[FwWearFactory createSingleInstance:@protocol\(IFwContactAbility\)\];        \[\[contactSync getAllContact\] subscribeNext:^\(NSArray<FwContactModel \*> \* \_Nullable list\) \{        if\(list\)\{            self\->commonContactArr = \[NSMutableArray new\];            for\(int i=0;i<list\.count;i\+\+\)\{                \[self\->commonContactArr addObject:@\{@"phone":list\[i\]\.phone, @"name":list\[i\]\.name, @"short":list\[i\]\.initial\}\];            \}        \}        \[self tryLoadData\];    \}\];    \[contactSync getEmergencyContact:^\(NSMutableArray<FwContactModel \*> \*list\) \{        self\->emergencyArr = \[NSMutableArray new\];        if\(list\)\{            for\(int i=0;i<list\.count;i\+\+\)\{                \[self\->emergencyArr addObject:@\{@"phone":list\[i\]\.phone, @"name":list\[i\]\.name, @"short":list\[i\]\.initial\}\];            \}        \}        \[self tryLoadData\];    \}\];\}

<a id="heading_142"></a>__4、发送常用联系人__

\-\(void\)sendCommonContact:\(NSArray<TPSContactModel\*>\*\)list

调用举例：

Plain Text\-\(void\)sendData\{    NSMutableArray<FwContactModel\*>\* list = \[NSMutableArray new\];    for\(int i=0;i<emergencyArr\.count;i\+\+\)\{        NSString\* phone = emergencyArr\[i\]\[@"phone"\];        NSString\* name = emergencyArr\[i\]\[@"name"\];        FwContactModel\* model = \[\[FwContactModel alloc\] initWithName:name phone:phone initial:\[self getInitial:name\]\];        \[list addObject:model\];    \}    for\(int i=0;i<commonContactArr\.count;i\+\+\)\{        NSString\* phone = commonContactArr\[i\]\[@"phone"\];        NSString\* name = commonContactArr\[i\]\[@"name"\];        FwContactModel\* model = \[\[FwContactModel alloc\] initWithName:name phone:phone initial:\[self getInitial:name\]\];        \[list addObject:model\];    \}    \[contactSync sendCommonContact:list\];        if\(emergencyArr\.count > 0\)\{        NSString\* userName = emergencyArr\[0\]\[@"name"\];        NSString\* initial = \[self getInitial:userName\];        FwContactModel\* emergencyModel = \[\[FwContactModel alloc\] initWithName:userName phone:emergencyArr\[0\]\[@"phone"\] initial:initial\];        \[contactSync sendEmergencyContact:emergencyModel\];    \}else\{        \[contactSync sendEmergencyContact:nil\];    \}\}

<a id="heading_143"></a>__5、观察常用联系人__

\-\(RACSubject\*\)observeContactChange

调用举例：

Plain Text

<a id="heading_144"></a>__27\.查找设备__

<a id="heading_145"></a>__1、回复查找手机__

\-\(void\)replyFindPhone

调用举例：

Plain Text\- \(IBAction\)closeBtnAction:\(id\)sender \{    id<IFwFinderAbility> finderSync = \[FwWearFactory createSingleInstance:@protocol\(IFwFinderAbility\)\];    \[finderSync replyFindPhone\];    \[self stopVoice\];\}

<a id="heading_146"></a>__2、查找手机__

\-\(void\)findWatch

调用举例：

Plain Text\-\(void\)onClickBtn:\(UIButton\*\)sender\{    if\(isFinding\)\{        isFinding = NO;        \[finderSync stopFindWatch\];        \[self showReFindUI\];        \[TSAnimationTool stopSearchAnimation\];    \}else\{        isFinding = YES;        \[finderSync findWatch\];        self\.findStateLb\.text = kJL\_TXT\("正在查找手表\.\.\."\);        \[registerBtn setTitle:kJL\_TXT\("结束查找"\) forState:UIControlStateNormal\];        \[registerBtn setBackgroundImage:\[UIImage imageNamed:@"findwatch\_red\_btn\_bg"\] forState:UIControlStateNormal\];        \[TSAnimationTool startSearchAnimationTime:animationTimeCount container:self\.animationCon block:^\{            \[self showReFindUI\];        \}\];    \}\}

<a id="heading_147"></a>__3、停止查找手机__

\-\(void\)stopFindWatch

调用举例：

Plain Text\-\(void\)onClickBtn:\(UIButton\*\)sender\{    if\(isFinding\)\{        isFinding = NO;        \[finderSync stopFindWatch\];        \[self showReFindUI\];        \[TSAnimationTool stopSearchAnimation\];    \}else\{        isFinding = YES;        \[finderSync findWatch\];        self\.findStateLb\.text = kJL\_TXT\("正在查找手表\.\.\."\);        \[registerBtn setTitle:kJL\_TXT\("结束查找"\) forState:UIControlStateNormal\];        \[registerBtn setBackgroundImage:\[UIImage imageNamed:@"findwatch\_red\_btn\_bg"\] forState:UIControlStateNormal\];        \[TSAnimationTool startSearchAnimationTime:animationTimeCount container:self\.animationCon block:^\{            \[self showReFindUI\];        \}\];    \}\}\-\(void\)showReFindUI\{    isFinding = NO;    self\.findStateLb\.text = kJL\_TXT\("停止查找"\);    \[registerBtn setTitle:kJL\_TXT\("重新查找"\) forState:UIControlStateNormal\];    \[registerBtn setBackgroundImage:\[UIImage imageNamed:@"btn\_bg\_bluegreen"\] forState:UIControlStateNormal\];\}

<a id="heading_148"></a>__4、观察查找手机__

\-\(RACSubject\*\)observeFindingPhone

调用举例：

Plain Text\- \(BOOL\)application:\(UIApplication \*\)application didFinishLaunchingWithOptions:\(NSDictionary \*\)launchOptions \{      //\-\-\- 记录NSLOG \-\-\-    \[HOETool openLogTextFile\];        unsigned char data\[\] = \{0x00,0x02,0x45,0x28\};    NSInteger intData = \*\(\(NSInteger\*\)data\);    NSLog\(@"a\-\-:%ld",intData\);    NSLog\(@"b\-\-:%08lx",intData\);        uint16\_t us1 = 0xfffe;    int16\_t  s1 = \(int16\_t\)us1;    NSLog\(@"us1\-\-:%d,%02x",us1,us1\);    NSLog\(@"su1\-\-:%d,%02x",s1,s1\);    NSLog\(@"us1\-\-:%02x",us1\);    NSLog\(@"su1\-\-:%02x",s1\);        //    \[UIView appearance\]\.semanticContentAttribute = UISemanticContentAttributeForceRightToLeft;            //\-\-\- 设置屏幕常亮 \-\-\-    //    \[UIApplication sharedApplication\]\.idleTimerDisabled = YES;    //\-\-\- 按系统语言设置 \-\-\-    kJL\_SET\(""\);        \[User\_Http shareInstance\];    User\_Http\.shareInstance\.userPfInfo\.identify = \[HOETool getLocalUserId\];//add by leiwei,取消登录,改成单机模式        //\-\-\- 网络监测 \-\-\-//这一行会触发使用网络权限提示选择框，其他请求网络的时候貌似也会触发。    AFNetworkReachabilityManager \*net = \[AFNetworkReachabilityManager sharedManager\];    \[net startMonitoring\];        //\-\-\- 设置高德云SDK的apiKey \-\-\-    //    \[AMapServices sharedServices\]\.apiKey = @"a815e58ecb9ce231ccd730a5c503ff2d";        //\-\-\- 初始化UI \-\-\-    \[self setupUI\];        //\-\-\- 开启动画 \-\-\-    \[OpenShowView startOpenAnimation\];        if\(\[HOETool getHasConfirmPrivacy\]\)\{//否则推迟到隐私协议确认之后        \[self initShareInstance\];    \}        //\-\-\- 运行SDK \-\-\-    //    NSString \* accessToken = \[JL\_Tools getUserByKey:@"accessToken"\];    //    if \(accessToken\!=nil && accessToken\.length > 0\) \{//为使得蓝牙权限询问在隐私协议之后再弹出增加这个判断    //        \[JL\_RunSDK sharedMe\];    //    \}        \[self addNote\];    \[self createDir\];    \[\[LanguageCls share\] add:self\];        \[\[NSNotificationCenter defaultCenter\] addObserver:self selector:@selector\(showBluetoothUnauthorized\) name:@"TS\_BluetoothUnauthorized" object:nil\];    \[\[NSNotificationCenter defaultCenter\] addObserver:self selector:@selector\(showBluetoothPowerOff\) name:@"TS\_BluetoothPoweredOff" object:nil\];        //监听手表查找手机的命令    id<IFwFinderAbility> finderSync = \[FwWearFactory createSingleInstance:@protocol\(IFwFinderAbility\)\];    \[\[finderSync observeFindingPhone\] subscribeNext:^\(id  \_Nullable x\) \{        if \(self\->findView\.hidden == YES\) \{            self\->findView\.hidden = NO;            UIWindow \*win = \[UIApplication sharedApplication\]\.keyWindow;            \[win addSubview:self\->findView\];            \[self\->findView startVoice\];        \}    \}\];        \[\[\[FwSdk share\]\.connectorAbility observeConnectResult\] subscribeNext:^\(FwConnectResult \* \_Nullable x\) \{        if\(x\.state == FwConnnectResult\_State\_Connected\)\{            \[HOETool setIsUserDeleteWatch:NO\];            FwExtraConnectParam\* extraParam = \[\[FwExtraConnectParam alloc\] initWithUserId:\[HOETool getUserId\] gender:\[HOETool getGender\] age:\[HOETool getUserAge\] height:\[HOETool getHeight\] weight:\[HOETool getWeight\]\];            \[\[FwSdk share\]\.connectorAbility autoConnectLastPeripheralWithUserInfo:extraParam\];            \[\[SettingSyncMananger share\] start\];        \}else if\(x\.state == FwConnnectResult\_State\_Connecting\)\{            if\(x\.errorCode == FwConnnectResult\_Error\_Code\_Under\_IOS13\)\{                \[self showConnectEdrView\];            \}else if\(x\.errorCode == FwConnnectResult\_Error\_Code\_Low\_Battery\)\{                \[self showBatteryCannotBind\];            \}        \}    \}\];        \[self initMapNav\];                 return YES;\}\-\(void\)initMapNav\{    // 初始化定位SDK    \[\[BMKLocationAuth sharedInstance\] checkPermisionWithKey:BNAVI\_APP\_KEY authDelegate:self\];    //要使用百度地图，请先启动BMKMapManager    BMKMapManager\* \_mapManager = \[\[BMKMapManager alloc\] init\];        /\*\*     百度地图SDK所有API均支持百度坐标（BD09）和国测局坐标（GCJ02），用此方法设置您使用的坐标类型\.     默认是BD09（BMK\_COORDTYPE\_BD09LL）坐标\.     如果需要使用GCJ02坐标，需要设置CoordinateType为：BMK\_COORDTYPE\_COMMON\.     \*/    if \(\[BMKMapManager setCoordinateTypeUsedInBaiduMapSDK:BMK\_COORDTYPE\_BD09LL\]\) \{        NSLog\(@"经纬度类型设置成功"\);    \} else \{        NSLog\(@"经纬度类型设置失败"\);    \}        //启动引擎并设置AK并设置delegate    BOOL result = \[\_mapManager start:BNAVI\_APP\_KEY generalDelegate:self\];    if \(\!result\) \{        NSLog\(@"启动引擎失败"\);    \}        // 定位SDK隐私权限授权    \[\[BMKLocationAuth sharedInstance\] setAgreePrivacy:YES\];    // 地图SDK隐私权限授权    \[BMKMapManager setAgreePrivacy:YES\];\}

<a id="heading_149"></a>__5、观察查找手表__

\-\(RACSubject\*\)observeWatchBeFound

调用举例：

Plain Text\-\(void\)initUI\{    \[TSAnimationTool loadImageResource\];    animationTimeCount = 60;            self\.view\.backgroundColor = kDF\_RGBA\(248, 250, 252, 1\.0\);    self\.titleLb\.text = kJL\_TXT\("查找手表"\);        float sw = \[DFUITools screen\_2\_W\];    float sh = \[DFUITools screen\_2\_H\];            \[self\.btnBack addTarget:self action:@selector\(onClickBack\) forControlEvents:UIControlEventTouchUpInside\];        registerBtn = \[\[UIButton alloc\] initWithFrame:CGRectMake\(24,sh\-58\-48,sw\-48,48\)\];    \[registerBtn addTarget:self action:@selector\(onClickBtn:\) forControlEvents:UIControlEventTouchUpInside\];    \[registerBtn setTitle:kJL\_TXT\("结束查找"\) forState:UIControlStateNormal\];    \[registerBtn setBackgroundImage:\[UIImage imageNamed:@"findwatch\_red\_btn\_bg"\] forState:UIControlStateNormal\];    \[registerBtn\.titleLabel setFont:\[UIFont fontWithName:@"PingFangSC" size:15\]\];    \[registerBtn setTitleColor:kDF\_RGBA\(255, 255, 255, 1\.0\) forState:UIControlStateNormal\];//    \[registerBtn setBackgroundColor:kDF\_RGBA\(240, 241, 241, 1\.0\)\];    registerBtn\.backgroundColor = UIColor\.clearColor;//    registerBtn\.layer\.cornerRadius = 24;    \[self\.view addSubview:registerBtn\];        self\.findStateLb\.text = kJL\_TXT\("正在查找手表\.\.\."\);        self\.animationCon\.backgroundColor = UIColor\.clearColor;    isFinding = YES;    \[TSAnimationTool startSearchAnimationTime:animationTimeCount container:self\.animationCon block:^\{        \[self showReFindUI\];    \}\];        finderSync = \[FwWearFactory createSingleInstance:@protocol\(IFwFinderAbility\)\];    \[finderSync findWatch\];    watchBeFoundRacDisposable = \[\[finderSync observeWatchBeFound\] subscribeNext:^\(id  \_Nullable x\) \{        self\.findStateLb\.text = kJL\_TXT\("已经找到"\);        \[self showReFindUI\];    \}\];\}\-\(void\)showReFindUI\{    isFinding = NO;    self\.findStateLb\.text = kJL\_TXT\("停止查找"\);    \[registerBtn setTitle:kJL\_TXT\("重新查找"\) forState:UIControlStateNormal\];    \[registerBtn setBackgroundImage:\[UIImage imageNamed:@"btn\_bg\_bluegreen"\] forState:UIControlStateNormal\];\}

<a id="heading_150"></a>__6、停止从手表查找手机__

\-\(RACSubject\*\)observeWatchStopFindingPhone

调用举例：

Plain Text\- \(instancetype\)init\{    self = \[DFUITools loadNib:@"FindPhoneView"\];    if \(self\) \{        timeCount = 0;        self\.frame = CGRectMake\(0, 0, \[UIScreen mainScreen\]\.bounds\.size\.width, \[UIScreen mainScreen\]\.bounds\.size\.height\);        centerView\.layer\.cornerRadius = 10;        centerView\.layer\.masksToBounds = YES;        \[self languageChange\];        \[\[LanguageCls share\] add:self\];        id<IFwFinderAbility> finderSync = \[FwWearFactory createSingleInstance:@protocol\(IFwFinderAbility\)\];        racDispose = \[\[finderSync observeWatchStopFindingPhone\] subscribeNext:^\(id  \_Nullable x\) \{            \[self stopVoice\];        \}\];    \}    return self;\}\-\(void\)stopVoice\{    self\.hidden = YES;    \[self removeFromSuperview\];    \[voiceTimer invalidate\];    voiceTimer = nil;\}

