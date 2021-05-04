#include "MainController.h"

#define LIGHT_SENSOR_PIN 34
#define RED_PIN 32
#define GREEN_PIN 33
#define BLUE_PIN 25
// #define RED_PIN 32
// #define GREEN_PIN 25
// #define BLUE_PIN 27

MainController::MainController() : ledController(RED_PIN, GREEN_PIN, BLUE_PIN), lightSensorController(LIGHT_SENSOR_PIN), colorCommandsController()
{
  Serial.begin(115200);
}

void MainController::loop()
{
  this->ledController.loop();
  this->lightSensorController.loop();
  this->colorCommandsController.loop();

  this->updateLight();
  // this->updateColor();
}

void MainController::updateColor()
{
  // int *colors = this->colorController.getColors();

  // this->ledController.updateColor(colors[0], colors[1], colors[2]);
}

void MainController::updateLight()
{
  int currentLight = this->lightSensorController.getLight();

  this->ledController.toggle(currentLight < this->lightLimit);
}