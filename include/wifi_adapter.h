#ifndef wifi_adapter_h
#define wifi_adapter_h

#include "Arduino.h"

class wifi_adapter
{
  public: 
    wifi_adapter(int pin);
    void conectarme();
    bool isConnected();
    void setWifiCredentials(const char* SSID,const char* password);
    
  private:
    int wifi_status_pin;  
   
};

#endif /* wifi_adapter_h */
