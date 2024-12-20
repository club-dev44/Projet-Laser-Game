#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RGBLed.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define IR_PIN 4
int RECV_PIN = 2;
int ledPin = 12;
const int buttonPin1 = 27;
const int buttonPin2 = 32;
const int buttonPin3 = 33;

RGBLed led2(14, 13, 12);
RGBLed led1(19, 18, 17);

int buttonState1 = 0;
int lastButtonState1 = HIGH;  // Ajout d'une variable pour suivre l'état précédent du bouton

int buttonState2 = 0;
int lastButtonState2 = HIGH;  // Ajout d'une variable pour suivre l'état précédent du bouton

int buttonState3 = 0;
int lastButtonState3 = HIGH;  // Ajout d'une variable pour suivre l'état précédent du bouton

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

int vie = 5;
int balle = 10;
int fin = 5;

IRsend irsend(IR_PIN);  // Set the GPIO to be used to sending the message.
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  irsend.begin();
  irsend.enableIROut(38);  // Set the frequency to 38 kHz
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  // Ecran
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  //delay(2000);
  //Ecran
  display.clearDisplay();
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15, 0);
  // Display static text
  display.println("David 20");
  
  display.setTextSize(1);
  display.setCursor(5, 25);
  display.println("Vies : " + String(vie));
  display.setCursor(5, 50);
  display.println("Balles : " + String(balle));
  display.display(); 

  led1.setColor(0, 27, 27);
}

void loop() {
  irsend.sendNEC(0x700200, 32);
  led1.setColor(13, 13, 13);
  delay (1000);
  led1.setColor(0,0,0);
  delay (1000);
  
}
