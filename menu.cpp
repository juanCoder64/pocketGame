#include "Arduino.h"
#include "menu.h"



MENU::MENU() {

}
void MENU::begin() {
  //starts needed things to run the menu
  beginControls();
  erase();

}
int MENU::show(String title, String options[], int noptions) {
  //draws the menu on screen
  //draws title in the top-center
  centerText(0, title, RED);
  if (Lpointer != pointer) { //checks if the pointer has changed, to see if it is needed to draw again

    //erases last menu with las pointer position by drawing it in black
    for (int i = 0; i < noptions; i++) {
      String opt = options[i];
      if (Lpointer == i) {
        opt += "*";
      }
      centerText((height - noptions * 10) / 2 + i * 10, opt, BLACK);
    }

    //draws new menu with new pointer position 
    for (int i = 0; i < noptions; i++) {
      String opt = options[i];
      if (pointer == i) {
        opt += "*";
      }
      centerText((height - noptions * 10) / 2 + i * 10, opt, YELLOW);
    }
    Lpointer = pointer;
  }

  if (getbutton("DOWN") && millis() - lastmil > 200) {
    //move pointer DOWN if the down button is pressed and 200 millis had passed since the last button press   
    lastmil = millis();
    if (pointer + 1 < noptions)    pointer++;
    else   pointer = 0;
  }
  if (getbutton("UP") && millis() - lastmil > 200) {
    //move pointer UP if the up button is pressed and 200 millis had passed since the last button press
    lastmil = millis();
    if (pointer - 1 >= 0) pointer--;
    else pointer = noptions - 1;
  }
  if (getbutton("A")) {
    return pointer;
  }
  //if no option was chosen in excecution, return -1
  return -1;
}
