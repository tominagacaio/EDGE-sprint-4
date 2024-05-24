#include <Wire.h>        
#include <LiquidCrystal_I2C.h>
#define PIR_PIN 15      // PIR motion sensor
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
int motionCount = 0;  
int ledPin= 2;          //on board led
int inputPin= 15;       //from PIR
 
void setup(){
  Serial.begin(115200);
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print("Count No. = 0");
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  delay(4000);
}
 
void loop(){
  int value= digitalRead(inputPin);
   if (value == HIGH)
  {
    delay(2000);
    motionCount++;
    updateLCD();
 
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion Detect !");
       
    lcd.backlight();  
    lcd.setCursor(0, 0);  
    lcd.print("Motion Detect !");
    delay(2000) ;
   
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("NO motion detect");
    lcd.setBacklight(LOW);
    lcd.clear();
 
  }
  delay(1000);
}
 
void updateLCD() {
  lcd.setCursor(0, 1);
  lcd.print("    ");
  lcd.setCursor(0, 1);
  lcd.print("Count No. =  ");
  lcd.print(motionCount);
}