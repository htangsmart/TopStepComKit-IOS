//
//  FwWebResponseModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/19.
//

#ifndef FwWebResponseModel_h
#define FwWebResponseModel_h

@interface FwWebResponseModel : NSObject

@property(nonatomic, assign) int requestId;
/**
 0--网络请求成功,1--网络请求失败
 */
@property(nonatomic, assign) int error;
@property(nonatomic, strong) NSString* appId;
@property(nonatomic, strong) NSString* funName;
@property(nonatomic, strong) NSDictionary* content;

@end


#endif /* FwDayPrayModel_h */
