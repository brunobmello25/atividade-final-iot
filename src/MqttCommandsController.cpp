#include "MqttCommandsController.h"

MqttCommandsController::MqttCommandsController(LedController &ledController)
{
  this->WIFI = WiFiClient();
  this->MQTT = PubSubClient(this->WIFI);

  this->ledController = &ledController;
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

  using std::placeholders::_1;
  using std::placeholders::_2;
  using std::placeholders::_3;

  this->MQTT.setCallback(std::bind(&MqttCommandsController::callback, this, _1, _2, _3));
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
