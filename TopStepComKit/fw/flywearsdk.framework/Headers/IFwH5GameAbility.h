//
//  IFwH5GameAbility.h
//  flywearsdk
//
//  Created by 磐石 on 2024/3/12.
//

#import <flywearsdk/IFwWearBaseAbility.h>

NS_ASSUME_NONNULL_BEGIN
@class RACSubject<ValueType>;

@protocol IFwH5GameAbility <IFwWearBaseAbility>

+ (instancetype _Nonnull )share;

- (void)gameStart;

- (void)gameFinished;

- (void)gamePause;

- (void)gameContinue;

-(RACSubject*)observeGameValue;

- (BOOL)isSupportSensorGame;

@end

NS_ASSUME_NONNULL_END
