#include "Arduino.h"


#ifndef SCREEN_H
#define SCREEN_H

#define BLACK 0x0000
#define WHITE 0xFFFF
#define BLUE 0xF800
#define GREEN 0x07E0
#define RED 0x001F
#define YELLOW 0x07FF
#define MAGENTA 0xF81F
#define CYAN 0xFFE0
#define ORANGE 0xFC00

class screen {
public:
  screen();
  void beginScreen();
  void erase();
  void bigfont(), smallfont();
  bool send();
  void text(uint8_t x, uint8_t y, String message, uint16_t color);
  void rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);
  void frame(float x, float y, uint8_t w, uint8_t h, uint16_t color);
  void square(float x, float y, uint8_t w, uint16_t color);
  void circle(float x, float y, uint8_t radius, uint16_t color);
  void line(uint8_t x, uint8_t y, uint8_t w, uint16_t color);
  void fontsize(int n);
  uint8_t height = 128;
  uint8_t width = 160;
  int menu(const char* name, const char* options);
  void centerText(int16_t y, String message, uint16_t color);
  void triangle(float x, float y, uint8_t radius, uint16_t color);


private:
  int16_t x1, y1;
  uint16_t w, h;


};
#endif
