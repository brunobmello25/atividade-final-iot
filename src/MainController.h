#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <Arduino.h>
#include <LightSensorController.h>
#include <LedController.h>
#include <MqttCommandsController.h>

class MainController
{
public:
  MainController();
  void loop();

private:
  int lightLimit = 800;

  LedController ledController;
  LightSensorController lightSensorController;
  MqttCommandsController colorCommandsController;

  void updateLight();
  void updateColor();
};

#endif