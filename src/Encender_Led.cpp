#include "Arduino.h"
#include "esp32-hal-adc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encender_Led.h"

const int GreenLed = 04;
const int YellowLed = 22;
const int RedLed = 21;

//const int led_anterior = 22;


Encender_Led::Encender_Led(){       //consturctor
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
    
};

void Encender_Led::turnON(int ledAPrender){

    digitalWrite(GreenLed, LOW);
    digitalWrite(YellowLed, LOW);
    digitalWrite(RedLed, LOW);

    if((ledAPrender != led_anterior) && (ledAPrender != YellowLed)){ parpadea_led(ledAPrender);}     //Hago parpadear cuando pasa de rojo a verde y viceversa(en el medio amarillo no)

    digitalWrite(ledAPrender, HIGH);
    if ((ledAPrender != YellowLed)){led_anterior = ledAPrender;}                                     //Solo guardo el estado del rojo y verde
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

int Encender_Led::get_led_anterior(){
    return led_anterior;
}