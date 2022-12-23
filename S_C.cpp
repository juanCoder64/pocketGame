#include "Arduino.h"
#include "S_C.h"
#include "controls.h"




Test::Test() {

}

void Test::begin() {
  erase();
  Serial.begin(115200);
  Serial.println("Started");
}
void Test::run() {
  Serial.println("running");

  if (getbutton("UP"))
    rect(0, 0, width, height / 3, WHITE);
  else
    rect(0, 0, width, height / 3, BLACK);


  if (getbutton("DOWN"))
    rect(0, (height / 3) * 2, width, height, WHITE);
  else
    rect(0, (height / 3) * 2, width, height, BLACK);

  if (getbutton("B"))
    rect(0, height / 3, width / 2, (height / 3), WHITE);
  else
    rect(0, height / 3, width / 2, (height / 3), BLACK);


  if (getbutton("A"))
    rect(width / 2, height / 3, width / 2, height / 3, WHITE);
  else
    rect(width / 2, height / 3, width / 2, height / 3, BLACK);
}
