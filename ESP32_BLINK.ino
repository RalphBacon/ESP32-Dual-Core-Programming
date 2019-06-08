#define LED1 27

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("This Task runs on Core: ");
  Serial.println(xPortGetCoreID());

  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
}
