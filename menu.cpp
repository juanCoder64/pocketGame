#include "Arduino.h"
#include "menu.h"



MENU::MENU() {

}
void MENU::begin() {
  
  beginControls();
  erase();

}
int MENU::show(String title, String options[], int noptions) {
  
  centerText(0, title, RED);
  if (Lpointer != pointer) {
    for (int i = 0; i < noptions; i++) {
      String opt = options[i];
      if (Lpointer == i) {
        opt += "*";
      }
      centerText((height - noptions * 10) / 2 + i * 10, opt, BLACK);
    }
    
    for (int i = 0; i < noptions; i++) {
      String opt = options[i];
      if (pointer == i) {
        opt += "*";
      }
      centerText((height - noptions * 10) / 2 + i * 10, opt, YELLOW);
    }
    Lpointer = pointer;
  }
  if (getbutton("DOWN") &&millis()-lastmil>200) {
    lastmil=millis();
    if (pointer + 1 < noptions)    pointer++;
    else   pointer = 0;
  }
  if (getbutton("UP") &&millis()-lastmil>200) {
    lastmil=millis();
    if (pointer - 1 >= 0) pointer--;
    else pointer = noptions - 1;
  }
if(getbutton("A")){
  return pointer;
}
  return -1;
}
