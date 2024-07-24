#include <Wire.h> // Include for I2C communication
#include <RTClib.h> // Include for RTC library

#define CLK 2  // Define clock pin for display
#define DIO 3  // Define data pin for display
#define LED 13 // Define LED pin

RTC_DS3231 rtc; // Create an RTC object

TM1637 display(CLK, DIO); // Create a display object

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging (optional)
  Wire.begin();       // Start I2C communication
  rtc.begin();        // Initialize RTC

  if (!rtc.isTimeValid()) {
    Serial.println("RTC not configured, please set the time!");
    while (1); // Halt if RTC is not set
  }

  display.init();     // Initialize display
  display.setBrightness(7); // Set display brightness (0-7)
}

int lastHour = -1; // Variable to store previous hour

void loop() {
  DateTime now = rtc.now();

  int hour = now.hour();
  int minute = now.minute();

  // Display time on the 4-digit display
  display.display(0, (hour / 10) % 10); // Tens digit of hour
  display.display(1, hour % 10);       // Ones digit of hour
  display.display(2, (minute / 10) % 10); // Tens digit of minute
  display.display(3, minute % 10);       // Ones digit of minute
  display.set(:) = true;                 // Show colon between hours and minutes

  // Hourly chime with LED
  if (hour != lastHour) {
    for (int i = 0; i < hour; i++) { // Blink LED for each hour
      digitalWrite(LED, HIGH);
      delay(250);
      digitalWrite(LED, LOW);
      delay(250);
    }
    lastHour = hour; // Update last hour for comparison
  }

  delay(1000); // Update every second
}
