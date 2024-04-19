#ifndef VLUIoT_h
#define VLUIoT_h

#include <Arduino.h>

class VLUIoT {
  public:
    VLUIoT(int pin);
    void turnOnLED(unsigned long duration);
    void turnOffLED();

  private:
    int _pin;
};

#endif
