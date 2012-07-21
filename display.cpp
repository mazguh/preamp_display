#include <Arduino.h>
#include <SPI.h>

int currentInput=0;
unsigned long lastChangeTime = 0;

void writeChar(char, int);
void initSPI();
void setBrightness(int);

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
        writeChar('A', 0);
        writeChar(' ', 1);
        writeChar('D', 2);
        writeChar('V', 3);
        writeChar('D', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 

      case 1:
        writeChar('A', 0);
        writeChar(' ', 1);
        writeChar(' ', 2);
        writeChar('C', 3);
        writeChar('D', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 

      case 2:
        writeChar('A', 0);
        writeChar(' ', 1);
        writeChar(' ', 2);
        writeChar('T', 3);
        writeChar('V', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 
   }
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
  setBrightness(0);
  inputSelect(selectedInput);
  if(selectedInput != currentInput)
    {
      delay(50);
      selectedInput = getSelectedInput();
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

