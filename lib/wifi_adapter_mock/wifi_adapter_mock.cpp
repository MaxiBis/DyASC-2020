#include "wifi_adapter_mock.h"
#include <string.h>



wifi_adapter_mock::wifi_adapter_mock(): wifi_adapter_interface(){

    /*
    ssid = "Maxi-Tele";         //default credentials
    password = "vwgol123";     //default credentials
    */
}


void conectarme(){

    return;
}

bool isConnected(){
    return true;
}

void setWifiCredentials(const char* new_SSID,const char* new_password){

}

std::string wifi_adapter_mock::getSSID(){
    return "hola";       //ssid;
}