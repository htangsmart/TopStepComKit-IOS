//
//  FwRecordingModel.h
//  flywearsdk
//
//  Created by Zhuanz on 2024/6/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(UInt8, FwRecordingModel_Op){
    FwRecordingModel_Op_Add = 0,
    FwRecordingModel_Op_Del,
};

@interface FwRecordingModel : NSObject

/// 操作类型增或删
@property(nonatomic, assign) FwRecordingModel_Op op;
@property(nonatomic, copy) NSString *fileName;
@property(nonatomic, strong) NSDictionary *extraData;
@property(nonatomic, assign) NSInteger size;
@property(nonatomic, assign) float curSize;
@property(nonatomic, assign) float totalSize;

@end

NS_ASSUME_NONNULL_END
