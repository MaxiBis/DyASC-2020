#ifndef UNIT_TEST
#ifdef ARDUINO
#include <string.h>
#include <wifi_adapter.h>
#include <CI_controller_Travis.h>
#include "Test_Led.h"
#include <Encender_Led.h>


const int requestInterval = 7000;  // 7s
//web myweb;

// Url's para hacer las peticiones
//const char* URL = "https://api.travis-ci.org/repos/chinov1/https-github.com-VergesLuis-dyasc-2020-releases-tag-vq.0.2f2/builds";
//const char* URL = "https://api.travis-ci.org/chinov1/https-github.com-VergesLuis-dyasc-2020-releases-tag-v1.0.2f2.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/VergesLuis/https-github.com-VergesLuis-dyasc-2020-releases-tag-v1.0.2f2.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/VergesLuis/dyasc-2020.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/repos/MaxiBis/aydoo-2018/builds";
const char* URL = "https://api.travis-ci.org/repos/MaxiBis/dyasc_build/builds";
//const char* URL = "https://api.travis-ci.org/repos/MaxiBis/test_build_status/builds";

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
  CI_controller_Travis mycontroller;

  while(1){
    if(miwifi.isConnected()){ 

      //httpAnswer = mycontroller.getHHTPRequest(URL);
      //mycontroller.showAnswer(httpAnswer);
      mycontroller.process(URL);

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

