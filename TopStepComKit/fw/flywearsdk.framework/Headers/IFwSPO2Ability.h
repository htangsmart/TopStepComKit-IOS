//
//  IWearHistorySPO2Sync.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/18.
//

#ifndef IWearHistorySPO2Sync_h
#define IWearHistorySPO2Sync_h

#import <flywearsdk/FwHistorySPO2Model.h>
#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwSpo2ConfigModel.h>
#import <flywearsdk/WearBlockTypeDef.h>

@protocol IFwSPO2Ability <NSObject,IFwWearBaseAbility>

typedef void(^FwHistorySPO2Callback)(NSArray<FwHistorySPO2Model*>* _Nullable historySPO2ModelList);
typedef void(^FwSpo2ConfigCallback)(FwSpo2ConfigModel* _Nullable configModel);

+(instancetype _Nonnull )share;
-(void)getHistorySPO2:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistorySPO2Callback _Nullable)block;
-(void)getHistoryRealTimeSPO2:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime block:(FwHistorySPO2Callback _Nullable)block;
-(void)getSpo2Config:(FwSpo2ConfigCallback _Nonnull )block;
-(void)setSpo2Config:(FwSpo2ConfigModel*)model block:(FwSendMsgResult)block;

@end


#endif /* IWearCurDayActivitySync_h */
