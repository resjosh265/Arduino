#include <Servo.h> 
#include <Adafruit_NeoPixel.h>

int minDelay = 500;
int maxDelay = 5000;

int minAngle = 30;
int maxAngle = 140;

int servoPin1 = 2; 
int servoPin2 = 3;
int servoPin3 = 4;
int servoPin4 = 5;
int servoPin5 = 6;
int servoPin6 = 7;
int resetServoPin = 13;

unsigned long servoStart1;
unsigned long servoStart2;
unsigned long servoStart3;
unsigned long servoStart4;
unsigned long servoStart5;
unsigned long servoStart6;

int servoWait1 = 0;
int servoWait2 = 0;
int servoWait3 = 0;
int servoWait4 = 0;
int servoWait5 = 0;
int servoWait6 = 0;

Servo Servo1; 
Servo Servo2; 
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;
Servo ResetServo;

//Neopixels
#define LedPin 9
#define LedCount 25
Adafruit_NeoPixel lightStrip = Adafruit_NeoPixel(LedCount, LedPin, NEO_GRB + NEO_KHZ800);

void setup() { 
   lightStrip.begin();
   lightStrip.setPixelColor(1, 0, 255, 0); //GRB
   lightStrip.show();
   lightStrip.setBrightness(255);
  
   Servo1.attach(servoPin1); 
   Servo2.attach(servoPin2); 
   Servo3.attach(servoPin3); 
   Servo4.attach(servoPin4); 
   Servo5.attach(servoPin5); 
   Servo6.attach(servoPin6); 
   ResetServo.attach(resetServoPin); 

   servoStart1 = millis();
}
void loop(){ 
  moveEyeball1(millis());
  moveEyeball2(millis());
  moveEyeball3(millis());
  moveEyeball4(millis());
  moveEyeball5(millis());
  moveEyeball6(millis());

  lightController();

  ResetServo.write(90);
}

void moveEyeball1(unsigned long currentTime){

  if (currentTime >= servoStart1 + servoWait1){
    Servo1.write(random(minAngle, maxAngle)); 
    servoWait1 = random(minDelay, maxDelay);
    servoStart1 = millis();
  }
}

void moveEyeball2(unsigned long currentTime){

  if (currentTime >= servoStart2 + servoWait2){
    Servo2.write(random(minAngle, maxAngle)); 
    servoWait2 = random(minDelay, maxDelay);
    servoStart2 = millis();
  }
}

void moveEyeball3(unsigned long currentTime){

  if (currentTime >= servoStart3 + servoWait3){
    Servo3.write(random(minAngle, maxAngle)); 
    servoWait3 = random(minDelay, maxDelay);
    servoStart3 = millis();
  }
}

void moveEyeball4(unsigned long currentTime){

  if (currentTime >= servoStart4 + servoWait4){
    Servo4.write(random(minAngle, maxAngle)); 
    servoWait4 = random(minDelay, maxDelay);
    servoStart4 = millis();
  }
}

void moveEyeball5(unsigned long currentTime){

  if (currentTime >= servoStart5 + servoWait5){
    Servo5.write(random(minAngle, maxAngle)); 
    servoWait5 = random(minDelay, maxDelay);
    servoStart5 = millis();
  }
}

void moveEyeball6(unsigned long currentTime){

  if (currentTime >= servoStart6 + servoWait6){
    Servo6.write(random(minAngle, maxAngle)); 
    servoWait6 = random(minDelay, maxDelay);
    servoStart6 = millis();
  }
}

void lightController(){
  for(int i=0; i < LedCount; i++){
    lightStrip.setPixelColor(i, 0, 255, 0); //GRB
  }
  lightStrip.show();
}
