//
//  DevFileDesModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef TPSDevFileDesModel_h
#define TPSDevFileDesModel_h

@class FwDevFileDesModel;
@interface TPSDevFileDesModel : NSObject

@property(nonatomic, strong) NSString* fileName;
@property(nonatomic, strong) NSString* relativePath;
@property(nonatomic, strong) NSString* absolutePath;
@property(nonatomic, strong) NSString* rootPath;
@property(nonatomic, assign) BOOL isDirector;
@property(nonatomic, strong) NSMutableArray<TPSDevFileDesModel*>* subFiles;

-(instancetype)initWithFwModel:(FwDevFileDesModel*)fwDevFileDesModel;
+(NSArray<TPSDevFileDesModel*>*)toArrayWithFwModelArr:(NSArray<FwDevFileDesModel*>*)fwArr;

@end


#endif /* DevFileDesModel_h */
