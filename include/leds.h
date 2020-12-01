#ifndef leds_h
#define leds_h

//#include "Arduino.h"
//#include <string.h>
#include "Arduino.h"

class leds
{
  public: 
    leds();

    //String getHHTPRequest(const char* serverName);
    void solo_verde();
    void solo_rojo();
    void solo_amarillo();
    
  private:
    //int wifi_status_pin;  
    void prender_verde();
    void prender_rojo();
    void prender_amarillo();

    void apagar_verde();
    void apagar_rojo();
    void apagar_amarillo();
};

#endif /* wifi_adapter_h */