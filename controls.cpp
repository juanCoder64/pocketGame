#include "Arduino.h"
#include "controls.h"
controls::controls() {
}
void controls::beginControls() {
  //inicializa los botones
  pinMode(D3, INPUT_PULLUP);//arriba 0
  pinMode(D7, INPUT_PULLUP);//abajo 13
  pinMode(D6, INPUT_PULLUP);// 12 A
  pinMode(D5, INPUT_PULLUP);// 14 derecha
  pinMode(10, INPUT_PULLUP);// B
  pinMode(9, INPUT_PULLUP); // izquierda
}
int controls::pressed() {
  //retorna el boton que está siendo presionado
  if (digitalRead(9) == 0) {
    return 9;
  }
  if (digitalRead(0) == 0) {
    return 0;
  }
  if (digitalRead(10) == 0) {
    return 10;
  }
  for (int i = 12; i <= 16; i++) {
    if (digitalRead(i) == 0 && i != 15) {
      return i;
    }
  }
  return -1;
}
bool controls::getbutton(String a) {
  //retorna el estado del botón pedido
  if (a == "UP") {
    return !digitalRead(0);
  }
  else if (a == "DOWN") {
    return !digitalRead(13);
  }
  else if (a == "LEFT") {
    return !digitalRead(9);
  }
  else if (a == "RIGHT") {
    return !digitalRead(14);
  }
  else if (a == "A") {
    return !digitalRead(12);
  }
  else if (a == "B") {
    return !digitalRead(10);
  }
}
