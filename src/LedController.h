#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <Arduino.h>

class LedController
{
public:
  LedController(int redPin, int greenPin, int bluePin);

  void loop();

  void updateColor(int red, int green, int blue);

  void toggle(boolean ligthsOn);

private:
  int normalize(int num);

  int redPin;
  int greenPin;
  int bluePin;

  int redAmount;
  int greenAmount;
  int blueAmount;

  const int pwmFrequency = 5000;
  const int pwmRedChannel = 0;
  const int pwmGreenChannel = 1;
  const int pwmBlueChannel = 2;
  const int pwdResolution = 8;

  boolean lightsOn = false;
};

#endif