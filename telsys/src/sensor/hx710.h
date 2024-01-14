#ifndef HX710_H_
#define HX710_H_

#include <Arduino.h>
#include <SPI.h>
#include "HX710B.h"

class HX710Class {
  public:
    HX710Class();
    void start();
    bool ready();
    long get();
};

extern HX710Class pressure;

#endif // HX710_H_