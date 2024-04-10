//
//  IFwLanguageAbility.h
//  flywearsdk
//
//  Created by 磐石 on 2024/3/20.
//

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/WearBlockTypeDef.h>
#import <flywearsdk/FwLanguageModel.h>

@class RACSubject<ValueType>;


@protocol IFwLanguageAbility <NSObject,IFwWearBaseAbility>

+ (instancetype)share;

- (RACSubject<FwLanguageModel *>*)queryCurrentLanguage;

- (RACSubject*)setCurrentLangue:(FwLanguageModel *)language;

- (void)querySupportLanguageSuccess:(void(^)(NSArray <NSString *>*languages,NSArray <FwLanguageModel *>*languagesModels))success ;


@end

