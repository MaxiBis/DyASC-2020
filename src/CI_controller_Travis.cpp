#include "CI_controller.h"
#include <HTTPClient.h>
#include <string.h>
#include <Encender_Led.h>
#include <Parser_Json.h>
#include "Arduino_JSON.h"
#include "CI_controller_Travis.h"

Encender_Led el;

CI_controller_Travis::CI_controller_Travis() : CI_controller(){
   // estado_anterior();
};

String CI_controller_Travis::getHHTPRequest(const char* serverName) {
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

void CI_controller_Travis::showAnswer(String answ){
  int resultado;
  if (answ == "PASSING"){resultado = 0;}
  if (answ == "FAILING"){resultado = 1;}
  if (answ == "RUNNING"){resultado = 2;}
    /*Serial.println("answ \n");    
    Serial.println(answ);
    Serial.println("resultado \n");    
    Serial.println(resultado);*/

  switch (resultado)  {
    case 0:
      Serial.println("BUILD PASSING\n");
      el.turnON(GreenLed);
      break;
    case 1:
      Serial.println("BUILD FAILING\n");
      el.turnON(RedLed);    
      break;
    case 2:
      Serial.println("BUILD STARTING\n");
      el.turnON(YellowLed);    
      break;      
    default:    
    break;
  }
/*
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
    }*/
};


String CI_controller_Travis::analizeAnswer(String answ){
    Parser_Json parserj;    
    String currentState = parserj.getState(answ);

    if (currentState.equals("\"started\"") || currentState.equals("\"created\"")){
      return "RUNNING";
    }else if (currentState.equals("\"finished\"")){
      switch (parserj.getResult(answ))  {
          case 0:
            return "PASSING";
            break;
          case 1:
            return "FAILING"; 
            break;
          default:    
            break;
      }
    } else{
          //Mostrar algun error de que funciono mal? o estado distinto? 
    }
};

void CI_controller_Travis::process(const char* serverName){
  String httpAnswer = this->getHHTPRequest(serverName);
  String buildStatus= this->analizeAnswer(httpAnswer);
  this->showAnswer(buildStatus);
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