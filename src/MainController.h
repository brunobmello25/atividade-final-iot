#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <Arduino.h>
#include <LightSensorController.h>
#include <LedController.h>
#include <ColorCommandsController.h>

class MainController
{
public:
  MainController();
  void loop();

private:
  int lightLimit = 600;

  LedController ledController;
  LightSensorController lightSensorController;
  ColorCommandsController colorCommandsController;

  void updateLight();
  void updateColor();
};

#endif