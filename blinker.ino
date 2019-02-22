// modified from http://www.arduino.cc/en/Tutorial/Blink

void blinker(int t);  // subroutine prototype created for demonstration 
// the setup function runs once when you press reset or power the board

void setup()
{
  pinMode(7, OUTPUT); // initialize digital pin LED_BUILTIN as an output.
}

void loop()
{
  blinker(100);
}

void blinker(int t)
{
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);
  
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(t);
}
