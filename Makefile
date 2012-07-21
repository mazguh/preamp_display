ARDUINO_DIR  = /usr/share/arduino

TARGET       = display
BOARD_TAG    = nano328
ARDUINO_LIBS = SPI

#MCU          = atmega328
#F_CPU        = 16000000
#ARDUINO_PORT = /dev/cu.usb*
ARDUINO_PORT = /dev/ttyUSB*




include /usr/share/arduino/Arduino.mk
