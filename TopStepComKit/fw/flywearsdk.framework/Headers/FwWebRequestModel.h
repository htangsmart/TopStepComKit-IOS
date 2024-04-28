//
//  FwWebRequestModel.h
//  flywearsdk
//
//  Created by Topstep on 2024/3/18.
//

#ifndef FwWebRequestModel_h
#define FwWebRequestModel_h

@interface FwWebRequestModel : NSObject

@property(nonatomic, strong) NSString* url;
@property(nonatomic, strong) NSString* funName;
@property(nonatomic, assign) int requestId;
@property(nonatomic, strong) NSString* appId;
@property(nonatomic, strong) NSDictionary* params;
@property(nonatomic, strong) NSArray* localPathArr;

@end

#endif /* FwWebRequestModel_h */
