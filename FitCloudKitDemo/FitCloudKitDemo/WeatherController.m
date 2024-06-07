//
//  WeatherController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/3.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "WeatherController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface WeatherController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation WeatherController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0)
    {
        TPSFutureHourWeatherModel *futureHourModel1 = [[TPSFutureHourWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 3600 describe:TPSWeatherDescribeType_ENUM_CLEAR_DAY temperature:30];
        TPSFutureHourWeatherModel *futureHourModel2 = [[TPSFutureHourWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 7200 describe:TPSWeatherDescribeType_ENUM_CLOUDY temperature:25];
        
        NSArray<TPSFutureHourWeatherModel *> *futureHourModelArr = [NSArray arrayWithObjects:futureHourModel1, futureHourModel2, nil];
        
        TPSTodayWeatherModel *todayModel = [[TPSTodayWeatherModel alloc] initWithCurTemperature:28 minTemperature:22 maxTemperature:34 airpressure:50 wind:3 windAngle:2 windSpeed:10 humidity:10 uvIndex:3 visibility:10 futureHourList:futureHourModelArr];
        
        TPSFutureDayWeatherModel *futureModel1 = [[TPSFutureDayWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 86400 describe:TPSWeatherDescribeType_ENUM_PARTLY_CLOUDY_DAY minTemperature:23 maxTemperature:33];
        TPSFutureDayWeatherModel *futureModel2 = [[TPSFutureDayWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 172800 describe:TPSWeatherDescribeType_ENUM_CLEAR_DAY minTemperature:25 maxTemperature:35];
        TPSFutureDayWeatherModel *futureModel3 = [[TPSFutureDayWeatherModel alloc] initWithTimestamp:[[NSDate date] timeIntervalSince1970] + 259200 describe:TPSWeatherDescribeType_ENUM_CLEAR_DAY minTemperature:24 maxTemperature:34];
        
        NSArray<TPSFutureDayWeatherModel *> *futureModelArr = [NSArray arrayWithObjects:futureModel1, futureModel2, futureModel3, nil];
        
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
