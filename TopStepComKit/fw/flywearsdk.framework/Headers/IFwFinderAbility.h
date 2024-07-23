//
//  IWearFinderSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef IWearFinderSync_h
#define IWearFinderSync_h

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwMusicUpdateModel.h>
#import <flywearsdk/IFwFileAbility.h>
#import <flywearsdk/FwMusicModel.h>
//#import <ReactiveObjC.h>

@class RACSubject<ValueType>;
@protocol IFwFinderAbility <NSObject, IFwWearBaseAbility>

+(instancetype)share;

-(void)replyFindPhone;
-(void)findWatch;
-(void)stopFindWatch;
-(RACSubject*)observeFindingPhone;
-(RACSubject*)observeWatchBeFound;
-(RACSubject*)observeWatchStopFindingPhone;


@end


#endif /* IWearAlbumSync_h */
