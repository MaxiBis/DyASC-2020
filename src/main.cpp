#include <string.h>
#include <wifi_adapter.h>
#include <CI_controller.h>
#include <web.h>

const int requestInterval = 7000;  // 7s

String httpAnswer;
//web myweb;

// Url's para hacer las peticiones
const char* URL = "https://api.travis-ci.org/MaxiBis/test_build_status.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/MaxiBis/aydoo-2018.svg?branch=master";
wifi_adapter miwifi(2);

void setup(){
    Serial.begin(115200);

    miwifi.conectarme();    // nos conectamos a la red
} // EOF setup


void loop(){
  if(miwifi.isConnected()){ 
    CI_controller mycontroller;
    httpAnswer = mycontroller.getHHTPRequest(URL);
    mycontroller.showAnswer(httpAnswer);

    delay(requestInterval);   //delay entre requests
    //myweb.atenderCliente();
  }
} // EOF Loop



