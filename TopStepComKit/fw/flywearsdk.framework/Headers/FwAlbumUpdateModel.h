//
//  AlbumUpdateModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef AlbumUpdateModel_h
#define AlbumUpdateModel_h

@interface FwAlbumUpdateModel : NSObject

typedef NS_ENUM(UInt8, FwAlbumUpdateModel_Op){
    FwAlbumUpdateModel_Op_Add = 0,
    FwAlbumUpdateModel_Op_Del = 1,
};

///操作类型增或删
@property(nonatomic, assign) FwAlbumUpdateModel_Op op;

///要操作的文件全路径，以internal://share#开头
@property(nonatomic, strong) NSString* path;

@end


#endif /* AlbumUpdateModel_h */
