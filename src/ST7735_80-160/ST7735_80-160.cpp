#include <Adafruit_GFX.h>      
#include <Adafruit_ST7735.h>   
#define fasterase false
#define screen ST7735_80160
#include "Arduino.h"
#include "ST7735_80-160.hpp"

namespace ST7735_80160 {
  Adafruit_ST7735 tft = Adafruit_ST7735(15, 2, -1);
  uint32_t height = 80;
  uint32_t width = 160;
  void beginScreen() {
    //starts the screen
    tft.initR(INITR_MINI160x80);
    tft.setRotation(3);
  }
  void erase() {
    //blank the screen
    tft.fillScreen(BLACK);
  }
  bool send() {
    return false;
  }
  void bigfont() {
    tft.setTextSize(3);
  }
  void fontsize(int n) {
    tft.setTextSize(n);
  }
  void smallfont() {
    tft.setTextSize(0);
  }
  void text(uint8_t x, uint8_t y, String message, uint16_t color) {
    tft.setCursor(x, y);
    tft.setTextColor(color);
    tft.setTextSize(1);
    tft.println(message);

  }
  void rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color) {
    tft.fillRect(x, y, w, h, color);

  }
  void square(float x, float y, uint8_t w, uint16_t color) {
    tft.fillRect(x, y, w, w, color);

  }
  void frame(float x, float y, uint8_t w, uint8_t h, uint16_t color) {
    tft.drawRect(x, y, w, h, color);

  }
  void circle(float x, float y, uint8_t radius, uint16_t color) {
    tft.drawCircle(x, y, radius, color);

  }
  void line(uint8_t x, uint8_t y, uint8_t w, uint16_t color) {
    tft.drawFastHLine(x, y, w, color);
  }
  void centerText(int16_t y, String message, uint16_t color) {
    int x = width / 2;
    int messageW = message.length() * 5;
    int messageH = 7;
    if (messageW > width) {
      messageH = (messageW / width) * 7;
    }
    if (messageH + y > height)y = height - messageH;
    
    tft.getTextBounds(message, 0, 0, &x1, &y1, &w, &h); //calc width of new string
    tft.setCursor(x - w / 2, y);
    tft.setTextColor(color);
    tft.print(message);

  }
  void triangle(float x, float y, uint8_t radius, uint16_t color) {
    tft.fillTriangle(x - radius, y - radius, x, y + radius, x + radius, y + radius, RED);
  }

}