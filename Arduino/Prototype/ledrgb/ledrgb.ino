#include "RGBLed.h"

RGBLed led(14, 13, 12);

void setup() {
  led.setColor(0, 27, 27);
  //delay(1000);
}

void loop() {
  // Allumer la LED en rouge
  //led.setColor(100, 100, 0);
  //delay(1000);

  // Allumer la LED en vert
  //led.setColor(0, 100, 100);
  //delay(1000);

  // Allumer la LED en bleu
  //led.setColor(100, 0, 100);
  //delay(1000);
}
