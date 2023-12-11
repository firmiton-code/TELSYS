#include "hx710.h"

// const byte _data_pin = 26;
// const byte _clock_pin = 25;
// Q2HX711 hx711(_data_pin, _clock_pin);

HX710B pressure_sensor; 
const int DOUT_Pin = 26;   //sensor data pin
const int SCLK_Pin = 25;   //sensor clock pin

HX710Class *pressure_instances;

HX710Class::HX710Class(){
  pressure_instances = this;
}

void HX710Class::start(){
  pressure_sensor.begin(DOUT_Pin, SCLK_Pin, 128);
}

long HX710Class::get(){
  if(pressure_sensor.is_ready()){
    return pressure_sensor.mmHg();
  } else{
    return 0;
  }
}

HX710Class pressure;