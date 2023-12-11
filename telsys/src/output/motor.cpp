#include "motor.h"

MotorClass *motor_instances;

MotorClass::MotorClass(){
  motor_instances = this;
}

void MotorClass::begin(){
  pinMode(_tube_pin, OUTPUT);
  pinMode(_motor_pin, OUTPUT);
}

void MotorClass::start(){
  digitalWrite(_tube_pin, HIGH);
  digitalWrite(_motor_pin, HIGH);
}

void MotorClass::pause(){
  digitalWrite(_tube_pin, HIGH);
  digitalWrite(_motor_pin, LOW);
}

void MotorClass::stop(){
  digitalWrite(_tube_pin, LOW);
  digitalWrite(_motor_pin, LOW);
}

MotorClass motor;