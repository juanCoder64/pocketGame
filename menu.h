 #ifndef MENU_H
#define MENU_H
#include "Arduino.h"
#include "HWdefinitions.h"

#include screenLib
#include "controls.h"
class MENU {
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
