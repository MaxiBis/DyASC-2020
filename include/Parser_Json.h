#ifndef Parser_Json_H
#define Parser_Json_H

#include <Arduino.h>
#include <string.h>

class Parser_Json{

 private:
        String payload;
 public:
        Parser_Json();
        String parse(String st);

};
#endif /* Parser_Json */