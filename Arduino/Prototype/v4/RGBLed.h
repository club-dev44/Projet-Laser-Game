#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>

class RGBLed {
  public:
    RGBLed(int redPin, int greenPin, int bluePin) 
      : redPin(redPin), greenPin(greenPin), bluePin(bluePin) {
      // Initialiser les broches en sortie
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(bluePin, OUTPUT);
    }

    void setColor(int red, int green, int blue) {
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);
    }

  private:
    int redPin;
    int greenPin;
    int bluePin;
};

#endif