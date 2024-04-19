#include "VLUIoT.h"

VLUIoT::VLUIoT(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void VLUIoT::turnOnLED(unsigned long duration) {
  digitalWrite(_pin, HIGH);
  delay(duration);
}

void VLUIoT::turnOffLED() {
  digitalWrite(_pin, LOW);
}
