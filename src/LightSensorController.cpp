#include "LightSensorController.h"

#include <Arduino.h>

LightSensorController::LightSensorController(int sensorPin)
{
  this->sensorPin = sensorPin;

  pinMode(this->sensorPin, INPUT);
}

void LightSensorController::loop()
{
  this->sensorValue = analogRead(this->sensorPin);
}

int LightSensorController::getLight()
{
  return this->sensorValue;
}