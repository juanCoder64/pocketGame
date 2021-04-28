#include "BREAKOUT.h"
#include "PONG.h"
#include "menu.h"

BREAKOUT breakout;
PONG pong;
UI ui;
int game;
bool firstRun = true;
// screen display;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ui.begin();
  game = ui.show();
  pong.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(game){
  case 1:
  if(firstRun){
    pong.begin();
  }
    pong.run();
  break;
  case 2:
  if(firstRun){
    breakout.begin();
  }
  breakout.run();
  break;
}
firstRun=false;
}