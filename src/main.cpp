#include <Arduino.h>

#include "MainController.h"

MainController mainController;

void setup()
{
  mainController.setup();
}

void loop()
{
  mainController.loop();
}