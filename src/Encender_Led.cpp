#include "Arduino.h"
#include "esp32-hal-adc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encender_Led.h"

const int GreenLed = 04;
const int YellowLed = 22;
const int RedLed = 21;


Encender_Led::Encender_Led(){
    pinMode(GreenLed, OUTPUT);
    pinMode(YellowLed, OUTPUT);
    pinMode(RedLed, OUTPUT);
      
    digitalWrite(GreenLed, HIGH);
    digitalWrite(YellowLed, HIGH);
    digitalWrite(RedLed, HIGH);
    delay(1500);
    digitalWrite(GreenLed, LOW);
    digitalWrite(YellowLed, LOW);
    digitalWrite(RedLed, LOW);
    //led_correcto(led);
};

void Encender_Led::led_correcto(int led){
   
    digitalWrite(GreenLed, LOW);
    digitalWrite(YellowLed, LOW);
    digitalWrite(RedLed, LOW);

    digitalWrite(led, HIGH);
    
};


void Encender_Led::parpadea_led(int led){
    int i;
    for(i = 0; i < 15; i++){
        
        digitalWrite(led,HIGH);
        delay(300);

        digitalWrite(led, LOW);
        delay(300);

    }
    
};