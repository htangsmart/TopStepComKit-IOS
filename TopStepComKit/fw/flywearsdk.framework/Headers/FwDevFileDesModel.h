//
//  DevFileDesModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef DevFileDesModel_h
#define DevFileDesModel_h

@interface FwDevFileDesModel : NSObject

@property(nonatomic, strong) NSString* fileName;
@property(nonatomic, strong) NSString* relativePath;
@property(nonatomic, strong) NSString* absolutePath;
@property(nonatomic, strong) NSString* rootPath;
@property(nonatomic, assign) BOOL isDirector;
/**
 如果isDirector是false，则subFiles为nil
 */
@property(nonatomic, strong) NSMutableArray<FwDevFileDesModel*>* subFiles;

@end


#endif /* DevFileDesModel_h */
