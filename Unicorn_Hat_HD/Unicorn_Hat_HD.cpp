#include "Arduino.h"
#include "SPI.h"
#include "Unicorn_Hat_HD.h"

Unicorn_Hat_HD::Unicorn_Hat_HD(uint8_t slaveSelectPin)
{
	pinMode(slaveSelectPin, OUTPUT);
	_slaveSelectPin = slaveSelectPin;
}	

void Unicorn_Hat_HD::begin(void)
{
digitalWrite(_slaveSelectPin, HIGH);	
SPI.begin();	
}

void Unicorn_Hat_HD::show(void)
{
  SPI.beginTransaction(SPISettings(9000000, MSBFIRST, SPI_MODE0));
  digitalWrite(_slaveSelectPin, LOW);
  SPI.transfer(0x72); 
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      for (int c = 0; c < 3; c++) {
        SPI.transfer(_buff[x][y][c]);  
      }
    }
  }
  digitalWrite(_slaveSelectPin, HIGH);
  SPI.endTransaction();
}

void Unicorn_Hat_HD::clear()
{
  for (int i=0; i <= 15; i++){
    for (int j=0; j <= 15; j++){
    _buff[i][j][0] = 0;
    _buff[i][j][1] = 0;
    _buff[i][j][2] = 0;
    }
  }
}

void Unicorn_Hat_HD::setPixelColor(uint8_t n, uint8_t r, uint8_t g, uint8_t b)
{
  uint8_t y;
  uint8_t x;
  if(n >= 0 && n <= 15){
    y = 0;
    x = 0;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
  }
  else if(n >= 16 && n <= 31){
    y = 16;
    x = 1;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 32 && n <= 47){
    y = 32;
    x = 2;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 48 && n <= 63){
    y = 48;
    x = 3;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 64 && n <= 79){
    y = 64;
    x = 4;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 80 && n <= 95){
    y = 80;
    x = 5;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 96 && n <= 111){
    y = 96;
    x = 6;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 112 && n <= 127){
    y = 112;
    x = 7;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 128 && n <= 143){
    y = 128;
    x = 8;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 144 && n <= 159){
    y = 144;
    x = 9;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 160 && n <= 175){
    y = 160;
    x = 10;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 176 && n <= 191){
    y = 176;
    x = 11;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 192 && n <= 207){
    y = 192;
    x = 12;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 208 && n <= 223){
    y = 208;
    x = 13;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 224 && n <= 239){
    y = 224;
    x = 14;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 240 && n <= 255){
    y = 240;
    x = 15;
    _buff[(n-y)][x][0] = r;
    _buff[(n-y)][x][1] = g;
    _buff[(n-y)][x][2] = b;
    }
  else if(n >= 256){} 
}

void Unicorn_Hat_HD::setPixelColor(uint8_t n, uint32_t c)
{
  uint8_t y;
  uint8_t x;
  if(n >= 0 && n <= 15){
    y = 0;
    x = 0;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
  }
  else if(n >= 16 && n <= 31){
    y = 16;
    x = 1;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 32 && n <= 47){
    y = 32;
    x = 2;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 48 && n <= 63){
    y = 48;
    x = 3;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 64 && n <= 79){
    y = 64;
    x = 4;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 80 && n <= 95){
    y = 80;
    x = 5;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 96 && n <= 111){
    y = 96;
    x = 6;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 112 && n <= 127){
    y = 112;
    x = 7;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 128 && n <= 143){
    y = 128;
    x = 8;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 144 && n <= 159){
    y = 144;
    x = 9;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 160 && n <= 175){
    y = 160;
    x = 10;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 176 && n <= 191){
    y = 176;
    x = 11;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 192 && n <= 207){
    y = 192;
    x = 12;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 208 && n <= 223){
    y = 208;
    x = 13;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 224 && n <= 239){
    y = 224;
    x = 14;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 240 && n <= 255){
    y = 240;
    x = 15;
    _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
    _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
    _buff[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 256){} 
}
