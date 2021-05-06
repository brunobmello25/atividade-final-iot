#ifndef MQTT_COMMANDS_CONTROLLER_H
#define MQTT_COMMANDS_CONTROLLER_H

#include <PubSubClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <LedController.h>

class MqttCommandsController
{
public:
  MqttCommandsController(LedController &ledController);

  void setup();
  void loop();

private:
  void connectWifi();
  void connectMqtt();
  void initializeMqtt();

  void callback(char *topic, byte *payload, unsigned int length);

  const char *WIFI_SSID = "bruno";
  const char *WIFI_PASSWORD = "13337605";

  const char *BROKER_URL = "192.168.1.142";
  const int BROKER_PORT = 1883;
  const char *COLOR_TOPIC = "color_control";
  const char *CLIENT = "esp32";

  WiFiClient WIFI;
  PubSubClient MQTT;

  LedController *ledController;
};

#endif