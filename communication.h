/*
  para comunicarse con el control del jugador 2
*/
#include "Arduino.h"
#include "HWdefinitions.h"

#include screenLib
#ifndef COMUNICATION_H
#define COMUNICATION_H
class communication  {
public:
  communication();
  void begin();
  float talk();
  int8_t mode = -1;
  bool connect();
  int packetSize();

  String ip;
private:
  String ssid = "ESPap";
  String pass = "thereisnospoon";
  bool wifiReady;
};
#endif
