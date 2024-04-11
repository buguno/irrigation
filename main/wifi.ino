#include "environments.h"
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASSWORD;

void conectWifi() {
  Serial.println("------WI-FI connection------");
  Serial.print("Connecting to the network: ");
  Serial.println(ssid);
  Serial.println("Wait...");

  pinMode(LED_BUILTIN, OUTPUT);

  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, HIGH);
    return;
  }

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }

  Serial.println();
  Serial.print("Successfully connected to the network ");
  Serial.println(ssid);
  Serial.print("IP obtained: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_BUILTIN, HIGH);
}
