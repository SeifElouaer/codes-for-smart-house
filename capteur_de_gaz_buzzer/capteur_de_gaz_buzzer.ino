
const int mqxPin = A0;  // La sortie analogique du détecteur MQx est reliée au Pin analogique A0 de l'Arduino
const int buzzer = 8; 

void setup()
{
    Serial.begin(9600); // Initialise le port série à 9600 bps // 
      pinMode(buzzer, OUTPUT); 

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
}
