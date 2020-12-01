#include <string.h>
#include <wifi_adapter.h>
#include <CI_controller.h>
#include <web.h>
#include <Test_led.h>

const int requestInterval = 7000;  // 7s
CI_controller mycontroller;
String httpAnswer;
//web myweb;

// Url's para hacer las peticiones
const char* URL = "https://api.travis-ci.org/MaxiBis/dyasc_build.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/MaxiBis/test_build_status.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/MaxiBis/aydoo-2018.svg?branch=master";
wifi_adapter miwifi(2);

void setup(){
    Serial.begin(115200);

    miwifi.conectarme();    // nos conectamos a la red
          Test_Led probandoLed = Test_Led();
      probandoLed.test_Led_state_high(21);
      probandoLed.test_Led_state_high(22);
      probandoLed.test_Led_state_high(23);
} // EOF setup


void loop(){
  if(miwifi.isConnected()){ 
    httpAnswer = mycontroller.getHHTPRequest(URL);
    mycontroller.showAnswer(httpAnswer);

    delay(requestInterval);   //delay entre requests
    //myweb.atenderCliente();
  }
} // EOF Loop



