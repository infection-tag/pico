// Now turn this trash into treasure!

#include <TM1637.h>
#include <Wire.h> // Include for I2C communication
#include <RTClib.h> // Include for RTC library

#define SCL 2  // Define clock pin for display
#define SDA 4  // Define data pin for display
#define LED 13 // Define LED pin

RTC_DS1307 rtc; // Create an RTC object

void setup() {
  Serial.begin(57600);
  Wire.begin();       // Start I2C communication
  rtc.begin();        // Initialize RTC

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

int lastHour = -1; // Variable to store previous hour

void loop() {
  DateTime now = rtc.now();

  // // Display time on the 4-digit display
  // display.display(0, (hour / 10) % 10); // Tens digit of hour
  // display.display(1, hour % 10);       // Ones digit of hour
  // display.display(2, (minute / 10) % 10); // Tens digit of minute
  // display.display(3, minute % 10);       // Ones digit of minute
  // // TODO: Show colon between hours and minutes

  // // Hourly chime with LED
  // if (hour != lastHour) {
  //   for (int i = 0; i < hour; i++) { // Blink LED for each hour
  //     digitalWrite(LED, HIGH);
  //     delay(250);
  //     digitalWrite(LED, LOW);
  //     delay(250);
  //   }
  //   lastHour = hour; // Update last hour for comparison
  // }

  Serial.print(now.hour());

    Serial.print(now.year()); Serial.print("/");
    Serial.print(now.month()); Serial.print("/");
    Serial.print(now.day()); Serial.print(" ");

    Serial.print(now.hour()); Serial.print(":");
    Serial.print(now.minute()); Serial.print(":");
    Serial.print(now.second()); Serial.print("\n");

  delay(1000); // Update every second
}
