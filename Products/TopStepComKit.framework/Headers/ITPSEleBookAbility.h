//
//  IWearEleBookSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef ITPSEleBookAbility_h
#define ITPSEleBookAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSEBookModel.h>
#import <TopStepComKit/TPSProgressModel.h>
#import <TopStepComKit/TPSEBookUpdateModel.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>

@protocol ITPSEleBookAbility <NSObject,ITPSWearBaseAbility>

typedef void(^TPSEleBookListCallback)(NSArray<TPSEBookModel*> * bookList);

+(instancetype)share;

-(void)getBookList:(TPSEleBookListCallback)block;
-(void)pushBookToDev:(NSString*)phoneFilePath fileName:(NSString*)fileName block:(onTPSProgressResult)block;
-(void)cancelPush:(NSString*)fileName;
-(void)delBookOnDev:(NSString*)fileName block:(TPSSendMsgResult)block;

@end


#endif /* IWearEleBookSync_h */
