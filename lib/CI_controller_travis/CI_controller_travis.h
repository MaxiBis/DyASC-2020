#ifndef CI_controller_Travis_h
#define CI_controller_Travis_h
#include "CI_controller.h"
#include <HTTPClient.h>
#include <Arduino.h>
#include "Arduino_JSON.h"

class CI_controller_Travis : public CI_controller
{
  public: 
    CI_controller_Travis();

    String getHHTPRequest(const char* serverName);
    void showAnswer(String answ);
    void process(const char* serverName);
    String analizeAnswer(String answ);

  private:
    //int wifi_status_pin;  
    const int GreenLed = 04;
    const int YellowLed = 22;
    const int RedLed = 21;
          int led_anterior;
    

};

#endif /* CI_controller_h */
