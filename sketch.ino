#include "VLUIoT.h"
#include "VLUAVG.h"
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
VLUAVG vlavg;
VLUIoT vluiot(13); // Đèn LED được kết nối với chân 13

void setup() {
  Serial.begin(9600);
  vluiot.turnOnLED(1000); // Bật đèn trong 1 giây
  vluiot.turnOffLED();    // Tắt đèn

  dht.begin();
}

void loop() {
  // Đọc giá trị nhiệt độ và độ ẩm từ cảm biến
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Thêm giá trị nhiệt độ và độ ẩm vào VLUAVG
  vlavg.addTemperature(temperature);
  vlavg.addHumidity(humidity);

  // Tính trung bình nhiệt độ và độ ẩm
  float avgTemp = vlavg.calculateAverageTemperature();
  float avgHumidity = vlavg.calculateAverageHumidity();

  // In kết quả
  Serial.print("Average Temperature: ");
  Serial.println(avgTemp);
  Serial.print("Average Humidity: ");
  Serial.println(avgHumidity);

  // Chờ 1 giây trước khi đọc giá trị mới
  delay(1000);
}
