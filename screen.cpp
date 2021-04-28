#include <U8g2lib.h>
#include <U8x8lib.h>
#include<Wire.h>
#include "Arduino.h"
#include "screen.h"
U8G2_SSD1306_128X64_NONAME_1_HW_I2C oled(U8G2_R0, U8X8_PIN_NONE);
screen::screen() {

}

void screen::beginScreen() {
  
  oled.begin(D6,D7,D3, U8X8_PIN_NONE, U8X8_PIN_NONE, U8X8_PIN_NONE);
  oled.setFont(u8g2_font_6x10_tf);
  oled.setFontRefHeightExtendedText();
  oled.setDrawColor (1);
  oled.setFontPosTop ();
  oled.setFontDirection(0);
}
void screen::erase() {
  oled.firstPage();
}
bool screen::send() {
  return oled.nextPage();
}
void screen::bigfont(){
  oled.setFont(u8g2_font_ncenB14_tr);
}
void screen::smallfont(){
  oled.setFont(u8g2_font_6x10_tf);
}
void screen::text(uint8_t x, uint8_t y, String message) {
  oled.drawStr(x, y, message.c_str());
}
void screen::rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
  oled.drawBox(x, y, w, h);
  //oled.drawFrame(x, y, w, h);
}
void screen::square(float x, float y, uint8_t w) {
  oled.drawBox(x, y, w, w);
}
void screen::frame(float x, float y, uint8_t w,uint8_t h) {
  oled.drawFrame(x, y, w, h);
}
void screen::circle(float x, float y, uint8_t radius) {
  oled.drawCircle(x, y, radius, U8G2_DRAW_ALL);
}
void screen::line(uint8_t x, uint8_t y, uint8_t w){
  oled.drawHLine( x, y, w);
}
int screen::menu(const char* name,const char* options){
  int out;
  out=oled.userInterfaceSelectionList(name,0,options);
  return out;
}