
#define BUZZER_PIN 23 // Définir la broche du buzzer

void setup() {

  pinMode(BUZZER_PIN, OUTPUT); // Définir la broche du buzzer en mode sortie

}

void loop() {
 
        rechargeSound();
        delay(2000);  // Reduced delay

}

void piiiouSound() {
  

  // Diminuer la fréquence progressivement
  for (int frequency = 300; frequency >= 100; frequency -= 20) {
    tone(BUZZER_PIN, frequency); // Jouer le son à la fréquence actuelle
    delay(25); // Durée du son à chaque fréquence
  }

  // Arrêter le son
  noTone(BUZZER_PIN);
}

void rechargeSound() {
  

  // Augmenter la fréquence progressivement
  int increment = 0 ;
  for (int frequency = 300; frequency <= 1300; frequency += increment) {
    tone(BUZZER_PIN, frequency); // Jouer le son à la fréquence actuelle
    increment += 100 ;
    delay(150); // Durée du son à chaque fréquence
    noTone(BUZZER_PIN);
  delay(200);
  }

  // Arrêter le son
  
  
}

void touchSound() {
  

  // Diminuer la fréquence progressivement
  for (int frequency = 1500; frequency >= 1400; frequency -= 10) {
    tone(BUZZER_PIN, frequency); // Jouer le son à la fréquence actuelle
    delay(50); // Durée du son à chaque fréquence
    
  }

  // Arrêter le son
  noTone(BUZZER_PIN);
  delay(200);
  
}
