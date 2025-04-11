

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 模型类型
typedef NSString * TranslateLanguage NS_STRING_ENUM;

/// 自动检测 （只有from可以填写）
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageAuto;
/// 中文
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCh;
/// 繁体中文
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCht;
/// 英文
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEn;
/// 粤语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageYue;
/// 文言文
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageWyw;
/// 日语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageJp;
/// 韩语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKor;
/// 法语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageFra;
/// 西班牙语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSpa;
/// 泰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTh;
/// 阿拉伯语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageAra;
/// 俄语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageRu;
/// 葡萄牙语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguagePt;
/// 德语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageDe;
/// 意大利语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageIt;
/// 希腊语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEl;
/// 荷兰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageNl;
/// 波兰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguagePl;
/// 保加利亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageBul;
/// 爱沙尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEst;
/// 丹麦语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageDan;
/// 芬兰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageFin;
/// 捷克语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCs;
/// 罗马尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageRom;
/// 斯洛文尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSlo;
/// 瑞典语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSwe;
/// 匈牙利语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageHu;
/// 越南语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageVie;

@interface TranslateRequestBody : NSObject

/// 输入的文本
@property (nonatomic, strong) NSString *text;

/// 翻译前语言
@property (nonatomic, strong) TranslateLanguage from;

/// 翻译后语言
@property (nonatomic, strong) TranslateLanguage to;

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

@end

NS_ASSUME_NONNULL_END
