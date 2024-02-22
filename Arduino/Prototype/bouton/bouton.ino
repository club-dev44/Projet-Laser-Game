const int buttonPin = 32;
const int ledPin =  23;

// Etat du bouton poussoir
int buttonState = 0;

void setup() {
    Serial.begin(115200);

    //Configuration du pin en entrée pullup
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
}

void loop() {

    buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);

    if (buttonState == LOW) {
        // Allume la led
        digitalWrite(ledPin, HIGH);
    } else {
        // Eteins la led
        digitalWrite(ledPin, LOW);
    }
}
