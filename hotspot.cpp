#include <ESP8266WiFi.h>
//#include <EEPROM.h>
#include "Arduino.h"
#include "controls.h"
#include "hotspot.h"
//#define APSSID "ESPap"
//#define APPSK  "dsa"
hotspot::hotspot() {

}
/*String hotspot::getPass() {
//still testing
    EEPROM.begin(12);
    int address = 0;
    int readId;
    EEPROM.get(address, readId);
    Serial.print("Read Id = ");
    Serial.println(readId);
    address += sizeof(readId); //update address value
    EEPROM.end();
    return "123";
}*/
void hotspot::begin() {
    WiFi.softAP("pocketGame", password);
    screen::erase();
}
void hotspot::run() {
    //shows credentials and checks if exit button has been pressed
    screen::centerText(screen::height/2, "SSID: pocketGame", GREEN);
    screen::centerText(screen::height/2+10, "Password: " + password, GREEN);
    screen::centerText(screen::height-10, "Press B to exit", RED);
    if (controls::getbutton("B")) ESP.restart();


}
