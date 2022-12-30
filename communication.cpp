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
  //starts Wifi and UPD port
  wifiMode.begin();
  UDP.begin(UDP_PORT);
}
float communication::talk() {
}
bool communication::connect() {
  //connects with second player
  if (mode == -1) {
    //asks user which wifi mode use until one is chosen
    String opt[2] = { "hostpot", "connect to existing" };
    mode = wifiMode.show("Wifi?", opt, 2);
  }
  else if (!wifiReady) {
    //get Wifi sorted out
    if (mode == 1) {
      //in case connect to existing was chosen
      WiFiManager wifiManager;
      wifiManager.setDarkMode(true);
      //attemps to connect using wifi manager
      wifiManager.autoConnect();
      //get IP
      ip = WiFi.localIP().toString();
      wifiReady = true;
      erase();
    }
    if (mode == 0) {
      //in case hotspot was chosen
      //creates network
      WiFi.softAP("pocketGame");
      //gets IP
      ip = WiFi.softAPIP().toString();
      wifiReady = true;
      erase();
    }
  }
  else {
    //once Wifi is done, wait for secund player
    fontsize(2);
    centerText(height / 2 - 20, "Waiting for second  player", RED);
    fontsize(1);
    centerText(height / 2 + 20, "IP:" + ip, BLUE);
  }
  if (UDP.parsePacket() > 0) {
    //if a packet is recieved then second player has connected
    erase();
    return 1;
  }
  return 0;
}
int communication::packetSize() {
  return UDP.parsePacket();
}
