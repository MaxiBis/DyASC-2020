#ifndef Encender_Led_h
#define Encender_Led_h 

#include "Arduino.h"
#include <string.h>
#include <esp32-hal-bt.h>
//#include "Encender_Led.h"

class Encender_Led
{     
    public:
            Encender_Led();
            void turnON(int led);
            void parpadea_led(int led);
            int get_led_anterior();
      
    private:

            const int GreenLed = 04;
            const int YellowLed = 22;
            const int RedLed = 21;
                  int led_anterior;
            
   
};
 
#endif  /* Encender_Led_h */
