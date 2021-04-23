#include "LedController.h"

#include <Arduino.h>

LedController::LedController(int redPin, int greenPin, int bluePin)
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  this->redPin = redPin;
  this->greenPin = greenPin;
  this->bluePin = bluePin;

  ledcSetup(this->pwmRedChannel, this->pwmFrequency, this->pwdResolution);
  ledcSetup(this->pwmGreenChannel, this->pwmFrequency, this->pwdResolution);
  ledcSetup(this->pwmBlueChannel, this->pwmFrequency, this->pwdResolution);

  ledcAttachPin(redPin, this->pwmRedChannel);
  ledcAttachPin(greenPin, this->pwmGreenChannel);
  ledcAttachPin(bluePin, this->pwmBlueChannel);

  this->redAmount = 255;
  this->greenAmount = 255;
  this->blueAmount = 255;
}

void LedController::loop()
{
  ledcWrite(this->pwmRedChannel, this->redAmount);
  ledcWrite(this->pwmGreenChannel, this->greenAmount);
  ledcWrite(this->pwmBlueChannel, this->blueAmount);
}

void LedController::updateColor(int red, int green, int blue)
{
  this->redAmount = normalize(red);
  this->greenAmount = normalize(green);
  this->blueAmount = normalize(blue);
}

int LedController::normalize(int num)
{
  if (num > 255)
    return 255;
  if (num < 0)
    return 0;

  return num;
}