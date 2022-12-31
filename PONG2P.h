/*
  el juego PONG
*/
#include "controls.h"
#include "screen.h"
#include "Arduino.h"
#ifndef PONG2P_h
#define PONG2P_h
class PONG2P: public controls, public screen {
public:
  PONG2P();
  void begin();
  void run();
private:
  bool inRange(float, float, float);
  void draw();
  bool bounceP(uint8_t);
  void move();
  void cpu();
  void P1();
  void scoreCheck();
  bool P2ready = false;
  float pSpd = 0.2;
  //Starting position for ball
  float ballX = random(rad + upperBorder + 1, width - rad - 1), ballY = random(upperBorder + rad + 1, height - rad - 1);
  float ballSpdX = 0.2, ballSpdY = 0.2; //ball speeds
  int upperBorder = 10, maxScore = 6, rad = 3; //boundaries of the field
  float P2Y = 32, P1Y = 32; //players Y position
  int P1Score, P2Score, PH = 10, PW = 2;
  int min = width / 2, max= width; //area where 
  bool gameover = false;
  String winner;
  String score;
  String ip;
  int LballX = 0, LballY = 0, Lrad = 0, LP2Y = 0, LP1Y = 0;
  String Lscore = "";
  bool Wready = false;
  int8_t chosen = -1;
};
#endif
