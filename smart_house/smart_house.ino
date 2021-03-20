#include <Servo.h>

Servo myservo;  

int pos = 0;    

const int mqxPin = A0;  
const int buzzer = 8;

 
void setup()
{
   Serial.begin(9600);
   pinMode(buzzer, OUTPUT);
   myservo.attach(9);  
}

void loop()
{
   if(analogRead(mqxPin) > 190){
        tone(buzzer, 1000); 
        delay(1000);        
        noTone(buzzer);    
        delay(250);  
    }
    else{
    noTone(buzzer);
    }
  
    Serial.println(analogRead(mqxPin));
    delay(1000); 
          
//////////////////

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
