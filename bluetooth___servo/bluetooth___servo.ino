#include <Servo.h>

Servo myservo;  

int pos = 0;    

void setup() {
  myservo.attach(9); 
  Serial.begin(9600); 
}

void loop() {

  if(Serial.available())
{
  char i = Serial.read();

Serial.println(i);


    if(i == 'o')
      
  for (pos = 0; pos <= 180; pos += 1) { 
 
    myservo.write(pos);             
    delay(15); 
  }       

    if(i == 'c')
    
    for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);             
    delay(15);  
  }
}
}
