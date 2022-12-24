#include "Arduino.h"
#include "communication.h"
#include <ESP8266WiFi.h>
#include <WiFiManager.h> 
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "menu.h"
#include "screen.h"
#define UDP_PORT 4210

WiFiUDP UDP;
MENU wifiMode;

communication::communication() {

}
void communication::begin() {
  wifiMode.begin();
  UDP.begin(UDP_PORT);
}
float communication::talk() {
}
bool communication::connect() {
  if (mode == -1) {
    String opt[2] = { "hostpot", "connect to existing" };
    mode = wifiMode.show("Wifi?", opt, 2);

  }
  else if (!wifiReady) {
    if (mode == 1) {
      WiFiManager wifiManager;
      wifiManager.setDarkMode(true);
      wifiManager.autoConnect();
      ip = WiFi.localIP().toString();
      wifiReady = true;
      erase();
    }
    if (mode == 0) {

      WiFi.softAP("pocketGame");
      ip = WiFi.softAPIP().toString();
      wifiReady = true;
      erase();
    }
  }
  else {
    fontsize(2);
    centerText(height / 2 - 20, "Waiting for second  player", RED);
    fontsize(1);
    centerText(height / 2 + 20, "IP:" + ip, BLUE);
  }
  if (UDP.parsePacket() > 0) {
    erase();
    return 1;
  }
  return 0;
}
int communication::packetSize() {
  return UDP.parsePacket();
}
