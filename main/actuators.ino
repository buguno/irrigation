bool valveError = false;

void turnOnValve() {
  digitalWrite(16, HIGH);
}

void turnOffValve() {
  digitalWrite(16, LOW);
}

void irrigate(int humidity, long startTime) {
  if (!valveError) {
    turnOnValve();
    Serial.println("Irrigating...");
  }

  delay(30000);

  int currentHumidity = readHumidity();
  if (currentHumidity <= humidity && !valveError) {
    Serial.println("Capacitive Soil Moisture Sensor Error");
    Serial.println("Initial Humidity is: " + String(humidity) + " and Current Humidity is: " + String(currentHumidity));
    turnOffValve();
    valveError = true;
  }

  Serial.println("Stopping watering, the current humidity is: " + String(currentHumidity));
}
