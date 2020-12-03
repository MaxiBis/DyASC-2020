#ifndef wifi_adapter_h
#define wifi_adapter_h

#include "wifi_adapter_interface.h"
#include <string> 

class wifi_adapter : public wifi_adapter_interface
{
  public: 
    wifi_adapter();
    void conectarme();
    bool isConnected();
    void setWifiCredentials(const char* new_SSID,const char* new_password);
    std::string getSSID();
    
  private:
    int wifi_status_pin;  
   
};

#endif /* wifi_adapter_h */
