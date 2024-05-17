//
//  OrmAdapter.h
//  TopStepComKit
//
//  Created by Topstep on 2024/5/17.
//

#ifndef OrmAdapter_h
#define OrmAdapter_h

#import <TopStepComKit/TPSSdk.h>
#import <TopStepComKit/TPSProgressModel.h>


@interface OrmAdapter : NSObject

+ (instancetype)share;

-(void)pushMusicToDevWithPhoneFilePath:(NSData*)musicData remoteFileName:(NSString*)remoteFileName block:(onTPSProgressResult)block;
-(void)respondHttpToWatch:(TPSWebResponseModel*)model audioData:(NSData*)audioData block:(TPSSendMsgResult)block;


@end


#endif /* OrmAdapter_h */
