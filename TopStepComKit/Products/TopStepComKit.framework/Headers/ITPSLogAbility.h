//
//  ITPSLogAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/8/21.
//

#import <Foundation/Foundation.h>


@protocol ITPSLogAbility <NSObject>

- (void)requestWatchLogComplete:(void(^)(BOOL success, NSData *logData))complete;

@end

