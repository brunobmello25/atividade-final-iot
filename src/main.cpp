#include <Arduino.h>
#include "LedController.h"
#include "LightSensorController.h"

#define RED_PIN 32
#define GREEN_PIN 33
#define BLUE_PIN 25
#define LIGHT_SENSOR_PIN 12

LedController ledController(RED_PIN, GREEN_PIN, BLUE_PIN);
LightSensorController lightSensorController(LIGHT_SENSOR_PIN);

boolean lightsOn = false;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  ledController.loop();
  lightSensorController.loop();
  ledController.updateColor(120, 0, 120);

  int currentLight = lightSensorController.getLight();

  Serial.println(currentLight);
  ledController.toggle(currentLight < 400);

  delay(500);
}