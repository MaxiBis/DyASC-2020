#ifndef CI_controller_h
#define CI_controller_h
//#include <string>
#include <string.h>
//#include <esp32-hal-bt.h>
//#include <string> 
//#include "Arduino.h"

class CI_controller
{
  public: 
    CI_controller();

    void process(const char* serverName);
    /*
    String analizeAnswer(String answ);
    virtual String getHHTPRequest(const char* serverName) {String payload = "...";return payload;};
    virtual void showAnswer(String answ){};    
    */
    virtual int estado_anterior(){return 1;};
    


};

#endif /* CI_controller_h */