#ifndef UNICORN_HAT_HD_H
#define UNICORN_HAT_HD_H

#include "Arduino.h"

class Unicorn_Hat_HD 
{
  public:
    Unicorn_Hat_HD(uint8_t slaveSelectPin);
	void begin(void);
    void show(void);
	void clear();
    void setPixelColor(uint8_t n, uint8_t r, uint8_t g, uint8_t b);
	void setPixelColor(uint8_t n, uint32_t c);
	void setBrightness(uint8_t);
	uint32_t Color(uint8_t r, uint8_t g, uint8_t b);
  private:
    uint8_t _slaveSelectPin;
    uint8_t _buff[16][16][3];
    uint8_t _buff2[16][16][3];
    uint8_t brightness;
};
#endif
