#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>
#include <Time.h>
#include <Wire.h>
#include <LowPower_Teensy3.h>

#define SCK 13
#define MOSI 11
#define SS 10

Adafruit_SharpMem display(SCK, MOSI, SS);
TEENSY3_LP LP = TEENSY3_LP();

#define BLACK 0
#define WHITE 1

byte buf[1152];

void setup() {
  setSyncProvider(getTeensy3Time);
  Serial.begin(9600);
  pinMode(14, OUTPUT);
  digitalWrite(14, HIGH);
  display.begin();
  display.clearDisplay();
  delay(500);
  
  Serial.println("herro");
  delay(500);
  while(!Serial.available());
  
  if (Serial.available()) {
    time_t t = processSyncMessage();
    if (t != 0) {
      Teensy3Clock.set(t);   // set the RTC and the system time to the received value
      setTime(t);
    }
  }
}

void loop() {
  basicdigital();
  LP.DeepSleep(LPTMR_W, 933);
  setSyncProvider(getTeensy3Time);
  
  /*for(int i = 0; i < 1152; i++) {
    buf[i] = ~display.screenShot(1151-i);
  }
  for(int i = 0; i < 96; i += 4) {
    display.fillScreen(WHITE);
    display.setRotation(0);
    display.drawBitmap(i, 0, buf, 96, 96, BLACK);
    display.refresh();
    display.setRotation(2);
  }*/
  
}
