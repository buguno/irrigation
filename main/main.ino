void setup() {
  Serial.begin(115200);
  delay(2000);

  conectWifi();
}

void loop() {
  int humidity = readHumidity();
  String message = String("Humidity: " + String(humidity) + "%");
  Serial.println(message);
  delay(30000);
}
