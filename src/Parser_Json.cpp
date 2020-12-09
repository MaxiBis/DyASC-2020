#include <Arduino.h>
#include "Arduino_JSON.h"
#include <Parser_Json.h>
#include <string.h>

String payload;

Parser_Json::Parser_Json()
{

};




String Parser_Json::parse(String st)
{
   
    JSONVar build = JSON.parse(st);
    String estadoBuild = JSON.stringify(build[0]["state"]);
    int resultadoBuild = build[0]["result"];

    if (estadoBuild.equals("\"started\"") == 1 || estadoBuild.equals("\"created\"") == 1)
    {
        return "En progreso";
    }
    else if (estadoBuild.equals("\"finished\"") == 1 && resultadoBuild == 0)
    {
        return "Exitoso";
    }
    else
    {
        return "Fallido";
    }
    return "a";
}
