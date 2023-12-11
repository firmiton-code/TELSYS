#ifndef MOTOR_H_
#define MOTOR_H_

#include <Arduino.h>

class MotorClass {
  private:
    uint8_t _tube_pin = 33;
    uint8_t _motor_pin = 32;
  public:
    MotorClass();
    void begin();
    void start();
    void pause();
    void stop();  
};

extern MotorClass motor;

#endif // MOTOR_H_