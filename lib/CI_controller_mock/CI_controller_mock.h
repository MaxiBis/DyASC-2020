#ifndef CI_controller_mock_h
#define CI_controller_mock_h
#include "../lib/CI_controller/CI_controller.h"
#include <string.h>
#include <string>

class CI_controller_mock : public CI_controller
{
  public: 
    CI_controller_mock();

   // String getHHTPRequest(const char* serverName);
    //void showAnswer(String answ);
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
