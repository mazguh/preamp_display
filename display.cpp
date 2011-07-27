#include "WProgram.h"
#include "displayDriver.h"
#include "inputSelect.h"
// #include <SPI.h>

int currentInput=0;
unsigned long lastChangeTime = 0;

int getSelectedInput()
{
  int ret = -1;
  
  if(digitalRead(2)==HIGH)
    ret = 0;
    
  if(digitalRead(4)==HIGH)
    ret = 1;

  if(digitalRead(6)==HIGH)
    ret = 2;
  
  return ret;  
}

void setup()
{                
  initSPI();
  pinMode(2, INPUT);     
  pinMode(3, INPUT);     
}


void loop()
{
    int selectedInput = getSelectedInput();
    if(selectedInput != currentInput && selectedInput != -1)
    {
       currentInput = selectedInput;
       inputSelect(currentInput);
       lastChangeTime = millis();
       setBrightness(0);
    }
    
    if((lastChangeTime + 3000)<millis())
       setBrightness(4);
    if((lastChangeTime + 5000)<millis())
       setBrightness(6);
}
