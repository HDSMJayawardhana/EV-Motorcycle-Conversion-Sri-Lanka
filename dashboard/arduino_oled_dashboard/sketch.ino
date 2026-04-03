#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pins
const int modeSwitchPin = 2;     // Button pin
const int voltagePin = A0;       // Simulated battery voltage input
const int tempPin = A1;          // Simulated temperature sensor

// Variables
bool evMode = false;             // false = ECO, true = SPORT
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 300; // ms

void setup() {
  pinMode(modeSwitchPin, INPUT_PULLUP); // Internal pull-up for button
  pinMode(voltagePin, INPUT);
  pinMode(tempPin, INPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.println("CT100 EV Starting...");
  display.display();
  delay(2000);
}

void loop() {
  // Read button with debounce
  if (digitalRead(modeSwitchPin) == LOW && millis() - lastDebounceTime > debounceDelay) {
    evMode = !evMode;
    lastDebounceTime = millis();
  }

  // Simulated or real readings
  float voltage = analogRead(voltagePin) * (5.0 / 1023.0) * (12.0 / 5.0); // Assume voltage divider
  float tempC = analogRead(tempPin) * (5.0 / 1023.0) * 100; // LM35 or simulation
  float speed = evMode ? 65 : 45; // Simulated speed based on mode

  // Display info
  display.clearDisplay();

  //display.setTextSize(1);
  //display.setCursor(0, 0);
  //display.println("CT100 EV DASH");

  display.setCursor(0, 12);
  display.print("Voltage: ");
  display.print(voltage, 1);
  display.println(" V");

  display.setCursor(0, 22);
  display.print("Temp: ");
  display.print(tempC, 1);
  display.println(" C");

  display.setCursor(0, 32);
  display.print("Speed: ");
  display.print(speed, 0);
  display.println(" km/h");

  display.setCursor(0, 42);
  display.print("Mode: ");
  display.println(evMode ? "SPORT" : "ECO");

  display.setCursor(0, 52);
  display.print("H.D.S.M. Jayawardhana");

  //display.setCursor(0, 60);
  //display.print("UoP");  // University of Peradeniya

  display.display();

  delay(200); // Update delay
}
