
int keyIn = 0;                        //Variable for keypad input
int	keyVals[16] = {1023, 511, 341, 256, 207, 172, 147, 129, 115, 104, 94, 86, 80, 74, 69, 65}; // Replace those values with yours
int	prec = 1; // precision variable +/- 
char	keys[16] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'}; // Character's values

void setup()
{
	Serial.begin(9600);
}

void loop()
{  
  int	index = -1;
  keyIn =  analogRead(A0);      //Read in keypad input
  String str = "";             //Create a variable to store the key character
  while (++index < 16)     //Run through the array of key values
    if (keyIn >= keyVals[index]-prec && keyIn <= keyVals[index]+prec)   //If the measured value is in the range of one key
      str = keys[index];     //Set str equal to the character for that key
  Serial.print("Key: ");
  Serial.println(str);             //Display key character on the Serial
  delay(50);  
}