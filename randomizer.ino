int speed = 0 ;
int spintime = 0 ;

void setup()
{
  pinMode( 2 , INPUT);
  pinMode( 3 , OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if ( digitalRead(2) == HIGH )
  {
    speed = ( 150 + 	random( 0 , 100 ) ) ;
    spintime = ( 1000 * 	random( 1 , 10 ) ) ;
    Serial.print("speed: ");
    Serial.println(speed);
    Serial.print("spintime: ");
    Serial.println(spintime);
    analogWrite(3 , speed);
    delay( spintime );
  }
}

