//
//  EBookUpdateModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef TPSEBookUpdateModel_h
#define TPSEBookUpdateModel_h

@interface TPSEBookUpdateModel : NSObject

typedef NS_ENUM(UInt8, TPSEBookUpdateModel_Op){
    TPSEBookUpdateModel_Op_Add = 0,
    TPSEBookUpdateModel_Op_Del = 1,
};

///操作类型增或删
@property(nonatomic, assign) TPSEBookUpdateModel_Op op;

///要操作的文件的文件名
@property(nonatomic, strong) NSString* name;

@end


#endif /* EBookUpdateModel_h */
