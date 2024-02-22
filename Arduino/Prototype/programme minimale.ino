
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRsend.h>
#include <IRutils.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Pin de sortie de la LED IR
const int IR_LED_PIN = 4; // Remplacez-le par le numéro de broche approprié de votre ESP32
// Pin d'entrée du récepteur IR
const int IR_RECEIVE_PIN = 14; // Remplacez-le par le numéro de broche approprié de votre ESP32
// Pin d'entrée du bouton
const int BUTTON_PIN = 2; // Remplacez-le par le numéro de broche approprié de votre ESP32
// Pins de sortie de la LED RGB (anode commune)
const int LED_RED_PIN = 5; // Remplacez-le par le numéro de broche approprié de votre ESP32
const int LED_GREEN_PIN = 6; // Remplacez-le par le numéro de broche approprié de votre ESP32
const int LED_BLUE_PIN = 7; // Remplacez-le par le numéro de broche approprié de votre ESP32

IRrecv irReceiver(IR_RECEIVE_PIN);
decode_results results;
IRsend irSender(IR_LED_PIN);

// Déclaration de l'écran OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Nombre initial de vies
int nombreDeVies = 10;

// Configuration des LEDs RGB
const int LED_BLINK_DELAY = 500; // Délai de clignotement en millisecondes
const int LED_OFF_DELAY = 1000;  // Délai d'extinction en millisecondes

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT);

  // Démarrer le récepteur IR
  irReceiver.enableIRIn();

  // Initialiser l'écran OLED
  if (!display.begin(SSD1306_I2C_ADDRESS, 4, 15)) {
    Serial.println(F("Erreur lors de l'initialisation de l'écran OLED"));
    for (;;)
      ;
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();

  // Configurer les pins des LEDs RGB
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);

  // Initialiser la LED RGB en bleu au début
  setColor(0, 0, 255);
}

void loop() {
  // Vérifier si un signal infrarouge a été reçu
  if (irReceiver.decode(&results)) {
    // Afficher les informations du signal infrarouge reçu sur l'écran OLED
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(F("Code IR reçu: "));
    display.println(results.value, HEX);

    // Réduire le nombre de vies
    nombreDeVies--;

    // Afficher le nombre de vies restantes sur l'écran OLED
    display.setCursor(0, 10);
    display.print(F("Vies restantes: "));
    display.println(nombreDeVies);

    display.display();

    // Gérer l'état de la LED RGB en fonction du nombre de vies restantes
    if (nombreDeVies > 0) {
      blinkLED(0, 0, 255); // Faire clignoter la LED en bleu en cas de touché
    } else {
      turnOffLED(); // Éteindre la LED en cas de Game Over
    }

    // Remettre le récepteur IR en attente
    irReceiver.resume();
  }

  // Vérifier si le bouton est pressé pour envoyer un signal infrarouge
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // Code décimal que vous souhaitez envoyer
    unsigned int codeDecimal = 1234; // Remplacez-le par le code que vous souhaitez envoyer

    // Envoi du code infrarouge
    irSender.sendNEC(codeDecimal);

    // Afficher le code envoyé sur l'écran OLED
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(F("Code IR envoyé: "));
    display.println(codeDecimal);
    display.display();

    Serial.print("Code infrarouge envoyé: ");
    Serial.println(codeDecimal);

    // Attendez que le bouton soit relâché pour éviter l'envoi continu du signal
    while (digitalRead(BUTTON_PIN) == HIGH) {
      delay(10);
    }
  }
}

// Fonction pour faire clignoter la LED RGB
void blinkLED(int red, int green, int blue) {
  setColor(red, green, blue);
  delay(LED_BLINK_DELAY);
  turnOffLED();
  delay(LED_BLINK_DELAY);
}

// Fonction pour éteindre la LED RGB
void turnOffLED() {
  setColor(0, 0, 0);
  delay(LED_OFF_DELAY);
}

// Fonction pour configurer la couleur de la LED RGB
void setColor(int red, int green, int blue) {
  analogWrite(LED_RED_PIN, red);
  analogWrite(LED_GREEN_PIN, green);
  analogWrite(LED_BLUE_PIN, blue);
}
