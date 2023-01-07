#include "Arduino.h"
#include "PONG2P.h"
#include "communication.h"
#include "controls.h"

communication Player2;
#include <Adafruit_ST7735.h>  
#define P1X (screen::width-PW*2)
#define P2X 0

PONG2P::PONG2P() {

}

void PONG2P::begin() {
  screen::erase();
  Player2.begin();
}

void PONG2P::run() {

  if (!P2ready) {
        P2ready = Player2.connect();
  }
  else {
    if (!gameover) {
      move();
      cpu();
      P1();
      scoreCheck();
    }
    else {
      //if game is over wait for A to be pressed
      if (controls::getbutton("A"))gameover = false, screen::erase(), P1Score = 0, P2Score = 0;
      else if (controls::getbutton("B"))ESP.restart();
    }
    draw();

  }

}
void PONG2P::draw() {
  //erase();
  do {
    if (!gameover) {
      //draws ball
      if (LballX != ballX || LballY != ballY) {
        screen::circle(LballX, LballY, Lrad, BLACK);
        screen::circle(ballX, ballY, rad, GREEN);

      }
      //draws player 2
      if (LP2Y != P2Y) {
        screen::rect(0, LP2Y, PW, PH, BLACK);
        screen::rect(0, P2Y, PW, PH, BLUE);

      }
      //draws player 1
      screen::rect(screen::width - PW * 2, LP1Y, PW, PH, BLACK);
      screen::rect(screen::width - PW * 2, P1Y, PW, PH, RED);

      //draws score
      if (score != Lscore) {
        screen::smallfont();
        screen::centerText(0, Lscore, BLACK);
        screen::smallfont();
        screen::centerText(0, score, GREEN);
      }
      //erase();
      //draws line separing score and game
      screen::line(0, upperBorder, screen::width, GREEN);

      LballX = ballX, LballY = ballY, Lrad = rad, LP2Y = P2Y, LP1Y = P1Y, Lscore = score;
    }
    else {
      //draws gameover screen
      screen::bigfont();
      screen::centerText(32, winner + " wins", BLUE);
      screen::smallfont();
      screen::centerText(64, "press A to continue", CYAN);
      screen::centerText(74, "press B to exit", CYAN);

    }
  } while (screen::send());
}
bool PONG2P::inRange(float min, float max, float x) {
  return x > min && x < max;
}
bool PONG2P::bounceP(uint8_t P) {
  if (P == 2) {
    if (inRange(P2Y - rad, P2Y + rad + PH, ballY))
      if (inRange(P2X, P2X + PW, ballX))
        return 1;
    return 0;
  }
  else {
    if (inRange(P1Y - rad, P1Y + rad + PH, ballY))
      if (inRange(P1X, P1X + PW, ballX))
        return 1;
    return 0;

  }
}
void PONG2P::move() {
  //bounces ball with player

  //if ((((ballY + rad > P2Y && ballY + rad < P2Y + PH) || (ballY - rad > P2Y && ballY - rad < P2Y + PH)) && ballX <= PW) || (((ballY + rad > P1Y && ballY + rad < P1Y + PH) || (ballY - rad > P1Y && ballY - rad < P1Y + PH)) && ballX >= width - PW)) {
  if (bounceP(1)) {
    ballSpdX = -ballSpdX; //inverses direction
    ballSpdX = ballSpdX > 0 ? ballSpdX + .01 : ballSpdX - .01;//speeds up ball
    ballSpdY = ballSpdY > 0 ? ballSpdY + .01 : ballSpdY - .01;//speeds up ball
    pSpd = pSpd > 0 ? pSpd + 0.005 : pSpd + 0.005;//speeds up player
    ballY = ballY + PW;
  }
  else if (bounceP(2)) {
    ballSpdX = -ballSpdX; //inverses direction
    ballSpdX = ballSpdX > 0 ? ballSpdX + .01 : ballSpdX - .01;//speeds up ball
    ballSpdY = ballSpdY > 0 ? ballSpdY + .01 : ballSpdY - .01;//speeds up ball
    pSpd = pSpd > 0 ? pSpd + 0.005 : pSpd + 0.005;//speeds up player
    ballY = ballY - PW;
  }


  if (ballX + rad > PW)
    //bounces ball with borders
    if (ballY + rad > screen::height || ballY - rad < upperBorder)  ballSpdY = -ballSpdY;
  //moves ball
  ballY += ballSpdY;
  ballX += ballSpdX;
}
void PONG2P::cpu() {
  //moves CPU
  int packetSize = Player2.packetSize();
  if (packetSize == 4) {
    P2Y += 1;
  }
  else if (packetSize > 0) {
    P2Y -= 1;
  }


  //ballSpdY > 0 ? P2Y += pSpd : P2Y -= pSpd;
  if (P2Y + PH > screen::height)P2Y = screen::height - PH;
  if (P2Y < upperBorder)P2Y = upperBorder;
}
void PONG2P::P1() {
  //moves player 1
  if (controls::getbutton("UP")) P1Y -= pSpd;
  if (controls::getbutton("DOWN"))P1Y += pSpd;
  if (P1Y + PH > screen::height)P1Y = screen::height - PH;
  if (P1Y < upperBorder)P1Y = upperBorder;
}
void PONG2P::scoreCheck() {
  //check if someone scored
  if (ballX < 0 || ballX > screen::width) {
    if (ballX < 0) {
      //P2 scored
      ballSpdX = -0.2;
      ballSpdY = -0.2;
      min = screen::width / 2;
      max = screen::width;
      P2Score++;
      ballX = screen::width - (PW + 1);
      ballY = P2Y + PH / 2;
    }
    if (ballX > screen::width) {
      //P1 scored
      ballSpdX = 0.2;
      ballSpdY = 0.2;
      min = PH;
      max = screen::width / 2;
      ballX = PH + 1;
      ballY = P1Y + PH / 2;
      P1Score++;
    }

    //puts ball in a new position
    // ballSpdX = ballSpdX < 0 ? ballSpdX + .1 : ballSpdX - .1;
    // ballSpdY = ballSpdY < 0 ? ballSpdY + .1 : ballSpdY - .1;

    pSpd = 0.25;
    //  ballX = random(min, max);
    //   ballY = random(upperBorder + rad + 1, height - rad);
  }
  if (P2Score > maxScore || P1Score > maxScore) {
    //decides who won
    gameover = true;
    winner = P2Score > P1Score ? "P1" : "P2";
    screen::erase();
  }
  //updates score
  score = "P2: " + String(P1Score) + "  |" + "   P1: " + String(P2Score);
}
