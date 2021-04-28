/*
  el juego PONG
*/
#include "controls.h"
#include "screen.h"
#include "Arduino.h"
#ifndef PONG_h
#define PONG_h
class PONG: public controls, public screen {
  public:
    PONG();
    void begin();
    void run();
  private:
    void draw();
    void move();
    void cpu();
    void P1();
    void scoreCheck();
    float pSpd=1.8;
    float ballX=random(rad,width-rad), ballY=random(upperBorder+rad,height-rad);
    float ballSpdX=1,ballSpdY=1;
    int upperBorder=9,maxScore=6,rad=3;
    float P2Y=32,P1Y=32;
    int P1Score,P2Score,PH=10,PW=2;
    int min,max;
    bool gameover=false;
    String winner;
    String score;
};
#endif
