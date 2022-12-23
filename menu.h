 #ifndef MENU_H
#define MENU_H
#include "Arduino.h"
#include "screen.h"
#include "controls.h"
class MENU: public controls, public screen {
  public:
    MENU();
    void begin();
    int show(String title, String options[], int noptions);
      int pointer=0;
      int Lpointer=1;
  private:
  unsigned long long int lastmil;
    uint8_t picked;
};
#endif
