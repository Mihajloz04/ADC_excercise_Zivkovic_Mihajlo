/**
  Name: Zivkovic Mihajlo
  Klasse: 4BHEL
  Datum: 24.04.2025
  Project: ADC_Exercise
 **/
#include <Arduino.h>

const int poti = A0;
volatile int analogWert = 0;
volatile bool adcReady = false;

unsigned long lastMillis = 0;
const unsigned long interval = 500;

void setup() {
  Serial.begin(115200);
  ADMUX = (1 << REFS0);
  ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  sei();
}

void loop() {
  if (millis() - lastMillis >= interval) {
    lastMillis = millis();
    ADCSRA |= (1 << ADSC);
  }

  if (adcReady) {
    adcReady = false;
    float spannung = (analogWert / 1023.0) * 5.0;
    Serial.print("Potentiometer Wert = ");
    Serial.print(spannung, 3);
    Serial.println(" V");
  }
}

ISR(ADC_vect) {
  analogWert = ADC;
  adcReady = true;
}
/** Refferenzspannung, Prescaler, MUX, Start conmverstion bit und Interrupt  */