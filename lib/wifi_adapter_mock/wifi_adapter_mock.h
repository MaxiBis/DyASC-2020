#ifndef wifi_adapter_mock_h
#define wifi_adapter_mock_h

#include "wifi_adapter_interface.h"
#include <string> 

class wifi_adapter_mock : public wifi_adapter_interface
{
  public: 
    wifi_adapter_mock();
    void conectarme();
    bool isConnected();
    void setWifiCredentials(const char* new_SSID,const char* new_password);
    std::string getSSID();
    
  private:
    int wifi_status_pin;  
   
};

#endif  /* wifi_adapter_mock_h */