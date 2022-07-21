//Motor connections
int enA = 9;
int in1 = 8;
int in2 = 7;
#include<Servo.h>
Servo Myservo;
void setup() {
  intialize_motor();
  
}

void loop() {
   for(int i=0;i<50;i=i+10){
    motorcontrol(1,i);
    delay(1000);
  }
  Left(25);
  for(int i=0;i<50;i=i+10){
    motorcontrol(0,i);
    delay(1000);
  }
  Right(25);
  Serial.print(78);
}

//MOTOR CODE
void intialize_motor(){
  //setting the output pins for motor driver
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT); 

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
//Use dir==1 for in1 high and 0 for opposite
//Speed will varry from  0 to 50
void motorcontrol(int dir,int spid){
  if(dir==1){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
  }
  if (dir==0){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
  }
  int temp=map(spid,0,50,0,255);
  analogWrite(enA, temp);
}
void motorstop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
// MOTOR CODE ended

//Steering Code
void Servo_init(){
    Myservo.attach(3);
    Myservo.write(90);
}
void Right(int angle){
    Myservo.write(90-angle);
}
void Left(int angle){
    Myservo.write(90+angle);
}
