//
//  MusicModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/22.
//

#ifndef TPSMusicModel_h
#define TPSMusicModel_h

@interface TPSMusicModel : NSObject

@property(nonatomic, strong) NSString* fileName;


+ (NSArray *)toTPSArrayWithFCPArray:(NSArray *)fcpArray;

@end


#endif /* MusicModel_h */
