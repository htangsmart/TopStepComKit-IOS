//
//  AppDelegate+LoggerService.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AppDelegate+LoggerService.h"
#import <XLFacility/XLFacilityMacros.h>
#import <iOSLogBrowserSDK/iOSLogBrowserSDK.h>
#import <Reachability/Reachability.h>


#if __has_include(<QuickTraceiOSLogger/QuickTraceiOSLogger.h>)
#import <QuickTraceiOSLogger/QuickTraceiOSLogger.h>
#else
//#import "QuickTraceiOSLogger.h"
#import <XLFacility/XLFacilityMacros.h>
#import <iOSLogBrowserSDK/iOSLogBrowserSDK.h>
#import <Reachability/Reachability.h>


#endif

#if __has_include(<XLFacility/XLStandardLogger.h>)
#import <XLFacility/XLStandardLogger.h>
#else
#import "XLStandardLogger.h"
#endif

@interface AppDelegate ()

@property(nonatomic, assign) BOOL started;


@end

@implementation AppDelegate (LoggerService)



-(void) loggerServiceConfig
{
    {
        [[XLStandardLogger sharedOutputLogger] setFormat:XLLoggerFormatString_NSLog];
        [[XLStandardLogger sharedErrorLogger] setFormat:XLLoggerFormatString_NSLog];
        
    }
    
    
    {
        
        iOSLogBrowserOption* option = [iOSLogBrowserOption defaultOption];
        option.suspendInBackground = YES;
        [iOSLogBrowserSDK startWithOption:option];

        XLOG_INFO(@"%@", @"您正在使用 iOS 局域网日志查看服务！");
        self.started = YES;

//        [QuickiOSLogServer start];
//        XLOG_INFO(@"%@", APP_LOG_STRING(@"您正在使用 iOS 远程日志查看服务！"));
    }
}

@end
