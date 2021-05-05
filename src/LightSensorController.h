#ifndef LIGHT_SENSOR_CONTROLLER_H
#define LIGHT_SENSOR_CONTROLLER_H

#include <Arduino.h>

class LightSensorController
{
public:
  LightSensorController();

  void setup(int sensorPin);
  void loop();
  int getLight();

private:
  int sensorPin;
  int sensorValue = 0;
};

#endif