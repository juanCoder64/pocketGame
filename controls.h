/*
  esto hace mas simple adaptar el juego a otro tipo de hardware
*/
#ifndef CONTROLS_H
#define CONTROLS_H
#include "Arduino.h"
class controls {
  public:
    controls();
    void beginControls();
    bool anyPressed();
    bool getbutton(String a);
};
#endif
