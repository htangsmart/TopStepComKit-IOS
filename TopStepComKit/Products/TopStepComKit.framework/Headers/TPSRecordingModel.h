//
//  TPSRecordingModel.h
//  TopStepComKit
//
//  Created by 磐石 on 2025/2/19.
//

#import <Foundation/Foundation.h>

@class FwRecordingModel;
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(UInt8, TPSRecordingModel_Op){
    TPSRecordingModel_Op_Add = 0,
    TPSRecordingModel_Op_Del,
};

@interface TPSRecordingModel : NSObject

/// 操作类型增或删
@property(nonatomic, assign) TPSRecordingModel_Op op;
@property(nonatomic, copy) NSString *fileName;
@property(nonatomic, strong) NSDictionary *extraData;
@property(nonatomic, assign) NSInteger size;
@property(nonatomic, assign) float curSize;
@property(nonatomic, assign) float totalSize;

+ (TPSRecordingModel *)tpsRecordWithFwRecord:(FwRecordingModel *)fwRecord;
+ (NSArray <TPSRecordingModel *> *)tpsRecordArrayWithFwRecordArray:(NSArray <FwRecordingModel *> *)fwRecords;


@end

NS_ASSUME_NONNULL_END
