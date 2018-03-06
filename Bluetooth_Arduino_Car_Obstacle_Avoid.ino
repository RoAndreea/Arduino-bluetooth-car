#include <NewPing.h>

//RIGHT MOTOR
int Motor_A_Enable = 10;
int Motor_A_Reverse = 9;
int Motor_A_Forward = 8;   

//LEFT MOTOR  
int Motor_B_Enable = 5;
int Motor_B_Reverse = 6;
int Motor_B_Forward = 7;

//SENSOR 
const int trigger = 11;
const int echo = 12;

#define maximum_distance 200
boolean goesForward = false;
int distance;

NewPing sonar(11, 12, maximum_distance); //sensor function

int readPing() { 
  delay(50);
  int cm = sonar.ping_cm();
  if(cm==0) 
    cm = 250;
  return cm;
}

void setup() {
  Serial.begin(9600);
  
  pinMode(Motor_A_Enable, OUTPUT);
  pinMode(Motor_A_Forward, OUTPUT);
  pinMode(Motor_A_Reverse, OUTPUT);

  pinMode(Motor_B_Enable, OUTPUT);
  pinMode(Motor_B_Forward, OUTPUT);
  pinMode(Motor_B_Reverse, OUTPUT); 


}

void forward() {
  analogWrite(Motor_B_Enable, 100);
  analogWrite(Motor_A_Enable, 100);
  digitalWrite(Motor_A_Reverse, LOW);
  digitalWrite(Motor_B_Reverse, LOW);
  digitalWrite(Motor_A_Forward, HIGH);
  digitalWrite(Motor_B_Forward, HIGH); 
}

void reverse() {
  analogWrite(Motor_B_Enable, 100);
  analogWrite(Motor_A_Enable, 100);
  digitalWrite(Motor_A_Forward, LOW);
  digitalWrite(Motor_B_Forward, LOW);
  digitalWrite(Motor_A_Reverse, HIGH);
  digitalWrite(Motor_B_Reverse, HIGH);
}

void forwardLeft(){
  analogWrite(Motor_A_Enable, 100);
  analogWrite(Motor_B_Enable, 0);
  digitalWrite(Motor_A_Reverse, LOW);
  digitalWrite(Motor_A_Forward, HIGH);
}

void forwardRight(){
  analogWrite(Motor_B_Enable, 100);
  analogWrite(Motor_A_Enable, 0);
  digitalWrite(Motor_B_Reverse, LOW);
  digitalWrite(Motor_B_Forward, HIGH); 
}

void reverseLeft() {
  analogWrite(Motor_A_Enable, 100);
  analogWrite(Motor_B_Enable, 0);
  digitalWrite(Motor_A_Reverse, HIGH);
  digitalWrite(Motor_A_Forward, LOW);
}

void reverseRight() {
  analogWrite(Motor_B_Enable, 100);
  analogWrite(Motor_A_Enable, 0);
  digitalWrite(Motor_B_Reverse, HIGH);
  digitalWrite(Motor_B_Forward, LOW);
}


void loop() {
  distance = readPing();
  if (distance < 10) {
    reverse();
    goesForward = false;
    
        while (distance < 30) {
            distance = readPing();
        }
        goesForward = true;
        forwardRight();
  }

  if(Serial.available() > 0)
  {
    char data;
    data = Serial.read();
    Serial.write(Serial.read());

    switch (data)
    { 
      case '1': //FORWARD LEFT
        forwardLeft();
        break;        
      case '2': //FORWARD
        forward();
        break;
      case '3': //FORWARD RIGHT
        forwardRight();
        break;
      case '7': //REVERSE LEFT
        reverseLeft();
        break;
      case '8': //REVERSE
        reverse(); 
        break;
     
      case '9': //REVERSE RIGHT
        reverseRight();
        break;
      default: //If bluetooth module receives any value not listed above, both motors turn off
        analogWrite(Motor_A_Enable, 0);
        analogWrite(Motor_B_Enable, 0);
       
    }
  }
}
