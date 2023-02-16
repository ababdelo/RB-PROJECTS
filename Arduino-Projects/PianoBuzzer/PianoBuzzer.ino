int buzzer = 8;

int btn0 = A0;
int btn1 = A1;
int btn2 = A2;
int btn3 = A3;
int btn4 = A4;
int btn5 = A5;

void setup()
{
  pinMode(buzzer, OUTPUT);
  
  pinMode(btn0, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
}

void loop()
{
  // if button press on A0 is detected
  if (digitalRead(btn0) == HIGH) {
    tone(buzzer, 229, 100);
  }
  // if button press on A1 is detected
  if (digitalRead(btn1) == HIGH) {
    tone(buzzer, 362, 100);
  }
  // if button press on A2 is detected
  if (digitalRead(btn2) == HIGH) {
    tone(buzzer, 399, 100);
  }
  // if button press on A3 is detected
  if (digitalRead(btn3) == HIGH) {
    tone(buzzer, 440, 100);
  }
  // if button press on A4 is detected
  if (digitalRead(btn4) == HIGH) {
    tone(buzzer, 494, 100);
  }
  // if button press on A5 is detected
  if (digitalRead(btn5) == HIGH) {
    tone(buzzer, 523, 100);
  }
  delay(50); // Delay a little bit to improve simulation performance
}