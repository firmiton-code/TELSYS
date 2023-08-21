#include "max30100.h"

MAX30100Class *bpm_instances;

MAX30100Class::MAX30100Class(){
  bpm_instances = this;
}

void MAX30100Class::begin(){
  pox.begin();
}

int MAX30100Class::bpm(){
  pox.update();

  int bpmSens = pox.getHeartRate() + 15;
  int spoSens = pox.getSpO2();

  return bpmSens;        
}

int MAX30100Class::spo2(){
  pox.update();

  int bpmSens = pox.getHeartRate() + 15;
  int spoSens = pox.getSpO2();

  return spoSens;        
}

MAX30100Class bpm;