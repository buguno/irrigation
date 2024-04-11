int readHumidity(void) {
  Serial.println("Capacitive Soil Moisture Sensor");
  int adcValue = analogRead(0);
  const int adcAirReading = 706;
  const int adcWaterReading = 284;

  Serial.print("ADC Reading: ");
  Serial.println(adcValue);
  int soilMoisturePercentage = map(adcValue, adcAirReading, adcWaterReading, 0, 100);

  Serial.print("Percent Humidity: ");
  Serial.print(soilMoisturePercentage);
  Serial.println("%");

  return soilMoisturePercentage;
}
