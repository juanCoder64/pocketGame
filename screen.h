#ifndef SCREEN_H
#define SCREEN_H
#include "Arduino.h"
class screen {
  public:
    screen();
    void beginScreen();
    void erase();
    void bigfont(),smallfont();
    bool send();
    void text(uint8_t x, uint8_t y, String message);
    void rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
    void frame(float x, float y, uint8_t w, uint8_t h);
    void square(float x, float y, uint8_t w);
    void circle(float x, float y, uint8_t radius);
    void line(uint8_t x, uint8_t y, uint8_t w);
    uint8_t height = 64;
    uint8_t width = 128;
    int menu(const char* name,const char* options);
    private:
    
};
#endif
