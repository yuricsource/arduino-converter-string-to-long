String phrase;

void setup() {

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

}

void loop() {

  while(Serial.available()) {
  
    phrase = Serial.readString();// read the incoming data as string
    int comma = phrase.indexOf(',');
    
    String first = phrase.substring(0,comma);
    String second = phrase.substring(comma+1);
    
    long lon, lat;
    lon = string_to_long(first);
    lat = string_to_long(second);
    
    
    Serial.println(" position : ");
    Serial.println( lat );
    Serial.println( lon );
   // Serial.println(" second: " + lat);
    
  }

}

long string_to_long (String number)
{
  number = number + ' ';
  char buf[number.length()];
  //Serial.println(number);
  number.toCharArray(buf,number.length());
  long result=atol(buf); 
  //Serial.println(result);
  return result;
}
