#define LED 1

void setup() {
  pinMode(LED, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(1); // this speeds up the simulation

  digitalWrite(LED, HIGH);
  delay(3000);
}
