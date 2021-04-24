#include "MainController.h"

#include <Arduino.h>

#define RED_PIN 32
#define GREEN_PIN 33
// #define GREEN_PIN 25
#define BLUE_PIN 25
// #define BLUE_PIN 27
#define LIGHT_SENSOR_PIN 12

MainController::MainController() : ledController(RED_PIN, GREEN_PIN, BLUE_PIN), lightSensorController(LIGHT_SENSOR_PIN)
{
  Serial.begin(115200);
  this->ledController.updateColor(10, 0, 10);
}

void MainController::loop()
{
  this->ledController.loop();
  this->lightSensorController.loop();

  this->updateLight();

  delay(500);
}

void MainController::updateLight()
{
  int currentLight = this->lightSensorController.getLight();

  Serial.println(currentLight);
  this->ledController.toggle(currentLight < this->lightLimit);
}