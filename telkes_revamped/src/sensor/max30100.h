#ifndef MAX30100_H_
#define MAX30100_H_

#include <Arduino.h>
#include "MAX30100_PulseOximeter.h"

class MAX30100Class {
  private:
    PulseOximeter pox;
  public:
    MAX30100Class();
    void begin();
    int bpm();
    int spo2();
};

extern MAX30100Class bpm;

#endif // MAX30100_H_