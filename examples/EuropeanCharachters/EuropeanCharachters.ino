
/*
  EurpoeanCharacters
 
 Demonstrates how to pass European charachters to the LED display.
 
 The circuit:
 * LEDs from pins 2 through 7 to ground
 
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
  int displayTime = 3; // Input 0.5 sec or 1 to 25 seconds
  
  //Animation types: IMMEDIATE, CURTAINUP, CURTAINDOWN, SCROLLLEFT, SCROLLRIGHT, VERTICALOPEN, VERTICALCLOSE, SCROLLUP, SCROLLDOWN, HOLD, SNOW, TWINKLE, BLOCKMOVE
  messageBoard.configure(displayTime,SCROLLLEFT,SCROLLLEFT);
}

void loop()
{
  // Testing with Swedish characters ÅÄÖåäö
  String euroChars = "Testing with Swedish characters <U45><U44><U76><U65><U64><U76>";
  messageBoard.displayMessage(PAGE_A,euroChars); // Page id PAGE_A - PAGE_Z and message of your choice
  delay(10000);
  
}

