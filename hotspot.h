#ifndef HOTSPOT_H
#define HOTSPOT_H
#include "Arduino.h"
#include "HWdefinitions.h"
#include screenLib
#include "controls.h"
class hotspot {
public:
  hotspot();
  void begin();
  void run();
private:
  String getPass();
  String password = String(random(100000000, 1000000000));
};
#endif