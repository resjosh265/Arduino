#include <Adafruit_NeoPixel.h>

#define LedPin 6
#define LedCount 25

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(LedCount, LedPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip1.begin();
  strip1.show();
}

void loop() {
  strip1.setBrightness(100);
  for(int i=0; i < 10; i++){
    if (i % 2 == 0){
      movingChunk(50, 255, 64, 0);
    }else{
      movingChunk(50, 140, 0, 255);
    }
  }
  
  for(int i=0; i < random(50, 100); i++){
    alternatePattern(500);
  }

    for(int i=0; i < 10; i++){
    if (i % 2 == 0){
      movingChunk(50, 255, 64, 0);
    }else{
      movingChunk(50, 140, 0, 255);
    }
  }

  for(int i=0; i < random(50, 100); i++){
    heartbeat(400);
  }
}

void alternatePattern(int waitTime){
  for(int i=0; i < LedCount; i++){
    if (i % 2 == 0){
      strip1.setPixelColor(i, 64, 255, 0); //GRB
    }else{
      strip1.setPixelColor(i, 0, 140, 255); //GRB
    }
  }
  strip1.show();
  delay(waitTime);

  for(int i=0; i < LedCount; i++){
    if (i % 2 == 0){
      strip1.setPixelColor(i, 0, 140, 255); //GRB
    }else{
      strip1.setPixelColor(i, 64, 255, 0); //GRB
    }
  }
  strip1.show();
  delay(waitTime);
}

void heartbeat(int waitTime){
  //must initiate lights by turning the brightness to at least 1
  strip1.setBrightness(1);
  strip1.show();
  
  for(int i=0; i < LedCount; i++){
    strip1.setPixelColor(i, 0, 150, 0); //GRB
  }

  for(int x=0; x < 2; x++){
      for(int i=1; i < 120; i++){
        strip1.setBrightness(i);
        strip1.show();
      }
    
      for(int i=120; i > 0; i--){
        strip1.setBrightness(i);
        strip1.show();
      }
  }

  strip1.setBrightness(0);
  strip1.show();
  delay(waitTime);
}

void movingChunk(int waitTime, int R, int G, int B){
  for(int x=0; x < 25; x++){
    strip1.clear();
    for(int i=0; i < 10; i++){
      strip1.setPixelColor(i + x, G, R, B); //GRB
    }
    strip1.show();
    delay(waitTime);
  }
   delay(waitTime * 10);  
}
