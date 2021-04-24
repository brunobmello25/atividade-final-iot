#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <Arduino.h>
#include <LightSensorController.h>
#include <LedController.h>

class MainController
{
public:
  MainController();
  void loop();

private:
  int lightLimit = 500;
  LedController ledController;
  LightSensorController lightSensorController;
  boolean lightsOn = false;
  void updateLight();
};

#endif