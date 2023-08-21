#ifndef ADS1115_H_
#define ADS1115_H_

#include <Arduino.h>
#include "Adafruit_ADS1X15.h"

class ADS1115Class {
  private:
    Adafruit_ADS1115 ads;
    int _diastol;
    int _sistol;

  public:
    ADS1115Class();
    void begin();
    void get_blood_pressure();
    int diastol();
    int sistol();
};

extern ADS1115Class pressure;

#endif // ADS1115_H_