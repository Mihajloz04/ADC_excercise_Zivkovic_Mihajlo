# ADC-Konfiguration – ATmega328P

Dieses Projekt verwendet den ADC des ATmega328P zur Messung von analogen Spannungen. Die folgenden Register und Bits werden gesetzt bzw. ausgelesen.
![Code](Code/src/main.cpp)
## Verwendete Register und Bits

### ADMUX – ADC Multiplexer Selection Register

- REFS0 = 1 → AVcc als Referenzspannung  
- MUX[3:0] = 0000 → Auswahl des Eingangs (z. B. ADC0)

### ADCSRA – ADC Control and Status Register A

- ADEN = 1 → ADC aktivieren  
- ADSC = 1 → Start der Konvertierung  
- ADIE = 1 → ADC Interrupt aktivieren  
- ADPS2 = 1, ADPS1 = 1, ADPS0 = 1 → Prescaler = 128

### ADCL und ADCH – Ergebnisregister

- ADC-Ergebnis wird aus ADCL und ADCH gelesen oder über das Makro `ADC` zusammengefasst

## Prescaler

Systemtakt: 16 MHz  
Gewählter Prescaler: 128  
ADC-Takt: 16 MHz / 128 = 125 kHz

## Multiplexer

ADMUX → MUX[3:0] wählt den Eingangskanal  
Beispiel: 0000 = ADC0, 0001 = ADC1, ..., 0111 = ADC7

## Start der Konvertierung

ADCSRA |= (1 << ADSC)

## Auswertung über Interrupt

- ADIE in ADCSRA setzen  
- Globale Interrupts aktivieren mit `sei()`  
- ISR definieren: