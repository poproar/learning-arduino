//testing

/*****************
 * This is the main file. It is the first file called when putting all the tabbed files together.
 * Here we will call our libraries (only Servo for now), set up global variables and constants. 
 *****************/
#include <Servo.h>


// variables // these could be DEFINEd or set as CONSTants
int led = 7;
int button = 2;
int buzzer = 5;
int left = 9;
int right = 11;

// class objects from our library
Servo leftMotor;
Servo rightMotor;

int distance = 0;

// pins set as const
const byte trig = 3;
const byte echo = 4;


void bleep(int times = 2, int per = 100, int freq = 440)
{
  for (int i = 0; i < times; i++)
  {
    digitalWrite(led, HIGH);
    tone(buzzer, freq);
    delay(per);
    digitalWrite(led, LOW);
    noTone(buzzer);
    delay(per);
  }
}
void forward(int t =10)
{
  leftMotor.write(0);
  rightMotor.write(180);
  delay(t);
}

void backward(int t =10)
{
  leftMotor.write(180);
  rightMotor.write(0);
  delay(t);
}

void turnright(int t =10)
{
  leftMotor.write(90);
  rightMotor.write(180);
  delay(t);
}

void turnleft(int t =10)
{
  leftMotor.write(0);
  rightMotor.write(90);
  delay(t);
}

void allstop(int t =10)
{
  leftMotor.write(90);
  rightMotor.write(90);
  delay(t);
}

void square()
{
  //first forward
  forward();
  delay(8020);
  allstop();
  delay(2000);

  //first turn
  turnright();
  delay(1782);
  allstop();
  delay(2000);

  //second forward
  forward();
  delay(5100);
  allstop();
  delay(2000);

  //second turn
  turnright();
  delay(1780);
  allstop();
  delay(2000);

  //third forward
  forward();
  delay(8200);
  allstop();
  delay(2000);

  //third turn
  turnright();
  delay(1785);
  allstop();
  delay(2000);

  //finish forward
  forward();
  delay(5000);
}

void test1()
{
  distance = ultrasonic();
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}

void test2()
{
  distance = ultrasonic();
  digitalWrite(led, HIGH);
  delay(distance * 10);
  digitalWrite(led, LOW);
  delay(distance * 10);
}

void test3()
{
  forward();
  test1();
}
void test4()
{
  distance = ultrasonic();
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 20 && distance > 0)
  {
    allstop();
  }
  else
  {
    forward();
  }
}

void test5()
{
  Serial.println("disconnect and test with battery");
  test4();
}

// function for ultrasonic returns the distance in cm
int ultrasonic()
{
  long duration;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  // send out trigger signal
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);

  // wait for a pulse on the echo pin
  duration = pulseIn(echo, HIGH);

  // take the pulse and scale it to cm
  duration = duration / 59;
  // equivalent to ((duration * 343) * 100) / (2 * 1000000); == / 58.3090

  // if duration is less than two or greater than 300, something is wrong.  Return an error.
  if ((duration < 2) || (duration > 300) )
  {
    return false;
  }
  
  return duration;
}

void setup() {
  // put your setup code here, to run once:
 leftMotor.attach(left);
  rightMotor.attach(right);

  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);


  //done 04.05.2019 for sensor
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.println("Hello all!");
  // int count;
  // count==1;      // == (2=) is comparison = (1=) is set. this line reads as FALSE 
  // int count = 1; // might be what you are looking for but will NOT carry over to loop
                    // to carry into loop use this in the main (first) file with the other
                    // variables
  while(digitalRead(button)!= LOW)
  {
    // wait til button pressed
    continue;
  }
  bleep(2, 500);
  bleep(1, 1000, 880);
}

void loop() {
  // put your main code here, to run repeatedly:
 leftMotor.attach(left);
  rightMotor.attach(right);

  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);


  //done 04.05.2019 for sensor
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.println("Hello all!");
  // int count;
  // count==1;      // == (2=) is comparison = (1=) is set. this line reads as FALSE 
  // int count = 1; // might be what you are looking for but will NOT carry over to loop
                    // to carry into loop use this in the main (first) file with the other
                    // variables
  while(digitalRead(button)!= LOW)
  {
    // wait til button pressed
    continue;
  }
  bleep(2, 500);
  bleep(1, 1000, 880);
}
