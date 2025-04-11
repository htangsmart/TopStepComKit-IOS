
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ASRRequestBody.h"
#import "TTSRequestBody.h"
#import "ChatRequestBody.h"
#import "ChatPictureRequestBody.h"
#import "TranslateRequestBody.h"
#import "HealthQABody.h"
#import "HealthAnalysisBody.h"

#import "ChatIntlRequestBody.h"
#import "ChatPictureIntlRequestBody.h"
#import "IntlAudioInput.h"

#import "AIMusicRequestBody.h"

#import "AIGCV3RequestBody.h"
#import "ASRFileIntlRequestBody.h"

#import "ChatRequestBodyV2.h"

#import "MagicHelperError.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MagicHelperDelegate <NSObject>

@optional

/// 初始化结果回调
/// - Parameters:
///   - result: result != nil 即为校验通过
///   result = @{@"useArea":@(1:国内 2:海外), @"support_langure":@"zh_cn,....", @"ttsConfig":@[@{language = "zh_cn";vcn = xiaoyan;}]}
/// 调用方需要根据useArea字段来区分调用方法
- (void)didReceiveInitResult:(nullable NSDictionary *)result error:(nullable NSError *)error;

/// 文本转语音结果回调
/// - Parameters:
///   - result: @{@"url":@"本地文件路径", @"qid":@"请求id"}
- (void)didReceiveTTSResult:(NSDictionary *)result error:(nullable NSError *)error;

/// 实时语音转文本结果回调，该方法会多次回调
- (void)didReceiveStreamAsrResponse:(NSDictionary *)result error:(nullable NSError *)error;

/// 语音文件转文本结果回调
- (void)didReceiveFileAsrResponse:(NSDictionary *)result error:(nullable NSError *)error;

/// chat结果回调
/// 如果是流式该方法会多次回调
- (void)didReceiveChatResponse:(NSDictionary *)result error:(nullable NSError *)error;

/// AI Image结果回调
/// - discussion: 从请求图片到回调耗时比较久，请耐心等待回调。
- (void)didReceiveAIImageResult:(NSDictionary *)images error:(nullable NSError *)error;

/// AI Image Style结果回调
- (void)didReceiveAIStyleResult:(nullable NSArray *)styles error:(nullable NSError *)error;

/// 翻译结果回调
- (void)didReceiveTranslateResult:(NSDictionary *)result error:(nullable NSError *)error;

/// 健康问答结果回调
- (void)didReceiveHealthQAResult:(nullable NSDictionary *)result error:(nullable NSError *)error;

/// 健康数据分析结果回调
- (void)didReceiveHealthAnalysisResult:(nullable NSDictionary *)result error:(nullable NSError *)error;

/// 海外版TTS回调
/// result: @{@"url":@"本地文件路径", @"qid":@"请求id", @"tid":@"xxxx"}
- (void)didReceiveIntlTTSResult:(NSDictionary *)result error:(nullable NSError *)error;

/// 海外版实时语音识别回调，该方法会多次回调
- (void)didReceiveIntlASRResult:(NSDictionary *)result error:(nullable NSError *)error;

/// 海外版语音文件识别回调
- (void)didReceiveIntlFileASRResult:(NSDictionary *)result error:(nullable NSError *)error;

/// 海外版gpt回调,该方法会多次回调
- (void)didReceiveIntlGptResult:(NSDictionary *)result error:(nullable NSError *)error;

/// 海外版aigc回调
- (void)didReceiveIntlAigcResult:(NSDictionary *)result error:(nullable NSError *)error;

/// aigc升级接口回调
- (void)didReceiveAigcV3Result:(NSDictionary *)result error:(nullable NSError *)error;

/// aigcStyle升级接口回调
- (void)didReceiveAigcV3StylesResult:(nullable NSArray *)styles error:(nullable NSError *)error;

/// AI音乐回调
- (void)didReceiveAIMusicResult:(NSDictionary *)result error:(nullable NSError *)error;

/// 获取支持的大模型回调
- (void)didReceiveSupportedModelTypes:(nullable NSArray *)types error:(nullable NSError *)error;

/// 国内大模型回调,该方法会多次回调
- (void)didReceiveModelV2Result:(NSDictionary *)result error:(nullable NSError *)error;
@end


@interface BDMagicHelper : NSObject

/// delegate
/// - See: BDHelperDelegate
@property (nonatomic, weak) id<MagicHelperDelegate> delegate;

/// 是否开启日志,默认NO
@property (nonatomic, assign) BOOL logEnable;

/// 是否开启海外版GPT测试链接， 默认NO
@property (nonatomic, assign) BOOL isTestIntlGPT;

/// 单例
+ (instancetype)share;

/// 初始化SDK
/// mac:设备mac地址
/// channel:渠道ID,由服务器分配
/// - Discussion: 该方法必须先调用，不然其它方法会出错，每次切换设备都需要调用
- (void)initMagicWithMac:(NSString *)mac channel:(NSString *)channel;

/// 文本转语音
- (void)text2Audio:(TTSRequestBody *)body;

/// 语音转文本
/// 音频文件转文本 body.data设置为整个音频文件
- (void)audio2Text:(ASRRequestBody *)body;

/// 音频流转文本 body.data为实时音频流
- (void)audioStream2Text:(ASRRequestBody *)body;

/// chat gpt
- (void)chatWithBody:(ChatRequestBody *)body;

/// 国内大模型
/// ChatRequestBody.type可选大模型
- (void)chatWithBodyV2:(ChatRequestBodyV2 *)body;

/// AI image
- (void)aiImageWithBody:(ChatPictureRequestBody *)body;

/// 获取AI image场景
- (void)aiStyle;

/// 翻译
- (void)translateWithBody:(TranslateRequestBody *)body;

/// 健康问答
- (void)healthQAWithBody:(HealthQABody *)body;

/// 健康数据分析
- (void)healthAnalysisWithBody:(HealthAnalysisBody *)body;

/// 海外版语音文件识别
/// - Parameter path: 语音文件路径
- (void)intlFileAsr:(ASRFileIntlRequestBody *)body;

/// 海外版语音识别(asr)
- (IntlAudioInput *)intlAsr:(ASRIntlRequestBody *)body;


/// 海外版语音合成(tts)
- (void)intlTts:(TTSIntlRequestBody *)body;

/// 海外版aigc (aigc)
- (void)intlAigc:(ChatPictureRequestBody *)body;

/// 海外版gpt
- (void)intlGpt:(GptIntlRequestBody *)body;


/// 海外版gpt（asr/文本 + gpt + tts?）
- (nullable IntlAudioInput *)startWithGptIntl:(ChatIntlRequestBody *)body;

/// 海外版aigc (asr/文本 + aigc)
- (nullable IntlAudioInput *)startWithAigcIntl:(ChatPictureIntlRequestBody *)body;

/// 海外版aigc (asr/文本 + aigc) 补充方法，用来确认语音识别文本
/// 该方法在ChatPictureIntlRequestBody.confirmText = YES时生效
/// - Parameters:
///   - qid: startWithAigcIntl对应的qid
///   - text: 确认好的文本，该文本必须是中、英文
/// - Return: YES则表示流程继续，返回NO则表示未找到该qid的任务
- (BOOL)aigcIntlContinueWithQid:(NSString *)qid text:(NSString *)text tid:(NSString *)tid;

/// 海外版aigc (asr/文本 + aigc) 补充方法，如果对识别文本不满意可以调改方法取消本次aigc任务
/// - Parameter qid: aigc任务id
- (void)aigcIntlCancelWithQid:(NSString *)qid;

/// aigc v3版本,不分国内、海外
- (void)aigcV3:(AIGCV3RequestBody *)body;

/// 新版本AIGC场景
/// language: 返回的数据将翻译到目标语种，不传则默认中文
/// 例如英语：en
- (void)aigcV3Styles:(nullable NSString *)language;

/// 获取支持大模型类型列表
- (void)getSupportedModelTypes;
@end

NS_ASSUME_NONNULL_END
