//
//  DemoListController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/20.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DemoListController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]

@interface DemoListController ()<UIDocumentPickerDelegate>{
    FITCLOUDMN mymnSetting;
}

- (IBAction)OnGoBack:(id)sender;
@end

@implementation DemoListController

- (void)viewDidLoad {
    [super viewDidLoad];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    if(indexPath.row == 1)
    {
        [self getBattery];
//        [self getNotificationSetting];
//        [self fetchSportsDataToday];
    }
    else if(indexPath.row == 2)
    {
        [self sendNotificationSetting];
//        [self manualSyncData];
    }
    else if(indexPath.row == 3)
    {
        [self findWatch];
    }
    else if(indexPath.row == 4)
    {
        [self getAllMiscSetting];
    }
    else if(indexPath.row == 19)
    {
        [self otaTest];
    }
}

- (void)otaTest {
    UIDocumentPickerViewController *picker = [[UIDocumentPickerViewController alloc] initWithDocumentTypes:@[ @"public.item" ] inMode:(UIDocumentPickerModeImport)];
    picker.delegate = self;
    picker.modalPresentationStyle = UIModalPresentationFormSheet;
    picker.allowsMultipleSelection = false;
    [self presentViewController:picker animated:true completion:nil];
}

- (void)beginOtaWithFilePath:(NSString *)path {
    
    [TPSSdk.share.otaAbility otaUpdateWithLocalPath:path block:^(TPSProgressModel *model) {
       
        XLOG_INFO(@"ota progress: %f, state: %d", model.percent, model.eventType);
    }];
}


- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURLs:(NSArray<NSURL *> *)urls {
    if (controller.documentPickerMode == UIDocumentPickerModeImport) {
        
        if ([urls isKindOfClass:NSArray.class] && urls.count > 0) {
            [self beginOtaWithFilePath:urls.firstObject.absoluteString];
        }
    }
}



// Get the day's sports health data
- (void)fetchSportsDataToday {
    
    // 调用此接口获取指定类型和指定时间段内的数据，如获取当日运动健康数据可设置类型为TSDataType_TodayTotalActivity
    // Call this interface to obtain data of a specified type and time period. For example, to obtain the current day's sports health data, you can set the type to TSDataType_TodayTotalActivity.
    XLOG_INFO(@"%@", APP_LOG_STRING(@"开始获取当日运动健康数据... \nGet the day's sports health data..."));
    [TPSSdk.share.synchronousDataAbility getHistoryDataWithType:TSDataType_TodayTotalActivity userID:@"" timeStart:0 timeEnd:0 resultBlock:^(NSDictionary<NSNumber *,NSArray *> * _Nullable result) {
        
        if ([result isKindOfClass:NSDictionary.class]) {
            
            // 根据type类型取出数据
            // Extract data according to type
            NSArray<TPSHistoryActivityModel *> *todayTotalActivity = result[@(TSDataType_TodayTotalActivity)];
            NSString *log = [todayTotalActivity yy_modelToJSONObject];
            XLOG_INFO(@"%@", APP_LOG_STRING(@"获取当日运动健康数据完成.\nAcquisition of the day's sports health data is complete."));
            XLOG_INFO(@"%@", log);
            dispatch_async(dispatch_get_main_queue(), ^{
                
                ConsoleResultToastTip(self.view);
            });
        }
    }];
}


//
- (void)manualSyncData {
    
    // 1.调用synchronousDataWithUserID:result:方法将手表中的数据同步到SDK中，userID用于标识数据属于哪个用户，如果您的数据不需要区分可置空。
    // 1.Call the synchronousDataWithUserID:result: method to synchronize the data in the watch to the SDK. The userID is used to identify which user the data belongs to. If your data does not need to be distinguished, you can leave it blank.
    XLOG_INFO(@"%@", APP_LOG_STRING(@"开始同步数据...\nStarting to sync data..."));
    [TPSSdk.share.synchronousDataAbility synchronousDataWithUserID:@"" result:^(TSDataType errorTypes) {
        
        // 同步失败的类型会在errorTypes中
        // The type of synchronization failure will be in errorTypes
        if (errorTypes == TSDataType_None) {
            
            XLOG_INFO(@"%@", APP_LOG_STRING(@"数据同步完成.\nData synchronization completed."));
            
            // 2.数据同步完成后调用此接口获取指定类型和指定时间段内的数据，如获取全部数据可设置type为TSDataType_All，时间区间从0到当前时间。
            // 2.After data synchronization is completed, call this interface to obtain data of the specified type and time period. If you want to obtain all data, you can set type to TSDataType_All, and the time interval is from 0 to the current time.
            [TPSSdk.share.synchronousDataAbility getHistoryDataWithType:TSDataType_All userID:@"" timeStart:0 timeEnd:[NSDate.date timeIntervalSince1970] resultBlock:^(NSDictionary<NSNumber *,NSArray *> * _Nullable result) {
                
                if ([result isKindOfClass:NSDictionary.class]) {
                    
                    // 根据type类型取出数据
                    // Extract data according to type
                    
                    // sport
                    NSArray<TPSHistorySportModel *> *sports = result[@(TSDataType_Sport)];
                    if ([sports isKindOfClass:NSArray.class] && sports.count > 0) {
                        
                        XLOG_INFO(@"运动数据 Sports data :\n%@\n", [sports yy_modelToJSONObject]);
                    }
                    
                    // activity
                    NSArray<TPSHistoryActivityModel *> *todayActivitys = result[@(TSDataType_TodayTotalActivity)];
                    NSArray<TPSHistoryActivityModel *> *activitys = result[@(TSDataType_Activity)];
                    NSArray<TPSHistoryActivityModel *> *todayTotalActivity = result[@(TSDataType_TodayTotalActivity)];
                    
                    // heartRate
                    NSArray<TPSHistoryHeartRateModel *> *heartRates = result[@(TSDataType_HeartRate)];
                    NSArray<TPSHistoryHeartRateModel *> *realTimeHeartRates = result[@(TSDataType_RealTimeHeartRate)];
                    NSArray<TPSHistoryHeartRateModel *> *restQuietHeartRates = result[@(TSDataType_RestQuietHeartRate)];
                    
                    // SPO2
                    NSArray<TPSHistorySPO2Model *> *SPO2s = result[@(TSDataType_BO)];
                    NSArray<TPSHistorySPO2Model *> *realTimeSPO2s = result[@(TSDataType_RealTimeSPO2)];
                    
                    // sleep
                    NSArray<TPSDaySleepEntity *> *sleeps = result[@(TSDataType_Sleep)];
                    
                    // stress
                    NSArray<TPSHistoryStressModel *> *stress = result[@(TSDataType_Stress)];
                }
            }];
            
        } else {
            
            if (errorTypes & TSDataType_Sleep)      { /* 睡眠数据同步失败 Sleep data sync failed */ }
            if (errorTypes & TSDataType_HeartRate)  { /* 心率数据同步失败 Heart rate data synchronization failed */ }
            if (errorTypes & TSDataType_Step)       { /* 步数数据同步失败 Step data synchronization failed */ }
            // if ...
            XLOG_INFO(@"%@", APP_LOG_STRING(@"数据同步失败."));
        }
    }];
    ConsoleResultToastTip(self.view);
}

-(void)findWatch{
    [TPSSdk.share.finderAbility findWatch];
}

//This is an example for get all misc setting
-(void)getAllMiscSetting{
    [TPSSdk.share.miscSettingAbility getAllMiscSetting:^(TPSMiscSettingModel *miscSettingModel) {
        ConsoleResultToastTip(self.view);
    }];
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}


-(void)sendNotificationSetting{
    __block FITCLOUDMN fit = FITCLOUDMN_NONE;
    NSLog(@"sendNotificationEnableList result %0llx", mymnSetting);
    
    [FitCloudKit setMessageNotification:self->mymnSetting block:^(BOOL succeed, NSError *error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            
            NSLog(@"sendNotificationEnableList result success");
        });
    }];
}

-(void)getNotificationSetting{
    [FitCloudKit getMessageNotificationSettingWithBlock:^(BOOL succeed, FITCLOUDMN mnSetting, NSError *error) {
        NSLog(@"getMessageNotificationSettingWithBlock cur %0llx", mnSetting);
        self->mymnSetting = mnSetting;
    }];
}

-(void)getBattery{
    [FitCloudKit getFirmwareVersionWithBlock:^(BOOL succeed, FitCloudFirmwareVersionObject *version, NSError *error) {
        [FitCloudKit getBatteryInfoWithBlock:^(BOOL succeed, FitCloudBatteryInfoObject *batteryInfo, NSError *error) {
            NSLog(@"getBatteryInfoWithBlock percent %d",batteryInfo.percent);
            dispatch_async(dispatch_get_main_queue(), ^{
                [self.view makeToast:[NSString stringWithFormat:@"battery:%d", batteryInfo.percent] duration:5.0 position:CSToastPositionTop];
            });
        }];
    }];
}

@end
