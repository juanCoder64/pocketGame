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
    WiFi.softAP("huh", "password");
    erase();
}
void hotspot::run() {
    centerText(64, "SSID: pocketGame",GREEN);
    centerText(74, "Password: " + password, GREEN);
    centerText(54, "Press B to exit", RED);
    if (anyPressed()) ESP.restart();
    

}
