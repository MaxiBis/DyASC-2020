#include "wifi_adapter_mock.h"
#include <string.h>
const char* ssid;
const char* password;


wifi_adapter_mock::wifi_adapter_mock(): wifi_adapter_interface(){

    
    ssid = "Maxi-Tele";         //default credentials
    password = "vwgol123";     //default credentials
    
}

void conectarme(){

    return;
}

bool isConnected(){
    return true;
}

void wifi_adapter_mock::setWifiCredentials(const char* new_SSID,const char* new_password){
    ssid = new_SSID;         
    password = new_password; 
}

std::string wifi_adapter_mock::getSSID(){
    return ssid;       //ssid;
}