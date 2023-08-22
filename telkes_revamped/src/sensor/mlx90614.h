#ifndef MLX90614_H_
#define MLX90614_H_

#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_MLX90614.h"

class MLX90614Class {
  private:
    Adafruit_MLX90614 mlx = Adafruit_MLX90614();
  public:
    MLX90614Class();
    void begin();
    float temperature();
};

extern MLX90614Class temp;

#endif // MLX90614_H_