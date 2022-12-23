/*
  el juego PONG
*/
#include "controls.h"
#include "screen.h"
#include "Arduino.h"
#ifndef S_C_h
#define S_C_h
class Test: public controls, public screen {
  public:
    Test();
    void begin();
    void run();
};
#endif
