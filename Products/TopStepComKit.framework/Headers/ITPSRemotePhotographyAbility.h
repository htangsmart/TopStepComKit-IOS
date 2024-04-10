//
//  TFwRemotePhotographyAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/22.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ITPSRemotePhotographyAbility <NSObject,ITPSWearBaseAbility>

+ (instancetype)share;

- (RACSubject *)enterRemotePhotography;

- (void)exitRemotePhotography;



@end

NS_ASSUME_NONNULL_END
