#ifndef ASTROTURRET_CONFIG_H 
#define ASTROTURRET_CONFIG_H

// NOTE: This will a more coherent config system later on, just keeping it simple with 
//          defs at the moment.

// LOGGER
#define CFG_LOGGER_SERVICE_ID           0
#define CFG_LOGGER_SERVICE_NAME         "MYLOG"
// END LOGGER

#define CFG_BLESERVICE_SERVICE_UUID     "58296e9b-ba91-4f47-8e3f-789e42f89b24"

// BUILD INFO
#define CFG_BUILD_VERSION               "0.0.1-pluto"
#define CFG_BUILD_TIME                  "00:00:00"
#define CFG_BUILD_DATE                  "18/06/2025"
// BUILD INFO BLE
#define CFG_BLESERVICE_CHARN_BUILDINFO   "c3c4cb20-f598-44e2-881f-3b5d6b140f94"  //READONLY
#define CFG_BLESERVICE_DESCM_BUILDINFO   "0x2902"                                //READONLY
// END BUILD INFO BLE
// END BUILD INFO

// WIFI
#define CFG_WIFI_APSSID                 "astro_cam"
#define CFG_WIFI_SSID                   "dba387a58f"
#define CFG_WIFI_PWD                    "f232184411b74b55af8ad13738b55408"
#define CFG_WIFI_HOSTNAME               "astrocam"
// WIFI BLE
// format:  "|APSSID: CHAR(32)|SSID: CHAR(32)|WIFIPWD: CHAR(32)|WIFIHOSTNAME CHAR(32)|"
// NOTE: Piping = 000000 data between entries
// Example: "000000617374726F5F63616D000000646261333837613538660000006632333231383434313162373462353561663861643133373338623535343038000000617374726F63616D000000"
//TODO: Encryption
#define CFG_BLESERVICE_CHARN_WIFI       "c3c4cb20-f598-44e2-881f-3b5d6b140f94"  //READONLY
#define CFG_BLESERVICE_DESCN_WIFI        "0x2902"                                //READONLY
#define CFG_BLESERVICE_CHARW_WIFI       "b3de1df7-774c-42b2-9072-6286ef7619f1"  //READONLY
#define CFG_BLESERVICE_DESCW_WIFI        "0x2903"                                //READONLY
// END WIFI BLE
// END WIFI

// OTA UPDATE
#define CFG_OTASERVICE_PORT             8123
#define CFG_OTASERVICE_HWID             "e298f4dc"  // ESP.getEfuseMac()
#define CFG_OTASERVICE_USERNAME         "ota"
#define CFG_OTASERVICE_PWD              "ohteayay"
// OTA UPDATE BLE
// Format: |SERVICEPORT UINT(16)|OTAHWID CHAR(32)|OTAUSERNAME CHAR(32)|OTAPASSWORD CHAR(32)|
// NOTE: Piping = 000000 data between entries
// Example: 0000001FBB00000065323938663464630000006F74610000006F68746561796179000000
// TODO: Encryption
#define CFG_BLESERVICE_CHARN_OTA       "2f1d3c82-2822-4fd2-88b9-d5ac5740aaf8"  //READONLY
#define CFG_BLESERVICE_DESCN_OTA        "0x2902"                                //READONLY
#define CFG_BLESERVICE_CHARW_OTA       "cc26910e-35e9-4d3c-95a2-748ef70e024b"  //READONLY
#define CFG_BLESERVICE_DESCW_OTA        "0x2903" 
// END OTA UPDATE BLE
// END OTA UPDATE

// TILT
#define CFG_TILT_PIN_FORWARD            -1
#define CFG_TILT_PIN_BACKWARD           -1
#define CFG_TILT_SPEED                  20
#define CFG_TILT_MIN_SPEED              1
#define CFG_TILT_MAX_SPEED              30
// TILT BLE
// Format: |TILTSPEED UINT(8)|MINSPEED UINT(8)|MAXSPEED UINT(8)|
// NOTE: Piping = 000000 data between entries
// Example: 0000001400000010000001E000000
// TODO: Encryption
#define CFG_BLESERVICE_CHARN_TILT       "83a372ac-40af-467b-a718-ed979c9e1d84"  //READONLY
#define CFG_BLESERVICE_DESCN_TILT       "0x2902"                                //READONLY
#define CFG_BLESERVICE_CHARW_TILT       "6754ebd3-2fc3-4330-8141-7c30a38d8c30"  //READONLY
#define CFG_BLESERVICE_DESCW_TILT       "0x2903" 
// END TILT BLE 
// END TILT

// PANNING
#define CFG_PANNER_PIN_IN1              4   // Yellow
#define CFG_PANNER_PIN_IN2              5   // White
#define CFG_PANNER_PIN_IN3              6   // Red
#define CFG_PANNER_PIN_IN4              7   // Black
#define CFG_PANNER_STEPS_PER_REV        2038
#define CFG_PANNER_SPEED                20
// TILT BLE
// Format: |PANSPEED UINT(8)|HEADING FLOAT(32)|
// NOTE: Piping = 000000 data between entries
// Example: 0000001400000042f670a4000000 //Heading = 123.22 - See https://gregstoll.com/~gregstoll/floattohex/
// TODO: Encryption
#define CFG_BLESERVICE_CHARN_PAN       "4a6525bb-03ee-451e-b90f-531443642251"  //READONLY
#define CFG_BLESERVICE_DESCN_PAN       "0x2902"                                //READONLY
#define CFG_BLESERVICE_CHARW_PAN       "f2054e1a-c3bd-48c0-9e58-16e5140b2708"  //READONLY
#define CFG_BLESERVICE_DESCW_PAN       "0x2903" 
// END PANNING BLE
// END PANNING

// BUZZER
#define CFG_BUZZER_PIN                  -1
#define CFG_CAMERA_SHUTTER_PIN          -1
// TODO: Buzzer Config Mute + Volume
// END BUZZER

//  Red VCC +5v
//  Black GND
#define CFG_GYRO_COMPASS_PIN_SDA        8 // White
#define CFG_GYRO_COMPASS_PIN_SCL        9 // Yellow

#endif //ASTROTURRET_CONFIG_H