#include "VLUAVG.h"

VLUAVG::VLUAVG() {
  count = 0;
}

void VLUAVG::addTemperature(float temperature) {
  if (count < 10) {
    temperatures[count] = temperature;
    count++;
  }
}

void VLUAVG::addHumidity(float humidity) {
  if (count < 10) {
    humidities[count] = humidity;
    count++;
  }
}

float VLUAVG::calculateAverageTemperature() {
  float sum = 0;
  for (int i = 0; i < count; i++) {
    sum += temperatures[i];
  }
  return sum / count;
}

float VLUAVG::calculateAverageHumidity() {
  float sum = 0;
  for (int i = 0; i < count; i++) {
    sum += humidities[i];
  }
  return sum / count;
}
