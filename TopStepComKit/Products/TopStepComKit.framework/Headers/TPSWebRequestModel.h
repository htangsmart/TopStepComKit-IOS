//
//  TPSWebRequestModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef TPSWebRequestModel_h
#define TPSWebRequestModel_h

@class FwWebRequestModel;
@interface TPSWebRequestModel : NSObject

@property(nonatomic, strong) NSString* url;
@property(nonatomic, strong) NSString* funName;
@property(nonatomic, assign) int requestId;
@property(nonatomic, strong) NSString* appId;
@property(nonatomic, strong) NSDictionary* params;
@property(nonatomic, strong) NSArray* localPathArr;

-(instancetype)initWithFwModel:(FwWebRequestModel*)fwModel;

@end

#endif /* FwWebRequestModel_h */
