#include "Arduino.h"
#include "PONG2P.h"
#include "communication.h"
#include "controls.h"
#include <WiFiManager.h> 
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "menu.h"
#define UDP_PORT 4210

WiFiUDP UDP;
MENU wifiMode;

#include <Adafruit_ST7735.h>   // include Adafruit ST7735 TFT library
#define P1X (width-PW*2)
#define P2X 0

PONG2P::PONG2P() {

}

void PONG2P::begin() {
  erase();
  wifiMode.begin();

  //WiFi.begin(WIFI_SSID, WIFI_PASS);
  //while (WiFi.status() != WL_CONNECTED) {
  //  delay(100);
  //}
  UDP.begin(UDP_PORT);
  erase();

}

void PONG2P::run() {

  if (!P2ready) {
    if (chosen == -1) {
      String opt[2] = { "hostpot", "connect to existing" };
      chosen = wifiMode.show("Wifi?", opt, 2);

    }
    else if (chosen == 0 && !Wready) {
      erase();
      Serial.print("inside");
      WiFi.softAP("huh", "password");
      ip = WiFi.softAPIP().toString();
      Wready = true;
    }
    else if (chosen == 1 && !Wready) {
      erase();
      WiFiManager wifiManager;
      wifiManager.setDarkMode(true);
      wifiManager.autoConnect();
      ip = WiFi.localIP().toString();
      Wready = true;

    }
    if (Wready) {
      fontsize(2);
      centerText(height / 2-20, "Waiting for second  player", RED);
      fontsize(1);
      centerText(height / 2 + 20, "IP:" + ip, BLUE);
    }
    P2ready = UDP.parsePacket() > 0;

  }
  else {
    if (!gameover) {
      move();
      cpu();
      P1();
      scoreCheck();
    }
    else {
      //if game is over wait for A to be pressed
      if (getbutton("A"))gameover = false, erase(), P1Score = 0, P2Score = 0;
      else if (getbutton("B"))ESP.restart();
      //ballSpdX += 0.1;
      //ballSpdY +=0.1;
    }
    draw();

  }

}
void PONG2P::draw() {
  //erase();
  do {
    if (!gameover) {
      //draws ball
      if (LballX != ballX || LballY != ballY) {
        circle(LballX, LballY, Lrad, ST77XX_BLACK);
        circle(ballX, ballY, rad, GREEN);

      }
      //draws player 2
      if (LP2Y != P2Y) {
        rect(0, LP2Y, PW, PH, BLACK);
        rect(0, P2Y, PW, PH, BLUE);

      }
      //draws player 1
      rect(width - PW * 2, LP1Y, PW, PH, BLACK);
      rect(width - PW * 2, P1Y, PW, PH, RED);

      //draws score
      if (score != Lscore) {
        smallfont();
        centerText(0, Lscore, BLACK);
        smallfont();
        centerText(0, score, GREEN);
      }
      //erase();
      //draws ball
      //draws player 2
      //draws player 1
      line(0, upperBorder, width, GREEN);

      //draws score


      LballX = ballX, LballY = ballY, Lrad = rad, LP2Y = P2Y, LP1Y = P1Y, Lscore = score;
    }
    else {
      //draws game over screen
      bigfont();
      centerText(32, winner + " wins", BLUE);
      smallfont();
      centerText(64, "press A to continue", CYAN);
      centerText(74, "press B to exit", CYAN);

    }
  } while (send());
}
bool PONG2P::inRange(float min, float max, float x) {
  return x > min && x < max;
}
bool PONG2P::bounceP(uint8_t P) {
  if (P == 2) {
    if (inRange(P2Y - rad, P2Y + rad + PH, ballY))
      if (inRange(P2X, P2X + PW, ballX))
        return 1;
    return 0;
  }
  else {
    if (inRange(P1Y - rad, P1Y + rad + PH, ballY))
      if (inRange(P1X, P1X + PW, ballX))
        return 1;
    return 0;

  }
}
void PONG2P::move() {
  //bounces ball with player

  //if ((((ballY + rad > P2Y && ballY + rad < P2Y + PH) || (ballY - rad > P2Y && ballY - rad < P2Y + PH)) && ballX <= PW) || (((ballY + rad > P1Y && ballY + rad < P1Y + PH) || (ballY - rad > P1Y && ballY - rad < P1Y + PH)) && ballX >= width - PW)) {
  if (bounceP(1)) {
    ballSpdX = -ballSpdX; //inverses direction
    ballSpdX = ballSpdX > 0 ? ballSpdX + .01 : ballSpdX - .01;//speeds up ball
    ballSpdY = ballSpdY > 0 ? ballSpdY + .01 : ballSpdY - .01;//speeds up ball
    pSpd = pSpd > 0 ? pSpd + 0.005 : pSpd + 0.005;//speeds up player
    ballY = ballY + PW;
  }
  else if (bounceP(2)) {
    ballSpdX = -ballSpdX; //inverses direction
    ballSpdX = ballSpdX > 0 ? ballSpdX + .01 : ballSpdX - .01;//speeds up ball
    ballSpdY = ballSpdY > 0 ? ballSpdY + .01 : ballSpdY - .01;//speeds up ball
    pSpd = pSpd > 0 ? pSpd + 0.005 : pSpd + 0.005;//speeds up player
    ballY = ballY - PW;
  }


  if (ballX + rad > PW)
    //bounces ball with borders
    if (ballY + rad > height || ballY - rad < upperBorder)  ballSpdY = -ballSpdY;
  //moves ball
  ballY += ballSpdY;
  ballX += ballSpdX;
}
void PONG2P::cpu() {
  //moves CPU
  int packetSize = UDP.parsePacket();
  if (packetSize == 4) {
    P2Y += 1;
  }
  else if (packetSize > 0) {
    P2Y -= 1;
  }


  //ballSpdY > 0 ? P2Y += pSpd : P2Y -= pSpd;
  if (P2Y + PH > height)P2Y = height - PH;
  if (P2Y < upperBorder)P2Y = upperBorder;
}
void PONG2P::P1() {
  //moves player 1
  if (getbutton("UP")) P1Y -= pSpd;
  if (getbutton("DOWN"))P1Y += pSpd;
  if (P1Y + PH > height)P1Y = height - PH;
  if (P1Y < upperBorder)P1Y = upperBorder;
}
void PONG2P::scoreCheck() {
  //check if someone scored
  if (ballX < 0 || ballX > width) {
    if (ballX < 0) {
      //P2 scored
      ballSpdX = -0.2;
      ballSpdY = -0.2;
      min = width / 2;
      max = width;
      P2Score++;
      ballX = width - (PW + 1);
      ballY = P2Y + PH / 2;
    }
    if (ballX > width) {
      //P1 scored
      ballSpdX = 0.2;
      ballSpdY = 0.2;
      min = PH;
      max = width / 2;
      ballX = PH + 1;
      ballY = P1Y + PH / 2;
      P1Score++;
    }

    //puts ball in a new position
    // ballSpdX = ballSpdX < 0 ? ballSpdX + .1 : ballSpdX - .1;
    // ballSpdY = ballSpdY < 0 ? ballSpdY + .1 : ballSpdY - .1;

    pSpd = 0.25;
    //  ballX = random(min, max);
    //   ballY = random(upperBorder + rad + 1, height - rad);
  }
  if (P2Score > maxScore || P1Score > maxScore) {
    //decides who won
    gameover = true;
    winner = P2Score > P1Score ? "P1" : "P2";
    erase();
  }
  //updates score
  score = "P2: " + String(P1Score) + "  |" + "   P1: " + String(P2Score);
}
