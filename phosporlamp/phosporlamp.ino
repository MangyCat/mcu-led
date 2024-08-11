int ledPin = D6; // lamp led
// Simple pseudorandom function
unsigned long pseudoRandom(unsigned long seed) { //pseudorandom seed for incompatible basic mcus
  seed = (seed * 1103515245 + 12345) % 2147483648;
  return seed;
}

void setup() {
  pinMode(ledPin, OUTPUT);
  
  // Initialize seed
  unsigned long seed = 87761;
  
  // phosphor startup
  for (int i = 0; i < 10; i++) {
    digitalWrite(ledPin, HIGH); //invert if needed
    delay(pseudoRandom(seed) % 150 + 50);
    digitalWrite(ledPin, LOW); //invert if needed
    delay(pseudoRandom(seed) % 150 + 50);
    seed = pseudoRandom(seed); // Update seed
  }
}

void loop() {
  // Initialize seed
  unsigned long seed = 12134;
  
  // flicker (every second or so a tiny flick)
  digitalWrite(ledPin, HIGH); //invert if needed
  delay(pseudoRandom(seed) % 500 + 954); 
  digitalWrite(ledPin, LOW); //invert if needed
  delay(pseudoRandom(seed) % 126 + 31); 
  seed = pseudoRandom(seed); // Update seed
}
