#ifndef MOTOR_H_
#define MOTOR_H_

#include <Arduino.h>

class MotorClass {
  private:
    uint8_t _tube_pin = 26;
    uint8_t _motor_pin = 25;
  public:
    MotorClass();
    void begin();
    void start();
    void pause();
    void stop();  
};

#endif // MOTOR_H_