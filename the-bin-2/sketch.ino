// Now turn this trash into treasure!

#include <TM1637.h>
#include "RTClib.h"

#define CLK 0
#define DIO 1
#define LED 3
#define SDA 28
#define SCL 26

RTC_DS1307 rtc;

TM1637 tm(CLK, DIO);

void setup() {
  // put your setup code here, to run once:

  tm.init();
  tm.set(BRIGHT_TYPICAL);
  Serial1.begin(115200);
  Serial1.println("Hello, Raspberry Pi Pico W!");
}

unsigned int counter = 0;

void loop() {
  // put your main code here, to run repeatedly:
  delay(1); // this speeds up the simulation

  tm.display(0, (counter / 1000) % 10);
  tm.display(1, (counter / 100) % 10);
  tm.display(2, (counter / 10) % 10);
  tm.display(3, counter % 10);

  counter++;
  if (counter == 10000) {
    counter = 0;
  }

  delay(1000);

}
