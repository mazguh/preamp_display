#include <Arduino.h>
#include <SPI.h>
#include <CapSense.h>

#define POWER_RELAY A4
#define MUTE_RELAY  A2

int currentInput=0;
unsigned long lastChangeTime = 0;
CapSense cap_sensor = CapSense(5,7);
unsigned long cap_state = 0;
bool power_state = false;
bool button_state = false;

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
   if(power_state == true)
   {
      switch(n)
      {
	 case 0:
	    writeChar('A', 0);
	    writeChar(':', 1);
	    writeChar(' ', 2);
	    writeChar('C', 3);
	    writeChar('D', 4);
	    writeChar(' ', 5);
	    writeChar(' ', 6);
	    writeChar(' ', 7);
	    break; 

	 case 1:
	    writeChar('A', 0);
	    writeChar(':', 1);
	    writeChar(' ', 2);
	    writeChar('D', 3);
	    writeChar('A', 4);
	    writeChar('B', 5);
	    writeChar(' ', 6);
	    writeChar(' ', 7);
	    break; 

	 case 2:
	    writeChar('A', 0);
	    writeChar(':', 1);
	    writeChar(' ', 2);
	    writeChar('P', 3);
	    writeChar('C', 4);
	    writeChar(' ', 5);
	    writeChar(' ', 6);
	    writeChar(' ', 7);
	    break; 

	 case 3:
	    writeChar('A', 0);
	    writeChar(':', 1);
	    writeChar(' ', 2);
	    writeChar('T', 3);
	    writeChar('V', 4);
	    writeChar(' ', 5);
	    writeChar(' ', 6);
	    writeChar(' ', 7);
	    break; 

	 case 4:
	    writeChar('D', 0);
	    writeChar(':', 1);
	    writeChar(' ', 2);
	    writeChar('D', 3);
	    writeChar('A', 4);
	    writeChar('C', 5);
	    writeChar(' ', 6);
	    writeChar('A', 7);
	    break; 

	 case 5:
	    writeChar('D', 0);
	    writeChar(':', 1);
	    writeChar(' ', 2);
	    writeChar('D', 3);
	    writeChar('A', 4);
	    writeChar('C', 5);
	    writeChar(' ', 6);
	    writeChar('B', 7);
	    break; 

	 case 6:
	    writeChar('D', 0);
	    writeChar(':', 1);
	    writeChar(' ', 2);
	    writeChar('D', 3);
	    writeChar('A', 4);
	    writeChar('C', 5);
	    writeChar(' ', 6);
	    writeChar('C', 7);
	    break; 

	 case 7:
	    writeChar('D', 0);
	    writeChar(':', 1);
	    writeChar(' ', 2);
	    writeChar('D', 3);
	    writeChar('A', 4);
	    writeChar('C', 5);
	    writeChar(' ', 6);
	    writeChar('D', 7);
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

void write_smed()
{
  writeChar(' ', 0);
  writeChar(' ', 1);
  writeChar('S', 2);
  writeChar('M', 3);
  writeChar('E', 4);
  writeChar('D', 5);
  writeChar(' ', 6);
  writeChar(' ', 7);
}

void write_aikido()
{
  writeChar(' ', 0);
  writeChar('A', 1);
  writeChar('I', 2);
  writeChar('K', 3);
  writeChar('I', 4);
  writeChar('D', 5);
  writeChar('O', 6);
  writeChar(' ', 7);
}

void blank_display()
{
  writeChar(' ', 0);
  writeChar(' ', 1);
  writeChar(' ', 2);
  writeChar(' ', 3);
  writeChar(' ', 4);
  writeChar(' ', 5);
  writeChar(' ', 6);
  writeChar(' ', 7);
}

void displayWarmup()
{
   Serial.println("Inside warmup loop.");
   setBrightness(0);
   write_smed();
   delay(3000);
   write_aikido();
   delay(3000);
   for(int i=0;i<2;i++)
   {
      write_please();
      for(int j=0;j<3;j++)
      {
	 setBrightness(0);
	 delay(100);
	 setBrightness(6);
	 delay(100);
      }
      write_wait();
      for(int j=0;j<3;j++)
      {
	 setBrightness(0);
	 delay(100);
	 setBrightness(6);
	 delay(100);
      }
   }
   Serial.println("Inside warmup loop. DONE.");
}

void toggle_power_switch()
{
   if(power_state == false) // Hi voltage is off
   {
      Serial.println("Power turns ON.");
      power_state = true;
      digitalWrite(POWER_RELAY, HIGH);
      displayWarmup();
      digitalWrite(MUTE_RELAY,  HIGH);
      inputSelect(getSelectedInput());
   }
   else
   {
      Serial.println("Power turns OFF.");
      power_state = false;
      digitalWrite(POWER_RELAY, LOW);
      digitalWrite(MUTE_RELAY,  LOW);
      blank_display();
   }
}

void check_cap_sensor()
{
   unsigned long reading = cap_sensor.capSense(10);
//   Serial.print("   CapSense Calibrated: ");
//   Serial.print(reading);
   if(reading > 3000)
   {
      if(cap_state<6)
	 cap_state++;
      if(cap_state==5 && button_state == false)
      {
	 button_state = true;
	 toggle_power_switch();
      }
	 
   }
   else
   {
      if(cap_state>0)
	 cap_state--;
      if(cap_state == 1)
	 button_state = false;
   }
//   Serial.print(" cap_state: ");
//   Serial.println(cap_state);
}

void setup()
{                
  delay(100);
  Serial.begin(9600);		// for debugging
  Serial.println("Starting.");
  initSPI();
  pinMode(2, INPUT);     
  pinMode(POWER_RELAY, OUTPUT);     
  pinMode(MUTE_RELAY,  OUTPUT);     
  digitalWrite(POWER_RELAY, LOW);
  digitalWrite(MUTE_RELAY,  LOW);
  blank_display();
}

void loop()
{
   int selectedInput = getSelectedInput();
   setBrightness(0);
   check_cap_sensor();
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

