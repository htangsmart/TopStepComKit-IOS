//
//  MusicModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/22.
//

#ifndef TPSMusicModel_h
#define TPSMusicModel_h

@class FwMusicModel;
@interface TPSMusicModel : NSObject

@property(nonatomic, strong) NSString* fileName;

-(instancetype)initWithFwModel:(FwMusicModel*)fwEBookModel;
+(NSArray<TPSMusicModel*>*)toTPSArrayWithFwModelArr:(NSArray<FwMusicModel*>*)fwArr;

+ (NSArray *)toTPSArrayWithFCPArray:(NSArray *)fcpArray;

@end


#endif /* MusicModel_h */
