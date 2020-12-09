#ifndef Parser_Json_H
#define Parser_Json_H

#include <Arduino.h>
#include <string.h>

class Parser_Json{

 private:
        String payload;
        String parse(String st);        
 public:
       Parser_Json();
       String getState(String jsonEntrada);
       int getResult(String jsonEntrada);
};
#endif /* Parser_Json */