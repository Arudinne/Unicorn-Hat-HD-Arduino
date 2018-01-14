#include <SPI.h>
#include <Unicorn_Hat_HD.h>

const int slaveSelectPinA = 7;

Unicorn_Hat_HD matrixA = Unicorn_Hat_HD(slaveSelectPinA, 0);

void setup() {
  Serial.begin(115200);
  matrixA.begin();
  
}

int      headA  = 0, tailA = -10; // Index of first 'on' and 'off' pixels
uint32_t colorA = 0x110000;      // 'On' color (starts red)

void loop(){

  matrixA.setPixelColor(headA, colorA); // 'On' pixel at head
  matrixA.setPixelColor(tailA, 0);     // 'Off' pixel at tail
  matrixA.show();                     // Refresh strip

  delay(20);                        // Pause 20 milliseconds (~50 FPS)

  if(++headA >= 256) {         // Increment head index.  Off end of strip?
    headA = 0;                       //  Yes, reset head index to start
    if((colorA >>= 8) == 0)          //  Next color (R->G->B) ... past blue now?
      colorA = 0x110000;             //   Yes, reset to red
  }
  if(++tailA >= 256) tailA = 0; // Increment, reset tail index
  
}
