int readHumidity(void) {
  Serial.println("Capacitive Soil Moisture Sensor");
  int adcValue = analogRead(0);
  const int adcAirReading = 634;
  const int adcWaterReading = 304;

  Serial.print("ADC Reading: ");
  Serial.println(adcValue);
  int soilMoisturePercentage = map(adcValue, adcWaterReading, adcAirReading, 100, 0);

  Serial.print("Percent Humidity: ");
  Serial.print(soilMoisturePercentage);
  Serial.println("%");

  return soilMoisturePercentage;
}
