#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRutils.h>

#define IR_PIN 4
int RECV_PIN = 2;
int ledPin = 12;

IRsend irsend(IR_PIN);  // Set the GPIO to be used to sending the message.
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  irsend.begin();
  Serial.begin(115200);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    digitalWrite(ledPin, HIGH);
  }
  delay(100);
  digitalWrite(ledPin, LOW);
  Serial.println("NEC");
  irsend.sendNEC(0x00FFE01FUL);
  delay(1000);
}