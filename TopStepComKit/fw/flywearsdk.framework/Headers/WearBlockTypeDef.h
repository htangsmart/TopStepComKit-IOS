//
//  WearBlockTypeDef.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef WearBlockTypeDef_h
#define WearBlockTypeDef_h



typedef void(^FwSendMsgResult)(BOOL isSendOK);

typedef void(^FwResultBlock)(BOOL isSendOK, NSDictionary * _Nullable errorInfo);

typedef void(^FwRttDicResult)(NSDictionary<NSString *, id> * _Nonnull jsonMsg);


#endif /* WearBlockTypeDef_h */
