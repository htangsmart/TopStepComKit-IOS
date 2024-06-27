//
//  EBookUpdateModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef EBookUpdateModel_h
#define EBookUpdateModel_h

@interface FwEBookUpdateModel : NSObject

typedef NS_ENUM(UInt8, FwEBookUpdateModel_Op){
    FwEBookUpdateModel_Op_Add = 0,
    FwEBookUpdateModel_Op_Del = 1,
};

///操作类型增或删
@property(nonatomic, assign) FwEBookUpdateModel_Op op;

///要操作的文件的文件名
@property(nonatomic, strong) NSString* name;

@end


#endif /* EBookUpdateModel_h */
