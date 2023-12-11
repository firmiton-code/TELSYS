#ifndef DEVICE_CONFIG_H_
#define DEVICE_CONFIG_H_

#include <Arduino.h>
#include "sensor/hx710.h"
#include "sensor/max30100.h"
#include "sensor/mlx90614.h"
#include "sensor/battery.h"
#include "display/lcd.h"
#include "output/motor.h"
#include "data/network.h"

#define FIREBASE_USE_PSRAM

#define DEFAULT_SSID        "3DPractical"
#define DEFAULT_PASS        "embeddedelectronics"
#define DEFAULT_AP_SSID     "TELSYS"

#define DEFAULT_DEVICE_CODE (uint32_t)ESP.getEfuseMac()

#define debug(x, y)         Serial.print("[");Serial.print(millis());Serial.print("]"); Serial.print("[");Serial.print(x);Serial.print("] "); Serial.println(y);
#define debugVal(x, y, z)   Serial.print("[");Serial.print(millis());Serial.print("]"); Serial.print("[");Serial.print(x);Serial.print("] "); Serial.print(y); Serial.println(z);

#endif // DEVICE_CONFIG_H_