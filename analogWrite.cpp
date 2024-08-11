#include "analogWrite.h"
#include <Arduino.h>

void analogWrite(int pin, int value) {
  int onTime = value; // on time
  int offTime = 255 - value; // low time

  for (int i = 0; i < 255; i++) {
    if (i < onTime) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
    delayMicroseconds(100); // adjust frequency if needed (if recording a led project has problems like strobing)
  }
}
