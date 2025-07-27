# Smart Energy Monitoring System (Simulation)

🔗 [View Live Simulation in Tinkercad]
(https://www.tinkercad.com/things/lW7OXP4AqxF)

This project simulates a basic energy monitoring system using Arduino and a potentiometer to mimic the behavior of an ACS712 current sensor.

---

## 🔌 Components Used
- Arduino Uno
- Potentiometer (10kΩ)
- Breadboard
- Jumper Wires
- Simulated using Autodesk Tinkercad

---

## 📊 Functionality
- Reads analog voltage from a potentiometer to simulate ACS712 current sensor output
- Calculates current based on voltage variation
- Calculates power assuming a constant 230V AC supply
- Displays real-time current and power values on the Serial Monitor

---

## 📷 Simulation Screenshot
![Circuit]
(simulation_screenshot.png)

---

## 💡 Arduino Code
```cpp
const int sensorPin = A0;
float sensitivity = 0.185; // Sensitivity of ACS712 (185 mV/A for 5A module)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(sensorPin);
  float voltage = (adcValue * 5.0) / 1023.0;
  float current = (voltage - 2.5) / sensitivity;
  float power = 230.0 * current; // Assuming constant voltage supply

  Serial.print("Current: ");
  Serial.print(current, 3);
  Serial.print(" A, Power: ");
  Serial.print(power, 2);
  Serial.println(" W");

  delay(1000);
}
