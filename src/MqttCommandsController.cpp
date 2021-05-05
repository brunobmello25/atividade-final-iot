#include "MqttCommandsController.h"

MqttCommandsController::MqttCommandsController()
{
  this->WIFI = WiFiClient();
  this->MQTT = PubSubClient(this->WIFI);
}

void MqttCommandsController::setup()
{
  this->initializeMqtt();
}

void MqttCommandsController::loop()
{
  this->connectWifi();
  this->connectMqtt();

  this->MQTT.loop();
}

void MqttCommandsController::connectWifi()
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

void MqttCommandsController::initializeMqtt()
{
  this->MQTT.setServer(this->BROKER_URL, this->BROKER_PORT);

  this->MQTT.setCallback(MqttCommandsController::callback);
}

void MqttCommandsController::connectMqtt()
{
  while (!this->MQTT.connected())
  {
    Serial.println("connect mqtt");
    if (this->MQTT.connect(this->CLIENT))
    {
      this->MQTT.subscribe(this->COLOR_TOPIC);
    }
  }
}

void MqttCommandsController::callback(char *topic, byte *payload, unsigned int length)
{
  DynamicJsonDocument parsedPayload(length);
  deserializeJson(parsedPayload, payload);

  if (String(topic) == "color_control")
    Serial.println("command");
}
