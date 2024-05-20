//
//  DeviceCell.h
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/17.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DeviceCell : UITableViewCell

-(void) configWithPeripheral:(TPSScanResult*)peripheral showStatus:(BOOL)showStatus;

@end

NS_ASSUME_NONNULL_END
