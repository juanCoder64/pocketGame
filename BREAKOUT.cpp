#include "BREAKOUT.h"
#include "Arduino.h"
#include "communication.h"
#include "controls.h"
#include "HWdefinitions.h"

#include screenLib

BREAKOUT::BREAKOUT() {}

void BREAKOUT::begin() {
  // initializes used libraries and calculates first set of blocks
  calcBlock();
  screen::erase();
}
void BREAKOUT::calcBlock() {
  // calculates block positions
  sum = 0;
  for (int o = 0; o < filas; o++) {
    div[o] = random(2, 10);
    w[o] = screen::width / div[o];
    for (int i = 0; i < div[o]; i++) {
      Blx[sum] = w[o] * i;
      sum++;
    }
  }
}
void BREAKOUT::run() {
  if (!gameOver) {
    move();
    checkBall();
  }
  else {
    //if game is over wait for A to be pressed
    if (controls::getbutton("A")) {
      Bx = 64;
      By = 32;
      calcBlock();
      gameOver = false;
      screen::erase();
    }
    else if (controls::getbutton("B"))ESP.restart();

  }
  draw();
}
void BREAKOUT::draw() {
  //erase();
  do {
    if (!gameOver) {
      // draws blocks
      sum = 0;
      for (int o = 0; o < filas; o++) {
        for (int i = 0; i < div[o]; i++) {
          screen::frame(Blx[sum], o * sepa, w[o], h, YELLOW);
          sum++;
        }
      }
      // draws player


      screen::rect(Lx,screen::height - 2, pad, 2, BLACK);
      screen::rect(x, screen::height - 2, pad, 2, RED);


      // draws ball
      if (Bx != LBx || By != LBy) {
        screen::circle(LBx, LBy, 3, BLACK);
        screen::circle(Bx, By, 3, BLUE);
      }

      LBx = Bx, LBy = By, Lx = x;
    }
    else {
      // draws game over screen
      screen::fontsize(2);
      screen::centerText(32, "Game over", BLUE);
      screen::smallfont();
      screen::centerText(64, "press A to continue", CYAN);
      screen::centerText(74, "press B to exit", CYAN);
    }
  } while (screen::send());
}
void BREAKOUT::move() {
  // moves ball according to speed
  By += spY;
  Bx += spX;
  // bounces ball with borders
  if (Bx > screen::width || Bx < 0) {
    spX = -spX;
  }
  if (By < 0) {
    spY = -spY;
  }
  // bounces ball with player
  if (Bx > x && Bx < x + pad && By >= screen::height - 2) {
    spY = -spY;
  }

  // moves player
  if (controls::getbutton("RIGHT") && x + pad < screen::width) {
    x += 2;
  } else if (controls::getbutton("LEFT") && x > 0) {
    x -= 2;
  }
}

void BREAKOUT::checkBall() {
  //checks if it has touched any block
  sum = 0;
  for (int o = 0; o < filas; o++) {
    for (int i = 0; i < div[o]; i++) {
      if (o * sepa < By && (o * sepa) + h > By) {
        if (Blx[sum] < Bx && Bx < Blx[sum] + w[o]) {
          spY = -spY;
          screen::frame(Blx[sum], o * sepa, w[o], h, BLACK);

          Blx[sum] = screen::width + 1;

        }
      }
      sum++;
    }
  }
  // Checks if ball is still in
  if (By > screen::height) {
    gameOver = true;
    screen::erase();
  }
}
