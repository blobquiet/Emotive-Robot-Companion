#include <Otto.h>
Otto Otto;
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
Adafruit_8x16matrix ematrix = Adafruit_8x16matrix();

int emotion = -1;

#define LeftLeg 2 // left leg pin, servo[0]
#define RightLeg 3 // right leg pin, servo[1]
#define LeftFoot 4 // left foot pin, servo[2]
#define RightFoot 5 // right foot pin, servo[3]
#define Buzzer 13 //buzzer pin

static const uint8_t PROGMEM
logo_bmp[] = {  B01111110, B10000001, B10111001, B10101001, B10111001, B10010001, B10111001, B10010001, B10010001, B10111001, B10010001, B10111001, B10101001, B10111001, B10000001, B01111110},
             happy_bmp[] = {  B00000000, B00111100, B00000010, B00000010, B00000010, B00000010, B00111100, B00000000, B00000000, B00111100, B00000010, B00000010, B00000010, B00000010, B00111100, B00000000},
                           eyes_bmp[] = {  B00000000, B00111100, B01000010, B01001010, B01000010, B01000010, B00111100, B00000000, B00000000, B00111100, B01000010, B01001010, B01000010, B01000010, B00111100, B00000000},
                                        sad_bmp[] =  {  B00000000, B00010000, B00010000, B00010000, B00010000, B00010000, B00010000, B00000000, B00000000, B00010000, B00010000, B00010000, B00010000, B00010000, B00010000, B00000000},
                                            xx_bmp[] =  {  B00000000, B00100010, B00010100, B00001000, B00010100, B00100010, B00000000, B00000000, B00000000, B00000000, B00100010, B00010100, B00001000, B00010100, B00100010, B00000000},
                                                XX_bmp[] = {  B01000001, B00100010, B00010100, B00001000, B00010100, B00100010, B01000001, B00000000, B00000000, B01000001, B00100010, B00010100, B00001000, B00010100, B00100010, B01000001},
                                                    angry_bmp[] = {  B00000000, B00011110, B00111100, B01111000, B01110000, B00100000, B00000000, B00000000, B00000000, B00000000, B00100000, B01110000, B01111000, B00111100, B00011110, B00000000},
                                                        angry2_bmp[] = {  B00000000, B00000010, B00000100, B00001000, B00010000, B00100000, B00000000, B00000000, B00000000, B00000000, B00100000, B00010000, B00001000, B00000100, B00000010, B00000000},
                                                            sleep_bmp[] = {  B00000000, B00100010, B00110010, B00101010, B00100110, B00100010, B00000000, B00000000, B00000000, B00000000, B00100010, B00110010, B00101010, B00100110, B00100010, B00000000},
                                                                freetful_bmp[] = {  B00000000, B00100000, B00010000, B00001000, B00000100, B00000010, B00000000, B00000000, B00000000, B00000000, B00000010, B00000100, B00001000, B00010000, B00100000, B00000000},
                                                                    love_bmp[] = {  B00000000, B00001100, B00011110, B00111100, B00111100, B00011110, B00001100, B00000000, B00000000, B00001100, B00011110, B00111100, B00111100, B00011110, B00001100, B00000000},
                                                                        confused_bmp[] = {  B00000000, B01111100, B10000010, B10111010, B10101010, B10001010, B01111000, B00000000, B00000000, B01111100, B10000010, B10111010, B10101010, B10001010, B01111000, B00000000},
                                                                            wave_bmp[] = {  B00000000, B00100000, B00010000, B00001000, B00010000, B00100000, B00010000, B00000000, B00000000, B00100000, B00010000, B00001000, B00010000, B00100000, B00010000, B00000000},
                                                                                magic_bmp[] = {  B00000000, B00000000, B01111110, B11111111, B01111110, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B01111110, B11111111, B01111110, B00000000, B00000000},
                                                                                    fail_bmp[] = {  B00000000, B00110000, B01111000, B01111000, B01111100, B00111100, B00001000, B00000000, B00000000, B00001000, B00111100, B01111100, B01111000, B01111000, B00110000, B00000000},
                                                                                        full_bmp[] =  {   B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111 };

void setup() {
  Serial.begin(9600);
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  Otto.home();

  ematrix.begin(0x70);  // pass in the address

  pinMode(A0, INPUT);
  ematrix.setBrightness(15);//the brightness of the LEDs use values from 0 to 15 only
  ematrix.clear();
  ematrix.drawBitmap(0, 0, + eyes_bmp , 8, 16, 1);
  ematrix.writeDisplay();
  delay(1 * 1000);

}

void loop() {
  if (digitalRead(A0)) {
    emotion = emotion + 1;
  }
  char e = Serial.read();
  if (emotion == 0 || e == '0') {  // Angry
    if (emotion == 0)
      emotion = emotion + 1;
    long r = random(0, 100);
    ematrix.clear();
    if ( r > 50) {
      ematrix.drawBitmap(0, 0, + angry_bmp, 8, 16, 1);
      ematrix.writeDisplay();
    }
    else if ( r <= 50) {
      ematrix.drawBitmap(0, 0, + angry2_bmp, 8, 16, 1);
      ematrix.writeDisplay();
    }
    Otto.playGesture(OttoAngry);
    ematrix.clear();
    ematrix.drawBitmap(0, 0, + eyes_bmp, 8, 16, 1);
    ematrix.writeDisplay();
  }
  else if (emotion == 2 || e == '1') {  // DANCE
    if (emotion == 2)
      emotion = emotion + 1;
    long r = random(0, 100);
    ematrix.clear();
    ematrix.drawBitmap(0, 0, + happy_bmp, 8, 16, 1);
    ematrix.writeDisplay();
    Otto.moonwalker(1, 1000, 25, 1);
    Otto.moonwalker(1, 1000, 25, -1);
    Otto.crusaito(1, 1000, 25, 1);
    Otto.crusaito(1, 1000, 25, -1);
    Otto.flapping(1, 1000, 25, 1);
    Otto.flapping(1, 1000, 25, -1);
    ematrix.clear();
    ematrix.drawBitmap(0, 0, + eyes_bmp, 8, 16, 1);
    ematrix.writeDisplay();
  }
  //  if (emotion == 3 || e == '3') {
  //    Otto.walk(4, 1000, 1); // FORWARD
  //  }
  else if (emotion == 4 || e == '2') { //HAPPY
    if (emotion == 4)
      emotion = emotion + 1;
    long r = random(0, 100);
    ematrix.clear();
    ematrix.drawBitmap(0, 0, + happy_bmp, 8, 16, 1);
    ematrix.writeDisplay();
    if ( r > 50) {
      Otto.playGesture(OttoHappy);
    }
    else if ( r <= 50) {
      Otto.playGesture(OttoSuperHappy);
    }
    ematrix.clear();
    ematrix.drawBitmap(0, 0, + eyes_bmp, 8, 16, 1);
    ematrix.writeDisplay();
  }
  if (emotion == 6 || e == '3') { //LOVE
    if (emotion == 6)
      emotion = emotion + 1;
    long r = random(0, 100);
    ematrix.clear();
    ematrix.drawBitmap(0, 0, + love_bmp, 8, 16, 1);
    ematrix.writeDisplay();
    Otto.playGesture(OttoLove);
    ematrix.clear();
    ematrix.drawBitmap(0, 0, + eyes_bmp, 8, 16, 1);
    ematrix.writeDisplay();
  }
  if (emotion == 8 || e == '5') { //SAD
    if (emotion == 8)
      emotion = emotion + 1;
    long r = random(0, 100);
    ematrix.clear();
    if ( r > 50) {
      ematrix.drawBitmap(0, 0, + sad_bmp, 8, 16, 1);
      ematrix.writeDisplay();
    }
    else if ( r <= 50) {
      ematrix.drawBitmap(0, 0, + fail_bmp, 8, 16, 1);
      ematrix.writeDisplay();
    }
    Otto.playGesture(OttoSad);
    ematrix.clear();
    ematrix.drawBitmap(0, 0, + eyes_bmp, 8, 16, 1);
    ematrix.writeDisplay();
  }
  if ( emotion == 9) {
    emotion = -1;
  }
}
