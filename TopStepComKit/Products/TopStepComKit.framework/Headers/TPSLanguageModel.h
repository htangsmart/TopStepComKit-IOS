//
//  TPSLanguageModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2024/3/21.
//

#import <Foundation/Foundation.h>
#import <TopStepComKit/TSJConnectorAbility.h>

NS_ASSUME_NONNULL_BEGIN
@class FwLanguageModel;
@interface TPSLanguageModel : NSObject

@property (nonatomic,strong) NSString * name;

- (instancetype)initWithName:(NSString *)name;

- (FwLanguageModel *)toFWLanguageModel;

+ (TPSLanguageModel *)toTPSLanguageModelWithFWModel:(FwLanguageModel *)fwModel;

+ (NSArray<TPSLanguageModel *> *)toTPSLanguageModeArraylWithFWModelArray:(NSArray<FwLanguageModel *> *)fwModelArray;

+ (NSArray<TPSLanguageModel *> *)toTPSLanguageModeArraylWithWMModelArray:(NSArray< NSString*> *)wmModelArray;




@end

NS_ASSUME_NONNULL_END
