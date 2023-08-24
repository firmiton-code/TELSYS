#ifndef LCD_H_
#define LCD_H_

#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "assets/battery.h"
#include "assets/config.h"
#include "assets/dashboard_logo.h"
#include "assets/finger.h"
#include "assets/hand.h"
#include "assets/telsys_logo.h"

#define BG_COLOR TFT_WHITE
#define LARGE_TEXT 6
#define NORMAL_TEXT 1
#define SMALL_TEXT 2
#define NUMBER_TEXT 7

typedef enum {
  BATTERY_LOW,
  BATTERY_HALF,
  BATTERY_FULL
} Battery_Level_t;

class LCDClass{
  private:
    TFT_eSPI tft = TFT_eSPI();
    TFT_eSprite bgSprite = TFT_eSprite(&tft);
    TFT_eSprite textSprite = TFT_eSprite(&tft);
    TFT_eSprite logoSprite = TFT_eSprite(&tft);
    Battery_Level_t batt;

  public:
    LCDClass();
    void init();
    void boot();
    void show(String value1, String value2, String value3, String value4, String value5);
    void notice(String value, String note);
    void load(int percentage);
    void reset();
    void showBattery(Battery_Level_t batt_level);
};

extern LCDClass lcd;

#endif // LCD_H_