//
//  ContractListController.m
//  FitCloudKitDemo
//
//  Created by 磐石 on 2024/6/15.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#import "ContractListController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface ContractListController ()

@end

@implementation ContractListController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

#pragma mark - Table view data source

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    
    
    if (indexPath.row == 0) {
        [[TPSSdk.share.contactAbility getAllContact] subscribeNext:^(NSArray<TPSContactModel *> * _Nullable x) {
            if (x && x.count>0) {
                for (TPSContactModel *contract  in x) {
                    NSLog(@"normal name is %@ num is %@",contract.name,contract.phone);
                }
            }
            OpResultToastTip(self.view, YES);
        }];
    }else if (indexPath.row == 1){
        NSMutableArray *allcontract = [NSMutableArray new];
        for (int i = 0; i<10; i++) {
            NSString *name = [NSString stringWithFormat:@"测试普通联系人%d",i];
            NSString *phone= [NSString stringWithFormat:@"1389297202%d",i];
            TPSContactModel *model = [[TPSContactModel alloc]initWithName:name phone:phone initial:nil];
            [allcontract addObject:model];
        }
        [TPSSdk.share.contactAbility sendCommonContact:allcontract];
        OpResultToastTip(self.view, YES);

    }else if (indexPath.row == 2){
        
        [TPSSdk.share.contactAbility getEmergencyContact:^(NSArray<TPSContactModel *> *list) {
            if (list && list.count>0) {
                for (TPSContactModel *contract  in list) {
                    NSLog(@"emergency name is %@ num is %@",contract.name,contract.phone);
                }
                
            }
            OpResultToastTip(self.view, YES);

        }];
        
    }else if (indexPath.row == 3){
        
        NSString *name = @"测试紧急联系人";
        NSString *phone= @"15201054230";
        TPSContactModel *model = [[TPSContactModel alloc]initWithName:name phone:phone initial:nil];
        [TPSSdk.share.contactAbility sendEmergencyContact:model];
        OpResultToastTip(self.view, YES);

    }
    
}
- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];

}

/*
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:<#@"reuseIdentifier"#> forIndexPath:indexPath];
    
    // Configure the cell...
    
    return cell;
}
*/

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    } else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath {
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
