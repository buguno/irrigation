bool capacitiveSoilMoistureSensorError = false;
char thingSpeakDataString[100] = {0};

void turnOnValve() {
  digitalWrite(16, HIGH);
}

void turnOffValve() {
  digitalWrite(16, LOW);
}

void irrigate(int humidity) {
  if (!capacitiveSoilMoistureSensorError) {
    sprintf(thingSpeakDataString, "field1=%d&field2=%d&field3=%d", humidity, 1, 0);
    sendDataToThingSpeak(thingSpeakDataString);

    Serial.println("Irrigating...");
    turnOnValve();
    delay(60000);
    turnOffValve();
  }

  int currentHumidity = readHumidity();
  if (currentHumidity <= humidity && !capacitiveSoilMoistureSensorError) {
    Serial.println("Capacitive Soil Moisture Sensor Error");
    Serial.println("Initial Humidity is: " + String(humidity) + " and Current Humidity is: " + String(currentHumidity));
    capacitiveSoilMoistureSensorError = true;
  }

  if (capacitiveSoilMoistureSensorError) {
    sprintf(thingSpeakDataString, "field1=%d&field2=%d&field3=%d", currentHumidity, 0, 1);
    sendDataToThingSpeak(thingSpeakDataString);
    return;
  }

  sprintf(thingSpeakDataString, "field1=%d&field2=%d&field3=%d", currentHumidity, 0, 0);
  sendDataToThingSpeak(thingSpeakDataString);
}
