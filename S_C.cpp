#include "Arduino.h"
#include "S_C.h"
#include "controls.h"


Test::Test() {
  
}


void Test::begin() {
  screen::erase();
  Serial.begin(115200);
  Serial.println("Started");
}
void Test::run() {
  Serial.println("running");

  if (controls::getbutton("UP"))
    screen::rect(0, 0, screen::width, screen::height / 3, WHITE);
  else
    screen::rect(0, 0, screen::width, screen::height / 3, BLACK);


  if (controls::getbutton("DOWN"))
    screen::rect(0, (screen::height / 3) * 2, screen::width, screen::height, WHITE);
  else
    screen::rect(0, (screen::height / 3) * 2, screen::width, screen::height, BLACK);

  if (controls::getbutton("B"))
    screen::rect(0, screen::height / 3, screen::width / 2, (screen::height / 3), WHITE);
  else
    screen::rect(0, screen::height / 3, screen::width / 2, (screen::height / 3), BLACK);


  if (controls::getbutton("A"))
    screen::rect(screen::width / 2, screen::height / 3, screen::width / 2, screen::height / 3, WHITE);
  else
    screen::rect(screen::width / 2, screen::height / 3, screen::width / 2, screen::height / 3, BLACK);
}
