
/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range and display it to the lcd.
  To do this, it sends a pulse to the sensor to initiate a
  reading, then listens for a pulse to return.  The length of
  the returning pulse is proportional to the distance of the 
  object from the sensor.

  The circuit for ultrason sensor:
   * +V connection of the PING))) attached to +5V
   
   * GND connection attached to ground
   
   * Trig connection attached to digital pin 7
   
   * Echo connection attached to digital pin 8

GND-> ground

VCC-> +5V

SDA-> A4

SCL-> A5

*/

#include LiquidCrystal_I2C.h

#include Wire.h

long readUltrasonicDistance(int triggerPin, int echoPin);

void setup()
{
  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();}

void loop()
{  
  float  distcm = 0;
  float distin = 0;
  int dur = readUltrasonicDistance(7, 8
  float soundspeed = 0.034; //centimeter/microsecond
  
  lcd.clear();
  
  // measure the ping time in cm
  distcm = (soundspeed * dur) / 2;
  // convert to inches by dividing by 2.54
  distin = (distcm / 2.54);
  
  lcd.setCursor(0,1);
  lcd.print("Inche: ");
  lcd.print(distin);
  
  lcd.setCursor(0,0);
  lcd.print("Cmeter: ");
  lcd.print(distcm);
  delay(50); // Wait for 100 millisecond(s)
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  int duration = 0;
  
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW); // Clear the trigger
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  return (duration);
}
