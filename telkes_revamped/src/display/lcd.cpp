#include "lcd.h"

LCDClass *lcd_instances;

LCDClass::LCDClass(){
  lcd_instances = this;
}

void LCDClass::init(){
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(BG_COLOR);
  tft.setSwapBytes(true);
  tft.setFreeFont(&FreeSans12pt7b);
  tft.setTextColor(TFT_BLACK, BG_COLOR);
  
  Serial.print("Free Heap: ");
  Serial.println(ESP.getFreeHeap());
  // max 240*230=55200
  if (NULL != bgSprite.createSprite(290, 190)) {
    Serial.println("Sprite created");
    Serial.print("Free Heap: ");
    Serial.println(ESP.getFreeHeap());
    bgSprite.setSwapBytes(true);
  } else {
    Serial.println("Sprite creation failed");
  }

  tft.pushImage(90, 40, 140, 120, telsys_logo);
}

void LCDClass::boot(){
  delay(2000);
  tft.fillScreen(BG_COLOR);
  tft.pushImage(90, 60, 140, 120, telsys_logo);
}

void LCDClass::show(String value1, String value2, String value3, String value4, String value5){
  tft.fillScreen(BG_COLOR);

  tft.drawSmoothRoundRect(8, 10, 10, 12, 142, 100, TFT_DARKGREY, BG_COLOR);
  tft.drawSmoothRoundRect(170, 10, 10, 12, 142, 100, TFT_DARKGREY, BG_COLOR);
  tft.drawSmoothRoundRect(8, 130, 10, 12, 142, 100, TFT_DARKGREY, BG_COLOR);
  tft.drawSmoothRoundRect(170, 130, 10, 12, 142, 100, TFT_DARKGREY, BG_COLOR);
  
  bgSprite.fillSprite(BG_COLOR);
  bgSprite.pushImage(75, 35, 140, 120, dashboard_logo);
  bgSprite.pushSprite(15, 25, BG_COLOR);

  tft.setTextDatum(TL_DATUM);
  tft.drawString("Heart Rate", 50, 15, 2);
  tft.drawString("Oxygen", 230, 15, 2);
  tft.drawString("Temperature", 37, 135, 2);
  tft.drawString("Blood Pressure", 210, 135, 2);

  tft.setTextDatum(TR_DATUM);
  tft.drawString(value1, 108, 45, 6);
  tft.setTextDatum(TL_DATUM);
  tft.drawString("bpm", 112, 45, 2);
  tft.setTextDatum(TR_DATUM);
  tft.drawString(value2, 270, 45, 6);
  tft.setTextDatum(TL_DATUM);
  tft.drawString("%", 273, 45, 1);
  tft.setTextDatum(TR_DATUM);
  tft.drawString(value3, 123, 165, 6);
  tft.setTextDatum(BL_DATUM);
  tft.drawString("*C", 125, 205, 2);
  tft.setFreeFont(&FreeSans18pt7b);
  tft.setTextDatum(TR_DATUM);
  tft.drawString(value4, 270, 160, 1);
  tft.drawString(value5, 270, 190, 1);
  tft.setTextDatum(TL_DATUM);
  tft.drawString("mmhg", 273, 180, 2);
  tft.setFreeFont(&FreeSans12pt7b);
}

void LCDClass::notice(String value, String note){
  if(value == "BPM"){
    tft.fillScreen(BG_COLOR);
    tft.pushImage(90, 30, 140, 120, finger);
    tft.drawCentreString(note, 160, 150, 1);
  } else if(value == "TENSI"){
    tft.fillScreen(BG_COLOR);
    tft.pushImage(90, 30, 140, 120, hand);
    tft.drawCentreString(note, 160, 150, 1);
  }
}

void LCDClass::load(int percentage){
  tft.fillSmoothRoundRect(85, 190, 150, 15, 15, TFT_DARKGREY, BG_COLOR);
  tft.fillSmoothRoundRect(85, 190, percentage*15, 15, 15, TFT_BLUE, BG_COLOR);
  // tft.drawSmoothArc(160, 120, 10, 12, 0, percentage*36, TFT_GREEN, BG_COLOR);
  // tft.fillSmoothCircle(160, 120, 50, TFT_GREEN, BG_COLOR);
}

void LCDClass::reset(){
  tft.fillScreen(BG_COLOR);
}

void LCDClass::showBattery(Battery_Level_t batt_level){
  switch (batt_level){
    case BATTERY_LOW :
      tft.pushImage(295, 5, 25, 15, battery_low, BG_COLOR);
      tft.fillRect(305, 19, 15, 2, BG_COLOR);
      break;
    case BATTERY_HALF :
      tft.pushImage(295, 5, 25, 15, battery_half, BG_COLOR);
      tft.fillRect(305, 19, 15, 2, BG_COLOR);
      break;
    case BATTERY_FULL :
      tft.pushImage(295, 5, 25, 15, battery_full, BG_COLOR);
      tft.fillRect(305, 19, 15, 2, BG_COLOR);
      break;
    default :
      tft.pushImage(295, 5, 25, 15, battery_low, BG_COLOR);
      tft.fillRect(305, 19, 15, 2, BG_COLOR);
      break;
  }
}

LCDClass lcd;
