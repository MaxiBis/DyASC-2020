#ifndef CI_controller_h
#define CI_controller_h

#include "Arduino.h"
#include <string.h>
#include <esp32-hal-bt.h>
#include "Encender_Led.h"


class CI_controller
{
  public: 
    CI_controller();

    String getHHTPRequest(const char* serverName);
    void showAnswer(String answ);
    void procesar_salida(int led);
    int estado_anterior();

  private:
    //int wifi_status_pin;  
    const int GreenLed = 04;
    const int YellowLed = 22;
    const int RedLed = 21;
          int led_anterior;
};

#endif /* CI_controller_h */
