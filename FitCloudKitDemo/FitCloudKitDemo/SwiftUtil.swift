//
//  SwiftUtil.swift
//  FitCloudKitDemo
//
//  Created by Topstep on 2024/7/29.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

import Foundation


/// 设备蓝牙相关基础类
///

@objc class SwiftUtil: NSObject {
    @objc func stopScan() -> String {
        print("oooooooooooo")
        return "bioooo"
    }
    
    @objc func getSwiftUrl() -> String {
        let url = Bundle.main.url(forResource: "template9845", withExtension: "bin");
        return url?.relativePath ?? "abcdefg";
    }
}
