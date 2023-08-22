#include "ads1115.h"

ADS1115Class *pressure_instances;

ADS1115Class::ADS1115Class(){
  pressure_instances = this;
}

void ADS1115Class::begin(){
  ads.setGain(GAIN_TWOTHIRDS);
  ads.begin();
}

int ADS1115Class::mmhg(){
  int adc_value = ads.readADC_SingleEnded(0);
  _mmhg = adc_value / 14;              //kalibrasi mmhg
  return _mmhg;
}

ADS1115Class pressure;