#ifndef PIN_CONFIG_H 
#define PIN_CONFIG_H

#define CFG_BUILD_VERSION           "0.0.1"
#define CFG_BUILD_TIME              "00:00:01"
#define CFG_BUILD_DATE              "13/06/2025"

#define CFG_WIFI_APSSID             "astro_cam"
#define CFG_WIFI_SSID               "dba387a58f"
#define CFG_WIFI_PWD                "f232184411b74b55af8ad13738b55408"
#define CFG_WIFI_HOSTNAME           "astrocam"

#define CFG_OTASERVICE_PORT         8123
#define CFG_OTASERVICE_HWID         "e298f4dc"  // ESP.getEfuseMac()
#define CFG_OTASERVICE_USERNAME     "ota"
#define CFG_OTASERVICE_PWD          "ota"

#define CFG_TILT_PIN_FORWARD        -1
#define CFG_TILT_PIN_BACKWARD       -1
#define CFG_TILT_SPEED              20
#define CFG_TILT_MIN_SPEED          1
#define CFG_TILT_MAX_SPEED          30


#define CFG_PANNER_PIN_IN1          4
#define CFG_PANNER_PIN_IN2          5
#define CFG_PANNER_PIN_IN3          6
#define CFG_PANNER_PIN_IN4          7
#define CFG_PANNER_STEPS_PER_REV    2038
#define CFG_PANNER_SPEED            20

#define CFG_BUZZER_PIN              -1
#define CFG_CAMERA_SHUTTER_PIN      -1

#define CFG_GYRO_COMPASS_PIN_SDA    8
#define CFG_GYRO_COMPASS_PIN_SCL    9




#endif //PIN_CONFIG_H