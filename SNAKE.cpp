/*#include "SNAKE.h"
#include "Arduino.h"
#include "communication.h"
#include "controls.h"
#include "screen.h"
#define scale 10
SNAKE::SNAKE() {}

void SNAKE::begin() {

}
void SNAKE::run() {

}
void SNAKE::draw() {
  erase();
  do {
    if (!gameOver) {
      //snake
      for (int i = 0; i < snakeS; i++) {
        square(snake[0][i], snake[1][i]);
      }
      //apple
      square(appleX * scale, apppleY * scale, h);
    } else {
      //gameOver
    } while (send());
  }
  void SNAKE::move() {

  }
  void SNAKE::newPos() {
    appleX = random(0, 12);
    appleY = random(0, 6);
    snake[0][0] = random(0, 12);
    snake[1][0] = random(0, 6);
  }*/
