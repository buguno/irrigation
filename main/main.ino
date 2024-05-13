void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(16, OUTPUT);
  conectWifi();
  delay(2000);

  ntpStart();
}

void loop() {
  char thingSpeakDataString[100] = {0};
  int humidity = readHumidity();
  long irrigationStarted = 0;
  long irrigationFinished = 0;

  if (getHour() == 5 || getHour() == 17) {
    if (humidity > 100 || humidity < -70) {
      sprintf(thingSpeakDataString, "field1=%d&field2=%d&field3=%d", humidity, 0, 1);
      sendDataToThingSpeak(thingSpeakDataString);
      Serial.println("Capacitive Soil Moisture Sensor Error!!!");
    } else if (humidity < 40) {
      irrigationStarted = millis();
      irrigate(humidity);
      irrigationFinished = millis();
    }
  } else {
    sprintf(thingSpeakDataString, "field1=%d&field2=%d&field3=%d", humidity, 0, 0);
    sendDataToThingSpeak(thingSpeakDataString);
  }

  delay(1200000 - (irrigationFinished - irrigationStarted));
}
