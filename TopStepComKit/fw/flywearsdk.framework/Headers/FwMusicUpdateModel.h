//
//  MusicUpdateModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/22.
//

#ifndef MusicUpdateModel_h
#define MusicUpdateModel_h

@interface FwMusicUpdateModel : NSObject

typedef NS_ENUM(UInt8, FwMusicUpdateModel_Op){
    FwMusicUpdateModel_Op_Add = 0,
    FwMusicUpdateModel_Op_Del = 1,
};

///操作类型增或删
@property(nonatomic, assign) FwMusicUpdateModel_Op op;

///要操作的文件名
@property(nonatomic, strong) NSString* fileName;
@property(nonatomic, strong) NSDictionary* extraData;

@end


#endif /* MusicUpdateModel_h */
