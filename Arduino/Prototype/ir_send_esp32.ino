#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

#define IR_PIN 4

IRsend irsend(IR_PIN);  // Set the GPIO to be used to sending the message.

void setup() {
  irsend.begin();
  Serial.begin(115200);
}

void loop() {
  Serial.println("NEC");
  irsend.sendNEC(0x00FFE01FUL);
  delay(2000);
}
