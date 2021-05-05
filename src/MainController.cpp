#include "MainController.h"

#define LIGHT_SENSOR_PIN 34
#define RED_PIN 32
#define GREEN_PIN 33
#define BLUE_PIN 25
// #define RED_PIN 32
// #define GREEN_PIN 25
// #define BLUE_PIN 27

MainController::MainController() : ledController(), lightSensorController(), mqttCommandsController()
{
}

void MainController::setup()
{
  Serial.begin(115200);

  this->ledController.setup(RED_PIN, GREEN_PIN, BLUE_PIN);
  this->lightSensorController.setup(LIGHT_SENSOR_PIN);
  this->mqttCommandsController.setup();
}

void MainController::loop()
{
  this->ledController.loop();
  this->lightSensorController.loop();
  this->mqttCommandsController.loop();

  this->updateLight();
}

void MainController::updateLight()
{
  int currentLight = this->lightSensorController.getLight();

  this->ledController.toggle(currentLight < this->lightLimit);
}