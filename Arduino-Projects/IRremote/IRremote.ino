#include <IRremote.h>

int RECV_PIN = 5;

int	    ledrd = 12;
int	    ledbl = 11;
int     ledgr = 10;

boolean	status;

IRrecv irrecv(RECV_PIN);
decode_results res;

void setup()
{
  pinMode(ledrd, OUTPUT);
  pinMode(ledbl, OUTPUT);
  pinMode(ledgr, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  status = 1;
}

void loop()
{
  if (irrecv.decode(&res))
    {
      if (res.value == 0xFD08F7)
      {
        clrall();
        digitalWrite(ledrd, 1);
        Serial.print("Only Red led is ON\n");
      }

      if (res.value == 0xFD8877)
      {
        clrall();
        digitalWrite(ledbl, 1);
        Serial.print("Only Blue led is ON\n");
      }

      if (res.value == 0xFD48B7)
      {
        clrall();
        digitalWrite(ledgr, 1);
        Serial.print("Only Green led is ON\n");
      }
    
      if (res.value == 0xFD00FF)
      {
        fill(!status);
       	Serial.print("All Leds are :");
		if (status)
        	Serial.print(" ON\n");
        else
        	Serial.print(" OFF \n");

        status = !status;
      }

      //Serial.println(res.value, HEX);
      irrecv.resume(); // Receive the next value  
  }
}

void	clrall()
{
    digitalWrite(ledrd, 0);
    digitalWrite(ledbl, 0);
    digitalWrite(ledgr, 0);
}

void	fill(boolean status)
{
    digitalWrite(ledrd, !status);
    digitalWrite(ledbl, !status);
    digitalWrite(ledgr, !status);
}