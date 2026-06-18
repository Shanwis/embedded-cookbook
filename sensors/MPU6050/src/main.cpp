#include <Arduino.h>
#include <Wire.h>

#define MPU_ADDR 0x68

void writeRegister(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

int16_t read16(uint8_t reg) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(MPU_ADDR, (uint8_t)2);

    uint8_t high = Wire.read();
    uint8_t low  = Wire.read();

    return (int16_t)((high << 8) | low);
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    Wire.begin(21, 22);
    Wire.setClock(400000);

    // Wake up sensor
    writeRegister(0x6B, 0x00);

    delay(100);

    // Check WHO_AM_I
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x75);
    Wire.endTransmission(false);

    Wire.requestFrom(MPU_ADDR, (uint8_t)1);

    if (Wire.available()) {
        Serial.print("WHO_AM_I = 0x");
        Serial.println(Wire.read(), HEX);
    }

    Serial.println("Sensor initialized.");
}

void loop() {

    int16_t ax = read16(0x3B);
    int16_t ay = read16(0x3D);
    int16_t az = read16(0x3F);

    int16_t gx = read16(0x43);
    int16_t gy = read16(0x45);
    int16_t gz = read16(0x47);

    Serial.print("ACC: ");
    Serial.print(ax);
    Serial.print('\t');
    Serial.print(ay);
    Serial.print('\t');
    Serial.print(az);

    Serial.print("    GYRO: ");
    Serial.print(gx);
    Serial.print('\t');
    Serial.print(gy);
    Serial.print('\t');
    Serial.println(gz);

    delay(200);
}
