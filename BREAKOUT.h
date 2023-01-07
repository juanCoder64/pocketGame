#ifndef BREAKOUT_H
#define BREAKOUT_h
#include "controls.h"
#include "HWdefinitions.h"

#include screenLib
#include "Arduino.h"
class BREAKOUT {
  public:
    BREAKOUT();
    void begin();
    void run();

  private:
    int sum = 0, h = 5, filas = 3;
    int x = 0, Bx = 64, By = 32, spX = -1, spY = -1, sepa = 8, pad=20;
    int Blx[50];
    int w[5];
    int div[5];
    bool gameOver = false;
    void calcBlock();
    void move();
    void checkBall();
    void draw();
    int LBx=0, LBy=0, Lx=0;
};
#endif
