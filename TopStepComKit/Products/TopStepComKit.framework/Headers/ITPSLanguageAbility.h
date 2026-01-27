//
//  ITPSLanguageAbility.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/21.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSLanguageModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TPSLanguageModel;

@protocol ITPSLanguageAbility <NSObject,ITPSWearBaseAbility>

+ (instancetype)share;

- (RACSubject<TPSLanguageModel *>*)queryCurrentLanguage;

- (RACSubject*)setCurrentLangue:(TPSLanguageModel *)language;

- (void)querySupportLanguageCompletion:(void(^)(NSArray <NSString *>*languages))completion ;



@end

NS_ASSUME_NONNULL_END
