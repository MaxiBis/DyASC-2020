#include "CI_controller.h"
#include <HTTPClient.h>
#include "Arduino.h"
#include <string.h>
#include "Encender_Led.h"
#include <Parser_Json.h>

int led_anterior;

CI_controller::CI_controller(){
   // estado_anterior();
   
};

String CI_controller::getHHTPRequest(const char* serverName) {
  HTTPClient http;    
  http.begin(serverName);
  
  // Enviamos peticion HTTP
  int httpResponseCode = http.GET();
  
  String payload = "..."; 
  


  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Parser_Json pj;
  
    String respuesta = pj.parse(payload);
    Serial.println(respuesta);
    //showAnswer(respuesta);
    //Serial.println(payload);
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // liberamos
  http.end();

  return payload;
};



void CI_controller::showAnswer(String answ){
    String answer = answ;
    
    if (answer.indexOf("failing") > 0) {
        Serial.println("FAILING\n");
      procesar_salida(RedLed);
       
        
      } else
    if (answer.indexOf("canceled") > 0) {
        Serial.println("CANCELED\n");
      
        procesar_salida(YellowLed);

    } else
    if (answer.indexOf("passing") > 0) {
        Serial.println("PASSING\n");
        procesar_salida(GreenLed);
    } 
    return;
};



int CI_controller::estado_anterior(){
  if(digitalRead(22)==HIGH){

    led_anterior = 22;
    return 22;
  }else if(digitalRead(04)==HIGH){
    
    led_anterior = 04;
    return 04;
  }else if(digitalRead(21)){
    led_anterior = 21;
    return 21;
  }
  
   return led_anterior;
};



void CI_controller::procesar_salida(int led){
   
 
  Encender_Led el;
  if(led != estado_anterior()){
    el.parpadea_led(led);
  }
 el.led_correcto(led);
 
};