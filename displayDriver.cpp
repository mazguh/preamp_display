#include <Arduino.h>
#include <SPI.h>

void initSPI()
{
  pinMode(9, OUTPUT);     
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV32);
  delay(10);

  digitalWrite(9, LOW);
  delay(1);
  digitalWrite(9, HIGH);
}

void writeSpiChar(int c)
{
  digitalWrite(10, LOW);
  SPI.transfer(c);  //char 0
  digitalWrite(10, HIGH);
 }

void setBrightness(int n)
{
  if(n>=0 && n<8)
  {
    writeSpiChar(0xE0 + n);
  }
}

void selectDisplayChar(int n)
{
  if(n>=0 && n<8)
     writeSpiChar(0xA0 + n);
}


void write_blank()
{
  writeSpiChar(0x00);
  writeSpiChar(0x00);
  writeSpiChar(0x00);
  writeSpiChar(0x00);
  writeSpiChar(0x00);
  writeSpiChar(0x00);
  writeSpiChar(0x00);
}

void write_A()
{
  writeSpiChar(0x0E);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x1F);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
}

void write_B()
{
  writeSpiChar(0x1E);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x1E);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x1E);
}

void write_C()
{
  writeSpiChar(0x0E);
  writeSpiChar(0x11);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x11);
  writeSpiChar(0x0E);
}

void write_D()
{
  writeSpiChar(0x1E);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x1E);
}

void write_E()
{
  writeSpiChar(0x1F);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x1E);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x1F);
}

void write_F()
{
  writeSpiChar(0x1F);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x1E);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
}

void write_G()
{
  writeSpiChar(0x0E);
  writeSpiChar(0x11);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x13);
  writeSpiChar(0x11);
  writeSpiChar(0x0E);
}

void write_H()
{
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x1F);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
}

void write_I()
{
  writeSpiChar(0x0E);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x0E);
}

void write_J()
{
  writeSpiChar(0x01);
  writeSpiChar(0x01);
  writeSpiChar(0x01);
  writeSpiChar(0x01);
  writeSpiChar(0x01);
  writeSpiChar(0x11);
  writeSpiChar(0x0E);
}

void write_K()
{
  writeSpiChar(0x11);
  writeSpiChar(0x12);
  writeSpiChar(0x14);
  writeSpiChar(0x18);
  writeSpiChar(0x14);
  writeSpiChar(0x12);
  writeSpiChar(0x11);
}

void write_L()
{
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x1F);
}

void write_M()
{
  writeSpiChar(0x11);
  writeSpiChar(0x1B);
  writeSpiChar(0x15);
  writeSpiChar(0x15);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
}

void write_N()
{
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x19);
  writeSpiChar(0x15);
  writeSpiChar(0x13);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
}

void write_O()
{
  writeSpiChar(0x0E);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x0E);
}

void write_P()
{
  writeSpiChar(0x1E);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x1E);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
  writeSpiChar(0x10);
}

void write_Q()
{
  writeSpiChar(0x0E);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x15);
  writeSpiChar(0x12);
  writeSpiChar(0x0D);
}

void write_R()
{
  writeSpiChar(0x1E);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x1E);
  writeSpiChar(0x14);
  writeSpiChar(0x12);
  writeSpiChar(0x11);
}

void write_S()
{
  writeSpiChar(0x0E);
  writeSpiChar(0x11);
  writeSpiChar(0x10);
  writeSpiChar(0x0E);
  writeSpiChar(0x01);
  writeSpiChar(0x11);
  writeSpiChar(0x0E);
}

void write_T()
{
  writeSpiChar(0x1F);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
}

void write_U()
{
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x0E);
}

void write_V()
{
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x0A);
  writeSpiChar(0x0A);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
}

void write_W()
{
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x15);
  writeSpiChar(0x15);
  writeSpiChar(0x1B);
  writeSpiChar(0x11);
}

void write_X()
{
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x0A);
  writeSpiChar(0x04);
  writeSpiChar(0x0A);
  writeSpiChar(0x11);
  writeSpiChar(0x11);
}

void write_Y()
{
  writeSpiChar(0x11);
  writeSpiChar(0x11);
  writeSpiChar(0x0A);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
  writeSpiChar(0x04);
}

void write_Z()
{
  writeSpiChar(0x1F);
  writeSpiChar(0x01);
  writeSpiChar(0x02);
  writeSpiChar(0x04);
  writeSpiChar(0x08);
  writeSpiChar(0x10);
  writeSpiChar(0x1F);
}

void write_colon()
{
  writeSpiChar(0x00);
  writeSpiChar(0x0C);
  writeSpiChar(0x0C);
  writeSpiChar(0x00);
  writeSpiChar(0x0C);
  writeSpiChar(0x0C);
  writeSpiChar(0x00);
}


void write_dash()
{
  writeSpiChar(0x00);
  writeSpiChar(0x00);
  writeSpiChar(0x00);
  writeSpiChar(0x1F);
  writeSpiChar(0x00);
  writeSpiChar(0x00);
  writeSpiChar(0x00);
}

void write_checker()
{
  writeSpiChar(0x0A);
  writeSpiChar(0x15);
  writeSpiChar(0x0A);
  writeSpiChar(0x15);
  writeSpiChar(0x0A);
  writeSpiChar(0x15);
  writeSpiChar(0x0A);
}


void writeChar(char letter, int pos)
{
  selectDisplayChar(pos);
  switch(letter)
  {
   case ' ':
     write_blank();
     break;
     
   case 'A':
     write_A();
     break;
     
   case 'B':
     write_B();
     break;
     
   case 'C':
     write_C();
     break;
     
   case 'D':
     write_D();
     break;
     
   case 'E':
     write_E();
     break;
     
   case 'F':
     write_F();
     break;
     
   case 'G':
     write_G();
     break;
     
   case 'H':
     write_H();
     break;
     
   case 'I':
     write_I();
     break;
     
   case 'J':
     write_J();
     break;
     
   case 'K':
     write_K();
     break;
     
   case 'L':
     write_L();
     break;
     
   case 'M':
     write_M();
     break;
     
   case 'N':
     write_N();
     break;
     
   case 'O':
     write_O();
     break;
     
   case 'P':
     write_P();
     break;
     
   case 'Q':
     write_Q();
     break;
     
   case 'R':
     write_R();
     break;
     
   case 'S':
     write_S();
     break;
     
   case 'T':
     write_T();
     break;

   case 'U':
     write_U();
     break;
     
   case 'V':
     write_V();
     break;

   case 'W':
     write_W();
     break;
     
   case 'X':
     write_X();
     break;
     
   case 'Y':
     write_Y();
     break;
     
   case 'Z':
     write_Z();
     break;
     
   case ':':
     write_colon();
     break;
     
  default:
    write_checker();
    break;
  } 
}
