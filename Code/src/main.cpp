/**
  Name: Zivkovic Mihajlo
  Klasse: 4BHEL
  Datum: 24.04.2025
  Project: ADC_Exercise
 **/
#include <Arduino.h>

const int poti = A0; 
unsigned long lastMillis = 0;
const unsigned long interval = 500;

void setup() 
  {
    Serial.begin(115200);
    // ADC initialisieren
    ADMUX |= (1 << REFS0);             
    ADCSRA |= (1 << ADEN) |= (1 << ADPS2) | (1 << ADPS1)| (1 << ADPS0); 
  }

void loop() {
  if (millis() - lastMillis >= interval) 
  {
    lastMillis = millis();
    ADCSRA |= (1 << ADSC);  
    while (ADCSRA & (1 << ADSC)!=0);  
    int analogWert = ADC;  
    float spannung = (analogWert / 1023.0) * 5.0;
    Serial.print("Potentiometer Wert = ");
    Serial.print(spannung);
    Serial.println(" V");
  }
}
/** Refferenzspannung, Prescaler, MUX, Start conmverstion bit und Interrupt  */