void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(16, OUTPUT);
  conectWifi();
}

void loop() {
  int humidity = readHumidity();

  if (humidity > 100) {
    // Launch error to ThingSpeak
    Serial.println("Capacitive Soil Moisture Sensor Error!!!");
  } else if (humidity < 40) {
    irrigate(humidity, millis());
  }

  delay(60000);
}
