#define LED 1 
#define IR 4


int pirState = LOW;
int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(IR, OUTPUT);

  Serial.begin(9600); // i got this from an online tutorial
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1); // this speeds up the simulation

  digitalWrite(LED, HIGH);
  delay(3000);

  val = digitalRead(IR);
  if(val == HIGH) {
      digitalWrite(LED, LOW);
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  }
  else {
    digitalWrite(LED, LOW); // turn LED OFF
    if (pirState == HIGH) {
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
