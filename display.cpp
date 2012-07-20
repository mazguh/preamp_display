// #include "WProgram.h"
#include "Arduino.h"
#include "pins_arduino.h"
#include "displayDriver.h"
// #include "inputSelect.h"
// #include <SPI.h>

int currentInput=0;
unsigned long lastChangeTime = 0;
displayDriver display;

int getSelectedInput()
{
  int ret = 0;
  
  if(digitalRead(2)==HIGH)
    ret += 1;
    
  if(digitalRead(4)==HIGH)
    ret += 2;

  if(digitalRead(6)==HIGH)
    ret += 4;
  
  return ret;  
}

void inputSelect(int n)
{
   switch(n)
   {
      case 0:
        display.writeChar(' ', 0);
        display.writeChar(' ', 1);
        display.writeChar('D', 2);
        display.writeChar('V', 3);
        display.writeChar('D', 4);
        display.writeChar(' ', 5);
        display.writeChar(' ', 6);
        display.writeChar(' ', 7);
        break; 

      case 1:
        display.writeChar(' ', 0);
        display.writeChar(' ', 1);
        display.writeChar(' ', 2);
        display.writeChar('C', 3);
        display.writeChar('D', 4);
        display.writeChar(' ', 5);
        display.writeChar(' ', 6);
        display.writeChar(' ', 7);
        break; 

      case 2:
        display.writeChar(' ', 0);
        display.writeChar(' ', 1);
        display.writeChar(' ', 2);
        display.writeChar('T', 3);
        display.writeChar('V', 4);
        display.writeChar(' ', 5);
        display.writeChar(' ', 6);
        display.writeChar(' ', 7);
        break; 
   }
}


void setup()
{                
  //  display.initSPI();
  pinMode(2, INPUT);     
  pinMode(3, INPUT);     
}


void loop()
{
  int selectedInput = getSelectedInput();
  if(selectedInput != currentInput)
    {
      delay(50);
      selectedInput = getSelectedInput();
      currentInput = selectedInput;
      inputSelect(currentInput);
      lastChangeTime = millis();
      display.setBrightness(0);
    }
    
    if((lastChangeTime + 3000)<millis())
       display.setBrightness(4);
    if((lastChangeTime + 5000)<millis())
       display.setBrightness(6);
}
