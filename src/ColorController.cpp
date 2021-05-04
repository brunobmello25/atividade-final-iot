#include "ColorController.h"

ColorController::ColorController()
{
  this->WIFI = WiFiClient();
  this->MQTT = PubSubClient(this->WIFI);

  this->initializeMqtt();

  this->colors = new int[3];
  this->colors[0] = 100;
  this->colors[1] = 0;
  this->colors[2] = 100;
}

void ColorController::loop()
{
  this->connectWifi();
  // this->connectMqtt();

  // this->MQTT.loop();
}

int *ColorController::getColors()
{
  return this->colors;
}

void ColorController::connectWifi()
{
  if (WiFi.status() == WL_CONNECTED)
    return;

  Serial.println("connect wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(this->WIFI_SSID, this->WIFI_PASSWORD);
    delay(100);
  }
}

void ColorController::initializeMqtt()
{
  this->MQTT.setServer(this->BROKER_URL, this->BROKER_PORT);

  this->MQTT.setCallback(ColorController::callback);
}

void ColorController::connectMqtt()
{
  while (!this->MQTT.connected())
  {
    Serial.println("connect mqtt");
    if (this->MQTT.connect(this->CLIENT))
    {
      this->MQTT.subscribe(this->TOPIC);
    }
  }
}

void ColorController::callback(char *topic, byte *payload, unsigned int length)
{
  String msg;

  for (int i = 0; i < length; i++)
  {
    char c = (char)payload[i];
    msg += c;
  }

  Serial.println(msg);
}
