// Including the required Arduino libraries
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Uncomment according to your hardware type
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins
#define MAX_DEVICES 4
#define CS_PIN 3

// Create a new instance of the MD_Parola class with hardware SPI connection
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  // Intialize the object
  myDisplay.begin();

  // Set the intensity (brightness) of the display (0-15)
  myDisplay.setIntensity(0);

  // Clear the display
  myDisplay.displayClear();
}

void loop() {
  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("Left");
  delay(2000);
  
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.print("Center");
  delay(2000);

  myDisplay.setTextAlignment(PA_RIGHT);
  myDisplay.print("Right");
  delay(2000);

  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setInvert(true);
  myDisplay.print("Invert");
  delay(2000);
}
