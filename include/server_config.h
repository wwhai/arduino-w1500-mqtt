#ifndef __SERVER_CONFIG_H__
#define __SERVER_CONFIG_H__
//******************NETWORK-CONFIG*****************
// WIFI SSID
#define WIFI_SSID "nilyouth"
// WIFI 密码
#define WIFI_PASSWORD "665544332211"
//******************SERVER-CONFIG******************
// MQTT Server
#define MQTT_HOST "81.71.10.205"
// MQTT 端口
#define MQTT_PORT 1883
//
//********************MQTT-ARGS********************
const char *PRODUCT = "p8ba87223fd3944ff85ed820b1eb4770b";
const char *DEVICEID = "d0e50d7a0adb3412c8f3573c5f7976bbf";
const char *CLIENTID = "d0e50d7a0adb3412c8f3573c5f7976bbf";
const char *USERNAME = "d0e50d7a0adb3412c8f3573c5f7976bbf";
const char *PASSWORD = "2af3d388ab444ed1aa01320e38e90b3a";
//
//********************MQTT-ARGS********************
// 属性上报
const char *PROPERTY_UP = "$thing/up/property/p8ba87223fd3944ff85ed820b1eb4770b/d0e50d7a0adb3412c8f3573c5f7976bbf";
// 属性下发
const char *PROPERTY_DOWN = "$thing/down/property/p8ba87223fd3944ff85ed820b1eb4770b/d0e50d7a0adb3412c8f3573c5f7976bbf";
// 属性回复
const char *PROPERTY_REPLY = "$thing/property/reply/p8ba87223fd3944ff85ed820b1eb4770b/d0e50d7a0adb3412c8f3573c5f7976bbf";
// 属性下发
const char *ACTION_DOWN = "$thing/down/action/p8ba87223fd3944ff85ed820b1eb4770b/d0e50d7a0adb3412c8f3573c5f7976bbf";
// 动作回复
const char *ACTION_REPLY = "$thing/action/reply/p8ba87223fd3944ff85ed820b1eb4770b/d0e50d7a0adb3412c8f3573c5f7976bbf";
#endif