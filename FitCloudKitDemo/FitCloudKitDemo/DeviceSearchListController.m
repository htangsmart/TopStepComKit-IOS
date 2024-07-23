//
//  DeviceSearchListController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/17.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DeviceSearchListController.h"
#import "DeviceCell.h"
#import "DeviceBindingController.h"
#import <TopStepComKit/TPS_Tools.h>

#define USER_ID @"10000"

@interface DeviceSearchListController (){
    RACDisposable* scanRacDisposable;
    RACDisposable* conectRacDisposable;
    DeviceBindingController* bindingVC;
}

@property (nonatomic, assign) BOOL isSearching;
@property (nonatomic, strong) NSMutableArray<TPSScanResult*> * peripherals;
@property (weak, nonatomic) IBOutlet UITableView *tableView;

- (IBAction)OnGoBack:(id)sender;
@end

@implementation DeviceSearchListController

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder
{
    if(self = [super initWithCoder:aDecoder])
    {
        _isSearching = NO;
        _peripherals = [NSMutableArray<TPSScanResult*> array];
    }
    return self;
}


-(void)dealloc{
    if(self.isSearching)    {
        [[TPSSdk share].connectorAbility stopScan];
    }
    if(scanRacDisposable){
        [scanRacDisposable dispose];
    }
    if(conectRacDisposable){
        [conectRacDisposable dispose];
    }
    self->bindingVC = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    if(scanRacDisposable){
        [scanRacDisposable dispose];
    }
    
    if(self.isSearching){
        self.isSearching = FALSE;
        [[TPSSdk share].connectorAbility stopScan];
    }
    else
    {
        self.isSearching = TRUE;
        [self.peripherals removeAllObjects];
        [self.tableView reloadData];
        RACSubject<TPSScanResult*>* scanRacSubject = [[TPSSdk share].connectorAbility startScan];
        scanRacDisposable = [scanRacSubject subscribeNext:^(TPSScanResult * _Nullable x) {
            if (x.name.length > 0) {
                NSString *mac = x.mac ? x.mac : @"";
                int foundIndex = [self getSamePeeripehralIndex:x.peripheral.identifier.UUIDString];
                //if has existed(you will scan many repetitious peripheral,you need to merge them into one peripheral)
                if(foundIndex > -1){
                    //Due to weak signal reasons, sometimes the data is incomplete and MAC cannot be obtained. Fill in the most complete situation instead of filling in the latest situation
                    if(self.peripherals[foundIndex].mac==nil || self.peripherals[foundIndex].mac.length==0){
                        self.peripherals[foundIndex].mac = mac;
                    }
                }else{
                    [self.peripherals addObject:x];
                }
                [self.tableView reloadData];
            }
        }];
    }
}

-(int)getSamePeeripehralIndex:(NSString*)uuid{
    for(int i=0;i<self.peripherals.count;i++){
        if([self.peripherals[i].peripheral.identifier.UUIDString isEqualToString:uuid]){
            return i;
        }
    }
    return -1;
}

-(void) registerNotificationObserver
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudWriteCharacteristicReady:) name:FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY object:nil];
}

-(void)OnFitCloudWriteCharacteristicReady:(NSNotification*) notification
{
    
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.peripherals count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    DeviceCell *cell = [tableView dequeueReusableCellWithIdentifier:@"DeviceCell" forIndexPath:indexPath];
    
    if ([self.peripherals isKindOfClass:[NSArray class]] && [self.peripherals count] > indexPath.row)
    {
        TPSScanResult* item = [self.peripherals objectAtIndex:indexPath.row];
        if([item isKindOfClass:[TPSScanResult class]])
        {
            [cell configWithPeripheral:item showStatus:YES];
        }
    }
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 72.0f;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if(indexPath.section == 0)
    {
        if ([self.peripherals isKindOfClass:[NSArray class]] && [self.peripherals count] > indexPath.row)
        {
            
            TPSScanResult* item = [self.peripherals objectAtIndex:indexPath.row];
            if([item isKindOfClass:[TPSScanResult class]] && item.state != CBPeripheralStateConnecting && (item.peripheral.state != CBPeripheralStateConnected))
            {
                //Record the last MAC address, and next time you can automatically connect based on this MAC address
                [TPS_Tools setUser:item.mac forKey:@"lastMac"];
                //When binding, you need to pass the user's userId (defined by yourself), gender, age, height, and weight to the watch
                TPSExtraConnectParam* extraParam = [[TPSExtraConnectParam alloc] initWithUserId:@"123456789" gender:0 age:18 height:180 weight:65];
                RACSubject<TPSConnectResult*>* conRacSubject = [[TPSSdk share].connectorAbility connectWithCBPeripheral:item.peripheral mac:item.mac extraParam:extraParam];
                if(conectRacDisposable){
                    [conectRacDisposable dispose];
                }
                conectRacDisposable = [conRacSubject subscribeNext:^(TPSConnectResult * _Nullable x) {
                    [self handleConnectResult:x];
                }];
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self.tableView reloadRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationAutomatic];
                });
            }
        }
    }
}

-(void)handleConnectResult:(TPSConnectResult*)x{
    NSLog(@"handleConnectResult handleConnectResult is %d",x.state);
    if(x.state == TPSConnnectResult_State_Connected){
        //do something
    }else if(x.state == TPSConnnectResult_State_Connecting){
        NSLog(@"FwConnnectResult_State_Connecting");
        if(bindingVC == nil){
            self->bindingVC = [self.storyboard instantiateViewControllerWithIdentifier:@"DeviceBindingController"];
            self->bindingVC.modalPresentationStyle = UIModalPresentationFullScreen;
            [self.navigationController presentViewController:self->bindingVC animated:NO completion:nil];
            [self.navigationController popToRootViewControllerAnimated:NO];
        }
    }else if(x.state == TPSConnnectResult_State_Disconnected){
        if(x.errorCode == TPSConnnectResult_Error_Code_Low_Battery){
            //do something
        }else if(x.errorCode == TPSConnnectResult_Error_Code_Wait_Reboot){
            //do something
        }else{
            //do something
        }
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
