#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int vie = 10;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15, 0);
  // Display static text
  display.println("David 20");

  display.setTextSize(1);
  display.setCursor(5, 20);
  display.println("Nombre de vie :");
  display.display(); 
}

void loop() {
  for (int i=0; i<10; i++)
  {
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15, 0);
  // Display static text
  display.println("David 20");

  display.setTextSize(1);
  display.setCursor(5, 25);
  display.println("Nombre de vie : " + String(vie-i));
  display.display(); 
  delay (1000);
  }
}
