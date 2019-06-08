#include "Arduino.h"

// The LED flashing pin
#define LED0 27

// We need to create a task (object)
TaskHandle_t Task0;

void setup()
{
  Serial.begin(115200);
  Serial.println("Setup started.");

  pinMode(LED0, OUTPUT);

  xTaskCreatePinnedToCore(
      loop0,    /* Function to implement the task */
      "Task0",  /* Name of the task */
      1000,     /* Stack size in words */
      NULL,     /* Task input parameter */
      0,        /* Priority of the task */
      &Task0,   /* Task handle. */
      0);       /* Core where the task should run */

  Serial.println("Setup completed.");
}

// This is a new loop (any name will do) for our new task
void loop0(void * parameter) {

  // It must run forever, so this is the construct
  for (;;) {

    // Just put your code here as you would do for the std loop()
    Serial.print("Running on core: ");
    Serial.println(xPortGetCoreID());

    digitalWrite(LED0, HIGH);
    delay(500);
    digitalWrite(LED0, LOW);
    delay(500);
  }
}

void loop()
{
  // If you don't put this in the original loop, NOTHING happens
  delay(1);
}
