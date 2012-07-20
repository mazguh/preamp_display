#ifndef DISPLAYDRIVER_H
#define DISPLAYDRIVER_H


class displayDriver
{
 public:
  displayDriver();
  void setBrightness(int n);
  void writeSpiChar(int c);
  void selectDisplayChar(int n);
  void writeChar(char letter, int pos);
  
 private:
  void initSPI();
  void write_blank();  
  void write_C();
  void write_D();
  void write_T();
  void write_V();
};

#endif //ifndef DISPLAYDRIVER_H
