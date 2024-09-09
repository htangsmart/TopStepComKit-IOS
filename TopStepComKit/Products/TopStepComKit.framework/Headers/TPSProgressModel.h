//
//  ProgressModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef TPSProgressModel_h
#define TPSProgressModel_h


@interface TPSProgressModel : NSObject

typedef NS_ENUM(UInt8,TPSProgressModel_Event_Type){
    TPSProgressModel_Event_Type_OnSuccess = 0,  //成功不一定完毕
    TPSProgressModel_Event_Type_OnFailed = 1,
    TPSProgressModel_Event_Type_OnProcess = 2,
    TPSProgressModel_Event_Type_OnCompleted = 3, //完毕位于成功之后触发
};

typedef void(^onTPSProgressResult)(TPSProgressModel* model);

///1.0为满进度
@property(nonatomic, assign) float percent;
@property(nonatomic, assign) TPSProgressModel_Event_Type eventType;


@end



#endif /* ProgressModel_h */
