//
//  EBookModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef TPSEBookModel_h
#define TPSEBookModel_h

@class FwEBookModel;
@interface TPSEBookModel : NSObject

@property(nonatomic, strong) NSString* bookName;

-(instancetype)initWithFwModel:(FwEBookModel*)fwEBookModel;
+(NSArray<TPSEBookModel*>*)toTPSArrayWithFwModelArr:(NSArray<FwEBookModel*>*)fwArr;

@end


#endif /* EBookModel_h */
