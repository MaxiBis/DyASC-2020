#include "wifi_adapter.h"
#include <WiFi.h>
#include "Arduino.h"
const char* ssid = "Maxi-Tele";
const char* password =  "vwgol123";

wifi_adapter::wifi_adapter(int pin){
    pinMode(pin, OUTPUT);
    wifi_status_pin = pin;
    ssid = "Maxi-Tele";         //default credentials
    password =  "vwgol123";     //default credentials
}


void wifi_adapter::conectarme(){
    WiFi.begin(ssid, password);
    Serial.println("connecting");
    bool estado_led = true;
    while(WiFi.status() != WL_CONNECTED) { 
        delay(500);
        Serial.print(".");
        if (estado_led){
            digitalWrite(wifi_status_pin, LOW);
            estado_led = false;
        } else{
            digitalWrite(wifi_status_pin, HIGH);
            estado_led = true;
        }              
    }
    digitalWrite(wifi_status_pin, HIGH);
    Serial.print("\nConectado a la red con la IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    return;
}

bool wifi_adapter::isConnected(){
    return WL_CONNECTED;
}

void setWifiCredentials(const char* SSID,const char* password){
    ssid = SSID;         
    password = password; 
}