#ifndef DISPLAYDRIVER_H
#define DISPLAYDRIVER_H

void initSPI();
void setBrightness(int n);
void writeSpiChar(int c);
void selectDisplayChar(int n);
void writeChar(char letter, int pos);

#endif //ifndef DISPLAYDRIVER_H
