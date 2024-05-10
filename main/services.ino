#include "environments.h"
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

const char* ntpServer = "a.st1.ntp.br";
const int timeZone = -3 * 3600;

char thingSpeakApi[] = "api.thingspeak.com";
String thingSpeakApiKey = SECRET_THINGS_SPEAK;

WiFiClient client;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer, timeZone, 60000);

void ntpStart() {
  timeClient.begin();
  timeClient.forceUpdate();
}

int getHour() {
  return timeClient.getHours();
}

String getFormattedTime() {
  return timeClient.getFormattedTime();
}

void sendDataToThingSpeak(String dataString) {
  if (client.connect(thingSpeakApi, 80)) {
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+thingSpeakApiKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(dataString.length());
    client.print("\n\n");
    client.print(dataString);

    Serial.println("Information sent to ThingSpeak!");
  }
}