#include<Arduino.h>

const int sensorPin = 32;

void setup(){
	Serial.begin(115200);
}

void loop(){
	int value = analogRead(sensorPin);

	Serial.println("ADC: ");
	Serial.println(value);

	delay(100);
}
