#include <Arduino.h>
#include "LedController.h"

LedController ledController(32, 33, 25);

void setup()
{
}

void loop()
{
  ledController.updateColor(255, 0, 255);

  ledController.loop();
}