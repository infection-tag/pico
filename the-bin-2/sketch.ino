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

  Serial1.begin(115200);

  tm.init();
  tm.set(BRIGHT_TYPICAL);

  rtc.begin();

  // if (! rtc.isrunning()) {
  //   Serial.println("RTC is NOT running, let's set the time!");
  //   // When time needs to be set on a new device, or after a power loss, the
  //   // following line sets the RTC to the date & time this sketch was compiled
  //   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //   // This line sets the RTC with an explicit date & time, for example to set
  //   // January 21, 2014 at 3am you would call:
  //   // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  // }

  // Serial1.println("Hello, Raspberry Pi Pico W!");
}

unsigned int counter = 0;  
DateTime now = rtc.now();

void loop() {
  delay(1); // this speeds up the simulation

  tm.display(0, ((now.hour(), DEC) / 10) % 10);
  tm.display(1, (now.hour(), DEC) % 10);
  tm.display(2, ((now.minute(), DEC) / 10) % 10);
  tm.display(3, (now.minute(), DEC) % 10);

  // // print time, for debugging 
  // Serial.print("Current time: ");
  // Serial.print(now.year(), DEC);
  // Serial.print('/');
  // Serial.print(now.month(), DEC);
  // Serial.print('/');
  // Serial.print(now.day(), DEC);
  // Serial.print(now.hour(), DEC);
  // Serial.print(':');
  // Serial.print(now.minute(), DEC);
  // Serial.print(':');
  // Serial.print(now.second(), DEC);
  // Serial.println();



  // put your main code here, to run repeatedly:

  // tm.display(0, (counter / 1000) % 10);
  // tm.display(1, (counter / 100) % 10);
  // tm.display(2, (counter / 10) % 10);
  // tm.display(3, counter % 10);

  // counter++;
  // if (counter == 10000) {
  //   counter = 0;
  // }

  // delay(1000);

}
