//
//  WearInterfaceFatctor.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef TPSWearFactory_h
#define TPSWearFactory_h

@interface TPSWearFactory : NSObject

+(instancetype)share;

+(id)createSingleInstance:(Protocol*)protocol;
-(id)createSingleInstance:(Protocol*)protocol;

@end

#endif /* WearInterfaceFatctor_h */
