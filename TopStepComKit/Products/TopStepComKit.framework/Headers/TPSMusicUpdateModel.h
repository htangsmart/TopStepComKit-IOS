//
//  MusicUpdateModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/22.
//

#ifndef TPSMusicUpdateModel_h
#define TPSMusicUpdateModel_h

@interface TPSMusicUpdateModel : NSObject

typedef NS_ENUM(UInt8, TPSMusicUpdateModel_Op){
    TPSMusicUpdateModel_Op_Add = 0,
    TPSMusicUpdateModel_Op_Del = 1,
};

///操作类型增或删
@property(nonatomic, assign) TPSMusicUpdateModel_Op op;

///要操作的文件名
@property(nonatomic, strong) NSString* fileName;
@property(nonatomic, strong) NSDictionary* extraData;

@end


#endif /* MusicUpdateModel_h */
