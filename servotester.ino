#include <Servo.h>
Servo myservo;
int pos = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial);  // wait until serial connects
  myservo.attach(9);
  
  Serial.println("calibrate servo pretest ...");
  
  for(pos = 0; pos <= 180; pos++)
  {
    myservo.write(pos);
    delay(15);
  }
  Serial.println("servo traversed ... ");
  
  myservo.write(0);
  delay(2000);
}

void loop()
{
  if (Seral.available() > 0)
  {
    Serial.print("\n Please enter an angle between 0 and 180: ");
    int state = Serial.parseInt();
    
    Serial.print("turning servo to ");
    Serial.print(state);
    Serial.println(" degrees");
    
    delay(100);
    myservo.write(state);
   }
}

// if you are interested in adding line endings and handling ascii please see
// http://forum.arduino.cc/index.php?topic=396450.msg2727728#msg2727728
