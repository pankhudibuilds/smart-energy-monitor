const int sensorPin = A0;
float sensitivity = 0.185; // Sensitivity of ACS712 (185 mV/A for 5A module)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(sensorPin);
  float voltage = (adcValue * 5.0) / 1023.0;
  float current = (voltage - 2.5) / sensitivity;
  float power = 230.0 * current;

  Serial.print("Current: ");
  Serial.print(current, 3);
  Serial.print(" A, Power: ");
  Serial.print(power, 2);
  Serial.println(" W");

  delay(1000);
}
