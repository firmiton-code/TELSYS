#include "battery.h"

BatteryClass *battery_instances;

BatteryClass::BatteryClass(){
  battery_instances = this;
}

void BatteryClass::begin(){
  pinMode(_pin, INPUT);
}

int BatteryClass::get_percentage(){
  float voltage = analogReadMilliVolts(_pin) / 1000.0;
  int percentage = map(voltage, 2.8, 3.3, 0, 100);

  return percentage;
}

float BatteryClass::get_voltage(){
  float voltage = analogReadMilliVolts(_pin) / 1000.0;

  return voltage;
}

BatteryClass battery;