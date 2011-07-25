#include "displayDriver.h"

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

