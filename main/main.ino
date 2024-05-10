void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(16, OUTPUT);
  conectWifi();
  delay(2000);

  ntpStart();
}

void loop() {
  delay(30);
  char thingSpeakDataString[100] = {0};
  int humidity = readHumidity();

  if (humidity > 100) {
    sprintf(thingSpeakDataString, "field1=%d&field2=%d&field3=%d", humidity, 0, 1);
    sendDataToThingSpeak(thingSpeakDataString);
    Serial.println("Capacitive Soil Moisture Sensor Error!!!");
  } else if (humidity < 40) {
    irrigate(humidity, millis());
  }

  delay(60000);
}
