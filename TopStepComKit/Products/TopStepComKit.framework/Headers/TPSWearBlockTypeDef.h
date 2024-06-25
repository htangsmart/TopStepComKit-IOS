//
//  TPSWearBlockTypeDef.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef TPSWearBlockTypeDef_h
#define TPSWearBlockTypeDef_h

typedef void(^TPSSendMsgResult)(BOOL isSendOK);

typedef void(^TPSResultBlock)(BOOL isSendOK, NSDictionary * _Nullable errorInfo);

typedef void(^TPSRttDicResult)(NSDictionary<NSString *, id> * _Nonnull jsonMsg);


#endif /* TPSWearBlockTypeDef_h */
