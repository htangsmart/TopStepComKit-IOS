//
//  AlbumUpdateModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/18.
//

#ifndef TPSAlbumUpdateModel_h
#define TPSAlbumUpdateModel_h

@interface TPSAlbumUpdateModel : NSObject

typedef NS_ENUM(UInt8, TPSAlbumUpdateModel_Op){
    TPSAlbumUpdateModel_Op_Add = 0,
    TPSAlbumUpdateModel_Op_Del = 1,
};

///操作类型增或删
@property(nonatomic, assign) TPSAlbumUpdateModel_Op op;

///要操作的文件全路径，以internal://share#开头
@property(nonatomic, strong) NSString* path;


@end


#endif /* AlbumUpdateModel_h */
