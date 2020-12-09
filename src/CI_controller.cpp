#include "CI_controller.h"
#include <HTTPClient.h>
#include "Arduino.h"
#include <string.h>
#include "Encender_Led.h"
#include <Parser_Json.h>
#include "Arduino_JSON.h"

Encender_Led el;

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
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();     // liberamos

  return payload;
};

void CI_controller::showAnswer(String answ){
    Parser_Json parserj;    
    String currentState = parserj.getState(answ);

    if (currentState.equals("\"started\"") || currentState.equals("\"created\"")){
      Serial.println("BUILD STARTING\n");
      el.turnON(YellowLed);
    }else if (currentState.equals("\"finished\"")){
      switch (parserj.getResult(answ))  {
          case 0:
            Serial.println("BUILD PASSING\n");
            el.turnON(GreenLed);
            break;
          case 1:
            Serial.println("BUILD FAILING\n");
            el.turnON(RedLed);    
            break;
          default:    
            break;
      }
    } else{
          //Mostrar algun error de que funciono mal? 
    }
};

/*
    String answer = answ;
    Serial.println("ESTADO JSON\n\n\n");    
    Serial.println(currentState);
    Serial.println("\n");
    Serial.println(currentResult);

    if (answer.indexOf("failing") > 0) {
      Serial.println("FAILING\n");
      el.turnON(RedLed);    
    }else if (answer.indexOf("canceled") > 0) {
      Serial.println("CANCELED\n");
      el.turnON(YellowLed);
    } else if (answer.indexOf("passing") > 0) {
      Serial.println("PASSING\n");
      el.turnON(GreenLed);
    } 
*/    