//#include "WProgram.h"
#include "pins_arduino.h"
#include "SPI.h"
#include "displayDriver.h"
// #include "charset.h"

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
   case 'C':
     write_C();
     break;
     
   case 'D':
     write_D();
     break;
     
   case 'T':
     write_T();
     break;

  case ' ':
   writeSpiChar(0x0E);
   writeSpiChar(0x11);
   writeSpiChar(0x10);
   writeSpiChar(0x10);
   writeSpiChar(0x10);
   writeSpiChar(0x11);
   writeSpiChar(0x0E);
   //     write_blank();
     break;
  default:
  case 'V':
    write_V();
    break;
  } 
}

/********************************/
/*    Charset definition        */
/********************************/

void displayDriver::write_blank()
{
   writeSpiChar(0x00);
   writeSpiChar(0x00);
   writeSpiChar(0x00);
   writeSpiChar(0x00);
   writeSpiChar(0x00);
   writeSpiChar(0x00);
   writeSpiChar(0x00);
}


void displayDriver::write_C()
{
   writeSpiChar(0x0E);
   writeSpiChar(0x11);
   writeSpiChar(0x10);
   writeSpiChar(0x10);
   writeSpiChar(0x10);
   writeSpiChar(0x11);
   writeSpiChar(0x0E);
}


void displayDriver::write_D()
{
   writeSpiChar(0x1E);
   writeSpiChar(0x11);
   writeSpiChar(0x11);
   writeSpiChar(0x11);
   writeSpiChar(0x11);
   writeSpiChar(0x11);
   writeSpiChar(0x1E);
}

void displayDriver::write_T()
{
   writeSpiChar(0x1F);
   writeSpiChar(0x04);
   writeSpiChar(0x04);
   writeSpiChar(0x04);
   writeSpiChar(0x04);
   writeSpiChar(0x04);
   writeSpiChar(0x04);
}

void displayDriver::write_V()
{
   writeSpiChar(0x11);
   writeSpiChar(0x11);
   writeSpiChar(0x11);
   writeSpiChar(0x0A);
   writeSpiChar(0x0A);
   writeSpiChar(0x04);
   writeSpiChar(0x04);
}

