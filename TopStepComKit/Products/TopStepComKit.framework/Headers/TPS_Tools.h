//
//  TPS_Tools.h
//  Topstep
//
//  Created by Topstep on 2024/2/18.
//

#ifndef TPS_Tools_h
#define TPS_Tools_h

#import <UIKit/UIKit.h>

@interface TPS_Tools : NSObject

typedef void(^TPS_Action)(void);
typedef void(^TPS_ActionString)(NSString*);

/**
 往NSUserDefault存入对象（注意：可变类型对象不适用）。
 
 @param objc 对象
 @param key 键值
 */
+(void)setUser:(id)objc forKey:(NSString*)key;

/**
 从NSUserDefault取出对象（注意：可变类型对象不适用）。
 
 @param key 键值
 @return 返回对象
 */
+(id)getUserByKey:(NSString*)key;

/**
 移除NSUserDefault相对应的对象
 
 @param key 键值
 */
+(void)removeUserByKey:(NSString*)key;

/**
 延时执行block。
 
 @param sec 延时时间（秒）
 @param block 代码块
 */
+(void)delay:(double)sec Task:(TPS_Action)block;

/**
 异步执行block。
 
 @param block 代码块
 */
+(void)subTask:(TPS_Action)block;

/**
 主线程执行block。
 
 @param block 代码块
 */
+(void)mainTask:(TPS_Action)block;

+(NSDictionary*)getHistoryMacPeripheralUUIDMap;

+(void)addHistoryMacPeripheralUUIDMap:(NSString*)mac peripheralIdentifer:(NSString*)peripheralIdentifer;

+(NSString*)objectToJsonStr:(NSDictionary*)dic;

+(NSString*)convertHexStrToStr:(NSString*)hexStr;

+(NSData*)convertHexStrToData:(NSString *)str;

+(UIImage*)trimImageInCenter:(UIImage*)scaledImage centerW:(float)centerW centerH:(float)centerH;

+(UIImage *)resizeImage:(UIImage *)image width:(float)width height:(float)height;

+(NSString*)macWithSplit:(NSString*)macWithoutSplit;

+(BOOL)isValidJson:(id)jsonString;

+(NSDictionary*)dictionaryWithJsonNSDate:(NSData*)jsonData;

+(NSData*)toJsonNSDataWithObject:(NSObject*)obj keys:(NSArray*)keys;

+(double)km2CaloriesWithKm:(double)km weight:(double)weight;

+(NSString*)getPeripheralIdentifer;

+(void)setPeripheralIdentifer:(NSString*)peripheralIdentifer;

+(NSDictionary*)dictionaryWithJsonString:(NSString*)jsonString;

+(NSString*)dataChangeToString:(NSData *)data;

+(NSData*)uInt8_data:(uint8_t)value;

/**
 *  用途:【查找】一个文件，在你想要的路径下，不存在则返回nil，存在则返回完整路径
 *  @param   sPath     系统路径
 *  @param   mPath     中途路径    -->> @"test1/test2/test3" <<--
 *  @param   file      文件名
 */
+(NSString*)findPath:(NSSearchPathDirectory)sPath
          MiddlePath:(NSString*)mPath
                File:(NSString*)file;

/**
 在存在的文件路径上，建立新的文件。file参数为""字符串时，会创建文件夹
 
 @param sPath 沙盒
 @param mPath 中间路径
 @param file 文件名
 @return 完成路径
 */
+(NSString*)createOn:(NSSearchPathDirectory)sPath
          MiddlePath:(NSString*)mPath
                File:(NSString*)file;

+(void)removePath:(NSString*)filePath;

+(void)logSome;

+ (BOOL)isEmptyDictonary:(NSDictionary *)dict;

+ (int)copyPropertListFromObjec:(id)fromObject toObject:(id)toObject;

+(NSDate*)toStartOfDate:(NSDate*)toConvertDate;

//获取一个时间戳组成的数组，各个时间戳是那一天的零时。
+(NSArray*)timestampArrFromEachStartOfDay:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime;

+(NSData*)convertWavToPcm:(NSString *)inputFilePath outputFilePath:(NSString *)outputFilePath;

+(NSString*)writeToTmpFile:(NSData*)data fileName:(NSString*)fileName;

+(NSString*)bundleToDocuments:(NSString *)dir fileName:(NSString *)fileName existsCover:(BOOL)cover;

+(void)mp3ToPCMWithMp3File:(NSString*)mp3FilePath outPutPCMPath:(NSString*)outPutPCMPath sampleRate:(int)sampleRate bitDepth:(int)bitDepth block:(TPS_Action)block;

@end


#endif /* TPS_Tools_h */
