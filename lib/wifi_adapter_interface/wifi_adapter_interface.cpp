#include "wifi_adapter_interface.h"


wifi_adapter_interface::wifi_adapter_interface(){
}


void wifi_adapter_interface::conectarme(){
    return;
}

bool wifi_adapter_interface::isConnected(){
    return true;
}

void wifi_adapter_interface::setWifiCredentials(const char* new_SSID,const char* new_password){

}

std::string wifi_adapter_interface::getSSID(){
    return "ssid";
}