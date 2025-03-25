//
//  IWearOTASync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//

#ifndef ITPSOTAAbility_h
#define ITPSOTAAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSDevInfoModel.h>
#import <TopStepComKit/TPSProgressModel.h>
#import <TopStepComKit/TPSOTAModel.h>

@protocol ITPSOTAAbility <NSObject,ITPSWearBaseAbility>

+(instancetype)share;

-(void)otaUpdateWithLocalPath:(NSString*)localPath block:(onTPSProgressResult)block;
-(void)otaUpdateWithLocalPath:(NSString*)localPath otaModel:(nullable TPSOTAModel*)otaModel block:(onTPSProgressResult _Nonnull )block;

@end


#endif /* IWearDevInfoSync_h */
