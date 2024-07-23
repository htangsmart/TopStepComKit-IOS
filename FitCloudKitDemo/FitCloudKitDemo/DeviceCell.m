//
//  DeviceCell.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/17.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DeviceCell.h"

@interface DeviceCell()

@property (nonatomic, assign) BOOL  showStatus;
@property (nonatomic, weak) TPSScanResult *peripheral;
@property (weak, nonatomic) IBOutlet UILabel *name;
@property (weak, nonatomic) IBOutlet UILabel *macAddr;
@property (weak, nonatomic) IBOutlet UILabel *rssi;
@property (weak, nonatomic) IBOutlet UILabel *status;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activity;

@end

@implementation DeviceCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

-(void) configWithPeripheral:(TPSScanResult*)peripheral showStatus:(BOOL)showStatus
{
    self.peripheral = peripheral;
    _showStatus = showStatus;
    self.name.text = peripheral.name == nil || peripheral.name.length == 0 ? @"UNKNOWN" : peripheral.name;
    self.rssi.text = [NSString stringWithFormat:@"RSSI:%d", peripheral.RSSI.intValue+100];
    self.macAddr.text = peripheral.mac;
    if(!showStatus)
    {
        if(self.activity.animating)[self.activity stopAnimating];
        self.status.hidden = self.activity.hidden = YES;
    }
    else
    {
        CBPeripheralState state = peripheral.peripheral.state;
        if(state == CBPeripheralStateConnecting || state == CBPeripheralStateDisconnecting)
        {
            self.activity.hidden = NO;
            self.status.hidden = YES;
            [self.activity startAnimating];
        }
        else
        {
            if(self.activity.animating)[self.activity stopAnimating];
            self.activity.hidden = YES;
            self.status.hidden = NO;
            if(state == CBPeripheralStateConnected)
            {
                self.status.textColor = RGB(0x00, 0xB2, 0x00);
                self.status.text = NSLocalizedString(@"CONNECTED", nil);
            }
            else if(state == CBPeripheralStateDisconnected)
            {
                self.status.textColor = [UIColor lightGrayColor];
                self.status.text = NSLocalizedString(@"DISCONNECTED", nil);
            }
        }
    }
}


-(void)dealloc
{
    
}

@end
