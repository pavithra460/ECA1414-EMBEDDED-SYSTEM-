#include <Wire.h>

#define LM75_ADDRESS 0x48

void setup() {
  Wire.begin();           
  Serial.begin(9600);    
  
  Serial.println("LM75A Temperature Monitor");
}

void loop() {
  Wire.beginTransmission(LM75_ADDRESS);
  Wire.write(0x00);              // Temperature register
  Wire.endTransmission();

  Wire.requestFrom(LM75_ADDRESS, 2);

  if (Wire.available() >= 2) {
    byte msb = Wire.read();
    byte lsb = Wire.read();

    // LM75A temperature = 9-bit, 0.5°C resolution
    int16_t raw = ((int16_t)msb << 8) | lsb;
    raw >>= 7;

    float temperature = raw * 0.5;

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
  }

  delay(1000);
}