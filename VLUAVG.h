#ifndef VLUAVG_h
#define VLUAVG_h

#include <Arduino.h>

class VLUAVG {
  public:
    VLUAVG();
    void addTemperature(float temperature);
    void addHumidity(float humidity);
    float calculateAverageTemperature();
    float calculateAverageHumidity();

  private:
    float temperatures[10];
    float humidities[10];
    int count;
};

#endif
