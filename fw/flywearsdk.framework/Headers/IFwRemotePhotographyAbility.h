//
//  IFwRemotePhotographyAbility.h
//  flywearsdk
//
//  Created by 磐石 on 2024/3/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IFwRemotePhotographyAbility <NSObject>

+ (instancetype)share;

- (RACSubject *)enterRemotePhotography;

- (void)exitRemotePhotography;


@end

NS_ASSUME_NONNULL_END
