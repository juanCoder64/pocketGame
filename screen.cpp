#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_ST7735.h>   // include Adafruit ST7735 TFT library
/*#include <U8g2lib.h>
  #include <U8x8lib.h>
  #include<Wire.h>*/
#include "Arduino.h"
#include "screen.h"
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C oled(U8G2_R0, U8X8_PIN_NONE);
Adafruit_ST7735 tft = Adafruit_ST7735(15, 2, -1);

screen::screen() {

}

void screen::beginScreen() {
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
void screen::erase() {
  //blank the screen
  tft.fillScreen(BLACK);
  //oled.firstPage();
}
bool screen::send() {
  //return oled.nextPage();
  return false;
}
void screen::bigfont() {
  //oled.setFont(u8g2_font_ncenB14_tr);
  tft.setTextSize(3);

  /*tft.setTextColor(ST7735_WHITE);
    tft.setTextSize(0);*/
}
void screen::fontsize(int n) {
  tft.setTextSize(n);

}
void screen::smallfont() {
  //oled.setFont(u8g2_font_6x10_tf);
  tft.setTextSize(0);

  /*tft.setTextColor(ST7735_WHITE);
    tft.setTextSize(2);*/
}
void screen::text(uint8_t x, uint8_t y, String message, uint16_t color) {
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextSize(1);
  tft.println(message);

  //oled.drawStr(x, y, message.c_str());
}
void screen::rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color) {
  tft.fillRect(x, y, w, h, color);

  //oled.drawBox(x, y, w, h);
  //oled.drawFrame(x, y, w, h);
}
void screen::square(float x, float y, uint8_t w, uint16_t color) {
  tft.fillRect(x, y, w, w, color);

  //oled.drawBox(x, y, w, w);
}
void screen::frame(float x, float y, uint8_t w, uint8_t h, uint16_t color) {
  tft.drawRect(x, y, w, h, color);

  //oled.drawFrame(x, y, w, h);
}
void screen::circle(float x, float y, uint8_t radius, uint16_t color) {
  tft.drawCircle(x, y, radius, color);

  //oled.drawCircle(x, y, radius, U8G2_DRAW_ALL);
}
void screen::line(uint8_t x, uint8_t y, uint8_t w, uint16_t color) {
  tft.drawFastHLine(x, y, w, color);
}
void screen::centerText(int16_t y, String message, uint16_t color) {
  int x = width / 2;
  tft.getTextBounds(message, 0, 0, &x1, &y1, &w, &h); //calc width of new string
  tft.setCursor(x - w / 2, y);
  tft.setTextColor(color);
  tft.print(message);

}
void screen::triangle(float x, float y, uint8_t radius, uint16_t color) {
  tft.fillTriangle(x - radius, y - radius, x, y + radius, x + radius, y + radius, RED);
}

/*int screen::menu(const char* name, const char* options) {
  int out;
  out = oled.userInterfaceSelectionList(name, 0, options);
  return out;
  }*/
