#ifndef MENU_H
#define MENU_H
#include "Arduino.h"
#include "screen.h"
#include "controls.h"
class UI: public controls, public screen {
    public:
        UI();
        void begin();
        int show();
    private:
        uint8_t picked;
        const char* games=
        "Pong\n"
        "Breakout";
};
#endif
