
#include "menu.h"
#include screenLib
#include "PONG.h"
#include "BREAKOUT.h"
#include "S_C.h"
#include "hotspot.h"
#include "PONG2P.h"

//array with the main menu options
String games[] = { "Pong", "Breakout", "Test", "Hotspot", "PONG2P" };

//creates the objects for each game
Test test;
BREAKOUT breakout;
PONG pong;
MENU start;
hotspot Hotspot;
PONG2P pong2p;

//variable that stores which game has been chosen in tha main menu (set to -1 because it has not been chosen yet)
int game = -1;
bool firstRun = true;


void setup() {
  //starts the start menu
  screen::beginScreen();
  start.begin();
  Serial.begin(115200);

}

void loop() {
  if (game == -1) {
    //show game menu if no game has been chosen
    game = start.show("Select a game", games, sizeof(games) / sizeof(games[0]));
  }
  else {
    switch (game) {
    case 0:
      //PONG
      if (firstRun) {
        pong.begin();
      }
      pong.run();
      break;
    case 1:
      //BREAKOUT
      if (firstRun) {
        breakout.begin();
      }
      breakout.run();
      break;
    case 2:
      //button test
      if (firstRun) {
        test.begin();
      }
      test.run();
      break;
    case 3:
      //hotspot
      if (firstRun) {
        Hotspot.begin();
      }
      Hotspot.run();
      break;
    case 4:
      //PONG2P
      if (firstRun) {
        pong2p.begin();
      }
      pong2p.run();
      break;
    }
    firstRun = false;
  }
}
