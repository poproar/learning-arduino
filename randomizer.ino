int speed = 0 ;
int spintime = 0 ;
int start = 0 ;
int end = 0 ;
int trip = 0 ;
int cycle = 100;
bool led= false ;

void setup()
{
  pinMode( 2 , INPUT);
  pinMode( 3 , OUTPUT);
  Serial.begin(9600);
  pinMode( 7 , OUTPUT);
}

void loop()
{
  if ( digitalRead(2) == HIGH )
  {
    speed = ( 150 + 	random( 0 , 100 ) ) ;
    spintime = ( 1000 * 	random( 1 , 10 ) ) ;
    start = millis() ;
    end = ( start + spintime ) ;
    trip = ( start + cycle ) ;
    Serial.print("speed: ");
    Serial.println(speed);
    Serial.print("spintime: ");
    Serial.println(spintime);
    analogWrite(3 , speed);
    
    while ( millis()  < end )
    {
      if (( ( millis() ) >= ( trip ) ))
      {
        trip = ( trip + cycle ) ;
        led = !led ;
        speed -= 10;
        digitalWrite( 7 , led );
        analogWrite(3 , speed);
      }
    }
  }
  digitalWrite( 7, LOW );
  analogWrite(3, 0);
}
