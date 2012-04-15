/*
  BockiMessageBoard.cpp - 
  Created by Ellen Sundh, April 12, 2012.
  Released into the public domain.
*/

#include "Arduino.h"
#include <math.h>
#include "BockiMessageBoard.h"

//char BockiMessageBoard::ports[] = 
BockiMessageBoard::BockiMessageBoard(int boardId)
{
  Serial.begin(9600);
  ports = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  String bId = String(boardId);
  pId = "A";
  dTime = "WA";
  dModeIn = "FE";
  dModeOut = "FE";
  if(bId.length() == 1) bId = "0" + bId;
  messageBoardId = "<ID" + bId + ">";
  updateConfigureString();
}
/* Configures how long the message should who, how to animate in and out. Produces codes according to settings. */
void BockiMessageBoard::configure(int displayTime, String displayModeIn, String displayModeOut)
{ 
  
  displayTime = int(fmin(abs(displayTime),25));
  Serial.print(displayTime);
  dTime = "W" + String(ports[round(displayTime)]);

  dModeIn = displayModeIn;
  dModeOut = displayModeOut;

  updateConfigureString();
  
}

/* Sets the latest configuration passed to the library */

void BockiMessageBoard::updateConfigureString() {
    configureString = "<L1><P" + pId + "><" + dModeIn + "><MA><" + dTime + "><" + dModeOut + ">";
}

/* Returns the latest configuration to be calculated in the checksum */

String BockiMessageBoard::returnConfigureString(String inputString) {
    updateConfigureString();
    return configureString + inputString;
}
/*
displayMessage calculates the checksum of display message and configuration of the message board. 
Prints out the message to message board.
*/ 
void BockiMessageBoard::displayMessage(int pageId, String inputString)
{
  byte checksum = 0x00; 
  //pId = pageId;

  
  inputString = returnConfigureString(inputString);

  char ascii_char[inputString.length() + 1];
  inputString.toCharArray(ascii_char, sizeof(ascii_char));


 for (int i=0; i<strlen(ascii_char); i++) {
   checksum = checksum ^ ascii_char[i];
   
 }
  String hexStr =  String(checksum, HEX); 
   hexStr.toUpperCase();
   if(hexStr.length() == 1) {
     hexStr = "0" + hexStr;
   } 
   inputString = inputString + hexStr; 
  Serial.println(messageBoardId  + inputString + "<E>");
}

