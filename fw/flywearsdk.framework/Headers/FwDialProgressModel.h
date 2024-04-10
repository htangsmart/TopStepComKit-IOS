//
//  DialProgressModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/23.
//

#ifndef DialProgressModel_h
#define DialProgressModel_h

@interface FwDialProgressModel : NSObject

typedef NS_ENUM(UInt8,FwDialProgressModel_Event_Type){
    FwDialProgressModel_Event_Type_OnSuccess = 0,  //成功不一定完毕
    FwDialProgressModel_Event_Type_OnFailed = 1,
    FwDialProgressModel_Event_Type_OnProcess = 2,
    FwDialProgressModel_Event_Type_OnInstalling = 3,
    FwDialProgressModel_Event_Type_OnCompleted = 4, //完毕位于成功之后触发
};



///1.0为满进度
@property(nonatomic, assign) float percent;
@property(nonatomic, assign) FwDialProgressModel_Event_Type eventType;

@end


#endif /* DialProgressModel_h */
