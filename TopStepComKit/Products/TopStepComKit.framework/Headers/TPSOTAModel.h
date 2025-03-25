//
//  TPSOTAModel.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/7.
//

#ifndef TPSOTAModel_h
#define TPSOTAModel_h

@interface TPSOTAModel : NSObject

///表示调用者希望尽量采取静默模式升级，但是实际上sdk内部会检查硬件是否支持，如果不支持，仍然会采取非静默升级的模式
@property(nonatomic, assign) BOOL needSilentMode;

///如果是ui包，某些平台（目前851）会忽略固件是否支持静默模式的标志位，采取静默模式
@property(nonatomic, assign) BOOL isUIBin;

@end


#endif
