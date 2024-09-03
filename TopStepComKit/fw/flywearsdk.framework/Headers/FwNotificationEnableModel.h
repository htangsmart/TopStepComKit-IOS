//
//  NotificationEnableModel.h
//  JieliJianKang
//
//  Created by Topstep on 2024/1/26.
//

#ifndef NotificationEnableModel_h
#define NotificationEnableModel_h



//NSArray* allNameArray =  @[
//    @{@"icon":@"device_msg_all",@"msg_title":kJL_TXT("消息一键开启"),@"tool_id":@"all",@"visible":@(1)},
//    @{@"icon":@"device_msg_phone",@"msg_title":kJL_TXT("来电提醒"),@"tool_id":@"telephony",@"visible":@(1)},
//    @{@"icon":@"device_msg_msg",@"msg_title":kJL_TXT("短信"),@"tool_id":@"sms",@"visible":@(1)},
//    @{@"icon":@"device_msg_email",@"msg_title":kJL_TXT("邮件"),@"tool_id":@"mail",@"visible":@(1)},
//    @{@"icon":@"device_msg_wx",@"msg_title":kJL_TXT("微信"),@"tool_id":@"wechat",@"visible":@(1)},
//    @{@"icon":@"device_msg_qq",@"msg_title":kJL_TXT("QQ"),@"tool_id":@"qq",@"visible":@(1)},
//    @{@"icon":@"device_msg_fb",@"msg_title":kJL_TXT("Facebook"),@"tool_id":@"facebook",@"visible":@(1)},
//    @{@"icon":@"device_msg_tw",@"msg_title":kJL_TXT("X"),@"tool_id":@"twitter",@"visible":@(1)},
//    @{@"icon":@"device_msg_whatsapp",@"msg_title":kJL_TXT("WhatsApp"),@"tool_id":@"whatsapp",@"visible":@(1)},
//    @{@"icon":@"device_msg_linkedin",@"msg_title":kJL_TXT("LinkedIn"),@"tool_id":@"linkedin",@"visible":@(1)},
//    @{@"icon":@"device_msg_instagram",@"msg_title":kJL_TXT("Instagram"),@"tool_id":@"instagram",@"visible":@(1)},
//    @{@"icon":@"device_msg_messenger",@"msg_title":kJL_TXT("Messenger"),@"tool_id":@"facebookmessenger",@"visible":@(1)},
//    @{@"icon":@"device_msg_snapchat",@"msg_title":kJL_TXT("Snapchat"),@"tool_id":@"snapchat",@"visible":@(1)},
//    @{@"icon":@"device_msg_line",@"msg_title":kJL_TXT("Line"),@"tool_id":@"line",@"visible":@(1)},
//    @{@"icon":@"device_msg_kaokaotalk",@"msg_title":kJL_TXT("Kaokao Talk"),@"tool_id":@"kakaotalk",@"visible":@(1)},
//    @{@"icon":@"device_msg_instaviber",@"msg_title":kJL_TXT("Viber"),@"tool_id":@"viber",@"visible":@(1)},
//    @{@"icon":@"device_msg_skype",@"msg_title":kJL_TXT("Skype"),@"tool_id":@"skype",@"visible":@(1)},
//    @{@"icon":@"device_msg_telegram",@"msg_title":kJL_TXT("Telegram"),@"tool_id":@"telegram",@"visible":@(1)},
//    @{@"icon":@"device_msg_pinterest",@"msg_title":kJL_TXT("Pinterest"),@"tool_id":@"pinterest",@"visible":@(1)},
//    @{@"icon":@"device_msg_youtube",@"msg_title":kJL_TXT("Youtube"),@"tool_id":@"youtube",@"visible":@(1)},
//    @{@"icon":@"device_msg_applemusic",@"msg_title":kJL_TXT("Applemusic"),@"tool_id":@"applemusic",@"visible":@(1)},
//    @{@"icon":@"device_msg_zoom",@"msg_title":kJL_TXT("Zoom"),@"tool_id":@"zoom",@"visible":@(1)},
//    @{@"icon":@"device_msg_tiktok",@"msg_title":kJL_TXT("Tiktok"),@"tool_id":@"tiktok",@"visible":@(1)},
//    @{@"icon":@"device_msg_hike",@"msg_title":kJL_TXT("Hike"),@"tool_id":@"hike",@"visible":@(0)},
//    @{@"icon":@"device_msg_default",@"msg_title":kJL_TXT("更多提醒"),@"tool_id":@"default",@"visible":@(1)},
//];

@interface FwNotificationEnableModel : NSObject

typedef NS_ENUM(UInt8, FwNotification_Type){
    FwNotification_Type_telephony = 1,
    FwNotification_Type_sms,
    FwNotification_Type_mail,
    FwNotification_Type_wechat,
    FwNotification_Type_qq,
    FwNotification_Type_facebook,
    FwNotification_Type_twitter,
    FwNotification_Type_whatsapp,
    FwNotification_Type_linkedin,
    FwNotification_Type_instagram,
    FwNotification_Type_facebookmessenger,
    FwNotification_Type_snapchat,
    FwNotification_Type_line,
    FwNotification_Type_kakaotalk,
    FwNotification_Type_viber,
    FwNotification_Type_skype,
    FwNotification_Type_telegram,
    FwNotification_Type_pinterest,
    FwNotification_Type_youtube,
    FwNotification_Type_applemusic,
    FwNotification_Type_zoom,
    FwNotification_Type_tiktok,
    FwNotification_Type_hike,
    FwNotification_Type_whatsapp_bs,
    FwNotification_Type_outlook,
    FwNotification_Type_gmail,
    FwNotification_Type_default,
};

@property(nonatomic, assign) FwNotification_Type type;
@property(nonatomic, copy, readonly) NSString* name;
@property(nonatomic, assign) BOOL enable;


@end


#endif /* NotificationEnableModel_h */
