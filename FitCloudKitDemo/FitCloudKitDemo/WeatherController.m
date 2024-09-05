//
//  WeatherController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/3.
//  Copyright © 2019 HetangSmart. All rights reserved.
//  天气 --- Weather

#import "WeatherController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface WeatherController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation WeatherController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    FITCLOUDPREFER isWeatherEnable = FitCloudKit.allConfig.prefer & FITCLOUDPREFER_WEATHERPUSH;
    NSLog(@"FITCLOUDPREFER isWeatherEnable1 %d", isWeatherEnable);
    isWeatherEnable = isWeatherEnable & (FITCLOUDPREFER_WEATHERPUSH ^ FITCLOUDPREFER_WEATHERPUSH);
    NSLog(@"FITCLOUDPREFER isWeatherEnable2 %d", isWeatherEnable);
    [FitCloudKit setFitCloudPrefer:isWeatherEnable block:^(BOOL succeed, NSError *error) {
        [FitCloudKit getFitCloudPreferWithBlock:^(BOOL succeed, FITCLOUDPREFER prefer, NSError *error) {
            FITCLOUDPREFER isWeatherEnableNext = prefer & FITCLOUDPREFER_WEATHERPUSH;
            NSLog(@"FITCLOUDPREFER isWeatherEnable3 %d", isWeatherEnableNext);
        }];
    }];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0) {
        // 同步天气 --- Sync Weather
        TPSFutureHourWeatherModel *futureHourModel1 = [[TPSFutureHourWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 3600 describe:TPSWeatherLargeCategory_CLEAR temperature:30];
        TPSFutureHourWeatherModel *futureHourModel2 = [[TPSFutureHourWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 7200 describe:TPSWeatherLargeCategory_CLEAR temperature:25];
        
        NSArray<TPSFutureHourWeatherModel *> *futureHourModelArr = [NSArray arrayWithObjects:futureHourModel1, futureHourModel2, nil];
        
        TPSTodayWeatherModel *todayModel = [[TPSTodayWeatherModel alloc] initWithCurTemperature:28 minTemperature:22 maxTemperature:34 airpressure:50 wind:3 windAngle:2 windSpeed:10 humidity:10 uvIndex:3 visibility:10 futureHourList:futureHourModelArr];
        
        TPSFutureDayWeatherModel *futureModel1 = [[TPSFutureDayWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 86400 describe:TPSWeatherLargeCategory_CLEAR minTemperature:23 maxTemperature:33];
        TPSFutureDayWeatherModel *futureModel2 = [[TPSFutureDayWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 172800 describe:TPSWeatherLargeCategory_CLEAR minTemperature:25 maxTemperature:35];
        TPSFutureDayWeatherModel *futureModel3 = [[TPSFutureDayWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 259200 describe:TPSWeatherLargeCategory_CLEAR minTemperature:24 maxTemperature:34];
        
        NSArray<TPSFutureDayWeatherModel *> *futureModelArr = [NSArray arrayWithObjects:futureModel1, futureModel2, futureModel3,futureModel3,futureModel3,futureModel3,futureModel3, nil];
        
        TPSWeatherModel *model = [[TPSWeatherModel alloc] initWithCity:@"深圳" temperatureUnit:0 updateTime:[[NSDate date] timeIntervalSince1970] todayWeather:todayModel futureDayWeather:futureModelArr];
        
        __weak typeof(self) weakSelf = self;
        [TPSSdk.share.weatherAbility sendWeather:model block:^(BOOL isSendOK) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (isSendOK) {
                    OpResultToastTip(weakSelf.view, YES);
                } else {
                    OpResultToastTip(weakSelf.view, NO);
                }
            });
        }];
    } else if (indexPath.row == 1) {
        // 天气开关(开) --- Weather Switch (Open)
        [TPSSdk.share.miscSettingAbility sendWeather_sync_mode:TPSMiscSettingModel_State_Open];
        OpResultToastTip(self.view, YES);
    } else if (indexPath.row == 2) {
        // 天气开关(关) --- Weather Switch (Close)
        [TPSSdk.share.miscSettingAbility sendWeather_sync_mode:TPSMiscSettingModel_State_Close];
        OpResultToastTip(self.view, YES);
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
