#include "WProgram.h"
#include "SPI.h"
#include "displayDriver.h"
#include "charset.h"

displayDriver::displayDriver()
{
  initSPI();
}

void displayDriver::initSPI()
{
  pinMode(9, OUTPUT);     
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV64);
  delay(10);

  digitalWrite(9, LOW);
  delay(1);
  digitalWrite(9, HIGH);
}

void displayDriver::setBrightness(int n)
{
  if(n>=0 && n<8)
  {
    writeSpiChar(0xE0 + n);
  }
}

void displayDriver::writeSpiChar(int c)
{
  digitalWrite(10, LOW);
  SPI.transfer(c);  //char 0
  digitalWrite(10, HIGH);
 }

void displayDriver::selectDisplayChar(int n)
{
  if(n>=0 && n<8)
     writeSpiChar(0xA0 + n);
}

void displayDriver::writeChar(char letter, int pos)
{
  selectDisplayChar(pos);
  switch(letter)
  {
   case ' ':
     write_blank();
     break;
     
   case 'C':
     write_C();
     break;
     
   case 'D':
     write_D();
     break;
     
   case 'T':
     write_T();
     break;

   case 'V':
     write_V();
     break;
  } 
}
