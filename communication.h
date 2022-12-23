/*
  para comunicarse con el control del jugador 2
*/
#include "Arduino.h"
#ifndef COMUNICATION_H
#define COMUNICATION_H
class communication {
  public:
    communication();
    void begin();
    float talk();
  private:
    String ssid = "ESPap";
    String pass = "thereisnospoon";
};
#endif
