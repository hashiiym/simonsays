// ESP32 Piano: 4 buttons = 4 notes + LED light patterns + Buzzer
// Wiring same as Simon: LEDs GPIO4,5,18,19 | Buttons GPIO12,13,14,15 | Buzzer GPIO2

const int ledPins[4]    = {4, 5, 18, 19};      // LEDs 0-3 (colors)
const int buttonPins[4] = {12, 13, 14, 15};    // Piano keys 0-3
const int buzzerPin    = 2;                    // Buzzer

// Piano notes (C major scale)
const int notes[4] = {262, 294, 330, 349};     // C4, D4, E4, F4

// LED light patterns when playing
const int ledPatterns[4][4] = {
  {1,0,0,0},  // Note 0: LED0 only
  {1,1,0,0},  // Note 1: LED0+1
  {1,1,1,0},  // Note 2: LED0+1+2  
  {1,1,1,1}   // Note 3: ALL LEDs
};

int lastButtonState[4] = {1,1,1,1};  // For debouncing (pullup = HIGH when not pressed)

void setup() {
  Serial.begin(115200);
  
  // LEDs
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  
  // Buttons (pullup)
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
  // Buzzer
  pinMode(buzzerPin, OUTPUT);
  
  // Startup chord!
  startupMelody();
}

void loop() {
  for (int i = 0; i < 4; i++) {
    int reading = digitalRead(buttonPins[i]);
    
    // Button pressed (LOW due to pullup)
    if (reading == LOW && lastButtonState[i] == HIGH) {
      playNote(i);
      updateLeds(i);
      delay(30); // debounce
    }
    
    lastButtonState[i] = reading;
  }
}

// Play note with buzzer
void playNote(int noteIndex) {
  tone(buzzerPin, notes[noteIndex]);
  Serial.print("Playing note ");
  Serial.print(noteIndex);
  Serial.print(" (");
  Serial.print(notes[noteIndex]);
  Serial.println(" Hz)");
}

// Light up LED pattern for this note
void updateLeds(int noteIndex) {
  // Turn all off first
  for (int j = 0; j < 4; j++) {
    digitalWrite(ledPins[j], LOW);
  }
  
  // Light pattern
  for (int j = 0; j < 4; j++) {
    if (ledPatterns[noteIndex][j]) {
      digitalWrite(ledPins[j], HIGH);
    }
  }
}

// Startup melody (C-D-E-F chord)
void startupMelody() {
  allLedsOn();
  delay(200);
  allLedsOff();
  
  for (int i = 0; i < 4; i++) {
    playNote(i);
    updateLeds(i);
    delay(400);
  }
  noTone(buzzerPin);
  allLedsOff();
  delay(500);
  
  // Welcome flash
  for (int i = 0; i < 3; i++) {
    allLedsOn();
    delay(150);
    allLedsOff();
    delay(150);
  }
}

void allLedsOn() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

void allLedsOff() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
