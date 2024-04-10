//
//  FwLanguageModel.h
//  flywearsdk
//
//  Created by 磐石 on 2024/3/20.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, FwLanguageType) {
    eFwLanguage_system,
    eFwLanguage_zh,
    eFwLanguage_en,
    eFwLanguage_de,
    eFwLanguage_ja,
    eFwLanguage_es,
    eFwLanguage_fr,
    eFwLanguage_it,
    eFwLanguage_ko,
    eFwLanguage_pt,
    eFwLanguage_ru,
    eFwLanguage_ar,
    eFwLanguage_hi,
    eFwLanguage_fa,
    eFwLanguage_vi,
    eFwLanguage_th,
};


NS_ASSUME_NONNULL_BEGIN
@interface FwLanguageModel : NSObject

@property (nonatomic,strong) NSString * name;
@property (nonatomic,assign) FwLanguageType type;

+ (NSArray<NSString *> *)languages;
+ (NSArray<FwLanguageModel *> *)languagesModels;

- (instancetype)initWithName:(NSString *)name;

- (NSString *)localLanguageName;
- (NSString *)languageNameWithLocalName:(NSString *)localName;

@end
NS_ASSUME_NONNULL_END
