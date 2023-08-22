#ifndef ADS1115_H_
#define ADS1115_H_

#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_ADS1X15.h"

class ADS1115Class {
  private:
    Adafruit_ADS1115 ads;
    int _mmhg;

  public:
    ADS1115Class();
    void begin();
    int mmhg();
};

extern ADS1115Class pressure;

#endif // ADS1115_H_