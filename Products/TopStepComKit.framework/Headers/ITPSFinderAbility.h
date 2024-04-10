//
//  IWearFinderSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef ITPSFinderAbility_h
#define ITPSFinderAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSMusicUpdateModel.h>
#import <TopStepComKit/ITPSFileAbility.h>
#import <TopStepComKit/TPSMusicModel.h>
//#import <ReactiveObjC.h>

@class RACSubject<ValueType>;
@protocol ITPSFinderAbility <NSObject, ITPSWearBaseAbility>

+(instancetype)share;

/*
 * @brief 手表回复手机找到了
 */
-(void)replyFindPhone;

/*
 * @brief 查找手表
 */
-(void)findWatch;

/*
 * @brief 停止查找手表
 */
-(void)stopFindWatch;

/*
 * @brief
 */
-(RACSubject*)observeFindingPhone;

/*
 * @brief
 */
-(RACSubject*)observeWatchBeFound;

/*
 * @brief
 */
-(RACSubject*)observeWatchStopFindingPhone;


@end


#endif /* IWearAlbumSync_h */
