#define MAX_INPUTS 6

#include "displayDriver.h"

void inputSelect(int n)
{
   switch(n)
   {
      case 0:
        writeChar(' ', 0);
        writeChar(' ', 1);
        writeChar('D', 2);
        writeChar('V', 3);
        writeChar('D', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 

      case 1:
        writeChar(' ', 0);
        writeChar(' ', 1);
        writeChar(' ', 2);
        writeChar('C', 3);
        writeChar('D', 4);
        writeChar(' ', 5);
        writeChar(' ', 6);
        writeChar(' ', 7);
        break; 

      case 2:
        writeChar(' ', 0);
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
