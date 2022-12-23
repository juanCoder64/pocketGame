/*#include "Arduino.h"
#include "communication.h"
#include <ESP8266WiFi.h>

IPAddress server(192, 168, 0, 80);    // the fix IP address of the server
WiFiClient client;

communication::communication() {

}
void communication::begin() {
  //inicia la comumicacion WiFi
  Serial.begin(115200);               // only for debug
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}
float communication::talk() {
  //se comunica con el otro jugador
  client.connect(server, 80);   // Connection to the server
  Serial.println(".");
  client.println("\r"); // sends the message to the server
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println(answer);
  client.flush();
  return answer.toFloat();
}
*/