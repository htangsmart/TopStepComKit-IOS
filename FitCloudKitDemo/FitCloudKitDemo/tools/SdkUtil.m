//
//  SdkUtil.m
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/7/26.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SdkUtil.h"
#import <AFNetworking/AFNetworking.h>

@implementation SdkUtil

+(void)requestCommon:(NSDictionary*)dic rqUrl:(NSString*)rqUrl Result:(void(^)(NSDictionary *info))result{
    NSDictionary *headers = @{@"content-type": @"application/json",
                              @"cache-control": @"no-cache"};
    NSData *bodyData = [NSJSONSerialization dataWithJSONObject:dic options:0 error:nil];
    [self requestUrl:rqUrl Header:headers Body:bodyData Result:result];
}


+(void)requestUrl:(NSString*)url
           Header:(NSDictionary*)headers
             Body:(NSData *__nullable)bodyData
           Result:(void(^)(NSDictionary *info))result
{
    NSLog(@"requestUrl start url: %@", url);
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:url]
                                                           cachePolicy:NSURLRequestUseProtocolCachePolicy
                                                       timeoutInterval:10.0];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    if(bodyData)[request setHTTPBody:bodyData];
    
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request
                                                completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            NSLog(@"error url:%@ :%@", url, error);
            [SdkUtil mainTask:^{
                if (result) result(nil);
            }];
            
        } else {
            NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableLeaves error:nil];
            NSString *jsonStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            [SdkUtil mainTask:^{
                NSLog(@"requestUrl %@ dic:%@ json is %@", url, dict,jsonStr);
                if (result) result(dict);
            }];
        }
    }];
    [dataTask resume];
}

+(void)mainTask:(TPS_Action)block{
    dispatch_async(dispatch_get_main_queue(), ^{
        block();
    });
}

+(void) sendPostRequestWithFormParameters{
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
                    NSLog(@"JSON解析错误: %@", jsonError.localizedDescription);
                } else {
                    // 使用解析后的JSON数据
                    NSLog(@"Response: %@", json);
                }
            }
        }
    }] resume];
}

//这里的大坑是不覆盖原路径
+(void)downloadUrl:(NSString*)urlString Path:(NSString*)path Result:(JLHTTP_BK)result{
    //构造资源链接
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    //创建AFN的manager对象
    AFHTTPSessionManager *manager = [[AFHTTPSessionManager alloc] initWithSessionConfiguration:configuration];
    //构造URL对象
    NSURL *url = [NSURL URLWithString:urlString];
    //构造request对象
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    //使用系统类创建downLoad Task对象
    NSURLSessionDownloadTask* downloadTask = [manager downloadTaskWithRequest:request progress:^(NSProgress * _Nonnull downloadProgress) {
        float progress = 1.0 * downloadProgress.completedUnitCount/downloadProgress.totalUnitCount;
        NSLog(@"AFN---->%f",progress);
        if (result) { result(progress,JLHTTP_ResultDownload);}
        
    } destination:^NSURL * _Nonnull(NSURL * _Nonnull targetPath, NSURLResponse * _Nonnull response) {

        return [NSURL fileURLWithPath:path];
    } completionHandler:^(NSURLResponse * _Nonnull response, NSURL * _Nullable filePath, NSError * _Nullable error) {
        //下载完成走这个block
        if (!error)
        {
            //如果请求没有错误(请求成功), 则打印地址
            NSLog(@"AFN---->Success:%@", [filePath lastPathComponent]);
            if (result) { result(1.0,JLHTTP_ResultSuccess);}
        }else{
            NSLog(@"AFN---->err");
            if (result) { result(1.0,JLHTTP_ResultFail);}
        }
    }];
    //开始请求
    [downloadTask resume];
}

/**
 在存在的文件路径上，建立新的文件。file参数为""字符串时，会创建文件夹
 
 @param sPath 沙盒
 @param mPath 中间路径
 @param file 文件名
 @return 完成路径
 */
+(NSString*)createOn:(NSSearchPathDirectory)sPath
          MiddlePath:(NSString*)mPath
                File:(NSString*)file{
    NSString * docsdir = [NSSearchPathForDirectoriesInDomains(sPath, NSUserDomainMask, YES) objectAtIndex:0];
    NSString *folderPath = [docsdir stringByAppendingPathComponent:mPath];
    NSString* filePath;
    if(file && file.length > 0){
        filePath = [folderPath stringByAppendingPathComponent:file];
    }
    NSFileManager *fileManager = [NSFileManager defaultManager];
    BOOL isDir = NO;
    // fileExistsAtPath 判断一个文件或目录是否有效，isDirectory判断是否一个目录
    BOOL existed = [fileManager fileExistsAtPath:folderPath isDirectory:&isDir];
    if (!existed || !isDir) {
        // 在Document目录下创建一个archiver目录
        [fileManager createDirectoryAtPath:folderPath withIntermediateDirectories:YES attributes:nil error:nil];
    }
    if(filePath){
        [fileManager createFileAtPath:filePath contents:[NSMutableData new] attributes:nil];
    }
    if(filePath){
        return filePath;
    }else{
        return folderPath;
    }
}

@end
