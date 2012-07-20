ARDUINO_DIR  = /usr/share/arduino

TARGET       = display
BOARD_TAG    = nano
ARDUINO_LIBS = SPI

MCU          = atmega328
F_CPU        = 16000000
ARDUINO_PORT = /dev/cu.usb*




include /usr/share/arduino/Arduino.mk
