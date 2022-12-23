#include "BREAKOUT.h"
#include "PONG.h"
#include "menu.h"
#include "S_C.h"
#include "hotspot.h"
#include "PONG2P.h"

#define ngames 5

Test test;
BREAKOUT breakout;
PONG pong;
MENU start;
hotspot Hotspot;
PONG2P pong2p;

int game = -1;
bool firstRun = true;
String games[ngames] = { "Pong", "Breakout", "Test", "Hotspot", "PONG2P" };
void setup() {
  // put your setup code here, to run once:
  start.beginScreen();
  start.begin();
  Serial.begin(115200);
    
}

void loop() {
  if (game == -1) {
    game = start.show("Select a game", games, ngames);
  }
  else {
    switch (game) {
    case 0:
      if (firstRun) {
        pong.begin();
      }
      pong.run();
      break;
    case 1:
      if (firstRun) {
        breakout.begin();
      }
      breakout.run();
      break;
    case 2:
      if (firstRun) {
        test.begin();
      }
      test.run();
      break;
    case 3:
      if (firstRun) {
        Hotspot.begin();
      }
      Hotspot.run();
      break;
    case 4:
      if (firstRun) {
        pong2p.begin();
      }
      pong2p.run();
      break;
    }
    firstRun = false;
  }
}
