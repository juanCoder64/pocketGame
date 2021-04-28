#include "Arduino.h"
#include "menu.h"
UI::UI(){

}
void UI::begin(){
    beginScreen();
    beginControls();
}
int UI::show(){
     picked = menu("Select a game",games);
    return picked;
}
