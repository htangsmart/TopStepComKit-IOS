//
//  SportSortController.h
//  FitCloudKitDemo
//
//  Created by Topstep on 2026/3/6.
//  Copyright © 2026 HetangSmart. All rights reserved.
//

#ifndef SportSortController_h
#define SportSortController_h

#import <UIKit/UIKit.h>

/**
 * @brief Controller for testing sport type sorting/reordering on the watch
 * @chinese 用于测试手表运动类型排序/重新排列功能的控制器
 *
 * @discussion
 * [EN]: This controller queries editable sport slots from the device,
 * displays them in a reorderable list, and allows the user to drag-to-reorder
 * or manually move sport slots. The updated order can be sent back to the device.
 * [CN]: 该控制器从设备查询可编辑的运动槽位，
 * 以可重新排序的列表形式展示，允许用户拖拽重新排序或手动移动运动槽位。
 * 更新后的顺序可以发送回设备。
 */
@interface SportSortController : UIViewController

@end

#endif /* SportSortController_h */
