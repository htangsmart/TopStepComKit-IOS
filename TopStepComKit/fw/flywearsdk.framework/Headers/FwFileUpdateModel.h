//
//  FileUpdateModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/4.
//

#ifndef FileUpdateModel_h
#define FileUpdateModel_h

@interface FwFileUpdateModel : NSObject

typedef NS_ENUM(UInt8, FwFileUpdateModel_Op){
    FwFileUpdateModel_Op_Add = 0,
    FwFileUpdateModel_Op_Del = 1,
};

///操作类型增或删
@property(nonatomic, assign) FwFileUpdateModel_Op op;

///要操作的文件的在手表上的全路径，例如,internal://share#com.realthread.LocalPhoto/photo/abc.png
@property(nonatomic, strong) NSString* remotePathInternalForm;

@property(nonatomic, strong) NSDictionary* extraData;

@end


#endif /* FileUpdateModel_h */
