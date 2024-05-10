#include <WiFiUdp.h>
#include <NTPClient.h>

const char* ntpServer = "a.st1.ntp.br";
const int timeZone = -10800;

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
