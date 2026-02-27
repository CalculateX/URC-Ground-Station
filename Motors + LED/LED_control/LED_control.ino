#include <Adafruit_NeoPixel.h>

#define LED_COUNT  1
#define PIN_A      6
#define PIN_B      9
#define BAUD_RATE  9600

// Define two separate instances for each pin
Adafruit_NeoPixel stripA(LED_COUNT, PIN_A, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripB(LED_COUNT, PIN_B, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(BAUD_RATE);
  
  stripA.begin();
  stripB.begin();
  
  // Initialize both to OFF
  setBothColors(0, 0, 0);
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    
    // Clear the buffer to prevent lag if multiple commands pile up
    while(Serial.available() > 0) Serial.read();

    switch (cmd) {
      case 'R': // Red (Warning)
        setBothColors(255, 0, 0);
        break;
      case 'G': // Green (Safe)
        setBothColors(0, 255, 0);
        break;
      case 'B': // Blue (Auto)
        setBothColors(0, 0, 255);
        break;
      case 'O': // Off
        setBothColors(0, 0, 0);
        break;
    }
  }
}

// Helper function to update both LEDs at the same time
void setBothColors(int g, int r, int b) {
  // Set Strip A
  stripA.setPixelColor(0, stripA.Color(r, g, b));
  stripA.show();
  
  // Set Strip B
  stripB.setPixelColor(0, stripB.Color(r, g, b));
  stripB.show();
}