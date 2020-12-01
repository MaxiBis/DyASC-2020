#include "Arduino.h"
#include "leds.h"
//#include <string.h>
#include <iostream> 
#include <iterator> 
#include <map> 

const int GreenLed = 23;
const int YellowLed = 22;
const int RedLed = 21;

    leds::leds(){
        // empty map container 
        
        std::map<std::string, int> color_salidas; 
  
        // insert elements in random order 
        color_salidas.insert({"verde", 40});
        
        // initialize digital pin ledPin as an output and set them as low
        pinMode(GreenLed, OUTPUT);
        pinMode(YellowLed, OUTPUT);
        pinMode(RedLed, OUTPUT);
        digitalWrite(GreenLed, LOW);
        digitalWrite(YellowLed, LOW);
        digitalWrite(RedLed, LOW);
    }

    void leds::solo_verde(){
        apagar_amarillo();
        apagar_rojo();
        prender_verde();
    }
    void leds::solo_rojo(){
        apagar_amarillo();
        prender_rojo();
        apagar_verde();
    }
    void leds::solo_amarillo(){
        prender_amarillo();
        apagar_rojo();
        apagar_verde();
    }
    
    //int wifi_status_pin;  
    void leds::prender_verde(){
        digitalWrite(GreenLed, HIGH);
    }
    void leds::prender_rojo(){
        digitalWrite(RedLed, HIGH);
    }
    void leds::prender_amarillo(){
        digitalWrite(YellowLed, HIGH);
    }

    void leds::apagar_verde(){
        digitalWrite(GreenLed, LOW);
    }
    void leds::apagar_rojo(){
        digitalWrite(RedLed, LOW);
    }
    void leds::apagar_amarillo(){
        digitalWrite(YellowLed, LOW);
    }


