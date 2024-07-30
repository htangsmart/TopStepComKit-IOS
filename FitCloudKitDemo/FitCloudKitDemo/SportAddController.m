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
#import "SdkUtil.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface SportAddController (){
    NSMutableArray<SportAddModel*>* sportToAddList;
    //list the types of sports supported in this watch
    NSArray<NSNumber *> *sportSupportedList;
    NSArray<FitCloudWatchSportModeObject *> *currentWatchSportList;
    BOOL isBusy;
    UIActivityIndicatorView* activityIndicator;
}

- (IBAction)OnGoBack:(id)sender;
@end

@implementation SportAddController

- (void)viewDidLoad {
    [super viewDidLoad];
    isBusy = NO;
    self->sportToAddList = [NSMutableArray new];
    [self getSupportSportTypeFromWatch];
    // Do any additional setup after loading the view.
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return sportToAddList.count;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSLog(@"abccc");
    __weak typeof(self) weakSelf = self;
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    if(isBusy){
        NSLog(@"it is busy now, downloading, do not try other operation");
        ConsoleResultToastTip(weakSelf.view);
        return;
    }
    NSString* fileName = sportToAddList[indexPath.row].binUrl.lastPathComponent;
    NSString * docsdir = [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    NSString *binFilePath = [docsdir stringByAppendingPathComponent:fileName];
    isBusy = YES;
    [self showProgress];
    [SdkUtil downloadUrl:sportToAddList[indexPath.row].binUrl Path:binFilePath Result:^(float progress, JLHTTP_Result result) {
        if (result == JLHTTP_ResultDownload) {
            NSLog(@"Download file progress %f", progress);
        }
        if (result == JLHTTP_ResultSuccess) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [TPSSdk.share.otaAbility otaUpdateWithLocalPath:binFilePath block:^(TPSProgressModel *model) {
                    if (model.eventType == TPSProgressModel_Event_Type_OnCompleted) {
                        self->isBusy = NO;
                        NSLog(@"push sportui bin ok");
                        OpResultToastTip(weakSelf.view, YES);
                        [self removeProgress];
                    } else if (model.eventType == TPSProgressModel_Event_Type_OnProcess){
                        NSLog(@"sportui bin progress number:%.1f", model.percent);
                    }else if (model.eventType == TPSProgressModel_Event_Type_OnFailed) {
                        NSLog(@"push sportui bin fail");
                        OpResultToastTip(weakSelf.view, NO);
                    }
                }];
            });
        }
        if (result == JLHTTP_ResultFail) {
            NSLog(@"Download file fail");
        }
    }];
    
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [[UITableViewCell alloc] init];
    if([self isInCurrentWatchSportList:sportToAddList[indexPath.row].sportType]){
        cell.textLabel.text = [NSString stringWithFormat:@"%@,%@",sportToAddList[indexPath.row].sportName, @" -current in watch"];
    }else{
        cell.textLabel.text = sportToAddList[indexPath.row].sportName;
    }
    
    [cell.imageView sd_setImageWithURL:[NSURL URLWithString:sportToAddList[indexPath.row].iconUrl] placeholderImage:[UIImage imageNamed:@"icon_health_act_progress.png"]];
    return cell;
}



- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

-(void)getSupportSportTypeFromWatch{
    [FitCloudKit getSupportedWatchSportsWithBlock:^(BOOL succeed, NSArray<NSNumber *> *sports, NSError *error) {
        self->sportSupportedList = sports;
        dispatch_async(dispatch_get_main_queue(), ^{
            [self getCurrentSportTypeFromWatch];
        });
    }];
}

-(void)getCurrentSportTypeFromWatch{
    [FitCloudKit getCurrentWatchSportsWithBlock:^(BOOL succeed, NSArray<FitCloudWatchSportModeObject *> *sports, NSError *error) {
        self->currentWatchSportList = sports;
        dispatch_async(dispatch_get_main_queue(), ^{
            [self getSportTypeInformationFromServer];
        });
    }];
}

-(void) getSportTypeInformationFromServer{
    // 目标URL
    NSURL *url = [NSURL URLWithString:@"https://fitcloud.hetangsmart.com/public/sportbin/list"];
  
    // 创建可变URL请求
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
      
    // 设置请求方法为POST
    request.HTTPMethod = @"POST";
  
    // 设置请求头（如果需要的话）
    [request setValue:@"application/x-www-form-urlencoded" forHTTPHeaderField:@"Content-Type"];
  
    // 创建表单参数
    FitCloudAllConfigObject *allConfig = [FitCloudKit allConfig];
    FitCloudFirmwareVersionObject* firmware = allConfig.firmware;
    NSString* hardwareInfo = [firmware description];
    NSString *postData = [NSString stringWithFormat:@"hardwareInfo=%@", hardwareInfo];
      
    // 将字符串转换为NSData
    request.HTTPBody = [postData dataUsingEncoding:NSUTF8StringEncoding];
  
    // 初始化URLSession
    NSURLSession *session = [NSURLSession sharedSession];
      
    // 创建并启动data task
    [[session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        if (error) {
            // 处理错误
            NSLog(@"请求错误: %@", error.localizedDescription);
        } else {
            // 处理返回的数据
            if (data) {
                // 假设服务器返回的是JSON数据
                NSError *jsonError;
                NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:0 error:&jsonError];
                if (jsonError) {
                    NSLog(@"JSON parse error: %@", jsonError.localizedDescription);
                } else {
                    // 使用解析后的JSON数据
                    NSLog(@"Response: %@", json);
                    self->sportToAddList = [NSMutableArray new];
                    NSArray* dataList = json[@"data"];
                    for(int i=0;i<dataList.count;i++){
                        SportAddModel* sportAddModel = [[SportAddModel alloc] init];
                        sportAddModel.binUrl = dataList[i][@"binUrl"];
                        sportAddModel.iconUrl = dataList[i][@"iconUrl"];
                        sportAddModel.sportName = dataList[i][@"sportUiName"];
                        sportAddModel.sportType = [dataList[i][@"sportUiType"] intValue];
                        if([self isInSupportedList:sportAddModel.sportType]){
                            [self->sportToAddList addObject:sportAddModel];
                        }
                    }
                    dispatch_async(dispatch_get_main_queue(), ^{
                        [self.mTableView reloadData];
                    });
                }
            }
        }
    }] resume];
}

-(BOOL)isInSupportedList:(int)sportType{
    if(sportSupportedList == nil){
        return YES;
    }
    for(int i=0;i<sportSupportedList.count;i++){
        if([sportSupportedList[i] intValue] == sportType){
            return YES;
        }
    }
    return NO;
}

-(BOOL)isInCurrentWatchSportList:(int)sportType{
    for(int i=0;i<currentWatchSportList.count;i++){
        if(currentWatchSportList[i].workoutType == sportType){
            return YES;
        }
    }
    return NO;
}

-(void)showProgress{
    activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    activityIndicator.center = CGPointMake(([UIScreen mainScreen].bounds.size.width)/2, ([UIScreen mainScreen].bounds.size.height)/2); // 或者设置其他frame
    activityIndicator.color = [UIColor blueColor];
    [self.view addSubview:activityIndicator];
    [activityIndicator startAnimating]; // 开始旋转
}

-(void)removeProgress{
    [activityIndicator stopAnimating]; // 停止旋转并从父视图中移除（可选）
    [activityIndicator removeFromSuperview];
}


//Response: {
//    data =     (
//                {
//            binSize = 19108;
//            binUrl = "https://fitcloud.hetangsmart.com/oss/upfiles/sportbin/2024/05/31/287171fc9cfb46a99a146c22bb58c053.bin";
//            category = 03617;
//            createTime = 1717138341000;
//            customer = "\U516c\U5171:GUI-8773";
//            iconUrl = "https://fitcloud.hetangsmart.com/oss/upfiles/admin/2024/05/31/07a8896268744552b246450826e08b3f.png";
//            id = 5608;
//            lcd = 22;
//            name = "SportModeUI_03617_000_20240531_MP-c7d4ae58da5d2d391d0c5ab26ca61cfd.bin";
//            relatedProject = "<null>";
//            sportUiName = "Outdoor Cycle";
//            sportUiNameCn = "\U6237\U5916\U9a91\U884c";
//            sportUiType = 0;
//            uiType =             {
//                nameCn = "\U6237\U5916\U9a91\U884c";
//                nameEn = "Outdoor Cycle";
//                type = 0;
//            };
//        },

@end
