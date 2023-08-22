#ifndef LCD_H_
#define LCD_H_

#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "assets/config.h"
#include "assets/dashboard_logo.h"
#include "assets/finger.h"
#include "assets/hand.h"

#define BG_COLOR TFT_WHITE

class LCDClass{
  private:
    TFT_eSPI tft = TFT_eSPI();
    TFT_eSprite bgSprite = TFT_eSprite(&tft);
    TFT_eSprite textSprite = TFT_eSprite(&tft);
    TFT_eSprite logoSprite = TFT_eSprite(&tft);

  public:
    LCDClass();
    void init();
    void boot();
    void show(String value);
    void notice(String value);
    void load(int percentage);
};

extern LCDClass lcd;

#endif // LCD_H_