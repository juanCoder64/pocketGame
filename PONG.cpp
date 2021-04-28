#include "Arduino.h"
#include "PONG.h"
#include "communication.h"
#include "controls.h"
PONG::PONG() {

}

void PONG::begin() {
  //initializes used libraries
  beginControls();
  beginScreen();
}
void PONG::run() {
  if(!gameover){
  move();
  cpu();
  P1();
  scoreCheck();
  }
  else{
    //if game is over wait for A to be pressed
    if(getbutton("A"))gameover=false;
    P1Score=0;
    P2Score=0;
    ballSpdX=1;
    ballSpdY=1;
    }
  draw();

}
void PONG::draw() {
  erase();
  do {
    if(!gameover){
    //draws ball
    circle(ballX, ballY, rad);
    //draws player 2
    rect(0, P2Y, PW, PH);
    //draws player 1
    rect(width-PW, P1Y, PW, PH);
    //draws score
    smallfont();
    text(0,0,score);
    line(0,upperBorder,128);
    }
    else{
      //draws game over screen
      bigfont();
      text(32,0,winner+" wins");
      smallfont();
      text(10,32,"press A to continue");
    }
  } while (send());
}
void PONG::move() {
  //bounces ball
  if ((ballY+rad > P2Y && ballY-rad < P2Y + PH && ballX <= PW) || (ballY+rad > P1Y && ballY-rad < P1Y + PH && ballX >= 124)){
   ballSpdX=-ballSpdX;
   ballSpdX=ballSpdX>0?ballSpdX+.1:ballSpdX-.1;
   ballSpdY=ballSpdY>0?ballSpdY+.1:ballSpdY-.1;
  }
  //moves ball
  if (ballY + rad > height || ballY - rad < upperBorder)  ballSpdY = -ballSpdY;
  ballY += ballSpdY;
  ballX += ballSpdX;
  }
void PONG::cpu() {
  //moves CPU
  ballSpdY > 0 ? P2Y += pSpd : P2Y -= pSpd;
  if (P2Y + PH > height)P2Y = height-PH;
  if (P2Y < upperBorder)P2Y = upperBorder;
}
void PONG::P1() {
  //moves player 1
  if (getbutton("UP")) P1Y -= pSpd;
  if (getbutton("DOWN"))P1Y += pSpd;
  if (P1Y + PH > height)P1Y = height-PH;
  if (P1Y < upperBorder)P1Y = upperBorder;
}
void PONG::scoreCheck() {
  //check if someone scored
  if (ballX < 0 || ballX > width) {
    if (ballX < 0) {
      //P2 scored
      min=width/2;
      max=width+PH;
      P2Score++;
    } 
    if (ballX > width) {
      //P1 scored
      min=PH;
      max=width/2;
      P1Score++;
    }

    //puts ball in a new position
    ballSpdX=ballSpdX<0?ballSpdX+.1:ballSpdX-.1;
    ballSpdY=ballSpdY<0?ballSpdY+.1:ballSpdY-.1;
    ballX=random(min,max);
    ballY=random(upperBorder+rad+1,height-rad);
  }
  if(P2Score>maxScore||P1Score>maxScore){
    //decides who won
    gameover=true;
    winner=P2Score>P1Score?"P1":"P2";
  }
  //updates score 
  score="    P2: "+String(P1Score)+"  |"+"   P1: "+String(P2Score);
}
