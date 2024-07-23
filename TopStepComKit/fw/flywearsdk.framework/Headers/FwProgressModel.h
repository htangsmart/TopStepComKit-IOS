//
//  ProgressModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef ProgressModel_h
#define ProgressModel_h

@interface FwProgressModel : NSObject

typedef NS_ENUM(UInt8,FwProgressModel_Event_Type){
    FwProgressModel_Event_Type_OnSuccess = 0,  //成功不一定完毕
    FwProgressModel_Event_Type_OnFailed = 1,
    FwProgressModel_Event_Type_OnProcess = 2,
    FwProgressModel_Event_Type_OnCompleted = 3, //完毕位于成功之后触发
};

typedef void(^onProgressResult)(FwProgressModel* model);

///1.0为满进度
@property(nonatomic, assign) float percent;
@property(nonatomic, assign) FwProgressModel_Event_Type eventType;

@end



#endif /* ProgressModel_h */
