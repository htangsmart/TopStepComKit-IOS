//
//  AppDelegate.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AppDelegate.h"
#import "AppDelegate+LoggerService.h"
#import "AppDelegate+FitCloudKit.h"
#import <AFNetworking/AFNetworking.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [[TPSSdk share] initSdk];
    TPSOptions* tpsOptions = [TPSOptions defaultOption];
    tpsOptions.debugMode = YES;
    [[TPSSdk share] initDeviceTypeWith:TPSDeviceType_OSW805 option:tpsOptions];
    
    //--- 网络监测 ---//这一行会触发使用网络权限提示选择框，其他请求网络的时候貌似也会触发。
    AFNetworkReachabilityManager *net = [AFNetworkReachabilityManager sharedManager];
    [net startMonitoring];
    
    //监听到手表已经在系统层面连上ble,但是手表此时无账号，这意味着手表刚恢复出厂设置
    //Detected that the watch has been connected to BLE at the system level, but the watch currently has no account, which means that the watch has just been restored to factory settings
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onConnectedButNoAccountNumber:) name:FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY object:nil];
    //监听这个事件，这个事件发生在完成手表绑定成功之后
    //Monitor this event, which occurred after successfully binding the watch
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onPrepareSyncWorkEndEvent:) name:FITCLOUDEVENT_PREPARESYNCWORK_END_NOTIFY object:nil];
    return YES;
}

//-(void)onConnectedButNoAccountNumber:(NSNotification*)notification{
//    //这里假设你的用户id已经存在，如果不存在用户id，请不要执行下面这段代码
//    //Assuming that your user ID already exists here, if there is no user ID, please do not execute the following code
//    BOOL existedUserId = YES;
//    if(existedUserId){
//        NSString* userId = @"123456789";
//        [FitCloudKit bindUserObject:userId randomCode:nil abortIfExist:NO block:^(BOOL succeed, NSError *error) {
//            dispatch_async(dispatch_get_main_queue(), ^{
//                NSLog(@"bindUserObject is success %d error info is %@",succeed,error);
//                if (!succeed) {
//                    NSLog(@"bindUserObject fail");
//                }
//            });
//        }];
//    }
//    
//}

// 请在此方法之内 同步数据、设置语言等等
//Please synchronize data, set language, etc. within this method
//- (void)onPrepareSyncWorkEndEvent:(NSNotification *)notification{
//    NSLog(@"onPrepareSyncWorkEndEvent %@",notification);
//    //从手表端获取手表上的目标设置值
//    //Retrieve the target setting value on the watch from the watch end
//    [FitCloudKit getDailyGoalWithBlock:^(BOOL succeed, FitCloudDailyGoalObject *goal, NSError *error) {
//        NSLog(@"step target from watch %d", goal.stepCountGoal);
//        NSLog(@"distance target from watch %d (cm)", goal.distanceGoal);
//        NSLog(@"calories target from watch %d (cal), (note:not kcal)", goal.caloryGoal);
//        NSLog(@"duration target from watch %d (minute)", goal.durationGoal);
//    }];
//}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
