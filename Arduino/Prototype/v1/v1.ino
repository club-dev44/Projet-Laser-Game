#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRutils.h>

#define IR_PIN 4
int RECV_PIN = 2;
int ledPin = 12;
const int buttonPin = 32;
int buttonState = 0;
int lastButtonState = HIGH;  // Ajout d'une variable pour suivre l'état précédent du bouton

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
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    digitalWrite(ledPin, HIGH);
  }
  delay(100);
  digitalWrite(ledPin, LOW);

  buttonState = digitalRead(buttonPin);  // Read the button state here
  if (buttonState == LOW && lastButtonState == HIGH) {  // Vérifiez si l'état du bouton est passé de HIGH à LOW
    irsend.sendNEC(0x000000, 32);
    delay(500);  // Reduced delay
  }
  lastButtonState = buttonState;  // Mettez à jour l'état précédent du bouton
}
