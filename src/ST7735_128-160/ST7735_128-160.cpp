#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_ST7735.h>   // include Adafruit ST7735 TFT library
#define fasterase false
/*#include <U8g2lib.h>
  #include <U8x8lib.h>
  #include<Wire.h>*/
#include "Arduino.h"
#include "ST7735_128-160.hpp"
  //U8G2_SSD1306_128X64_NONAME_1_HW_I2C oled(U8G2_R0, U8X8_PIN_NONE);
#define screen ST7735_128160


namespace ST7735_128160 {
  Adafruit_ST7735 tft = Adafruit_ST7735(15, 2, -1);
  uint32_t height = 128;
  uint32_t width = 160;
  void beginScreen() {
    //starts the screen
    //tft.initR(INITR_MINI160x80);
    tft.initR(INITR_GREENTAB);

    tft.setRotation(3);
    //tft.invertDisplay(true);
    /*oled.begin(D6, D7, D3, U8X8_PIN_NONE, U8X8_PIN_NONE, U8X8_PIN_NONE);
      oled.setFont(u8g2_font_6x10_tf);
      oled.setFontRefHeightExtendedText();
      oled.setDrawColor (1);
      oled.setFontPosTop ();
      oled.setFontDirection(0);*/
  }
  void erase() {
    //blank the screen
    Serial.print("wtf");
    tft.fillScreen(BLACK);
    //oled.firstPage();
  }
  bool send() {
    //return oled.nextPage();
    return false;
  }
  void bigfont() {
    //oled.setFont(u8g2_font_ncenB14_tr);
    tft.setTextSize(3);

    /*tft.setTextColor(ST7735_WHITE);
      tft.setTextSize(0);*/
  }
  void fontsize(int n) {
    tft.setTextSize(n);

  }
  void smallfont() {
    //oled.setFont(u8g2_font_6x10_tf);
    tft.setTextSize(0);

    /*tft.setTextColor(ST7735_WHITE);
      tft.setTextSize(2);*/
  }
  void text(uint8_t x, uint8_t y, String message, uint16_t color) {

    tft.setCursor(x, y);
    tft.setTextColor(color);
    tft.setTextSize(1);
    tft.println(message);

    //oled.drawStr(x, y, message.c_str());
  }
  void rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color) {
    tft.fillRect(x, y, w, h, color);

    //oled.drawBox(x, y, w, h);
    //oled.drawFrame(x, y, w, h);
  }
  void square(float x, float y, uint8_t w, uint16_t color) {
    tft.fillRect(x, y, w, w, color);

    //oled.drawBox(x, y, w, w);
  }
  void frame(float x, float y, uint8_t w, uint8_t h, uint16_t color) {
    tft.drawRect(x, y, w, h, color);

    //oled.drawFrame(x, y, w, h);
  }
  void circle(float x, float y, uint8_t radius, uint16_t color) {
    tft.drawCircle(x, y, radius, color);

    //oled.drawCircle(x, y, radius, U8G2_DRAW_ALL);
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

  /*int ST7735_128160::menu(const char* name, const char* options) {
    int out;
    out = oled.userInterfaceSelectionList(name, 0, options);
    return out;
    }*/
}