#include <Servo.h> 

int minDelay = 500;
int maxDelay = 2000;

int minAngle = 30;
int maxAngle = 140;

int servoPin1 = 2; 
int servoPin2 = 3;
int servoPin3 = 4;
int servoPin4 = 5;
int servoPin5 = 6;
int servoPin6 = 7;
int resetServoPin = 13;

Servo Servo1; 
Servo Servo2; 
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;
Servo ResetServo;

void setup() { 
   Servo1.attach(servoPin1); 
   Servo2.attach(servoPin2); 
   Servo3.attach(servoPin3); 
   Servo4.attach(servoPin4); 
   Servo5.attach(servoPin5); 
   Servo6.attach(servoPin6); 
   ResetServo.attach(resetServoPin); 
}
void loop(){ 
  moveEyeball1();
  moveEyeball2();
  moveEyeball3();
  moveEyeball4();
  moveEyeball5();
  moveEyeball6();

  ResetServo.write(90);
}

void moveEyeball1(){
  Servo1.write(random(minAngle, maxAngle)); 
  delay(random(minDelay, maxDelay)); 
}

void moveEyeball2(){
  Servo2.write(random(minAngle, maxAngle)); 
  delay(random(minDelay, maxDelay)); 
}

void moveEyeball3(){
  Servo3.write(random(minAngle, maxAngle)); 
  delay(random(minDelay, maxDelay)); 
}

void moveEyeball4(){
  Servo4.write(random(minAngle, maxAngle)); 
  delay(random(minDelay, maxDelay)); 
}

void moveEyeball5(){
  Servo5.write(random(minAngle, maxAngle)); 
  delay(random(minDelay, maxDelay)); 
}

void moveEyeball6(){
  Servo6.write(random(minAngle, maxAngle)); 
  delay(random(minDelay, maxDelay)); 
}
