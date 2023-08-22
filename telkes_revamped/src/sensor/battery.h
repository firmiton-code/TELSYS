#ifndef BATTERY_H_
#define BATTERY_H_

#include <Arduino.h>

class BatteryClass {
  private:
    uint8_t _pin = 36;
  public:
    BatteryClass();
    void begin();
    int get_percentage();
    float get_voltage();
};

extern BatteryClass battery;

#endif // BATTERY_H_