#include <Keypad.h>


const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad
char mdp[4] = {0, 0, 0, 0}; //connect to the column pinouts of the keypad
String pwd = "1234";
int counter = 0;
String userPWD = "";
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
}
void processLogin() {
  char key = keypad.getKey();
  while (key != '#') {
    Serial.println(key);
    userPWD += key;
    key = keypad.getKey();
  }
}

bool verifLogin() {
  return userPWD.equals(pwd);
}
void loop() {
  char key = keypad.getKey();
      Serial.println(key);

  if (key == '*') {
    processLogin();
    bool isCorrect = verifLogin();
    String msg = isCorrect ? "PWD OK !" : "PWD NOT OK, try again";
        Serial.println("moh");

    Serial.println(msg);
    userPWD = "";
    delay(1000);
  }
}

//
//  if (key) {
//    Serial.print(key);
//    mdp[counter] = key;
//    counter++;
//  }
//  if (counter == 6) {
//    if (mdp[0] == '*' && mdp[1] == '4' && mdp[2] == '4' && mdp[3] == '4' && mdp[4] == '4' && mdp[5] == '#')
//      Serial.print("correct");
//
//    else
//      Serial.print("Incorrect");
//  }

/*if(counter==4)
  {
  Serial.print(mdp[0]);
  Serial.print(mdp[1]);
  Serial.print(mdp[2]);
  Serial.print(mdp[3]);

  if(mdp[0]=='4' && mdp[1]=='4' && mdp[2]=='4' && mdp[3]== '4')
       Serial.print("correct");

  else
  Serial.print("Incorrect");
  counter=0;
  Serial.println();
  }

  if (key){
  Serial.print(key);
  mdp[counter]=key;
  counter++;
  }

*/
