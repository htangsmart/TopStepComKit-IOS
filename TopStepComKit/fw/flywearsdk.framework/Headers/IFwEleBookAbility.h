//
//  IWearEleBookSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef IWearEleBookSync_h
#define IWearEleBookSync_h

#define TSWearEleBookSync_Watch_Ebook_FilePath @"/data/share/com.realthread.EBook/EBook/"

#import <flywearsdk/IFwWearBaseAbility.h>
#import <flywearsdk/FwEBookModel.h>
#import <flywearsdk/FwProgressModel.h>
#import <flywearsdk/FwEBookUpdateModel.h>
#import <flywearsdk/WearBlockTypeDef.h>

@protocol IFwEleBookAbility <NSObject,IFwWearBaseAbility>

typedef void(^FwEleBookListCallback)(NSArray<FwEBookModel*> * bookList);

+(instancetype)share;

-(void)getBookList:(FwEleBookListCallback)block;
-(void)pushBookToDev:(NSString*)phoneFilePath fileName:(NSString*)fileName block:(onProgressResult)block;
-(void)cancelPush:(NSString*)fileName;
-(void)delBookOnDev:(NSString*)fileName block:(FwSendMsgResult)block;

@end


#endif /* IWearEleBookSync_h */
