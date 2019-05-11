unsigned long spintime, start, result, trip = 0;
unsigned int cycle = 0;
byte i, spin = 0;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop()
{
  if ( digitalRead(2) == LOW )
  {
    cycle = 100;
    spin = ( 180 +   random( 0 , 75 ) ) ;
    spintime = ( 1000 *   random( 1 , 10 ) ) ;
    start = millis() ;
    result = ( start + spintime ) ;
    trip = ( start + cycle ) ;
    Serial.print("start: ");
    Serial.print(start);
    Serial.print(" - end: ");
    Serial.print(result);
    Serial.print(" - speed: ");
    Serial.print(spin);
    Serial.print(" - spintime: ");
    Serial.print(spintime);
    analogWrite(3 , spin);
    
    while ( millis()  < result )
    {
      if (( ( millis() ) >= ( trip ) ))
      {
        i++;
        if (i == 8 )
        {
          cycle *= 2;
          i = 0;
        }
        
        trip = ( trip + cycle ) ;
        Serial.print(" - trip: ");
        Serial.print(trip);
        Serial.print(" - cycle: ");
        Serial.print(cycle);
        Serial.print(" - i: ");
        Serial.print(i);
        Serial.print(" ");
        spin -= 10;

        
        analogWrite( 9, bitRead(i,2)*255 ); //blue
        analogWrite( 6, bitRead(i,1)*255 ); //green
        analogWrite( 5, bitRead(i,0)*255 ); //red
        
        Serial.print(bitRead(i,2));
        Serial.print(bitRead(i,1));
        Serial.println(bitRead(i,0));

      }
    }
    Serial.print(" RESULT v TRIP?: ");
    Serial.print(result);
    Serial.print(" - v - : ");
    Serial.print(trip);
    Serial.print(" - f spin : ");
    Serial.print(spin);
    
      byte flash = i*5;
      for(byte j = 0; j<5 ; j++)
      {
        analogWrite( 9, 0 ); //blue
        analogWrite( 6, 0 ); //green
        analogWrite( 5, 0 ); //red
        delay(50);
        analogWrite( 9, bitRead(i,2)*255 ); //blue
        analogWrite( 6, bitRead(i,1)*255 ); //green
        analogWrite( 5, bitRead(i,0)*255 ); //red
        delay(50);
      }
      analogWrite(3, 0);
    
  }

}
