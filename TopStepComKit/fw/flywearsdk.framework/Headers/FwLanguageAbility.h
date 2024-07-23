//
//  FwLanguageAbility.h
//  flywearsdk
//
//  Created by 磐石 on 2024/3/20.
//

#import <Foundation/Foundation.h>
#import <flywearsdk/IFwLanguageAbility.h>
#import <flywearsdk/FwLanguageModel.h>

@class RACSubject;

@interface FwLanguageAbility : NSObject<IFwLanguageAbility>

+ (instancetype)share;

- (RACSubject<FwLanguageModel *>*)queryCurrentLanguage;

- (RACSubject*)setCurrentLangue:(FwLanguageModel *)language;

- (void)querySupportLanguageSuccess:(void(^)(NSArray <NSString *>*languages,NSArray <FwLanguageModel *>*languagesModels))success ;

@end

