/*
  BockiMessageBoard.h - 
  Created by Ellen Sundh, April 15, 2012.
  Released into the public domain.
*/

#ifndef BockiMessageBoard_h
#define BockiMessageBoard_h

#include "Arduino.h"

#define IMMEDIATE "FA"
#define CURTAINUP "FC"
#define CURTAINDOWN "FD"
#define SCROLLLEFT "FE"
#define SCROLLRIGHT "FF"
#define VERTICALOPEN "FG"
#define VERTICALCLOSE "FH"
#define SCROLLUP "FI"
#define SCROLLDOWN "FJ"
#define HOLD "FK"
#define SNOW "FL"
#define TWINKLE "FM"
#define BLOCKMOVE "FN"
#define RANDOM "FP"

typedef enum MessageBoardPage {PAGE_A, PAGE_B, PAGE_C, PAGE_D, PAGE_E, PAGE_F, PAGE_G, PAGE_H, PAGE_I, PAGE_J, PAGE_K, PAGE_L, PAGE_M, PAGE_N, PAGE_O, PAGE_P, PAGE_Q, PAGE_R, PAGE_S, PAGE_T, PAGE_U, PAGE_V, PAGE_W, PAGE_X, PAGE_Y, PAGE_Z};


class BockiMessageBoard
{
  public:
    BockiMessageBoard(int);
    void configure(int, String, String);
    void displayMessage(int, String);
   

  private:
  	void updateConfigureString();
  	String returnConfigureString(String);
   	String messageBoardId;
   	String configureString;
   	String pId;
   	String dTime;
   	String dModeIn;
   	String dModeOut;
   	String ports;
   	
};

#endif

