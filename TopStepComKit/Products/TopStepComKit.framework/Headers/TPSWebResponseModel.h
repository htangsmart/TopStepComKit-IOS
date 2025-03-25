//
//  TPSWebResponseModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/19.
//

#ifndef TPSWebResponseModel_h
#define TPSWebResponseModel_h

@class FwWebResponseModel;
@interface TPSWebResponseModel : NSObject

@property(nonatomic, assign) long requestId;
/**
 0--网络请求成功,1--网络请求失败
 */
@property(nonatomic, assign) int error;
@property(nonatomic, copy) NSString* errorMsg;
@property(nonatomic, copy) NSString* appId;
@property(nonatomic, copy) NSString* funName;
/**
 若存在云端下载的文件需要转发给手表，则要指定该文件在手表所存储的文件夹路径
 */
@property(nonatomic, copy) NSString* remoteSavePath;
@property(nonatomic, strong) NSDictionary* content;
@property(nonatomic, strong) NSArray* localPathArr;

-(FwWebResponseModel*)toFwModel;

@end


#endif /* FwDayPrayModel_h */
