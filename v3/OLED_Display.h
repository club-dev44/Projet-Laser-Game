#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Arduino.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

class OLED_Display {
  public:
    Adafruit_SSD1306 display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

    void setup() {
      if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
      }
    }

    void loop() {
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(15, 0);
      display.println("FIN DU JEU");
      display.display(); 
    }

    void displayText(String text) {
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(15, 0);
      display.println(text);
      display.display();
    }
};

#endif