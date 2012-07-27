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
   Serial.print("Input select: ");
   Serial.println(n);
   switch(n)
   {
      case 0:
        writeChar('G', 0);
        writeChar('O', 1);
        writeChar('D', 2);
        writeChar(' ', 3);
        writeChar(' ', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 

      case 1:
        writeChar('B', 0);
        writeChar('E', 1);
        writeChar('D', 2);
        writeChar('R', 3);
        writeChar('I', 4);
        writeChar('N', 5);
        writeChar('G', 6);
        writeChar(' ', 7);
        break; 

      case 2:
        writeChar('M', 0);
        writeChar('E', 1);
        writeChar('D', 2);
        writeChar(' ', 3);
        writeChar(' ', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 

      case 3:
        writeChar('F', 0);
        writeChar('O', 1);
        writeChar('D', 2);
        writeChar('E', 3);
        writeChar('N', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 

      case 4:
        writeChar('H', 0);
        writeChar('E', 1);
        writeChar('L', 2);
        writeChar('G', 3);
        writeChar('A', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 

      case 5:
        writeChar(' ', 0);
        writeChar(' ', 1);
        writeChar(' ', 2);
        writeChar(' ', 3);
        writeChar(' ', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 

      case 6:
        writeChar('G', 0);
        writeChar('G', 1);
        writeChar('G', 2);
        writeChar('G', 3);
        writeChar('G', 4);
        writeChar('G', 5);
        writeChar('G', 6);
        writeChar('G', 7);
        break; 

      case 7:
        writeChar('H', 0);
        writeChar('H', 1);
        writeChar('H', 2);
        writeChar('H', 3);
        writeChar('H', 4);
        writeChar('H', 5);
        writeChar('H', 6);
        writeChar('H', 7);
        break; 

      default:
        writeChar('N', 0);
        writeChar('O', 1);
        writeChar('T', 2);
        writeChar(' ', 3);
        writeChar('D', 4);
        writeChar('O', 5);
        writeChar('N', 6);
        writeChar('E', 7);
        break; 
   }
}

void write_please()
{
  writeChar(' ', 0);
  writeChar('P', 1);
  writeChar('L', 2);
  writeChar('E', 3);
  writeChar('A', 4);
  writeChar('S', 5);
  writeChar('E', 6);
  writeChar(' ', 7);
}

void write_wait()
{
  writeChar(' ', 0);
  writeChar(' ', 1);
  writeChar('W', 2);
  writeChar('A', 3);
  writeChar('I', 4);
  writeChar('T', 5);
  writeChar(' ', 6);
  writeChar(' ', 7);
}

void displayWarmup()
{
   Serial.println("Inside warmup loop.");
   setBrightness(0);
   for(int i=0;i<2;i++)
   {
      write_please();
      for(int j=0;j<10;j++)
      {
	 setBrightness(0);
	 delay(100);
	 setBrightness(6);
	 delay(100);
      }
      write_wait();
      for(int j=0;j<10;j++)
      {
	 setBrightness(0);
	 delay(100);
	 setBrightness(6);
	 delay(100);
      }
   }
   Serial.println("Inside warmup loop. DONE.");
   digitalWrite(3, HIGH);
}

void setup()
{                
  delay(100);
  Serial.begin(9600);		// for debugging
  Serial.println("Starting.");
  initSPI();
  pinMode(2, INPUT);     
  pinMode(3, OUTPUT);     
  digitalWrite(3, LOW);
  displayWarmup();
  inputSelect(getSelectedInput());
}

void loop()
{
   int selectedInput = getSelectedInput();
   setBrightness(0);
   if(selectedInput != currentInput)
   {
      Serial.println("Input changed.");
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

