ARDUINO_DIR  = /usr/share/arduino

TARGET       = display
# ARDUINO_LIBS = SPI

MCU          = atmega328
F_CPU        = 16000000
ARDUINO_PORT = /dev/cu.usb*

.PHONY: cccc

cccc:
	cccc *.cpp *.h


include /usr/share/arduino/Arduino.mk
