#include <SPI.h>

const int slaveSelectPinA = 7;

uint8_t buffer[16][16][3] = { 0 };

void setPixelU(uint8_t n, uint32_t c) {
  uint8_t y;
  uint8_t x;
  if(n >= 0 && n <= 15){
    y = 0;
    x = 0;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
  }
  else if(n >= 16 && n <= 31){
    y = 16;
    x = 1;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 32 && n <= 47){
    y = 32;
    x = 2;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 48 && n <= 63){
    y = 48;
    x = 3;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 64 && n <= 79){
    y = 64;
    x = 4;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 80 && n <= 95){
    y = 80;
    x = 5;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 96 && n <= 111){
    y = 96;
    x = 6;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 112 && n <= 127){
    y = 112;
    x = 7;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
  else if(n >= 128 && n <= 143){
    y = 128;
    x = 8;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
    else if(n >= 144 && n <= 159){
    y = 144;
    x = 9;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
    else if(n >= 160 && n <= 175){
    y = 160;
    x = 10;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
    else if(n >= 176 && n <= 191){
    y = 176;
    x = 11;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
    else if(n >= 192 && n <= 207){
    y = 192;
    x = 12;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
    else if(n >= 208 && n <= 223){
    y = 208;
    x = 13;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
    else if(n >= 224 && n <= 239){
    y = 224;
    x = 14;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
    else if(n >= 240 && n <= 255){
    y = 240;
    x = 15;
    buffer[(n-y)][x][0] = (uint8_t)(c >> 16);
    buffer[(n-y)][x][1] = (uint8_t)(c >> 8);
    buffer[(n-y)][x][2] = (uint8_t)c;
    }
    else if(n >= 256){} 
}

void clearPixels(){
  for (int i=0; i <= 15; i++){
    for (int j=0; j <= 15; j++){
    buffer[i][j][0] = 0;
    buffer[i][j][1] = 0;
    buffer[i][j][2] = 0; 
    }
  }  
}

void setup() {
  Serial.begin(9600);
  pinMode(slaveSelectPinA, OUTPUT);
  pinMode(slaveSelectPinB, OUTPUT);
  SPI.begin();
  
}

void sendBuffer(int slaveSelectPin){
  SPI.beginTransaction(SPISettings(9000000, MSBFIRST, SPI_MODE0));
  digitalWrite(slaveSelectPin, LOW);
  SPI.transfer(0x72); 
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      for (int c = 0; c < 3; c++) {
        SPI.transfer(buffer[x][y][c]);  
      }
    }
  }
  digitalWrite(slaveSelectPin, HIGH);
  SPI.endTransaction();
}

int      head  = 0, tail = -10; // Index of first 'on' and 'off' pixels
uint32_t color = 0xFF0000;      // 'On' color (starts red)

void loop(){

setPixelU(head, color); // 'On' pixel at head
  setPixelU(tail, 0);     // 'Off' pixel at tail
  sendBuffer(slaveSelectPin);                     // Refresh strip
  delay(20);                        // Pause 20 milliseconds (~50 FPS)

  if(++head >= 256) {         // Increment head index.  Off end of strip?
    head = 0;                       //  Yes, reset head index to start
    if((color >>= 8) == 0)          //  Next color (R->G->B) ... past blue now?
      color = 0xFF0000;             //   Yes, reset to red
  }
  if(++tail >= 256) tail = 0; // Increment, reset tail inde
}
