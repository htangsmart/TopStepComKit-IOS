//
//  ITPSAIWatchFaceAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/4/10.
//

#import <TopStepComKit/ITPSWearBaseAbility.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ITPSAIWatchFaceAbility <ITPSWearBaseAbility>

typedef void(^TPSAIWatchFaceCreateResultBlock)(BOOL isSuccess,NSError *error);

typedef void(^TPSAudioResultBlock)(BOOL isSuccess, NSString *audioPath , NSError *error);


- (void)registerAIWatchFaceCreateResult:(TPSAIWatchFaceCreateResultBlock)result;

- (void)registerRecognizeAudioPathResult:(TPSAudioResultBlock)audioPathResult;

@end

NS_ASSUME_NONNULL_END
