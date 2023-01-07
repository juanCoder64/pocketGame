#include "Arduino.h"
#include <Adafruit_ST7735.h>   


#ifndef SCREEN_H
#define SCREEN_H

#define BLACK 0xFFFF
#define WHITE 0x0000
#define BLUE 0xF800
#define GREEN  0xF81F
#define RED 0x07FF
#define YELLOW  0x001F
#define MAGENTA 0x07E0
#define CYAN 0xFFE0
#define ORANGE 0xFC00

#define screen ST7735_80160

/*class ST7735_80160 {
public:
  ST7735_80160();
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
  uint32_t height = 80;
  uint32_t width = 160;
  int menu(const char* name, const char* options);
  void centerText(int16_t y, String message, uint16_t color);
  void triangle(float x, float y, uint8_t radius, uint16_t color);


private:
  int16_t x1, y1;
  uint16_t w, h;


};*/
namespace ST7735_80160 {
  
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
  extern uint32_t height;
  extern uint32_t width ;
  int menu(const char* name, const char* options);
  void centerText(int16_t y, String message, uint16_t color);
  void triangle(float x, float y, uint8_t radius, uint16_t color);
  namespace {
    int16_t x1, y1;
    uint16_t w, h;
  }
}
#endif
