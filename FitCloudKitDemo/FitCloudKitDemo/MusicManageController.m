//
//  MusicManageController.m
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/6/15.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MusicManageController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface MusicManageController ()<UIDocumentPickerDelegate>{
    NSString *filePath;
}
- (IBAction)OnGoBack:(id)sender;
@end

@implementation MusicManageController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    __weak typeof(self) weakSelf = self;
    if (indexPath.row == 0) {
        // The project supports selectable file types
        NSArray *types = @[
                    @"public.mp3"
                ];
        //Select a file from the local directory
        UIDocumentPickerViewController* documentPicker = [[UIDocumentPickerViewController alloc]  initWithDocumentTypes:types inMode:UIDocumentPickerModeOpen];
        documentPicker.delegate = self;
        documentPicker.allowsMultipleSelection = NO;
        documentPicker.modalPresentationStyle = UIModalPresentationFullScreen;
        [self presentViewController:documentPicker animated:YES completion:nil];
    }
}

#pragma mark - UIDocumentPickerDelegate
- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURLs:(NSArray<NSURL *> *)urls {
    BOOL fileUrlAuthozied = NO;
    for(int i=0;i<urls.count;i++){
        //Obtain authorization
        fileUrlAuthozied = [urls[i] startAccessingSecurityScopedResource];
        if (fileUrlAuthozied) {
            NSFileCoordinator *fileCoordinator = [[NSFileCoordinator alloc] init];
            NSError *error;
            [fileCoordinator coordinateReadingItemAtURL:urls[i] options:0 error:&error byAccessor:^(NSURL *newURL) {
                //read file
                NSString *fileName = [newURL lastPathComponent];
                NSError *error = nil;
                NSData *fileData = [NSData dataWithContentsOfURL:newURL options:NSDataReadingMappedIfSafe error:&error];
                filePath = [TPS_Tools findPath:NSDocumentDirectory MiddlePath:@"music" File:fileName];
                if (filePath!=nil && filePath.length>0) {
                    [TPS_Tools removePath:filePath];
                }
                filePath = [TPS_Tools createOn:NSDocumentDirectory MiddlePath:@"music" File:fileName];
                [fileData writeToFile:filePath atomically:YES];
                XLOG_INFO(@"--->Get Itunes share mp3 :%@",fileName);
                [self dismissViewControllerAnimated:YES completion:NULL];
            }];
            [urls[i] stopAccessingSecurityScopedResource];
        } else {
            break;
        }
    }
    if(!fileUrlAuthozied){
        [self.view makeToast:NSLocalizedString(@"Please go to Set Open Permissions for Normal Use", nil) duration:3.0f position:CSToastPositionTop];
    }else{
        //Upload music to the watch
        [TPSSdk.share.musicAbility pushMusicToDevWithPhoneFilePath:filePath remoteFileName:filePath.lastPathComponent block:^(TPSProgressModel *model) {
            if(model.eventType == TPSProgressModel_Event_Type_OnFailed){
                XLOG_INFO(@"File transfer failed!");
            }else if(model.eventType == TPSProgressModel_Event_Type_OnProcess){
                XLOG_INFO(@"file trans,process:%.2f,total", model.percent);
            }
            if(model.eventType == TPSProgressModel_Event_Type_OnCompleted){
                XLOG_INFO(@"File transfer SUCCESS!");
            }
        }];
    }
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end

