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
  void setup();
  void loop();

private:
  int lightLimit = 800;

  void updateLight();

  LedController ledController;
  LightSensorController lightSensorController;
  MqttCommandsController mqttCommandsController;
};

#endif