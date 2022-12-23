/*#ifndef SNAKE_H
#define SNAKE_H
#include "controls.h"
#include "screen.h"
#include "Arduino.h"
class SNAKE: public controls, public screen {
  public:
    SNAKE();
    void begin();
    void run();

  private:
    bool gameOver;
    uint8_t snake[2][360], appleX, appleY, snakeS = 1, dir = 3;
    void draw();
    void move();
    void newPos();
};
#endif*/
