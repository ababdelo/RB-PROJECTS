int ldr = A3;
int	led = 10;

void setup()
{
  pinMode(led, OUTPUT);
	pinMode(ldr, INPUT);
	Serial.begin(9600);
}

void loop()
{
  int ldrval = analogRead(ldr);
	
    if (ldrval <= 500)
    {
      digitalWrite(led, HIGH);
      Serial.print("Darkness over here,turn on the LED :");
    }
  	else
    {
      digitalWrite(led, LOW);
      Serial.print("There is sufficient light , turn off the LED : ");;
    }
  	Serial.println(ldrval);
}