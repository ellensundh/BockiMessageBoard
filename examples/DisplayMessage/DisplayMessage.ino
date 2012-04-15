

/*
 DisplayMessage
 
 Demonstrates how to send string to be displayed on the LED Message Board.
 
 See character map in CharacterCodes.txt
 
 created 2012
 by Ellen Sundh
 modified 12 April 2012
 by Ellen Sundh 

BockiMessageBoard on GitHub
https://github.com/ellensundh/BockiMessageBoard

*/

#include <BockiMessageBoard.h>

BockiMessageBoard messageBoard = BockiMessageBoard(0); // Pass in ID of message board


void setup()
{
  Serial.begin(9600);
  int displayTime = 0.5; // Input 0.5 sec or 1 to 25 seconds
  
  //Animation types: IMMEDIATE, CURTAINUP, CURTAINDOWN, SCROLLLEFT, SCROLLRIGHT, VERTICALOPEN, VERTICALCLOSE, SCROLLUP, SCROLLDOWN, HOLD, SNOW, TWINKLE, BLOCKMOVE
  messageBoard.configure(displayTime,SCROLLLEFT,VERTICALCLOSE);
}

void loop()
{
  messageBoard.displayMessage(PAGE_A,"My message!"); // Page id PAGE_A - PAGE_Z and message of your choice
  delay(10000);
  
}

