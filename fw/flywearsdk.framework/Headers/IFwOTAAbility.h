//
//  IWearOTASync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//

#ifndef IWearOTASync_h
#define IWearOTASync_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwDevInfoModel.h>
#import <flywearsdk/FwProgressModel.h>

@protocol IFwOTAAbility <NSObject,IFwWearBaseAbility>

+(instancetype)share;

-(void)otaUpdateWithLocalPath:(NSString*)localPath block:(onProgressResult)block;

@end


#endif /* IWearDevInfoSync_h */
