#include "lcd.h"

LCDClass *lcd_instances;

LCDClass::LCDClass(){
  lcd_instances = this;
}

void LCDClass::calibration(){
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  // check file system exists 
  if (!SPIFFS.begin()) {
    Serial.println("Formating file system");
    SPIFFS.format();
    SPIFFS.begin();
  }

  // check if calibration file exists and size is correct
  if (SPIFFS.exists(CALIBRATION_FILE)) {
    if (REPEAT_CAL)
    {
      // Delete if we want to re-calibrate
      SPIFFS.remove(CALIBRATION_FILE);
    }
    else
    {
      File f = SPIFFS.open(CALIBRATION_FILE, "r");
      if (f) {
        if (f.readBytes((char *)calData, 14) == 14)
          calDataOK = 1;
        f.close();
      }
    }
  }

  if (calDataOK && !REPEAT_CAL) {
    // calibration data valid
    tft.setTouch(calData);
  } else {
    // data not valid so recalibrate
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(20, 0);
    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.println("Touch corners as indicated");

    tft.setTextFont(1);
    tft.println();

    if (REPEAT_CAL) {
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.println("Set REPEAT_CAL to false to stop this running again!");
    }

    tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.println("Calibration complete!");

    // store data
    File f = SPIFFS.open(CALIBRATION_FILE, "w");
    if (f) {
      f.write((const unsigned char *)calData, 14);
      f.close();
    }
  }
}

void LCDClass::init(){
  tft.init();
  tft.setRotation(3);
  pinMode(14, INPUT);

  calibration();

  tft.fillScreen(BG_COLOR);
  tft.setSwapBytes(true);
  tft.setFreeFont(&FreeSans12pt7b);
  tft.setTextColor(TFT_BLACK, BG_COLOR);
  
  Serial.print("Free Heap: ");
  Serial.println(ESP.getFreeHeap());
  // max 240*230=55200
  // if (NULL != bgSprite.createSprite(290, 190)) {
  //   Serial.println("Sprite created");
  //   Serial.print("Free Heap: ");
  //   Serial.println(ESP.getFreeHeap());
  //   bgSprite.setSwapBytes(true);
  // } else {
  //   Serial.println("Sprite creation failed");
  // }

  tft.pushImage(0, 0, 320, 240, Keeta_Boot);
  // tft.pushImage(0, 0, 320, 240, Boot);
}

void LCDClass::boot(){
  delay(2000);
  tft.fillScreen(BG_COLOR);
  // tft.pushImage(90, 60, 140, 120, telsys_logo);
  tft.pushImage(0, 0, 320, 240, Keeta_Boot);
  // tft.pushImage(0, 0, 320, 240, Boot);
}

void LCDClass::show(String value1, String value2, String value3, String value4, String value5){
  tft.fillScreen(BG_COLOR);
  tft.pushImage(0, 0, 320, 240, Dashboard);

  tft.setTextDatum(TR_DATUM);
  tft.drawString(value1, 135, 60, 6);
  tft.drawString(value2, 270, 60, 6);
  tft.drawString(value3, 140, 140, 6);
  tft.setFreeFont(&FreeSans18pt7b);
  tft.drawString(value4, 270, 135, 1);
  tft.drawString(value5, 270, 165, 1);

  tft.setFreeFont(&FreeSans12pt7b);

  _screen = MAIN_SCREEN;
}

void LCDClass::notice(String value, String note){
  _screen = SCAN_SCREEN;
  if(value == "BPM"){
    tft.fillScreen(BG_COLOR);
    tft.pushImage(110, 30, 100, 100, Icon_Finger);
    tft.drawCentreString(note, 160, 150, 1);
  } else if(value == "TENSI"){
    tft.fillScreen(BG_COLOR);
    tft.pushImage(110, 30, 100, 100, Icon_Pressure);
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
      tft.pushImage(280, 104, 26, 26, Icon_Battery_Low, BG_COLOR);
      // tft.fillRect(305, 19, 15, 2, BG_COLOR);
      break;
    case BATTERY_HALF :
      tft.pushImage(280, 104, 26, 26, Icon_Battery_Half, BG_COLOR);
      // tft.fillRect(305, 19, 15, 2, BG_COLOR);
      break;
    case BATTERY_FULL :
      tft.pushImage(280, 104, 26, 26, Icon_Battery_Full, BG_COLOR);
      // tft.fillRect(305, 19, 15, 2, BG_COLOR);
      break;
    default :
      tft.pushImage(280, 104, 26, 26, Icon_Battery_Low, BG_COLOR);
      // tft.fillRect(305, 19, 15, 2, BG_COLOR);
      break;
  }
}

bool LCDClass::touchUpdate(){
  if(digitalRead(14)) return false;

  uint16_t t_x, t_y;
  tft.getTouchRaw(&t_x, &t_y);
  tft.convertRawXY(&t_x, &t_y);

  if(t_x >= 20 && t_x <= 46 && t_y >= 104 && t_y <=130){
    _power = true;
  }

  if(t_x >= 140 && t_x <= 180 && t_y >= 96 && t_y <= 136){
    _play = true;
  } else{
    _play = false;
  }

  if(t_x >= 93 && t_x <= 226 && t_y >= 123 && t_y <=149){
    _connection = true;
  } else if(t_x >= 93 && t_x <= 226 && t_y >= 157 && t_y <=163){
    _connection = false;
  }
  
  if(t_x >= 20 && t_x <= 140 && t_y >= 20 && t_y <= 100){
    _hr_button = true;
  } else{
    _hr_button = false;
  }

  if(t_x >= 20 && t_x <= 140 && t_y >= 140 && t_y <= 220){
    _temp_button = true;
  } else{
    _temp_button = false;
  }

  if(t_x >= 180 && t_x <= 300 && t_y >= 20 && t_y <= 100){
    _spo2_button = true;
  } else{
    _spo2_button = false;
  }

  if(t_x >= 180 && t_x <= 300 && t_y >= 140 && t_y <= 220){
    _bp_button = true;
  } else{
    _bp_button = false;
  }
  
  return true;
}

void LCDClass::show_choose(){
  tft.pushImage(0, 0, 320, 240, Choose_Mode);
}

bool LCDClass::getConnection(){
  return _connection;
}

bool LCDClass::getPlay(){
  return _play;
}

bool LCDClass::getPower(){
  return _power;
}

bool LCDClass::getScreen(){
  return _screen;
}

bool LCDClass::getHRButton(){
  return _hr_button;
}

bool LCDClass::getTempButton(){
  return _temp_button;
}

bool LCDClass::getSPO2Button(){
  return _spo2_button;
}

bool LCDClass::getBPButton(){
  return _bp_button;
}

void LCDClass::setPlay(bool play){
  _play = play;
}

LCDClass lcd;
