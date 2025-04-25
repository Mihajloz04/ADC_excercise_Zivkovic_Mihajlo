/**
 * Name: Zivkovic Mihajlo
 * Class: 4BHEL
 * Date:  24.04.2025
 * Project: ADC_Exercise
 */
#include <Arduino.h>

const int poti = A0;
unsigned long lastMillis = 0;
const unsigned long interval = 500;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() - lastMillis >= interval) {
    lastMillis = millis();

    int AnalogWert = analogRead(poti);
    float Spginput = (AnalogWert / 1023.0) * 5.0;

    Serial.print("Potentiometer Wert = ");
    Serial.print(Spginput);
    Serial.println(" V");
  }
}