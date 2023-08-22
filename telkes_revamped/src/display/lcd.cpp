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

  tft.setTextColor(TFT_BLACK, BG_COLOR);
  tft.setFreeFont(&FreeSans12pt7b);
  tft.drawCentreString("Initializing Device", 160, 115, 1);

  Serial.print("Free Heap: ");
  Serial.println(ESP.getFreeHeap());
  // max 240*230=55200
  if (NULL != bgSprite.createSprite(290, 190)) {
    Serial.println("Sprite created");
    Serial.print("Free Heap: ");
    Serial.println(ESP.getFreeHeap());

    bgSprite.fillSprite(TFT_GREEN);
    bgSprite.setTextColor(TFT_RED);
    bgSprite.setFreeFont(&FreeSans12pt7b);
    bgSprite.setCursor(20, 5);
    bgSprite.print(ESP.getFreeHeap());
    bgSprite.setTextColor(TFT_BLACK, BG_COLOR);
    bgSprite.pushSprite(15, 25);
  } else {
    Serial.println("Sprite creation failed");
  }
  
  if (NULL != textSprite.createSprite(290, 190)) {
    Serial.println("Sprite created");
    Serial.print("Free Heap: ");
    Serial.println(ESP.getFreeHeap());

    textSprite.fillSprite(TFT_RED);
    textSprite.setTextColor(TFT_GREEN);
    textSprite.setCursor(50, 50);
    textSprite.print(ESP.getFreeHeap());
    textSprite.pushSprite(15, 25);
  } else {
    Serial.println("Sprite creation failed");
  }
}

void LCDClass::boot(){
  delay(2000);
  tft.fillScreen(BG_COLOR);
  tft.pushImage(90, 60, 140, 120, dashboard_logo);
  
  delay(2000);
  tft.fillScreen(BG_COLOR);
  tft.pushImage(90, 60, 140, 120, config);
  
  delay(2000);
  tft.fillScreen(BG_COLOR);
  tft.pushImage(90, 60, 140, 120, finger);
  
  delay(2000);
  tft.fillScreen(BG_COLOR);
  tft.pushImage(90, 60, 140, 120, hand);

  delay(2000);
  tft.fillScreen(BG_COLOR);
  tft.drawRect(3, 3, 314, 234, TFT_BLACK);
  tft.drawCentreString("Setup Done!", 160, 115, 1);

  delay(2000);
  tft.drawCentreString("STAND BY MODE", 160, 115, 1);
}

void LCDClass::show(String value){
  bgSprite.fillSprite(TFT_LIGHTGREY);
  bgSprite.drawCentreString(value, 145, 95, 1);
  bgSprite.pushSprite(15, 25, TFT_LIGHTGREY);
}

void LCDClass::notice(String value){
  bgSprite.fillSprite(BG_COLOR);
  bgSprite.drawCentreString(value, 145, 95, 1);
  bgSprite.pushSprite(15, 25, BG_COLOR);
}

void LCDClass::load(int percentage){

}

LCDClass lcd;