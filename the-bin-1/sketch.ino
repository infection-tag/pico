// A simple lighter - if the room is bright, the LED turns off. If the room is dark, the LED turns on.

#define LED 1 
#define IR 4
#define BUTTON 2

int pirState = LOW;
int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(BUTTON, INPUT);

  Serial.begin(9600); // i got this from an online tutorial
}

void loop() {
  delay(1); // this speeds up the simulation

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

  int buttonState = digitalRead(BUTTON);

  // Check if the button is pressed
  if (buttonState == HIGH){
    digitalWrite(LED, LOW);  // turn it off
  } else {
    digitalWrite(LED, HIGH); // leave it on
  }
}
