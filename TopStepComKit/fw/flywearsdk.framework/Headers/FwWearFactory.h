//
//  WearInterfaceFatctor.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef WearInterfaceFatctor_h
#define WearInterfaceFatctor_h

@interface FwWearFactory : NSObject

+(instancetype)share;

+(id)createSingleInstance:(Protocol*)protocol;
-(id)createSingleInstance:(Protocol*)protocol;

@end

#endif /* WearInterfaceFatctor_h */
