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
  int8_t chosen = -1;

  bool inRange(float, float, float);
  void draw();
  bool bounceP(uint8_t);
  bool P2ready = false;
  void move();
  void cpu();
  void P1();
  void scoreCheck();
  float pSpd = 0.2;
  float ballX = random(rad + upperBorder + 1, width - rad - 1), ballY = random(upperBorder + rad + 1, height - rad - 1);
  float ballSpdX = 0.2, ballSpdY = 0.2;
  int upperBorder = 10, maxScore = 6, rad = 3;
  float P2Y = 32, P1Y = 32;
  int P1Score, P2Score, PH = 10, PW = 2;
  int min, max;
  bool gameover = false;
  String winner;
  String score;
  String ip;
  int LballX = 0, LballY = 0, Lrad = 0, LP2Y = 0, LP1Y = 0;
  String Lscore = "";
  bool Wready = false;
};
#endif
