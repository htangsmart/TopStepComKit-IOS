//
//  DialController.m
//  FitCloudKitDemo
//
//  Created by 磐石 on 2024/6/15.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#import "DialController.h"

@interface DialController ()

@end

@implementation DialController

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
        
        [TPSSdk.share.dialAbility getCurrentDial:^(TPSDialModel *model) {
            if (model ) {
                NSLog(@"dial Id is %@",model.dialId);
            }
        }];

    }else if (indexPath.row == 1){
        [TPSSdk.share.dialAbility getAllDialInfo:^(NSArray<TPSDialModel *> *modelList) {
            if (modelList && modelList.count>0) {
                for (TPSDialModel *dial in modelList) {
                    NSLog(@"dial Id is %@",dial.dialId);
                }
            }
        }];

    }else if (indexPath.row == 2){
        
        [TPSSdk.share.dialAbility changeDialWithDialId:@"e5a1ce664341be5d744d2c7a96e647cf" block:^(BOOL isSendOK) {
            NSLog(@"changeDial success %d",isSendOK);
        }];
        
    }else if (indexPath.row == 3){
        
    }else if (indexPath.row == 4){
        
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
