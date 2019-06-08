#include "Arduino.h"

TaskHandle_t Task0;
TaskHandle_t Task1;

#define LED0 27
#define LED1 25

void loop0(void * parameter) {
	for (;;) {
		Serial.print("Running on core: ");
		Serial.println(xPortGetCoreID());

		digitalWrite(LED0, HIGH);
		delay(500);
		digitalWrite(LED0, LOW);
		delay(500);
	}
}

void loop1(void * parameter) {
	for (;;) {
		Serial.print("Running on core: ");
		Serial.println(xPortGetCoreID());

		digitalWrite(LED1, HIGH);
		delay(200);
		digitalWrite(LED1, LOW);
		delay(200);
	}
}

void setup()
{
	Serial.begin(115200);
	Serial.println("Setup started.");

	pinMode(LED0, OUTPUT);
	pinMode(LED1, OUTPUT);

	xTaskCreatePinnedToCore(
			loop0, /* Function to implement the task */
			"Task0", /* Name of the task */
			1000, /* Stack size in words */
			NULL, /* Task input parameter */
			0, /* Priority of the task */
			&Task0, /* Task handle. */
			0); /* Core where the task should run */

	xTaskCreatePinnedToCore(
			loop1, /* Function to implement the task */
			"Task1", /* Name of the task */
			1000, /* Stack size in words */
			NULL, /* Task input parameter */
			0, /* Priority of the task */
			&Task1, /* Task handle. */
			1); /* Core where the task should run */
	Serial.println("Setup completed.");
}

void loop()
{
	delay(1);
}
