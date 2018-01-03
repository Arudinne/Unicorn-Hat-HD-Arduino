/*-------------------------------------------------------------------------
  Arduino library to control the Pimoroni Unicorn Hat HD. 
  
  The Goal of this library is to allow the user to control the Unicorn Hat HD
  as if it were a strand of "NeoPixel or "DotStar" LEDs.
  
  Written By Brandon C. Allen
  
  -------------------------------------------------------------------------*/

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


// Convert separate R,G,B into packed 32-bit RGB color.
uint32_t Unicorn_Hat_HD::Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

// Transfer data to the LED Matrix
void Unicorn_Hat_HD::show(void)
{
	uint16_t b16 = (uint16_t)brightness;
	if(brightness) {
		for (int i=0; i <= 15; i++){
			for (int j=0; j <= 15; j++){
				_buff2[i][j][0] = (_buff[i][j][0] *b16 >>8);
				_buff2[i][j][1] = (_buff[i][j][1] *b16 >>8);
				_buff2[i][j][2] = (_buff[i][j][2] *b16 >>8);
			}
		}			
    }
	else{
		for (int i=0; i <= 15; i++){
			for (int j=0; j <= 15; j++){
				_buff2[i][j][0] = (_buff[i][j][0]);
				_buff2[i][j][1] = (_buff[i][j][1]);
				_buff2[i][j][2] = (_buff[i][j][2]);
			}
		}
	} 
				
	SPI.beginTransaction(SPISettings(20000000, MSBFIRST, SPI_MODE0));
	digitalWrite(_slaveSelectPin, LOW);
	SPI.transfer(0x72);
	for (int x = 15; x >= 0; x--) { // Reverse the X axis so we are displaying pixels from left to right
			for (int y = 0; y < 16; y++) {
				for (int c = 0; c < 3; c++) {
					SPI.transfer(_buff2[x][y][c]);
				}
			}
		}

/* 
 for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      for (int c = 0; c < 3; c++) {
        SPI.transfer(_buff[x][y][c]);  
      }
    }
  }
*/

  digitalWrite(_slaveSelectPin, HIGH);
  SPI.endTransaction();
}

void Unicorn_Hat_HD::clear()
{
	memset(_buff, 0, sizeof _buff);
}

// Set pixel color from separate R,G,B components:
void Unicorn_Hat_HD::setPixelColor(uint8_t n, uint8_t r, uint8_t g, uint8_t b)
{
  uint8_t y;
  uint8_t x;
  
  switch(n)
  {
	  case 0 ... 15:
		  y = 0;
		  x = 0;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 16 ... 31:
		  y = 16;
		  x = 1;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 32 ... 47:
		  y = 32;
		  x = 2;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 48 ... 63:
		  y = 48;
		  x = 3;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 64 ... 79:
		  y = 64;
		  x = 4;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 80 ... 95:
		  y = 80;
		  x = 5;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 96 ... 111:
		  y = 96;
		  x = 6;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 112 ... 127:
		  y = 112;
		  x = 7;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 128 ... 143:
		  y = 128;
		  x = 8;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 144 ... 159:
		  y = 144;
		  x = 9;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 160 ... 175:
		  y = 160;
		  x = 10;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 176 ... 191:
		  y = 176;
		  x = 11;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 192 ... 207:
		  y = 192;
		  x = 12;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 208 ... 223:
		  y = 208;
		  x = 13;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 224 ... 239:
		  y = 224;
		  x = 14;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 240 ... 255:
		  y = 240;
		  x = 15;
		  _buff[(n-y)][x][0] = r;
		  _buff[(n-y)][x][1] = g;
		  _buff[(n-y)][x][2] = b;
		  break;
	  case 256:
		break;
  }
}

// Set pixel color from 'packed' 32-bit RGB color:
void Unicorn_Hat_HD::setPixelColor(uint8_t n, uint32_t c)
{
  uint8_t y;
  uint8_t x;
  
  switch(n)
  {
	  case 0 ... 15:
		  y = 0;
		  x = 0;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 16 ... 31:
		  y = 16;
		  x = 1;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 32 ... 47:
		  y = 32;
		  x = 2;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 48 ... 63:
		  y = 48;
		  x = 3;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 64 ... 79:
		  y = 64;
		  x = 4;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 80 ... 95:
		  y = 80;
		  x = 5;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 96 ... 111:
		  y = 96;
		  x = 6;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 112 ... 127:
		  y = 112;
		  x = 7;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 128 ... 143:
		  y = 128;
		  x = 8;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 144 ... 159:
		  y = 144;
		  x = 9;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 160 ... 175:
		  y = 160;
		  x = 10;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 176 ... 191:
		  y = 176;
		  x = 11;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 192 ... 207:
		  y = 192;
		  x = 12;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 208 ... 223:
		  y = 208;
		  x = 13;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 224 ... 239:
		  y = 224;
		  x = 14;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 240 ... 255:
		  y = 240;
		  x = 15;
		  _buff[(n-y)][x][0] = (uint8_t)(c >> 16);
		  _buff[(n-y)][x][1] = (uint8_t)(c >> 8);
		  _buff[(n-y)][x][2] = (uint8_t)c;
		  break;
	  case 256:
		break;
  }
}

void Unicorn_Hat_HD::setBrightness(uint8_t b) 
{
  brightness = b + 1;
}
