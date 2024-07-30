//
//  SdkUtil.h
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/7/26.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#ifndef SdkUtil_h
#define SdkUtil_h

typedef NS_ENUM(UInt8, JLHTTP_Result) {
    JLHTTP_ResultFail         = 0x00, //下载失败
    JLHTTP_ResultSuccess      = 0x01, //下载成功
    JLHTTP_ResultDownload     = 0x02, //正在下载
};

typedef void(^JLHTTP_BK)(float progress, JLHTTP_Result result);

@interface SdkUtil : NSObject

+(void)requestCommon:(NSDictionary*)dic rqUrl:(NSString*)rqUrl Result:(void(^)(NSDictionary *info))result;

+(void)sendPostRequestWithFormParameters;

+(void)downloadUrl:(NSString*)urlString Path:(NSString*)path Result:(JLHTTP_BK)result;

+(NSString*)createOn:(NSSearchPathDirectory)sPath
          MiddlePath:(NSString*)mPath
File:(NSString*)file;

@end


#endif /* SdkUtil_h */
