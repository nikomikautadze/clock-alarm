#include <LiquidCrystal.h>
#include "virtuabotixRTC.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int configAlarmPin = 6;
const int incrementTimePin = 7;
const int changeCurrentPin = 8;

#define DS1302_CLK_PIN A5
#define DS1302_DAT_PIN A4
#define DS1302_RST_PIN 13

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


bool configAlarm = false;
bool buzzerToggle = false;

int currentSelection = 0;


int lastSecond = -1;

#define BUZZER 9
 



 
int HOUR = 0;
int MINUTE = 0;
int SECOND = 0;

virtuabotixRTC RTC(DS1302_CLK_PIN, DS1302_DAT_PIN, DS1302_RST_PIN);


void setup() {
  Serial.begin(115200);

  lcd.begin(16,2);


  pinMode(BUZZER, OUTPUT);

  pinMode(configAlarmPin, INPUT_PULLUP);
  pinMode(changeCurrentPin, INPUT_PULLUP);
  pinMode(incrementTimePin, INPUT_PULLUP);
 
}

void loop() {
 
  RTC.updateTime();
 
  lcd.setCursor(0,0);

  if (RTC.seconds != lastSecond) {
   
    lastSecond = RTC.seconds;

    lcd.setCursor(0,0);

    if(RTC.hours < 10) lcd.print("0");
    lcd.print(RTC.hours);
    lcd.print(":");

    if(RTC.minutes < 10) lcd.print("0");
    lcd.print(RTC.minutes);
    lcd.print(":");

    if(RTC.seconds < 10) lcd.print("0");
    lcd.print(RTC.seconds);


    lcd.setCursor(3,2);
    lcd.print("SET: ");

    if(HOUR < 10) lcd.print("0");
    lcd.print(HOUR);
    lcd.print(":");

    if(MINUTE < 10) lcd.print("0");
    lcd.print(MINUTE);
    lcd.print(":");
 
    if(SECOND < 10) lcd.print("0");
    lcd.print(SECOND);
  }

  if(RTC.hours == HOUR and RTC.minutes == MINUTE and RTC.seconds == SECOND) buzzerToggle=true;

  if(buzzerToggle){
    tone(BUZZER, 85);
    delay(100);
    noTone(BUZZER);
    delay(100);
  }

  int configAlarmState = digitalRead(configAlarmPin);
  if(configAlarmState == LOW){
    configAlarm = !configAlarm;
    currentSelection = 0;
    delay(200);
  }

  int incrementTimeState = digitalRead(incrementTimePin);
  if(incrementTimeState == LOW){
    if(buzzerToggle==true) {
      buzzerToggle=false;
      configAlarm=false;
    }
    if(configAlarm == true){
      switch (currentSelection) {
        case 0:
          if(HOUR==23) HOUR = 0;
          else HOUR++;
          break;
        case 1:
          if(MINUTE==59) MINUTE = 0;
          else MINUTE++;
          break;
        case 2:
          if(SECOND==59) SECOND = 0;
          else SECOND++;
          break;    
      }

    }
    delay(200);
  }
 
  int changeCurrentState = digitalRead(changeCurrentPin);
  if(changeCurrentState == LOW){
    if (configAlarm==true)  currentSelection = (currentSelection + 1) % 3;
    delay(200);
  }


  if(configAlarm) {
    lcd.setCursor(13,0);
    lcd.print("CNF");
  }
  if(not configAlarm){
    lcd.setCursor(13,0);
    lcd.print("   ");
  }

  lcd.setCursor(10,0);
  lcd.print(currentSelection);
 

}
