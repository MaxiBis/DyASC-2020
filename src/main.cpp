#ifndef UNIT_TEST
#ifdef ARDUINO

#include <string.h>
#include <wifi_adapter.h>
#include <CI_controller.h>
#include "Test_Led.h"
#include <Encender_Led.h>


const int requestInterval = 7000;  // 7s

String httpAnswer;
//web myweb;

// Url's para hacer las peticiones
const char* URL = "https://api.travis-ci.org/repos/chinov1/https-github.com-VergesLuis-dyasc-2020-releases-tag-vq.0.2f2/builds";
//const char* URL = "https://api.travis-ci.org/chinov1/https-github.com-VergesLuis-dyasc-2020-releases-tag-v1.0.2f2.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/VergesLuis/https-github.com-VergesLuis-dyasc-2020-releases-tag-v1.0.2f2.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/VergesLuis/dyasc-2020.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/MaxiBis/dyasc_build.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/MaxiBis/test_build_status.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/MaxiBis/aydoo-2018.svg?branch=master";
wifi_adapter miwifi;

void setup(){
    Serial.begin(115200);
    miwifi.conectarme();    // nos conectamos a la red

     Test_Led probandoLed = Test_Led();
      probandoLed.test_Led_state_high(21);
      probandoLed.test_Led_state_high(22);
      probandoLed.test_Led_state_high(04);

} // EOF setup


void loop(){
  Test_Led probandoLed = Test_Led();
  probandoLed.test_Led_state_high(21);
      probandoLed.test_Led_state_high(22);
      probandoLed.test_Led_state_high(04);


  while(1){
  if(miwifi.isConnected()){ 
    CI_controller mycontroller;
    httpAnswer = mycontroller.getHHTPRequest(URL);
    mycontroller.showAnswer(httpAnswer);

    delay(requestInterval);   //delay entre requests
    //myweb.atenderCliente();
  }
  }
} // EOF Loop

#else
int main(int argc, char **argv) {
}
#endif
#endif

