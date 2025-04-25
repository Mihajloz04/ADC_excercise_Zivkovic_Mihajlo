/**Name: Zivkovic Mihajlo
 * Class: 4BHEL
 * Date:  24.04.2025
 * Project: ADC_Excercise
 */
#include <Arduino.h>

const int poti=A0;

void setup()
{
  Serial.begin
}
void loop()
{
  int AnalogWert= analogRead(poti);
  float Spginput =(AnalogWert/1023.0)*5;
  Serial.print("Potentiometer Wert = ");
  Serial.print(Spginput);
  Serial.print("V");
  delay(500);
}