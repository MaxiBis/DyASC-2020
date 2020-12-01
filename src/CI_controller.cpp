#include "CI_controller.h"
#include <HTTPClient.h>
#include "Arduino.h"
#include <string.h>
#include <Test_led.h>
#include "leds.h"

// ledPin refers to ESP32 GPIOs
const int GreenLed = 23;
const int YellowLed = 22;
const int RedLed = 21;
//bool test = true;
leds misLeds;

CI_controller::CI_controller(){
    // initialize digital pin ledPin as an output and set them as low
    pinMode(GreenLed, OUTPUT);
    pinMode(YellowLed, OUTPUT);
    pinMode(RedLed, OUTPUT);
    digitalWrite(GreenLed, LOW);
    digitalWrite(YellowLed, LOW);
    digitalWrite(RedLed, LOW);
    
    //if(test){

      //test = false;
    //}
}

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
  // liberamos
  http.end();

  return payload;
};

void CI_controller::showAnswer(String answ){
    String answer = answ;
    if (answer.indexOf("failing") > 0) {
        Serial.println("FAILING\n");
        /*digitalWrite(GreenLed, LOW);
        digitalWrite(YellowLed, LOW);
        digitalWrite(RedLed, HIGH);*/
        misLeds.solo_rojo();
      } 
    if ((answer.indexOf("canceled") > 0) || (answer.indexOf("error") > 0)) {
        Serial.println("CANCELED\n");
        /*digitalWrite(GreenLed, LOW);
        digitalWrite(YellowLed, HIGH);
        digitalWrite(RedLed, LOW);*/
        misLeds.solo_amarillo();
    } 
    if (answer.indexOf("passing") > 0) {
        Serial.println("PASSING\n");
        /*digitalWrite(GreenLed, HIGH);
        digitalWrite(YellowLed, LOW);
        digitalWrite(RedLed, LOW);*/
        misLeds.solo_verde();
    } 
    return;
};