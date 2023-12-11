#include "mlx90614.h"

MLX90614Class *temp_instances;

MLX90614Class::MLX90614Class(){
  temp_instances = this;
}

void MLX90614Class::begin(){
  mlx.begin();
}

float MLX90614Class::temperature(){
  return mlx.readObjectTempC();
}

MLX90614Class temp;