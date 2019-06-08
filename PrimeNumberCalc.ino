#define maxPrime 501
int i, j;
bool b[maxPrime];

void setup() {
  Serial.begin(115200);
  Serial.println("Setup complete");
}

void loop() {
  Serial.println("Running loop.");
  unsigned long runTime = millis();

  // Calculate all prime numbers up to X
  for (i = 2; i < maxPrime; i++) {
    b[i] = true;
  }
  for (i = 1; i < maxPrime; i++) {
    if (b[i]) {
      //Serial.print(i); Serial.print(" "); Serial.flush();
      for (float i = 0.0; i < 9000; i++) {
        for (long j = 1; j < 9000; j++) {
          float temp = i * 0.05;
          long temp2 = (long)temp % j;
        }
      }
      for (j = i * 2; j < maxPrime; j += i)
        b[j] = false;
    }
  }

  Serial.println("\n--- Prime numbers completed ---\n");
  Serial.print(millis() - runTime); Serial.println(" milliseconds");
  delay(5000);
}
