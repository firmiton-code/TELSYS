#include "max30100.h"

MAX30100Class *bpm_instances;

MAX30100Class::MAX30100Class(){
  bpm_instances = this;
}

void MAX30100Class::begin(){
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.begin();
}

void MAX30100Class::start(){
  pox.begin();
}

void MAX30100Class::stop(){
  pox.shutdown();
}

void MAX30100Class::update(){
  pox.update();
}

int MAX30100Class::bpm(){
  int bpmSens = pox.getHeartRate() + 15;
  int spoSens = pox.getSpO2();

  return bpmSens;        
}

int MAX30100Class::spo2(){
  int bpmSens = pox.getHeartRate() + 15;
  int spoSens = pox.getSpO2();

  return spoSens;        
}

MAX30100Class bpm;