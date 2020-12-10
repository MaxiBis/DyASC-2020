#include <Arduino.h>
#include "Arduino_JSON.h"
#include <Parser_Json.h>
#include <string.h>

String payload;

Parser_Json::Parser_Json()
{

};

String Parser_Json::parse(String st){
    JSONVar build = JSON.parse(st);
    String estadoBuild = JSON.stringify(build[0]["state"]);
    int resultadoBuild = build[0]["result"];
    return "test";
}

String Parser_Json::getState(String jsonEntrada){
    JSONVar build = JSON.parse(jsonEntrada);
    String estadoBuild = JSON.stringify(build[0]["state"]);

    return estadoBuild;
}
int Parser_Json::getResult(String jsonEntrada){
    JSONVar build = JSON.parse(jsonEntrada);
    //String estadoBuild = JSON.stringify(build[0]["state"]);
    int resultadoBuild = build[0]["result"];

    return resultadoBuild;
}