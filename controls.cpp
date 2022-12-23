#include "Arduino.h"
#include "controls.h"
//#define UP 0
/*#define DOWN D7
  #define A D6
  #define B 10
  #define LEFT 9
  #define RIGHT D5
  #define UP D3*/

  //#define DOWN D3
  //#define A D0
  //#define B D1
  //#define LEFT D6
  //#define RIGHT D8
  //#define UP D2
  //D3
#define UP D2 //works
#define A D3 //works
#define B D1 //works
#define LEFT D6 
#define RIGHT D8
#define DOWN D0 //pullup

controls::controls() {
}
void controls::beginControls() {
  //inicializa los botones
  pinMode(UP, INPUT_PULLUP);//arriba 0
  pinMode(DOWN, INPUT_PULLUP);//abajo 13
  pinMode(A, INPUT_PULLUP);// 12 A
  pinMode(RIGHT, INPUT_PULLUP);// 14 derecha
  pinMode(B, INPUT_PULLUP);// B
  pinMode(LEFT, INPUT_PULLUP); // izquierda
}

bool controls::anyPressed() {
  return (getbutton("UP") || getbutton("DOWN") || getbutton("LEFT") || getbutton("RIGHT") || getbutton("A") || getbutton("B"));
}



bool controls::getbutton(String a) {
  //retorna el estado del botón pedido
  if (a == "UP") {
    return !digitalRead(UP);
    //return analogRead(A0)<600&&analogRead(A0)>500;
  }
  else if (a == "DOWN") {
    return !digitalRead(DOWN);
    //return analogRead(A0)>=1020;
  }
  else if (a == "LEFT") {
    return analogRead(A0) >= 800;
    //return !digitalRead(LEFT);
  }
  else if (a == "RIGHT") {
    return analogRead(A0) < 800 && analogRead(A0) > 200;
    //return !digitalRead(RIGHT);
  }
  else if (a == "A") {
    return !digitalRead(A);
  }
  else if (a == "B") {
    return !digitalRead(B);
  }

  return false;
}
