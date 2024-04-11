void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(16, OUTPUT);
  conectWifi();
}

void loop() {
  int humidity = readHumidity();

  if (humidity < 40) {
    turnOnValve();
  } else {
    turnOffValve();
  }

  delay(30000);
}
