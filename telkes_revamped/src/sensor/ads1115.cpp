#include "ads1115.h"

ADS1115Class *pressure_instances;

ADS1115Class::ADS1115Class(){
  pressure_instances = this;
}

void ADS1115Class::begin(){
  ads.setGain(GAIN_TWOTHIRDS);
  ads.begin();
}

void ADS1115Class::get_blood_pressure(){
  
}

int ADS1115Class::diastol(){
  return _diastol;
}

int ADS1115Class::sistol(){
  return _sistol;
}

ADS1115Class pressure;